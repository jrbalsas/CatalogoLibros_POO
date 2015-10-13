/** 
 * @file   Libro.h
 * @author jrbalsas
 *
 * @date 9 de octubre de 2015, 13:16
 */

#ifndef LIBRO_H
#define	LIBRO_H

#include "Ejemplar.h"


class Libro: public Ejemplar {
private:
    std::string _isbn;
    unsigned int _edicion;
    unsigned int _anioPublicacion;
    
public:
    Libro(std::string isbn="",std::string titulo="Sin titulo", std::string editorial="No especificada", float precio=0);
    Libro(const Libro& orig);
    virtual ~Libro();
    void setAnioPublicacion(unsigned int _anioPublicacion);
    unsigned int getAnioPublicacion() const;
    void setEdicion(unsigned int _edicion);
    unsigned int getEdicion() const;
    void setIsbn(std::string _isbn);
    std::string getIsbn() const;

    virtual std::string getID();

    //Métodos Interfaz ItemCSV
    virtual std::string toCSV();
    virtual void fromCSV(std::string linea);



private:

};

#endif	/* LIBRO_H */

