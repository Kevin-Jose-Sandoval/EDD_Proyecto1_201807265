#include "cabecera.h"

Cabecera::Cabecera(int numero)
{
    this->numero = numero;
}

void Cabecera::setNumero(int numero){
    this->numero = numero;
}

int Cabecera::getNumero(){
    return this->numero;
}
