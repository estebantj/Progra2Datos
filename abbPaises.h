#ifndef ABBPAISES_H
#define ABBPAISES_H

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

    void insertarPais(int pCodPais, string pNombre);

    bool existePais(int pCodPais);


    int codPais;
    string nombrePais;
    pNodoPais Hizq;
    pNodoPais Hder;
    pNodoCiudad ciudad;

    friend class abbPaises;
};

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
    pNodoPais pais;
    int altura;
};

class nodoConexion {
public:
    nodoConexion(int pCodPaisSalida, int pCodCiudadSalida, int pCodConexion, int pCodPaisDestino, int pCodCiudadDestino, int pTiempo);
    int codPaisSalida;
    int codCiudadSalida;
    int codConexion;
    int codPaisDestino;
    int codCiudadDestino;
    int tiempo;
    int color;
    pNodoCiudad ciudad;
    pNodoConexion Hizq;
    pNodoConexion Hder;
};

class abbPaises {
private:
    pNodoPais obtenerNodoPais(pNodoPais R, int pCodPais);

    pNodoCiudad insertarCiudad(int pCodPais, int pCodCiudad, string pNombre, pNodoCiudad t);


    pNodoCiudad rotacionSimpleDerechaAVL(pNodoCiudad &t);


    pNodoCiudad rotacionSimpleIzquierdaAVL(pNodoCiudad &t);


    pNodoCiudad rotacionDobleIzquierdaAVL(pNodoCiudad &t);


    pNodoCiudad rotacionDobleDerechaAVL(pNodoCiudad &t);


    pNodoCiudad encontrarMinimo(pNodoCiudad t);


    pNodoCiudad encontrarMaximo(pNodoCiudad t);

    int altura(pNodoCiudad t);

    int obtenerBalance(pNodoCiudad t);

    bool existeCiudad(int pCodCiudad, pNodoCiudad t);

    void inOrdenPaises(pNodoPais R);

    void inordenCiudades(pNodoCiudad t);

    void mostrarCiudades(pNodoPais R);

public:
    pNodoPais raiz;

    abbPaises() { raiz = nullptr; }

    bool existePais(int pCodPais);

    void insertarPais(int pCodPais, string pNombre);

    pNodoPais obtenerNodoPais(int pCodPais);

    bool existeCiudad(int pCodPais, int pCodCiudad);

    void insertarCiudad(int pCodPais, int pCodCiudad, string pNombre);

    void mostrarPaises() { inOrdenPaises(raiz); }

    void mostrarCiudades() { mostrarCiudades(raiz); }
};

void preOrdenPaises(pNodoPais R);

void postOrdenPaises(pNodoPais R);

enum Color {RED, BLACK, DOUBLE_BLACK};

struct Node

{

    int data;

    int color;

    Node *left, *right, *parent;



    explicit Node(int);

};



class RBTree

{

    private:

        Node *root;

    protected:

        void rotateLeft(Node *&);

        void rotateRight(Node *&);

        void fixInsertRBTree(Node *&);

        void fixDeleteRBTree(Node *&);

        void inorderBST(Node *&);

        void preorderBST(Node *&);

        int getColor(Node *&);

        void setColor(Node *&, int);

        Node *minValueNode(Node *&);

        Node *maxValueNode(Node *&);

        Node* insertBST(Node *&, Node *&);

        Node* deleteBST(Node *&, int);

        int getBlackHeight(Node *);

    public:

        RBTree();

        void insertValue(int);

        void deleteValue(int);

        void merge(RBTree);

        void inorder();

        void preorder();

};


#endif // ABBPAISES_H


