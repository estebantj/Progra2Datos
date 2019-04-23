#ifndef ABBPAISES_H
#define ABBPAISES_H

#include <iostream>

class nodoPais;
class nodoArbol;
typedef nodoPais *pNodoPais;
using namespace std;

class nodoPais{
public:
    nodoPais(int pCodPais, string pNombre);
    void insertarPais(int pCodPais, string pNombre);
    bool existePais(int pCodPais);


    int codPais;
	string nombrePais;
    pNodoPais Hizq;
    pNodoPais Hder;

	friend class abbPaises;
};

class abbPaises{
public:
    pNodoPais raiz;
    
    abbPaises(){raiz = nullptr;}
    bool existePais(int pCodPais);
    void insertarPais(int pCodPais, string pNombre);

private:

};

void preOrdenPaises(pNodoPais R);
void inOrdenPaises(pNodoPais R);
void postOrdenPaises(pNodoPais R);

#endif // ABBPAISES_H


