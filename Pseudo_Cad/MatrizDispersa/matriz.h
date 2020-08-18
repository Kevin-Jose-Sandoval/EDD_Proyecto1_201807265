#ifndef MATRIZ_H
#define MATRIZ_H
#include "nodo.h";
#include "cabecera.h"
#include "objeto.h"

class Matriz
{
public:
    Matriz();
    ~Matriz();
    void add(Objeto *nuevo);
    void codigo();

private:
    Cabecera *horizontal;
    Cabecera *vertical;
    Cabecera *getVertical(int numeroV);
    Cabecera *getHorizontal(int numeroH);
    Cabecera *crearVertical(int numeroV);
    Cabecera *crearHorizontal(int numeroH);

    Nodo *obtenerUltimoV(Cabecera *cabecera, int numeroV);
    Nodo *obtenerUltimoH(Cabecera *cabecera, int numeroH);
};

#endif // MATRIZ_H
