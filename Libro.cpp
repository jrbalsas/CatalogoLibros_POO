/** 
 * @file   Libro.cpp
 * @author jrbalsas
 *
 * @date 9 de octubre de 2015, 13:16
 */

#include "Libro.h"

Libro::Libro(std::string isbn,std::string titulo, std::string editorial, float precio)
    :Ejemplar(titulo,editorial,precio),_isbn(isbn){
}

Libro::Libro(const Libro& orig) {
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


