#ifndef ABB_H
#define ABB_H

#include <iostream>

class nodoPais;
class nodoArbol;
typedef nodoPais *pNodoPais;
using namespace std;

class nodoPais{
public:

private:
	int codPais;
	string nombrePais;
    pNodoPais Hizq;
    pNodoPais Hder;
	friend class abb;
};

class abb{
public:
	abb(){raiz = nullptr};
private:
    pNodoPais raiz;
};

#endif // ABB_H
