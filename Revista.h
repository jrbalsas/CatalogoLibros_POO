/** 
 * @file   Revista.h
 * @author jrbalsas
 *
 * @date 9 de octubre de 2015, 13:40
 */

#ifndef REVISTA_H
#define	REVISTA_H
#include "Ejemplar.h"
#include "Identificable.h"

class Revista: public Ejemplar {
private:
    std::string _ISSN;
    unsigned int _numero;
    unsigned int _anio;
public:
  
    Revista( std::string ISSN="",  std::string titulo="Sin titulo", unsigned int anio=0, unsigned int numero=0,
             std::string editorial="Sin especificar", float precio=0);

    Revista(const Revista& orig);
    virtual ~Revista();
    void setAnio(unsigned int _anio);
    unsigned int getAnio() const;
    void setNumero(unsigned int _numero);
    unsigned int getNumero() const;
    void setISSN(std::string _issn);
    std::string getISSN() const;


    //Interfaz Identificable
    virtual std::string getID();
    virtual bool operator==(std::string identificador);

    //Interfaz ItemCSV
    virtual std::string toCSV();
    virtual void fromCSV(std::string linea);


    //Interfaz Comparable
    virtual bool operator==(Comparable& e);
    virtual bool igualA(Comparable& e);


    //Interfaz Duplicable
    virtual Duplicable* copia() const;

private:

};

#endif	/* REVISTA_H */

