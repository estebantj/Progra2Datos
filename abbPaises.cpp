#include "abbPaises.h"

nodoPais::nodoPais(int pCodPais, string pNombre) {
    codPais = pCodPais;
    nombrePais = pNombre;
    Hizq = nullptr;
    Hder = nullptr;
    ciudad = nullptr;
};

nodoCiudad::nodoCiudad(int pCodPais, int pCodCiudad, string pNombre) {
    codPais = pCodPais;
    codCiudad = pCodCiudad;
    nombre = pNombre;
    pais = nullptr;
    Hizq = nullptr;
    Hder = nullptr;
    altura = 0;
}

bool nodoPais::existePais(int pCodPais) {
    if (codPais == pCodPais)
        return true;
    else if (pCodPais < codPais) {
        if (Hizq)
            return Hizq->existePais(pCodPais);
        else
            return false;
    } else if (pCodPais > codPais) {
        if (Hder)
            return Hder->existePais(pCodPais);
        else
            return false;
    } else
        return false;
}

pNodoPais abbPaises::obtenerNodoPais(pNodoPais R, int pCodPais) {
    if (R->codPais == pCodPais)
        return R;
    else if (pCodPais < R->codPais) {
        if (R->Hizq)
            return obtenerNodoPais(R->Hizq, pCodPais);
        else
            return nullptr;
    } else if (pCodPais > R->codPais) {
        if (R->Hder)
            return obtenerNodoPais(R->Hder, pCodPais);
        else
            return nullptr;
    } else
        return nullptr;
}


bool abbPaises::existePais(int pCodPais) {
    if (raiz == nullptr)
        return false;
    else
        return raiz->existePais(pCodPais);
}

void abbPaises::insertarPais(int pCodPais, string pNombre) {
    if (!existePais(pCodPais)) {
        if (raiz == nullptr) {
            raiz = new nodoPais(pCodPais, pNombre);
        } else {
            raiz->insertarPais(pCodPais, pNombre);
        }
    }

}

pNodoPais abbPaises::obtenerNodoPais(int pCodPais) {
    if (raiz != nullptr)
        return obtenerNodoPais(raiz, pCodPais);
    else
        return nullptr;
}

bool abbPaises::existeCiudad(int pCodPais, int pCodCiudad) {
    pNodoPais pais = obtenerNodoPais(pCodPais);
    if (pais != nullptr && pais->ciudad != nullptr)
        return existeCiudad(pCodCiudad, pais->ciudad);
    else
        return false;
}

void nodoPais::insertarPais(int pCodPais, string pNombre) {
    if (pCodPais <= codPais) {
        if (Hizq == nullptr) {
            Hizq = new nodoPais(pCodPais, pNombre);
        } else {
            Hizq->insertarPais(pCodPais, pNombre);
        }
    } else {
        if (Hder == nullptr) {
            Hder = new nodoPais(pCodPais, pNombre);
        } else {
            Hder->insertarPais(pCodPais, pNombre);
        }
    }

}

void preOrdenPaises(pNodoPais R) {
    if (R == nullptr) {
        return;
    } else {
        cout << "Codigo de pais: " << R->codPais << " Nombre:" << R->nombrePais << "\n";
        preOrdenPaises(R->Hizq);
        preOrdenPaises(R->Hder);
    }
}

void abbPaises::inOrdenPaises(pNodoPais R) {
    if (R == nullptr) {
        return;
    } else {
        inOrdenPaises(R->Hizq);
        cout << "Codigo de pais: " << R->codPais << " Nombre:" << R->nombrePais << "\n";
        inOrdenPaises(R->Hder);
    }
}

void postOrdenPaises(pNodoPais R) {
    if (R == nullptr) {
        return;
    } else {
        postOrdenPaises(R->Hizq);
        postOrdenPaises(R->Hder);
        cout << "Codigo de pais: " << R->codPais << " Nombre:" << R->nombrePais << "\n";
    }
}

pNodoCiudad abbPaises::insertarCiudad(int pCodPais, int pCodCiudad, string pNombre, pNodoCiudad t) {
    if (t == nullptr) {
        t = new nodoCiudad(pCodPais, pCodCiudad, pNombre);
    } else if (pCodCiudad <= t->codCiudad) {
        t->Hizq = insertarCiudad(pCodPais, pCodCiudad, pNombre, t->Hizq);
        if (altura(t->Hizq) - altura(t->Hder) == 2) {
            if (pCodCiudad < t->Hizq->codCiudad)
                t = rotacionSimpleDerechaAVL(t);
            else
                t = rotacionDobleDerechaAVL(t);
        }
    } else if (pCodCiudad > t->codCiudad) {
        t->Hder = insertarCiudad(pCodPais, pCodCiudad, pNombre, t->Hder);
        if (altura(t->Hder) - altura(t->Hizq) == 2) {
            if (pCodCiudad > t->Hder->codCiudad)
                t = rotacionSimpleIzquierdaAVL(t);
            else
                t = rotacionDobleIzquierdaAVL(t);
        }
    }
    t->altura = max(altura(t->Hizq), altura(t->Hder)) + 1;
    return t;
}

pNodoCiudad abbPaises::rotacionSimpleDerechaAVL(pNodoCiudad &t) {
    pNodoCiudad u = t->Hizq;
    t->Hizq = u->Hder;
    u->Hder = t;
    t->altura = max(altura(t->Hizq), altura(t->Hder)) + 1;
    u->altura = max(altura(u->Hizq), t->altura) + 1;
    return u;
}

pNodoCiudad abbPaises::rotacionSimpleIzquierdaAVL(pNodoCiudad &t) {
    pNodoCiudad u = t->Hder;
    t->Hder = u->Hizq;
    u->Hizq = t;
    t->altura = max(altura(t->Hizq), altura(t->Hder)) + 1;
    u->altura = max(altura(t->Hder), t->altura) + 1;
    return u;
}

pNodoCiudad abbPaises::rotacionDobleIzquierdaAVL(pNodoCiudad &t) {
    t->Hder = rotacionSimpleDerechaAVL(t->Hder);
    return rotacionSimpleIzquierdaAVL(t);
}

pNodoCiudad abbPaises::rotacionDobleDerechaAVL(pNodoCiudad &t) {
    t->Hizq = rotacionSimpleIzquierdaAVL(t->Hizq);
    return rotacionSimpleDerechaAVL(t);
}

pNodoCiudad abbPaises::encontrarMinimo(pNodoCiudad t) {
    if (t == nullptr)
        return nullptr;
    else if (t->Hizq == nullptr)
        return t;
    else
        return encontrarMinimo(t->Hizq);
}

pNodoCiudad abbPaises::encontrarMaximo(pNodoCiudad t) {
    if (t == nullptr)
        return nullptr;
    else if (t->Hder == nullptr)
        return t;
    else
        return encontrarMaximo(t->Hder);
}

int abbPaises::altura(pNodoCiudad t) {
    return (t == nullptr ? -1 : t->altura);
}

int abbPaises::obtenerBalance(pNodoCiudad t) {
    if (t == nullptr)
        return 0;
    else
        return altura(t->Hizq) - altura(t->Hder);
}

bool abbPaises::existeCiudad(int pCodCiudad, pNodoCiudad t) {
    if (t->codCiudad == pCodCiudad)
        return true;
    else if (pCodCiudad < t->codCiudad) {
        if (t->Hizq)
            return existeCiudad(pCodCiudad, t->Hizq);
        else
            return false;
    } else if (pCodCiudad > t->codCiudad) {
        if (t->Hder)
            return existeCiudad(pCodCiudad, t->Hder);
        else
            return false;
    } else
        return false;
}

void abbPaises::inordenCiudades(pNodoCiudad t) {
    if (t == nullptr)
        return;
    inordenCiudades(t->Hizq);
    cout << "Codigo de ciudad: " << t->codCiudad << " Nombre: " << t->nombre << "\n";
    inordenCiudades(t->Hder);
}

void abbPaises::mostrarCiudades(pNodoPais R) {
    if (R == nullptr) {
        return;
    } else {
        mostrarCiudades(R->Hizq);
        cout << "Codigo del pais: " << R->codPais << "\n";
        inordenCiudades(R->ciudad);
        mostrarCiudades(R->Hder);
    }
}

void abbPaises::insertarCiudad(int pCodPais, int pCodCiudad, string pNombre) {
    pNodoPais pais = obtenerNodoPais(pCodPais);
    if (pais != nullptr) {
        if (!existeCiudad(pCodPais, pCodCiudad)) {
            if (pais->ciudad != nullptr)
                pais->ciudad = insertarCiudad(pCodPais, pCodCiudad, pNombre, pais->ciudad);
            else {
                pais->ciudad = new nodoCiudad(pCodPais, pCodPais, pNombre);
                pais->ciudad->pais = pais;
            }
        }
    }
}
// ##########################################################################################
RBTree::RBTree() {

    root = nullptr;

}



int RBTree::getColor(Node *&node) {

    if (node == nullptr)

        return BLACK;



    return node->color;

}



void RBTree::setColor(Node *&node, int color) {

    if (node == nullptr)

        return;



    node->color = color;

}



Node* RBTree::insertBST(Node *&root, Node *&ptr) {

    if (root == nullptr)

        return ptr;



    if (ptr->data < root->data) {

        root->left = insertBST(root->left, ptr);

        root->left->parent = root;

    } else if (ptr->data > root->data) {

        root->right = insertBST(root->right, ptr);

        root->right->parent = root;

    }



    return root;

}



void RBTree::insertValue(int n) {

    Node *node = new Node(n);

    root = insertBST(root, node);

    fixInsertRBTree(node);

}



void RBTree::rotateLeft(Node *&ptr) {

    Node *right_child = ptr->right;

    ptr->right = right_child->left;



    if (ptr->right != nullptr)

        ptr->right->parent = ptr;



    right_child->parent = ptr->parent;



    if (ptr->parent == nullptr)

        root = right_child;

    else if (ptr == ptr->parent->left)

        ptr->parent->left = right_child;

    else

        ptr->parent->right = right_child;



    right_child->left = ptr;

    ptr->parent = right_child;

}



void RBTree::rotateRight(Node *&ptr) {

    Node *left_child = ptr->left;

    ptr->left = left_child->right;



    if (ptr->left != nullptr)

        ptr->left->parent = ptr;



    left_child->parent = ptr->parent;



    if (ptr->parent == nullptr)

        root = left_child;

    else if (ptr == ptr->parent->left)

        ptr->parent->left = left_child;

    else

        ptr->parent->right = left_child;



    left_child->right = ptr;

    ptr->parent = left_child;

}



void RBTree::fixInsertRBTree(Node *&ptr) {

    Node *parent = nullptr;

    Node *grandparent = nullptr;

    while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) {

        parent = ptr->parent;

        grandparent = parent->parent;

        if (parent == grandparent->left) {

            Node *uncle = grandparent->right;

            if (getColor(uncle) == RED) {

                setColor(uncle, BLACK);

                setColor(parent, BLACK);

                setColor(grandparent, RED);

                ptr = grandparent;

            } else {

                if (ptr == parent->right) {

                    rotateLeft(parent);

                    ptr = parent;

                    parent = ptr->parent;

                }

                rotateRight(grandparent);

                swap(parent->color, grandparent->color);

                ptr = parent;

            }

        } else {

            Node *uncle = grandparent->left;

            if (getColor(uncle) == RED) {

                setColor(uncle, BLACK);

                setColor(parent, BLACK);

                setColor(grandparent, RED);

                ptr = grandparent;

            } else {

                if (ptr == parent->left) {

                    rotateRight(parent);

                    ptr = parent;

                    parent = ptr->parent;

                }

                rotateLeft(grandparent);

                swap(parent->color, grandparent->color);

                ptr = parent;

            }

        }

    }

    setColor(root, BLACK);

}





void RBTree::inorderBST(Node *&ptr) {

    if (ptr == nullptr)

        return;



    inorderBST(ptr->left);

    cout << ptr->data << " " << ptr->color << endl;

    inorderBST(ptr->right);

}



void RBTree::inorder() {

    inorderBST(root);

}

Node *RBTree::minValueNode(Node *&node) {



    Node *ptr = node;



    while (ptr->left != nullptr)

        ptr = ptr->left;



    return ptr;

}



Node* RBTree::maxValueNode(Node *&node) {

    Node *ptr = node;



    while (ptr->right != nullptr)

        ptr = ptr->right;



    return ptr;

}



int RBTree::getBlackHeight(Node *node) {

    int blackheight = 0;

    while (node != nullptr) {

        if (getColor(node) == BLACK)

            blackheight++;

        node = node->left;

    }

    return blackheight;

}


nodoConexion::nodoConexion(int pCodPaisSalida, int pCodCiudadSalida, int pCodConexion, int pCodPaisDestino, int pCodCiudadDestino, int pTiempo)
{
    codPaisSalida = pCodPaisSalida;
    codCiudadSalida = pCodCiudadSalida;
    codConexion = pCodConexion;
    codPaisDestino = pCodPaisDestino;
    codCiudadDestino = pCodCiudadDestino;
    tiempo = pTiempo;
    Hizq = nullptr;
    Hder = nullptr;
    ciudad = nullptr;
    color
}
