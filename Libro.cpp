/** 
 * @file   Libro.cpp
 * @author jrbalsas
 *
 * @date 9 de octubre de 2015, 13:16
 */

#include <sstream>
#include "Libro.h"

#include <iostream>



/**Constructor de un libro a partir de su información básica*/
Libro::Libro(std::string isbn,std::string titulo, unsigned int anio, std::string autor, std::string editorial, float precio)
    :Ejemplar(titulo,editorial,precio),_isbn(isbn), _autor(autor),_anioPublicacion(anio),_edicion(0){
}

/**Constructor de copia*/
Libro::Libro(const Libro& orig): Ejemplar(orig),_isbn(orig._isbn),
                                _anioPublicacion(orig._anioPublicacion),_edicion(orig._edicion) {
}

/**Destructor*/
Libro::~Libro() {
}

void Libro::setAutor(std::string _autor) {
    this->_autor = _autor;
}

std::string Libro::getAutor() const {
    return _autor;
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

/**Obtiene el identificador único de un Libro que es igual a su ISBN*/
std::string Libro::getID() const {
    return this->getIsbn();
}

/**Compara el identificador con el ISBN de un libro*/
bool Libro::operator==(std::string identificador) const {
    return this->getIsbn()==identificador;
};

/**Devuelve una cadena con la representación CSV de los datos de un libro*/
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

/**Inicializa un Libro a partir de sus datos obtenidos en formato CSV almacenados en línea
 @pre formato de línea: isbn;año_publicacion;num_edicion;título;editorial;precio*/
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

/**Compara si otro ejemplar tiene el mismo ISBN*/
bool Libro::operator==(const Comparable& e) const {
    return igualA(e);
}

/**Compara si otro ejemplar tiene el mismo ISBN*/
bool Libro::igualA(const Comparable& e) const{
    return _isbn==dynamic_cast<const Ejemplar&>(e).getID();
}

/**Devuelve una copia en memoria dinámica del objeto
 @post la copia devuelva debe ser liberada por el llamador*/
Duplicable* Libro::copia() const{
    return new Libro(*this);
}

