/** Definición clase abstracta para representar cualquier ejemplar de un catálogo
 * @file   Ejemplar.h
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 12:55
 */

#ifndef EJEMPLAR_H
#define	EJEMPLAR_H

#include <string>
#include "ItemCSV.h"
#include "Comparable.h"
#include "Duplicable.h"
#include "Identificable.h"

/** Clase abstracta para cualquier ejemplar de un catálogo de libros*/
class Ejemplar: public ItemCSV, public Comparable, public Duplicable , public Identificable<std::string> {
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
   
    //Interfaz ItemCSV
    virtual std::string toCSV();
    virtual void fromCSV(std::string linea);
    

    //Redeclaración de métodos virtuales puros de interfaces
    //Necesario en versión gcc 4.9.2
    virtual bool operator==(Comparable& c) =0;
    virtual bool operator==(std::string identificador)=0;
    
private:
    

};

#endif	/* EJEMPLAR_H */

