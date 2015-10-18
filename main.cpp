/**
 * @file   main.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 12:55
 */

#include <iostream>

#include "Libro.h"
#include "Revista.h"
#include "busqueda.h"

using namespace std;

const int NUMEJEMPLARES=2;

/** Programa de ejemplo para probar el catálogo
*/
int main(int argc, char** argv) {

    Ejemplar* ejemplares[NUMEJEMPLARES]= {
        new Libro("8448105907","Programación Orientada a Objetos","Joyanes, L.","MacGraw-Hill",35),
        new Libro("8497320409","C++ Estandar","Hernandez, E.","Paraninfo",28)
    };
    
    Libro quijote("123456789","El ingenioso hidalgo, Don Quijote de la Mancha","Cervantes, M.","Edelvives",9.5);
    Libro poo("8448105907","Programación Orientada a Objetos","Joyanes, L.", "MacGraw-Hill",35);
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
                                  ,dynamic_cast<Ejemplar*>(&poo));
    
    if (posLibroCpp>=0) {
        std::cout << "Libro localizado: "
                  << dynamic_cast<Ejemplar*>(ejemplares[posLibroCpp])->toCSV() 
                  << std::endl;
    }
    
    int posLibroFatima=BuscaElemento(ejemplares, NUMEJEMPLARES
                                    ,dynamic_cast<Ejemplar*>(&fatima));
    if (posLibroFatima==-1) {
        std::cout << "El libro con ISBN " << fatima.getIsbn()
                  << " no se encuentra en el catálogo"
                  << std::endl;
    }

    //Liberamos objetos en memoria dinámica
    for (int i = 0; i < NUMEJEMPLARES; i++) {
        delete ejemplares[i];
    }

    
    return 0;
}

/**Visualiza un ejemplar de forma adecuada según su tipo*/
void visualizaEjemplar(Ejemplar &ejemplar) {
    //Usamos RTTI para determinar cómo se visualiza cada tipo de ejemplar
    if (dynamic_cast<Libro*>(&ejemplar)!=0) 
        visualizaEjemplar(dynamic_cast<Libro&>(ejemplar));
    else if (dynamic_cast<Revista*>(&ejemplar)!=0) 
        visualizaEjemplar(dynamic_cast<Revista&>(ejemplar));
    else {
        std::cout << "Ejemplar es de tipo desconocido:" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "ID: "<< ejemplar.getID() << std::endl;
        std::cout << "Nombre: " << ejemplar.getTitulo() << std::endl;
        std::cout << "Precio: "<< ejemplar.getPrecio() << " euros" << std::endl;     
    }
    
}
/**Visualiza un Libro en la salida estándar*/
void visualizaEjemplar(Libro &libro) {
    std::cout << "LIBRO: " << libro.getTitulo() << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Autor: " << libro.getAutor() << std::endl;
    std::cout << "Año de publicación:" << libro.getAnioPublicacion() << std::endl;
    std::cout << "Edición: " << libro.getEdicion() << std::endl;
    std::cout << "Editorial: " << libro.getEditorial() << std::endl;
    std::cout << "ISBN: " << libro.getIsbn() << std::endl;
    std::cout << "Precio: "<< libro.getPrecio() << " euros" << std::endl;     
}
/**Visualiza una Revista en la salida estándar*/
void visualizaEjemplar(Revista &revista) {
    std::cout << "REVISTA: " << revista.getTitulo() << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Editorial: " << revista.getEditorial() << std::endl;
    std::cout << "Año de publicación: " << revista.getAnio();
    std::cout << " Num: " << revista.getNumero() << std::endl;
    std::cout << "ISSN: " << revista.getAnio() << std::endl;
    std::cout << "Precio: "<< revista.getPrecio() << " euros" << std::endl;
}
