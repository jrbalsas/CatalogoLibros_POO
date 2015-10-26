/** Definición de la Interfaz Identificable
 * @file   Identificable.h
 * @author jrbalsas
 *
 * @date 16 de octubre de 2015, 11:46
 */

#ifndef IDENTIFICABLE_H
#define	IDENTIFICABLE_H

#include <string>

/**Interfaz para objetos que son identificable.
 Un objeto es identificable cuando puede representase por una clave única*/
template <typename T>
class Identificable {
public:
    virtual T getID() const = 0;
    virtual bool operator==(std::string identificador) const =0;
    virtual ~Identificable() {};
private:

};

#endif	/* IDENTIFICABLE_H */

