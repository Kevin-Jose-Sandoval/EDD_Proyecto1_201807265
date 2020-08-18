#ifndef CABECERA_H
#define CABECERA_H
#include <iostream>
#include <string>
#include "nodo.h"

using namespace std;

class Cabecera:public Nodo
{
private:
    int numero;
public:
    Cabecera(int numero);
    void setNumero(int numero);
    int getNumero();

};

#endif // CABECERA_H
