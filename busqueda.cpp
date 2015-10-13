/** Funciones de utilidad para la búsqueda de elementos en vectores
 * 
 * @file   busqueda.cpp
 * @author jrbalsas
 *
 * @date 13 de octubre de 2015, 12:11
 */

#include "busqueda.h"

/**Localiza un elemento en un vector
 * @pre  Los elementos del vector implementan la interfaz Comparable
   @post Devuelve la posicion del vector donde se encuentra la primera ocurrencia del elemento
   @post Devuelve -1 si el elemento no se encuentra en el vector
 */
int BuscaElemento(Comparable* elementos[], int numElementos, Comparable *elemento) {

    int posEncontrado=-1;
    
    for (int i=0; i<numElementos && posEncontrado==-1; i++) {
        if (*elementos[i]==*elemento) 
            posEncontrado=i;
    }
    return posEncontrado;
    
}

