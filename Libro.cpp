/** 
 * @file   Libro.cpp
 * @author jrbalsas
 *
 * @date 9 de octubre de 2015, 13:16
 */

#include <sstream>
#include "Libro.h"

#include <iostream>


Libro::Libro(std::string isbn,std::string titulo, std::string editorial, float precio)
    :Ejemplar(titulo,editorial,precio),_isbn(isbn){
}

Libro::Libro(const Libro& orig): Ejemplar(orig),_isbn(orig._isbn),
                                _anioPublicacion(orig._anioPublicacion),_edicion(orig._edicion) {
}

Libro::~Libro() {
}

void Libro::setAnioPublicacion(unsigned int _anioPublicacion) {
    this->_anioPublicacion = _anioPublicacion;
}

unsigned int Libro::getAnioPublicacion() const {
    return _anioPublicacion;
}

void Libro::setEdicion(unsigned int _edicion) {
    this->_edicion = _edicion;
}

unsigned int Libro::getEdicion() const {
    return _edicion;
}

void Libro::setIsbn(std::string _isbn) {
    this->_isbn = _isbn;
}

std::string Libro::getIsbn() const {
    return _isbn;
}

std::string Libro::getID() {
    return this->getIsbn();
}

std::string Libro::toCSV() {

    std::stringstream ss;
    std::string linea;
    
    
    ss  << _isbn <<';' 
        << _anioPublicacion << ';'
        << _edicion << ';';

    ss  << Ejemplar::toCSV();

    
    std::getline(ss,linea);

    return linea;
}

void Libro::fromCSV(std::string linea) {

    std::stringstream ss(linea);
    std::string lineaEjemplar;
    
    std::getline(ss,_isbn,';');
    ss >> _anioPublicacion;
    ss.ignore(); //ignoramos siguiente ';'
    ss >> _edicion;
    ss.ignore();
    
    //Procesamos resto de la línea con la parte de Ejemplar
    std::getline(ss,lineaEjemplar);
    Ejemplar::fromCSV(lineaEjemplar);
    
}

bool Libro::operator==(Comparable& e) {
    return _isbn==dynamic_cast<Libro&>(e)._isbn;
}



