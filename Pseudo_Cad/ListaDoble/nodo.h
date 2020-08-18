#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

class Nodo
{
public:
    string elemento;
    Nodo *sig;
    Nodo *ant;
    //METODOS
    Nodo(string elemento);
    string getElemento();
};

#endif // NODO_H


