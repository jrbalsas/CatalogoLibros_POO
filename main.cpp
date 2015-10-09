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
    
    std::cout << quijote.getID() << std::endl;
    std::cout << muy.getID() << std::endl;
    
    return 0;
}

