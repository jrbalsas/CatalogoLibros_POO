/**
 * @file   Ejemplar.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 12:55
 */

#include "Ejemplar.h"

Ejemplar::Ejemplar(std::string titulo, std::string editorial, float precio)
    :_titulo(titulo),_editorial(editorial),_precio(precio) {
}

Ejemplar::Ejemplar(const Ejemplar& orig)
    :_titulo(orig._titulo),_editorial(orig._editorial),_precio(orig._precio){
}

Ejemplar::~Ejemplar() {
}

void Ejemplar::setPrecio(float precio) {
    this->_precio = precio;
}

float Ejemplar::getPrecio() const {
    return _precio;
}

void Ejemplar::setEditorial(std::string editorial) {
    this->_editorial = editorial;
}

std::string Ejemplar::getEditorial() const {
    return _editorial;
}

void Ejemplar::setTitulo(std::string titulo) {
    this->_titulo = titulo;
}

std::string Ejemplar::getTitulo() const {
    return _titulo;
}

