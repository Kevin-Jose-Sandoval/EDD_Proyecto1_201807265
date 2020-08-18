#ifndef NODO_H
#define NODO_H


class Nodo
{
public:
    Nodo();
    void setNorte(Nodo *n);
    void setEste(Nodo *n);
    void setOeste(Nodo *n);
    void setSur(Nodo *n);
    Nodo* getNorte();
    Nodo* getSur();
    Nodo* getEste();
    Nodo* getOeste();
private:
    Nodo *sur;
    Nodo *norte;
    Nodo *este;
    Nodo *oeste;
};

#endif // NODO_H
