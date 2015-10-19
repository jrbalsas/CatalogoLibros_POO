/** 
 * @file   Catalogo.cpp
 * @author jrbalsas
 *
 * @date 16 de octubre de 2015, 10:45
 */

#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Catalogo.h"
#include "busqueda.h"
#include "ExNoEncontrado.h"

/**Constructor por defecto*/
Catalogo::Catalogo():numEjemplares(0) {
    //Inicializamos punteros del catálogo
    for (int i = 0; i < MAXEJEMPLARES; i++) {
        ejemplares[i]=0;
    }

}

int Catalogo::getNumEjemplares() const {
    return numEjemplares;
}

/**Constructor de copia*/
Catalogo::Catalogo(const Catalogo& orig):numEjemplares(orig.numEjemplares) {
    
    for (int i = 0; i < numEjemplares; i++) {
        
        //Cada ejemplar del catálogo original devuelve una copia suya para
        //el nuevo catálogo
        ejemplares[i]=dynamic_cast<Ejemplar*>( orig.ejemplares[i]->copia() );

    }

            
}
/**Destructor*/
Catalogo::~Catalogo() {
    vaciar();
}

/**Borrar todos los ejemplares de un catálogo */
void Catalogo::vaciar() {
    //Liberamos ejemplares creados en el catálogo
    for (int i = 0; i < numEjemplares; i++) {
        delete ejemplares[i];
    }
    numEjemplares=0;
}

/**Añadir una copia de un libro al catálogo
 @throw std::out_of_range si no hay espacio suficiente en el catálogo*/
void Catalogo::nuevoLibro(const Libro& libro) {
    if (numEjemplares==MAXEJEMPLARES) 
        throw std::out_of_range("[Catalogo]: Espacio insuficiente en catálogo para añadir un nuevo libro");
    ejemplares[numEjemplares]=new Libro(libro);
    numEjemplares++;
}

/**Añadir una copia de una revista al catálogo
 @throw std::out_of_range si no hay espacio suficiente en el catálogo*/
void Catalogo::nuevaRevista(const Revista& revista) {
    if (numEjemplares==MAXEJEMPLARES) 
        throw std::out_of_range("[Catalogo]: Espacio insuficiente en catálogo para añadir una nueva revista");
    ejemplares[numEjemplares]=new Revista(revista);
    numEjemplares++;
}

/**Añadir una copia de un ejemplar al catálogo
 @throw std::out_of_range si no hay espacio suficiente en el catálogo*/
void Catalogo::nuevoEjemplar(const Ejemplar& ejemplar) {
    if (numEjemplares==MAXEJEMPLARES) 
        throw std::out_of_range("[Catalogo::nuevoEjemplar]: Espacio insuficiente en catálogo para añadir un nuevo ejemplar");
    ejemplares[numEjemplares]=dynamic_cast<Ejemplar*>(ejemplar.copia());
    numEjemplares++;
}

/**Devuelve el ejemplar de un catálogo por su identificador
 @throw NoEncontrado si el ejemplar en cuestión no está en el catálogo*/
Ejemplar& Catalogo::buscaEjemplar(std::string idEjemplar) {

   int posEncontrado=BuscaElemento(ejemplares,numEjemplares,idEjemplar);
   if (posEncontrado<0) 
       throw ExNoEncontrado("[Catalogo::buscaEjemplar] el ejemplar no se encuentra en el Catálogo");
   return *ejemplares[posEncontrado];
}

/**Borra un ejemplar del catálogo a partir de su identificador
 @throw NoEncontrado si el ejemplar en cuestión no está en el catálogo
*/
void Catalogo::borraEjemplar(std::string idEjemplar) {
   int posEncontrado=BuscaElemento(ejemplares,numEjemplares,idEjemplar);
   if (posEncontrado<0) 
       throw ExNoEncontrado("[Catalogo::borraEjemplar] el ejemplar no se encuentra en el Catálogo");
   
   delete ejemplares[posEncontrado];
   numEjemplares--;
   if (numEjemplares>0) {
       //Sustituimos el elemento borrado por último para no dejar huecos en el vector de ejemplares
        ejemplares[posEncontrado]=ejemplares[numEjemplares];
   }
}

/**Devuelve un ejemplar al azar del Catálogo
 @throw NoEncontrado si el catálogo está vacío
*/
Ejemplar& Catalogo::ejemplarAlAzar() {
    if (numEjemplares==0)
       throw ExNoEncontrado("[Catalogo::ejemplarAlAzar] El catálogo está vacío");
    return *ejemplares[rand()%numEjemplares];
}

/** Guarda los ejemplares del catálogo en un fichero */
void Catalogo::guardaEnFichero(std::string nombreFichero) {
    std::ofstream f;
    std::string linea;
    
    f.open(nombreFichero.c_str());
    
    if (f.good()) {
        for ( int i=0; i<numEjemplares; i++ ) {
            //Añadimos el tipo de cada ejemplar en la primera columna de cada línea del fichero CSV
            if (dynamic_cast<Libro*>(ejemplares[i])!=0) {
                linea="Libro;";
            } else if (dynamic_cast<Revista*>(ejemplares[i])!=0) {
                linea="Revista;";
            } else {
                //Ejemplar de tipo desconocido
                linea="Desconocido;";
            }
            linea=linea+ejemplares[i]->toCSV();
            f <<  linea << std::endl;
        };
        f.close();        
    }
}

/** Recupera de un fichero CSV los ejemplares de un catálogo
    @throw std::logic_error si encuentra algún ejemplar que no es válido
 */
void Catalogo::recuperaDeFichero(std::string nombreFichero) {
    std::ifstream f;
    std::string tipo,linea;
    
    if (numEjemplares>0) {
        //Si el catálogo ya tiene ejemplares, borrarlos previamente
        vaciar();
    }
    f.open( nombreFichero.c_str() );

    if ( f.good() ) {
        while( !f.eof() ) {
            std::getline( f, tipo, ';' );
            if (tipo=="") {
                continue; //ignoramos líneas vacías
            }else if (tipo=="Libro") {
                ejemplares[numEjemplares]=new Libro();
            }else if (tipo=="Revista") {
                ejemplares[numEjemplares]=new Revista();
            }else {
                throw std::logic_error("[Catalogo::recuperaDeFichero] El fichero contiene ejemplares de tipo desconocido");                
            };
            
            std::getline(f,linea);
            ejemplares[numEjemplares]->fromCSV(linea);
            numEjemplares++;            
            }
            f.close();
    }

}

