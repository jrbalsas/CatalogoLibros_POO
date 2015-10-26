/** 
 * @file   Revista.cpp
 * @author jrbalsas
 *
 * @date 9 de octubre de 2015, 13:40
 */

#include <sstream>

#include "Revista.h"
#include "Ejemplar.h"


/**Construye una revista a partir de su información básica*/
Revista::Revista(   std::string ISSN, std::string titulo, unsigned int anio, unsigned int numero,
                    std::string editorial, float precio)
    : Ejemplar(titulo, editorial, precio), _ISSN(ISSN), _anio(anio), _numero(numero) {
}

/**Constructor de copia*/
Revista::Revista(const Revista& orig)
    :Ejemplar(orig),_ISSN(orig._ISSN),_anio(orig._anio),_numero(orig._numero){

}

/**Destructor*/
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

/**Obtiene el identificador único de una Revista que es igual a su ISSN*/
std::string Revista::getID() const {
    return this->getISSN();
}

/**Compara el identificador con el ISSN de una revista*/
bool Revista::operator==(std::string identificador) const {
    return this->getISSN()==identificador;
}

/**Devuelve una cadena con la representación CSV de los datos de una revista*/
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

/**Inicializa una Revista a partir de sus datos obtenidos en formato CSV almacenados en línea
 @pre formato de línea: issn;año_publicacion;num_publicacion;título;editorial;precio*/
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

/**Compara si otro ejemplar tiene el mismo ISSN*/
bool Revista::operator==(const Comparable& c) const {
    return igualA(c);
}
/**Compara si otro ejemplar tiene el mismo ISSN*/
bool Revista::igualA(const Comparable& c) const {
    return _ISSN==dynamic_cast<const Ejemplar&>(c).getID();
}

/**Devuelve una copia en memoria dinámica del objeto
 @post la copia devuelva debe ser liberada por el llamador*/
Duplicable* Revista::copia() const{
    return new Revista(*this);
}
