#ifndef TRENES_H
#define TRENES_H
#include "paises.h"
#include <string>

using namespace std;

class nodoTipoDeTren;
class nodoTren;
class nodoRuta;
typedef nodoTipoDeTren *pNodoTipoDeTren;
typedef nodoTren *pNodoTren;
typedef nodoRuta *pNodoRuta;

class nodoTipoDeTren{
public:
    nodoTipoDeTren(int pTipoDeTren, string pNombre);

    int codTipoTren;
    string nombre;
    pNodoTipoDeTren Hizq;
    pNodoTipoDeTren Hder;
    pNodoTren trenes;
};

class nodoTren{
public:
    nodoTren(int pCodTipoTren, int pCodTren, string pNombre, int pNumDeAsientos, int pCodPais, int pCodCiudad);

    int codTipoTren;
    int codTren;
    string nombre;
    int numDeAsientos;
    int codPais;
    int codCiudad;
    pNodoTren Hizq;
    pNodoTren Hder;
    pNodoRuta rutas;
    int altura;
};

class nodoRuta {
public:
    nodoRuta(int pCodTipoTren, int pCodTren, int pCodRuta, int pCodPaisSalida, int pCodCiudadSalida, int pCodPaisDestino, int pCodCiudadDestino,
             int pPrecio);
    int codTipoTren;
    int codTren;
    int codRuta;
    int codPaisSalida;
    int codCiudadSalida;
    int codPaisDestino;
    int codCiudadDestino;
    int precio;
    int nivel;
    pNodoRuta Hizq;
    pNodoRuta Hder;
};

class Trenes{
private:

    bool existeTipoTren(int pCodTipoTren, pNodoTipoDeTren R);

    void insertarTipoTren(int pCodTipoTren, string pNombre, pNodoTipoDeTren R);

    pNodoTipoDeTren obtenerNodoTipoTren(int pCodTipoTren, pNodoTipoDeTren R);


    // Arbol avl
    bool existeTren(int pCodTren, pNodoTren t);

    pNodoTren insertarTren(int pCodTipoTren, int pCodTren, string pNombre, int pNumDeAsientos, int pCodPais, int pCodCiudad, pNodoTren t);

    pNodoTren obtenerNodoTren(int pCodTren, pNodoTren t);

    pNodoTren rotacionSimpleDerechaAVL(pNodoTren &t);


    pNodoTren rotacionSimpleIzquierdaAVL(pNodoTren &t);


    pNodoTren rotacionDobleIzquierdaAVL(pNodoTren &t);


    pNodoTren rotacionDobleDerechaAVL(pNodoTren &t);


    pNodoTren encontrarMinimo(pNodoTren t);


    pNodoTren encontrarMaximo(pNodoTren t);

    int altura(pNodoTren t);

    int obtenerBalance(pNodoTren t);

    // Arbol AA
    pNodoRuta insertarRuta(int pCodTipoTren, int pCodTren, int pCodRuta, int pCodPaisSalida, int pCodCiudadSalida, int pCodPaisDestino, int pCodCiudadDestino,
                           int pPrecio, pNodoRuta nodo);

    bool existeRuta(int pCodRuta, pNodoRuta nodo);

    pNodoRuta giro(pNodoRuta nodo);

    pNodoRuta reparto(pNodoRuta nodo);

public:
    pNodoTipoDeTren raiz;

    Trenes();

    bool existeTipoTren(int pCodTipoTren);

    bool existeTren(int pCodTipoTren, int pCodTren);

    pNodoTipoDeTren obtenerNodoTipoTren(int pCodTipoTren);

    pNodoTren obtenerNodoTren(int pCodTipoTren, int pCodTren);

    void insertarTipoTren(int pCodTipoTren, string pNombre);

    void insertarTren(int pCodTipoTren, int pCodTren, string pNombre, int pNumDeAsientos, int pCodPais, int pCodCiudad, Paises paises);

    bool existeRuta(int pCodTipoTren, int pCodTren, int pCodRuta);

    void insertarRuta(int pCodTipoTren, int pCodTren, int pCodRuta, int pCodPaisSalida, int pCodCiudadSalida, int pCodPaisDestino, int pCodCiudadDestino,
                      int pPrecio, Paises paises);
};

#endif // TRENES_H
