TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ListaDoble/listadoble.cpp \
        ListaDoble/nodo.cpp \
        MatrizDispersa/cabecera.cpp \
        MatrizDispersa/matriz.cpp \
        MatrizDispersa/nodo.cpp \
        MatrizDispersa/objeto.cpp \
        main.cpp

HEADERS += \
    ListaDoble/listadoble.h \
    ListaDoble/nodo.h \
    MatrizDispersa/cabecera.h \
    MatrizDispersa/matriz.h \
    MatrizDispersa/nodo.h \
    MatrizDispersa/objeto.h
