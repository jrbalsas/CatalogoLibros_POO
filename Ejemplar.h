/**
 * @file   Ejemplar.h
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 12:55
 */

#ifndef EJEMPLAR_H
#define	EJEMPLAR_H

#include <string>
#include "ItemCSV.h"

/** Ejemplar de un catálogo de libros*/
class Ejemplar: public ItemCSV {
private:
    std::string _titulo;
    std::string _editorial;
    float _precio;
    //Date fechaAdquisicion;
public:
    Ejemplar(std::string titulo="No especificado", std::string editorial="No especificada", float precio=0);
    Ejemplar(const Ejemplar& orig);
    virtual ~Ejemplar();

    void setPrecio(float precio);
    float getPrecio() const;
    void setEditorial(std::string editorial);
    std::string getEditorial() const;
    void setTitulo(std::string titulo);
    std::string getTitulo() const;
    
    virtual std::string getID()=0;

    //Interfaz ItemCSV
    virtual std::string toCSV();
    virtual void fromCSV(std::string linea);


    
private:
    

};

#endif	/* EJEMPLAR_H */

