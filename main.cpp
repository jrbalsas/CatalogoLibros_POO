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

    Catalogo catalogo;
    
    inicializaCatalogo(catalogo);

    //Pruebas de búsqueda correcta y visualización
    try {
        utilEjemplar::visualiza( catalogo.ejemplarAlAzar() );    
        utilEjemplar::visualiza( catalogo.buscaEjemplar("8497320409") );        
    } catch (std::exception &e) {
        std::cerr << "Error en programa principal: "
                  << e.what();
    }

    //Prueba de búsqueda sin éxito
    std::string idBusqueda="2222222222"; //ejemplar no existente
    
    try {
        utilEjemplar::visualiza( catalogo.buscaEjemplar(idBusqueda) );        
    } catch (std::exception &e) {
        std::cerr << "El ejemplar  "+idBusqueda
                  << " no se encuentra disponible" << std::endl;
    };
    
    //Prueba de volcado y recuperación a fichero CSV    
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

    //Prueba de copia del catálogo
    std::cout << "Duplicamos el catálogo original" << std::endl;
    Catalogo catalogoCopia(catalogo);
    
    //Prueba de borrado de elementos del catálogo copia
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
