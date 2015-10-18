/** Implementación de un catálogo de ejemplares
 * @file   Catalogo.h
 * @author jrbalsas
 *
 * @date 16 de octubre de 2015, 10:45
 */

#ifndef CATALOGO_H
#define	CATALOGO_H

#include <string>
#include "Ejemplar.h"
#include "Libro.h"
#include "Revista.h"

/** Catálogo de ejemplares*/
class Catalogo {
public:
    static const int MAXEJEMPLARES = 100;
private:
    Ejemplar* ejemplares[MAXEJEMPLARES];
    int numEjemplares;
public:
    Catalogo();
    Catalogo(const Catalogo& orig);
    virtual ~Catalogo();
    
    void nuevoLibro(const Libro &libro);
    void nuevaRevista(const Revista &revista);
    void nuevoEjemplar(const Ejemplar &ejemplar);
    
    void borraEjemplar(std::string idEjemplar);
    Ejemplar& buscaEjemplar(std::string idEjemplar);
    Ejemplar& ejemplarAlAzar();
    void guardaEnFichero(std::string nombreFichero);
    void recuperaDeFichero(std::string nombreFichero );
    int getNumEjemplares() const;
    void vaciar();
    
private:
};

#endif	/* CATALOGO_H */

