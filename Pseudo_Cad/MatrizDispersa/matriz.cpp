#include "matriz.h"
#include "objeto.h"

#include <ostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;


Matriz::Matriz()
{
    this->horizontal = NULL;
    this->vertical = NULL;
}

Matriz::~Matriz(){
    Nodo *aux, *aux2, *temp, *temp2, *extra, *extra2;
    aux = this->vertical;
    temp = this->horizontal;
    //ELIMINANDO LOS VERTICALES
    while(aux != NULL){
        extra = aux->getSur();
        aux2 = aux->getEste();
        while(aux2 != NULL){
            extra2 = aux2->getEste();
            delete aux2;
            aux2 = extra2;
        }
        delete aux;
        aux = extra;
    }
    //ELIMINANDO LOS HORIZONTALES
    while(temp != NULL){
        temp2 = temp->getEste();
        delete temp;
        temp = temp2;
    }
}

void Matriz::add(Objeto *nuevo){
    //OBTENIENDO CABECERAS
    Cabecera *vertical = this->getVertical(nuevo->getMateria());
    Cabecera *horizontal = this->getHorizontal(nuevo->getNombre());

    //SINO EXISTEN, CREAR CABECERAS
    if(vertical == NULL){
        vertical = crearVertical(nuevo->getMateria());
    }
    if(horizontal == NULL){
        horizontal = crearHorizontal(nuevo->getNombre());
    }

    //OBTENIENDO NODO ULTIMO DE LA IZQUIERDA Y EL DE ARRIBA
    Nodo *izquierda = obtenerUltimoH(vertical, nuevo->getNombre()); //SE DESPLAZA VERTICAL
    Nodo *superior = obtenerUltimoV(horizontal, nuevo->getMateria());//SE DESPLAZA HORIZONTAL

    if(izquierda->getEste() == NULL){ //YA NO EXISTE OTRO NODO A LA DERECHA, ES ÚNICO
        izquierda->setEste(nuevo);
        nuevo->setOeste(izquierda);
    }else{
        //EXISTEN 2 SE DEBE INGRESAR AL CENTRO
        Nodo* temp = izquierda->getEste();
        izquierda->setEste(nuevo);
        nuevo->setOeste(izquierda);
        temp->setOeste(nuevo);
        nuevo->setEste(temp);
        }
        //ARRIBA
        if (superior->getSur() == NULL){//YA NO HAY NADA ABAJO
            superior->setSur(nuevo);
            nuevo->setNorte(superior);
        }else{
            Nodo *temp = superior->getSur();
            superior->setSur(nuevo);
            nuevo->setNorte(superior);
            temp->setNorte(nuevo);
            nuevo->setSur(temp);
        }
}

Cabecera* Matriz::crearHorizontal(string nombre){
    //LISTA DOBLE ORDENADA
    if(this->horizontal == NULL){
        Cabecera* nueva = new Cabecera(nombre);
        this->horizontal = nueva;
        return nueva;
    }
    Cabecera* aux = this->horizontal;
    //SI ES MENOR
    if(nombre.compare(aux->getNombre()) <= 0){
        Cabecera* nueva = new Cabecera(nombre);
        nueva->setEste(aux);
        this->horizontal->setOeste(nueva);
        this->horizontal = nueva;
        return nueva;
    }
    //BUSCANDO POSICION EXACTA
    while(aux->getEste() != NULL){
        //SI EL VALOR ES MAYOR EN EL QUE ESTAMOS Y MENOR AL SIGUIENTE
        if(nombre.compare(aux->getNombre()) > 0 && nombre.compare(((Cabecera*)aux->getEste())->getNombre())<=0){
            Cabecera* nueva = new Cabecera(nombre);
            Cabecera* temp = (Cabecera*)aux->getEste();
            temp->setOeste(nueva);
            nueva->setEste(temp);
            aux->setEste(nueva);
            nueva->setOeste(aux);
            return nueva;
        }
        aux = (Cabecera*)aux->getEste();
    }
    //ENTONCES ES MAYOR
    Cabecera* nuevo = new Cabecera(nombre);
    aux->setEste(nuevo);
    nuevo->setOeste(aux);
    return nuevo;
}

Cabecera* Matriz::crearVertical(string nombre){
    //LISTA DOBLE ORDENADA
    if(this->vertical == NULL){
        Cabecera* nueva = new Cabecera(nombre);
        this->vertical = nueva;
        return nueva;
    }
    Cabecera* aux = this->vertical;
    //SI ES MENOR
    if(nombre.compare(aux->getNombre()) <= 0){
        Cabecera* nueva = new Cabecera(nombre);
        nueva->setSur(this->vertical);
        this->vertical->setNorte(nueva);
        this->vertical = nueva;
        return nueva;
    }
    //BUSCANDO POSICION EXACTA
    while(aux->getSur() != NULL){
        //SI EL VALOR ES MAYOR EN EL QUE ESTAMOS Y MENOR AL SIGUIENTE
        if(nombre.compare(aux->getNombre()) > 0 && nombre.compare(((Cabecera*)aux->getSur())->getNombre())<=0){
            Cabecera* nueva = new Cabecera(nombre);
            Cabecera* temp = (Cabecera*)aux->getSur();
            temp->setNorte(nueva);
            nueva->setSur(temp);
            aux->setSur(nueva);
            nueva->setNorte(aux);
            return nueva;
        }
        aux = (Cabecera*)aux->getSur();
    }
    //ENTONCES ES MAYOR
    Cabecera* nueva = new Cabecera(nombre);
    aux->setSur(nueva);
    nueva->setNorte(aux);
    return nueva;
}

Nodo* Matriz::obtenerUltimoH(Cabecera *cabecera, string nombre){
    if(cabecera->getEste() == NULL){
        return cabecera;
    }
    Nodo* aux = cabecera->getEste();
    while(aux->getEste() != NULL){
        if(nombre.compare(((Persona*)aux)->getNombre()) <= 0){
            return aux;
        }
        aux = aux->getEste();
    }
    if(nombre.compare(((Persona*)aux)->getNombre()) <= 0){
        return aux->getOeste();
    }
    return aux;
}

Nodo* Matriz::obtenerUltimoV(Cabecera *cabecera, string materia){
    if(cabecera->getSur() == NULL){
        return cabecera;
    }
    Nodo* aux = cabecera->getSur();
    while(aux->getSur() != NULL){
        if(materia.compare(((Persona*)aux)->getMateria()) <= 0){
            return aux;
        }
        aux = aux->getSur();
    }
    if(materia.compare(((Persona*)aux)->getMateria()) <= 0){
        return aux->getNorte();
    }
    return aux;
}

Cabecera* Matriz :: getVertical(string nombre){
    if(this->vertical == NULL){
        return NULL;
    }
    Cabecera* aux = this->vertical;
    while(aux != NULL){
        if(((string)aux->getNombre()).compare(nombre)==0){
            return aux;
        }
        aux = (Cabecera*)aux->getSur();
    }
    return NULL;
}

Cabecera* Matriz :: getHorizontal(string nombre){
    if(this->horizontal == NULL){
        return NULL;
    }
    Cabecera* aux = this->horizontal;
    while(aux != NULL){
        if(((string)aux->getNombre()).compare(nombre)==0){
            return aux;
        }
        aux = (Cabecera*)aux->getEste();
    }
    return NULL;
}
