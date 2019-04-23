#ifndef ABB_H
#define ABB_H

#include <iostream>

class nodoPais;
class nodoArbol;
typedef nodoPais *pNodoPais;
using namespace std;

class nodoPais{
public:
    nodoPais(int pCodPais, string pNombre);
private:
	int codPais;
	string nombrePais;
    pNodoPais Hizq;
    pNodoPais Hder;
	friend class abb;
};

class abb{
public:
    abb(){raiz = nullptr;}
    void insertarPais();

private:
    pNodoPais raiz;
};

#endif // ABB_H
