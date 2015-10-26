/** Definición de la interfaz Comparable
 * @file   Comparable.h
 * @author jrbalsas
 *
 * @date 13 de octubre de 2015, 12:25
 */

#ifndef COMPARABLE_H
#define	COMPARABLE_H

/**Interfaz para clases cuyos objetos son comparables
 Dos objetos son comparables se puede saber si son iguales usando el operador ==
 */
class Comparable {
public:
    virtual bool operator==(const Comparable &e ) const =0;
    virtual bool igualA(const Comparable &e) const =0;
    virtual ~Comparable() {};
private:

};

#endif	/* COMPARABLE_H */

