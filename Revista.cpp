/** 
 * @file   Revista.cpp
 * @author jrbalsas
 *
 * @date 9 de octubre de 2015, 13:40
 */

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
