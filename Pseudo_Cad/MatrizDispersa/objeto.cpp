#include "objeto.h"
#include <iostream>
#include <string>

using namespace std;

Objeto::Objeto(int id, string nombre, string letra, string color, ListaDoble listaPuntos)
{
    this->id = id;
    this->nombre = nombre;
    this->letra = letra;
    this->color = color;
    this->listaPuntos = listaPuntos;
}

void Objeto::setId(int id){
    this->id = id;
}

void Objeto::setNombre(string nombre){
    this->nombre = nombre;
}

void Objeto::setLetra(string letra){
    this->letra = letra;
}

void Objeto::setColor(string color){
    this->color = color;
}

int Objeto::getId(){
    return this->id;
}

string Objeto::getNombre(){
    return this->nombre;
}

string Objeto::getLetra(){
    return this->letra;
}

string Objeto::getColor(){
    return this->color;
}

ListaDoble Objeto::getListaDoble(){
    return this->listaPuntos;
}
