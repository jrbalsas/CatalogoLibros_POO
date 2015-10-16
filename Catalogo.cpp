/** 
 * @file   Catalogo.cpp
 * @author jrbalsas
 *
 * @date 16 de octubre de 2015, 10:45
 */

#include <stdexcept>
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

/**Constructor de copia*/
Catalogo::Catalogo(const Catalogo& orig):numEjemplares(orig.numEjemplares) {
    
    for (int i = 0; i < numEjemplares; i++) {
        
        //Cada ejemplar del catálogo original devuelve una copia suya para
        //el nuevo catálogo
        ejemplares[i]=dynamic_cast<Ejemplar*>( orig.ejemplares[i]->copia() );

    }

            
}

Catalogo::~Catalogo() {
    //Liberamos ejemplares creados en el catálogo
    for (int i = 0; i < numEjemplares; i++) {
        delete ejemplares[i];
    }

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
        throw std::out_of_range("[Catalogo]: Espacio insuficiente en catálogo para añadir un nuevo ejemplar");
    ejemplares[numEjemplares]=dynamic_cast<Ejemplar*>(ejemplar.copia());
    numEjemplares++;
}

/**Devuelve el ejemplar de un catálogo por su identificador
 @throw NoEncontrado si el ejemplar en cuestión no está en el catálogo*/
Ejemplar& Catalogo::buscaEjemplar(std::string idEjemplar) {

   int posEncontrado=BuscaElemento(ejemplares,numEjemplares,idEjemplar);
   if (posEncontrado<0) 
       throw ExNoEncontrado("[Catalogo] el ejemplar no se encuentra en el Catálogo");
   return *ejemplares[posEncontrado];
}
