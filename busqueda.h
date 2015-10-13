/** 
 * @file   busqueda.h
 * @author jrbalsas
 *
 * @date 13 de octubre de 2015, 13:03
 */

#ifndef BUSQUEDA_H
#define	BUSQUEDA_H

#include "Comparable.h"

/**Localiza un elemento en un vector
   @post Devuelve la posicion del vector donde se encuentra la primera ocurrencia del elemento
   @post Devuelve -1 si el elemento no se encuentra en el vector
 */
template<typename T>
int BuscaElemento(T elementos[], int numElementos, T elemento) {

    int posEncontrado=-1;
    
    for (int i=0; i<numElementos && posEncontrado==-1; i++) {
        if (elementos[i]==elemento) 
            posEncontrado=i;
    }
    return posEncontrado;
    
}

#endif	/* BUSQUEDA_H */

