/** 
 * @file   Revista.h
 * @author jrbalsas
 *
 * @date 9 de octubre de 2015, 13:40
 */

#ifndef REVISTA_H
#define	REVISTA_H
#include "Ejemplar.h"

class Revista: public Ejemplar {
private:
    std::string _ISSN;
    unsigned int _numero;
    unsigned int _anio;
public:
  
    Revista( std::string ISSN,  std::string titulo, unsigned int anio, unsigned int numero,
             std::string editorial="Sin especificar", float precio=0);

    Revista(const Revista& orig);
    virtual ~Revista();
    void setAnio(unsigned int _anio);
    unsigned int getAnio() const;
    void setNumero(unsigned int _numero);
    unsigned int getNumero() const;
    void setISSN(std::string _issn);
    std::string getISSN() const;


    virtual std::string getID();


private:

};

#endif	/* REVISTA_H */

