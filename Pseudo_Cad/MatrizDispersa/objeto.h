#ifndef OBJETO_H
#define OBJETO_H
#include <iostream>
#include <string>
#include "nodo.h"
#include "ListaDoble/listadoble.h"

using namespace std;


class Objeto: public Nodo
{
private:
    int id;
    string nombre;
    string letra;
    string color;
    ListaDoble listaPuntos;

public:
    Objeto(int id, string nombre, string letra, string color, ListaDoble listaPuntos);
    //SETS
    void setId(int id);
    void setNombre(string nombre);
    void setLetra(string letra);
    void setColor(string color);
    //GETS
    int getId();
    string getNombre();
    string getLetra();
    string getColor();
    ListaDoble getListaDoble();
};

#endif // OBJETO_H
