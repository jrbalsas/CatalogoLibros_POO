/** 
 * @file   Comparable.h
 * @author jrbalsas
 *
 * @date 13 de octubre de 2015, 12:25
 */

#ifndef COMPARABLE_H
#define	COMPARABLE_H

/**Interfaz para clases que admiten el operador de igualdad*/
class Comparable {
public:
    virtual bool operator==(Comparable &e )=0;
    //virtual bool igualA(Comparable &e)=0;
    virtual ~Comparable() {};
private:

};

#endif	/* COMPARABLE_H */

