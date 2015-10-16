/** Interfaz para operación de obtener duplicado de un objeto de una clase
 * @file   Duplicable.h
 * @author jrbalsas
 *
 * @date 16 de octubre de 2015, 11:00
 */

#ifndef DUPLICABLE_H
#define	DUPLICABLE_H

/** Interfaz para clases que permiten a sus objetos obtener copias de ellos mismos.
 El método copia debe devolver una copia en memoria dinámica del objeto que recibe el método.
 El usuario del método es responsable de liberar la memoria del objeto duplicado cuando ya no
 sea de utilidad.*/
class Duplicable {
public:
    virtual Duplicable* copia(void) const = 0;
    virtual ~Duplicable() {};
private:

};

#endif	/* DUPICABLE_H */

