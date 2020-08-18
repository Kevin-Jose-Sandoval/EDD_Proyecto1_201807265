#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <iostream>
#include "nodo.h"
using namespace std;

class ListaDoble
{
private:
    Nodo *primero;
    Nodo *ultimo;

public:
    ListaDoble();
    bool vacio();
    void insertarInicio(string elemento);
    void insertarFinal(string elemento);
    void eliminarInicio();
    void eliminarFinal();
    void mostrarLista();
    void buscarNodo();
    void modificarNodo();
};

#endif // LISTADOBLE_H

