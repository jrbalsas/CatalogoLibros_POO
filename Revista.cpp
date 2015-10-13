/** 
 * @file   Revista.cpp
 * @author jrbalsas
 *
 * @date 9 de octubre de 2015, 13:40
 */

#include <sstream>

#include "Revista.h"
#include "Ejemplar.h"


Revista::Revista(   std::string ISSN, std::string titulo, unsigned int anio, unsigned int numero,
                    std::string editorial, float precio)
    : Ejemplar(titulo, editorial, precio), _ISSN(ISSN), _anio(anio), _numero(numero) {
}

Revista::Revista(const Revista& orig)
    :Ejemplar(orig),_ISSN(orig._ISSN),_anio(orig._anio),_numero(orig._numero){

}

Revista::~Revista() {
}

void Revista::setAnio(unsigned int _anio) {
    this->_anio = _anio;
}

unsigned int Revista::getAnio() const {
    return _anio;
}

void Revista::setNumero(unsigned int _numero) {
    this->_numero = _numero;
}

unsigned int Revista::getNumero() const {
    return _numero;
}

void Revista::setISSN(std::string _issn) {
    this->_ISSN = _issn;
}

std::string Revista::getISSN() const {
    return _ISSN;
}

std::string Revista::getID() {
    return this->getISSN();
}

std::string Revista::toCSV() {
    std::stringstream ss;
    std::string linea;
    
    
    ss  << _ISSN << ';'
        << _anio << ';'
        << _numero << ';';

    ss  << Ejemplar::toCSV();

    
    std::getline(ss,linea);
    
    return linea;
}

void Revista::fromCSV(std::string linea) {

    std::stringstream ss(linea);
    std::string lineaEjemplar;
    
    std::getline(ss,_ISSN,';');
    ss>>_anio;
    ss.ignore(); //ignoramos siguiente ';'
    ss>>_numero;
    ss.ignore();

    
    //Procesamos resto de la línea con la parte de Ejemplar
    std::getline(ss,lineaEjemplar);
    Ejemplar::fromCSV(lineaEjemplar);
    
}

bool Revista::operator==(Comparable& e) {
    return _ISSN==dynamic_cast<Revista&>(e)._ISSN;

}
