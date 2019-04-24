#ifndef TRENES_H
#define TRENES_H
#include <string>

using namespace std;

class tipoDeTren;
typedef tipoDeTren *pNodoTipoDeTren;

class tipoDeTren{
public:
    tipoDeTren(string pTipoDeTren, string pNombre);

    string codTipoTren;
    string nombre;
    pNodoTipoDeTren Hizq;
    pNodoTipoDeTren Hder;
};

class Trenes{
private:
    void insertarTipoTren(int pCodTipoTren, string pNombre, pNodoTipoDeTren R);
public:
    void insertarTipoTren(int pCodTipoTren, string pNombre);
};

#endif // TRENES_H
