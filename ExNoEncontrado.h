/** Definición de excepción lógica
 * @file   NoEncontrado.h
 * @author jrbalsas
 *
 * @date 16 de octubre de 2015, 9:33
 */

#ifndef NOENCONTRADO_H
#define	NOENCONTRADO_H

#include <stdexcept>
#include <string>

/**Excepción para indicar ausencia de elementos en búsquedas*/
class NoEncontrado: public std::logic_error {
public:
    NoEncontrado(std::string error="[NoEncontrado] Elemento no disponible"):std::logic_error(error) {};
    NoEncontrado(const NoEncontrado& orig):logic_error(orig) {};
    virtual ~NoEncontrado() {};
private:

};

#endif	/* NOENCONTRADO_H */

