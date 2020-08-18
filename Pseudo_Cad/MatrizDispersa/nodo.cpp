#include "nodo.h"
#include <iostream>

using namespace std;

Nodo::Nodo()
{
    this->norte = NULL;
    this->sur = NULL;
    this->este = NULL;
    this->oeste = NULL;
}

Nodo* Nodo::getSur(){
    return this->sur;
}

Nodo* Nodo::getNorte(){
    return this->norte;
}

Nodo* Nodo::getEste(){
    return this->este;
}

Nodo* Nodo::getOeste(){
    return this->oeste;
}

void Nodo::setOeste(Nodo *n){
    this->oeste = n;
}

void Nodo::setSur(Nodo *n){
    this->sur = n;
}

void Nodo::setNorte(Nodo *n){
    this->norte = n;
}

void Nodo::setEste(Nodo *n){
    this->este = n;
}
