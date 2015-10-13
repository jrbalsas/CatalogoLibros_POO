/**
 * @file   main.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 12:55
 */

#include <iostream>

#include "Libro.h"
#include "Revista.h"

using namespace std;

/** Programa de ejemplo para probar el catálogo
*/
int main(int argc, char** argv) {

    Libro quijote("123456789","El ingenioso hidalgo, Don Quijote de la Mancha","Edelvives",9.5);
    Revista muy("987654321","Muy Interesante",2016,5,"G+J",3);
    Libro fatima;
    Revista bike;
    
    std::cout << quijote.getID() << std::endl;
    std::cout << muy.getID() << std::endl;

    std::cout << quijote.toCSV() << std::endl;
    std::cout << muy.toCSV() << std::endl;
    
    fatima.fromCSV("8499893740;2012;1;La mano de Fatima;De bolsillo;9.46");
    bike.fromCSV("123456789;2015;10;Bike;Motorpress;3.50");
    
    std::cout << fatima.toCSV() << std::endl;
    std::cout << bike.toCSV() << std::endl;

    
    
    return 0;
}

