#include "nodo.h"

Nodo::Nodo(string elemento)
{
    this->elemento = elemento;
    sig = NULL;
    ant = NULL;
}

string Nodo::getElemento(){
    return this->elemento;
}
