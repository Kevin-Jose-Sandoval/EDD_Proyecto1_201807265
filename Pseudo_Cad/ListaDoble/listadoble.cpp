#include "listadoble.h"
#include <iostream>
#include "nodo.h"
using namespace std;

ListaDoble::ListaDoble()
{
    primero = ultimo = NULL;
}

bool ListaDoble::vacio(){
    return (primero == NULL);
}

//INSERTAR AL INICIO
void ListaDoble:: insertarInicio(string elemento){
    Nodo *temp = new Nodo(elemento);

    if(vacio() == true){
        primero = ultimo = temp;
    }
    else{
        temp->sig = primero;
        primero->ant = temp;
        primero = temp;
    }
}

//INSERTAR AL FINAL
void ListaDoble:: insertarFinal(string elemento){
    Nodo *temp = new Nodo(elemento);

    if(vacio() == true){
        primero = ultimo = temp;
    }
    else{
        ultimo->sig = temp;
        temp->ant = ultimo;
        ultimo = temp;
    }
}

//ELIMINAR AL INICIO
void ListaDoble::eliminarInicio(){
    if (vacio() == true){
        cout<<"No se puede eliminar. Lista vacia"<<endl;
    }
    else{
        if(primero == ultimo){
            primero = ultimo = NULL;
        }
        else{
            Nodo *temp = primero;
            primero = primero->sig;
            primero->ant = NULL;
            delete temp;
            cout<<"Elemento eliminado"<<endl;
        }
    }
}

//ELIMINAR AL FINAL
void ListaDoble:: eliminarFinal(){
    if (vacio() == true){
        cout<<"No se puede eliminar. Lista vacia"<<endl;
    }
    else{
        if(primero == ultimo){
            primero = ultimo = NULL;
        }
        else{
            Nodo *temp = ultimo;
            ultimo = ultimo->ant;
            ultimo->sig = NULL;
            delete temp;
            cout<<"Elemento eliminado"<<endl;
        }
    }
}

//MOSTRAR LISTA (DEL PRIMERO AL ULTIMO)
void ListaDoble:: mostrarLista(){
    if(vacio() == true){
        cout<<"No hay elementos en la lista"<<endl;
    }
    else{
        Nodo *aux = primero;
        int i = 1;
        bool seguir = true;
        cout<<"Datos de la lista: "<<endl;
        while(seguir){
            cout<<"El elemento "<<i<<" de la lista es: "<<aux->getElemento()<<endl;
            if(aux == ultimo){
                seguir = false;
            }
            aux = aux->sig;
            i++;
        }
    }
}

//BUSCAR NODO
void ListaDoble:: buscarNodo(){
    Nodo* actual =primero;
    bool encontrado = false;
    string nodoBuscado = "";
    cout << " Ingrese el dato del Nodo a Buscar: ";
    cin >> nodoBuscado;
    if(primero!=NULL){

        while(actual!=NULL && encontrado!=true){

            if(actual->elemento == nodoBuscado){
                cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";
                encontrado = true;
            }

            actual = actual->sig;
        }

        if(!encontrado){
            cout << "\n Nodo no Encontrado\n\n";
        }

    }else{
        cout << "\n La listas se encuentra Vacia\n\n";
    }
}

//MODIFICAR
void ListaDoble:: modificarNodo(){
    Nodo* actual = primero;
    bool encontrado = false;
    string nodoBuscado = "";
    cout << " Ingrese el dato del Nodo a Buscar para Modificar: ";
    cin >> nodoBuscado;
    if(primero!=NULL){

        while(actual!=NULL && encontrado!=true){

            if(actual->elemento == nodoBuscado){
                cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado";
                cout << "\n Ingrese el nuevo dato para este Nodo: ";
                cin >> actual->elemento;
                cout << " Nodo Modificado\n\n";
                encontrado = true;
            }

            actual = actual->sig;
        }

        if(!encontrado){
            cout << "\n Nodo no Encontrado\n\n";
        }

    }else{
        cout << "\n La listas se encuentra Vacia\n\n";
    }
}
}
















