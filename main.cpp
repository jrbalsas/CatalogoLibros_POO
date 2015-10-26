/**
 * @file   main.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 12:55
 */

#include <iostream>
#include <exception>

#include "Libro.h"
#include "Revista.h"
#include "busqueda.h"

#include "util_ejemplar.h"
#include "Catalogo.h"
#include "ExNoEncontrado.h"

using namespace std;

const int NUMEJEMPLARES=4;
const std::string ficheroEjemplares="ejemplares.csv";

/**Inicializamos un catálogo con algunos ejemplares de prueba*/
void inicializaCatalogo(Catalogo &catalogo) {
    
        catalogo.nuevoEjemplar( Libro("8448105907","Programación Orientada a Objetos",2011,"Joyanes, L.","MacGraw-Hill",35));
        catalogo.nuevoEjemplar( Libro("8497320409","C++ Estandar",2001,"Hernandez, E.","Paraninfo",28) );
        catalogo.nuevoEjemplar( Revista("123456789","Bike",2015,10,"Motorpress",3.50) );
        catalogo.nuevoEjemplar( Revista("987654321","Muy Interesante",2016,5,"G+J",3) );
        catalogo.nuevoEjemplar( Libro("8499893740","La mano de Fatima",2012,"Falcon, I.","De bolsillo",9.46) ) ;
}


/** Programa de ejemplo para probar el catálogo
*/
int main(int argc, char** argv) {

    Ejemplar* ejemplares[NUMEJEMPLARES]= {
        new Libro("8448105907","Programación Orientada a Objetos", 2011, "Joyanes, L.","MacGraw-Hill",35),
        new Libro("8497320409","C++ Estandar",2001, "Hernandez, E.","Paraninfo",28),
        new Revista("123456789","Bike",2015,10,"Motorpress",3.50),
        new Revista("987654321","Muy Interesante",2016,5,"G+J",3)
    };
    
    Libro quijote("123456789","El ingenioso hidalgo, Don Quijote de la Mancha",1605 ,"Cervantes, M.","Edelvives",9.5);
    Libro poo("8448105907","Programación Orientada a Objetos",2011, "Joyanes, L.", "MacGraw-Hill",35);
    Libro fatima;

    Revista muy("987654321","Muy Interesante",2016,5,"G+J",3);
    Revista bike;
    
    std::cout << quijote.getID() << std::endl;
    std::cout << muy.getID() << std::endl;

    std::cout << quijote.toCSV() << std::endl;
    std::cout << muy.toCSV() << std::endl;
    
    fatima.fromCSV("8499893740;2012;1;La mano de Fatima;De bolsillo;9.46");
    bike.fromCSV("123456789;2015;10;Bike;Motorpress;3.50");
    
    std::cout << fatima.toCSV() << std::endl;
    std::cout << bike.toCSV() << std::endl;

    int posLibroCpp=BuscaElemento(ejemplares, NUMEJEMPLARES
                                  ,dynamic_cast<Ejemplar&>(poo));
    
    if (posLibroCpp>=0) {
        std::cout << "Libro localizado: "
                  << dynamic_cast<Ejemplar*>(ejemplares[posLibroCpp])->toCSV() 
                  << std::endl;
    }
    
    int posLibroFatima=BuscaElemento(ejemplares, NUMEJEMPLARES
                                    ,dynamic_cast<Ejemplar&>(fatima));
    if (posLibroFatima==-1) {
        std::cout << "El libro con ISBN " << fatima.getIsbn()
                  << " no se encuentra en el catálogo"
                  << std::endl;
    }

    std::cout << "Listado de ejemplares" << std::endl;
    for (int i = 0; i < NUMEJEMPLARES; i++) {
        utilEjemplar::visualiza(*ejemplares[i]);
    }

    //Liberamos objetos en memoria dinámica
    for (int i = 0; i < NUMEJEMPLARES; i++) {        
        delete ejemplares[i];
    }

    //Pruebas de la clase catálogo
    Catalogo catalogo;
    
    inicializaCatalogo(catalogo);

    try {
        utilEjemplar::visualiza( catalogo.ejemplarAlAzar() );    
        utilEjemplar::visualiza( catalogo.buscaEjemplar("8497320409") );        
    } catch (std::exception &e) {
        std::cerr << "Error en programa principal: "
                  << e.what();
    }

    std::string idBusqueda="2222222222"; //ejemplar no existente
    
    try {
        utilEjemplar::visualiza( catalogo.buscaEjemplar(idBusqueda) );        
    } catch (std::exception &e) {
        std::cerr << "El ejemplar  "+idBusqueda
                  << " no se encuentra disponible" << std::endl;
    };
    

    try {
        std::cout << std::endl << "Volcando catálogo en fichero " << ficheroEjemplares << std::endl;
        catalogo.guardaEnFichero(ficheroEjemplares);

        std::cout << std::endl << "Vaciámos catálogo original " << std::endl;
        catalogo.vaciar();

        std::cout << std::endl << "Cargamos catálogo desde fichero " << ficheroEjemplares << std::endl;

        catalogo.recuperaDeFichero(ficheroEjemplares);
        std::cout << "Recuperados " << catalogo.getNumEjemplares() 
                  << " Ejemplares del fichero " << ficheroEjemplares << std::endl;

        try {
            idBusqueda="8497320409"; //Debería estar en el catálogo original almacenado
            utilEjemplar::visualiza( catalogo.buscaEjemplar(idBusqueda) );        
        } catch (ExNoEncontrado &e) {
            std::cerr << "El ejemplar  "+idBusqueda
                      << " no se encuentra disponible" << std::endl;
        }
    } catch (std::exception &e){
        std::cerr << "[main] Error al recuperar catálogo de disco. " << e.what();
        throw e; //Error irrecuperable. Terminamos la aplicación
    }

    std::cout << "Duplicamos el catálogo original" << std::endl;
    Catalogo catalogoCopia(catalogo);
    
    try {
        idBusqueda="123456789"; //Revista bike
        catalogoCopia.borraEjemplar(idBusqueda); 
        std::cout << std::endl << "Probamos a borrar un ejemplar no existente " << std::endl;
        catalogoCopia.borraEjemplar(idBusqueda); //No existente!
    } catch (ExNoEncontrado &e) {
        std::cerr << "El ejemplar  "+idBusqueda
                  << " no se encuentra disponible en la copia del catálogo" << std::endl;
    } 

    try {
        idBusqueda="123456789"; //Revista bike
        //La revista sí debe estar en el catálogo original
        utilEjemplar::visualiza( catalogo.buscaEjemplar(idBusqueda) );        
    } catch (ExNoEncontrado &e) {
        std::cerr << "El ejemplar  "+idBusqueda
                  << " no se encuentra disponible" << std::endl;
    } 
    
    return 0;
}
