/** Utilidades para entrada/salida de Ejemplares por Consola
 * @file   util_ejemplar.cpp
 * @author jrbalsas
 *
 * @date 18 de octubre de 2015
 */


#ifndef UTIL_EJEMPLAR_H
#define	UTIL_EJEMPLAR_H

#include "Ejemplar.h"
#include "Libro.h"
#include "Revista.h"

/**Funciones de utilidad para entrada/salida de Ejemplares por consola*/
namespace utilEjemplar {

    void visualiza(Ejemplar &ejemplar);
    void visualiza(Ejemplar *ejemplar);
    void visualiza(Libro &libro);
    void visualiza(Revista &revista);

}
#endif	/* UTIL_EJEMPLAR_H */

