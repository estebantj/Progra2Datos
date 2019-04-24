#ifndef PAISES_H
#define PAISES_H

#include <iostream>
#include <string>

class nodoPais;

class nodoCiudad;

class nodoArbol;

class nodoConexion;

typedef nodoPais *pNodoPais;
typedef nodoCiudad *pNodoCiudad;
typedef nodoConexion *pNodoConexion;
using namespace std;

class nodoPais {
public:
    nodoPais(int pCodPais, string pNombre);

    int codPais;
    string nombrePais;
    pNodoPais Hizq;
    pNodoPais Hder;
    pNodoCiudad ciudades;
};

enum Color {RED, BLACK};

class nodoCiudad {
public:
    nodoCiudad(int pCodpais, int pCodCiudad, string pNombre);

    nodoCiudad(int pCodCiudad);

    void insertarCiudad(int pCodCiudad, string pNombre);

    int codPais;
    int codCiudad;
    string nombre;
    pNodoCiudad Hizq;
    pNodoCiudad Hder;
    pNodoConexion conexiones;
    int altura;
};

class nodoConexion {
public:
    nodoConexion(int pCodPaisSalida, int pCodCiudadSalida, int pCodConexion, int pCodPaisDestino, int pCodCiudadDestino, int pTiempo, int precio);
    int codPaisSalida;
    int codCiudadSalida;
    int codConexion;
    int codPaisDestino;
    int codCiudadDestino;
    int tiempo;
    int precio;
    int color;
    pNodoConexion Hizq;
    pNodoConexion Hder;
    pNodoConexion padre;
};

class Paises {
private:
    // Metodos del arbol abb de paises
    void insertarPais(int pCodPais, string pNombre, pNodoPais R);

    bool existePais(int pCodPais, pNodoPais R);

    pNodoPais obtenerNodoPais(pNodoPais R, int pCodPais);

    pNodoCiudad insertarCiudad(int pCodPais, int pCodCiudad, string pNombre, pNodoCiudad t);

    void inOrdenPaises(pNodoPais R);

    // Metodos del arbol avl de ciudades
    pNodoCiudad rotacionSimpleDerechaAVL(pNodoCiudad &t);


    pNodoCiudad rotacionSimpleIzquierdaAVL(pNodoCiudad &t);


    pNodoCiudad rotacionDobleIzquierdaAVL(pNodoCiudad &t);


    pNodoCiudad rotacionDobleDerechaAVL(pNodoCiudad &t);


    pNodoCiudad encontrarMinimo(pNodoCiudad t);


    pNodoCiudad encontrarMaximo(pNodoCiudad t);

    int altura(pNodoCiudad t);

    int obtenerBalance(pNodoCiudad t);

    bool existeCiudad(int pCodCiudad, pNodoCiudad t);

    void inordenCiudades(pNodoCiudad t);

    void mostrarCiudades(pNodoPais R);

    pNodoCiudad obtenerNodoCiudad(int pCodCiudad, pNodoCiudad t);

    // Metodos del arbol de conexiones
    void rotacionIzquierdaRN(pNodoConexion &root, pNodoConexion &nodo);

    void rotacionDerechaRN(pNodoConexion &root, pNodoConexion &nodo);

    void arreglarInsercion(pNodoConexion &root, pNodoConexion &nodo);

    int getColor(pNodoConexion &nodo);

    void setColor(pNodoConexion &nodo, int);

    pNodoConexion nodoValorMinimo(pNodoConexion &nodo);

    pNodoConexion nodoValorMaximo(pNodoConexion &nodo);

    bool existeConexion(int pCodConexion, pNodoConexion node);

    pNodoConexion insertarConexion(pNodoConexion &R, pNodoConexion &nodo);

public:
    pNodoPais raiz;

    Paises() { raiz = nullptr; }
    // Metodos del arbol de paises
    bool existePais(int pCodPais);

    void insertarPais(int pCodPais, string pNombre);

    pNodoPais obtenerNodoPais(int pCodPais);

    // Metodos del arbol de ciudades
    bool existeCiudad(int pCodPais, int pCodCiudad);

    void insertarCiudad(int pCodPais, int pCodCiudad, string pNombre);

    void mostrarPaises() { inOrdenPaises(raiz); }

    void mostrarCiudades() { mostrarCiudades(raiz); }

    pNodoCiudad obtenerNodoCiudad(int pCodPais, int pCodCiudad);

    // Metodos del arbol de conexiones

    bool existeConexion(int pCodPaisSalida, int pCodCiudadSalida, int pCodConexion);

    void insertarConexion(int pCodPaisSalida, int pCodCiudadSalida, int pCodConexion, int pCodPaisDestino, int pCodCiudadDestino, int pTiempo, int pPrecio);

};

void preOrdenPaises(pNodoPais R);

void postOrdenPaises(pNodoPais R);

#endif // PAISES_H


