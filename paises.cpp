#include "paises.h"

nodoPais::nodoPais(int pCodPais, string pNombre) {
    codPais = pCodPais;
    nombrePais = pNombre;
    Hizq = nullptr;
    Hder = nullptr;
    ciudades = nullptr;
};

nodoCiudad::nodoCiudad(int pCodPais, int pCodCiudad, string pNombre) {
    codPais = pCodPais;
    codCiudad = pCodCiudad;
    nombre = pNombre;
    Hizq = nullptr;
    Hder = nullptr;
    conexiones = nullptr;
    altura = 0;
}
nodoConexion::nodoConexion(int pCodPaisSalida, int pCodCiudadSalida, int pCodConexion, int pCodPaisDestino, int pCodCiudadDestino, int pTiempo, int pPrecio)
{
    codPaisSalida = pCodPaisSalida;
    codCiudadSalida = pCodCiudadSalida;
    codConexion = pCodConexion;
    codPaisDestino = pCodPaisDestino;
    codCiudadDestino = pCodCiudadDestino;
    tiempo = pTiempo;
    precio = pPrecio;
    Hizq = nullptr;
    Hder = nullptr;
    padre = nullptr;
    color = 0;
}

bool Paises::existePais(int pCodPais, pNodoPais R) {
    if (R->codPais == pCodPais)
        return true;
    else if (pCodPais < R->codPais) {
        if (R->Hizq)
            return existePais(pCodPais, R->Hizq);
        else
            return false;
    } else if (pCodPais > R->codPais) {
        if (R->Hder)
            return existePais(pCodPais, R->Hder);
        else
            return false;
    } else
        return false;
}

pNodoPais Paises::obtenerNodoPais(pNodoPais R, int pCodPais) {
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


bool Paises::existePais(int pCodPais) {
    if (raiz == nullptr)
        return false;
    else
        return existePais(pCodPais, raiz);
}

void Paises::insertarPais(int pCodPais, string pNombre) {
    if (!existePais(pCodPais)) {
        if (raiz == nullptr) {
            raiz = new nodoPais(pCodPais, pNombre);
        } else {
            insertarPais(pCodPais, pNombre, raiz);
        }
    }

}

pNodoPais Paises::obtenerNodoPais(int pCodPais) {
    if (raiz != nullptr)
        return obtenerNodoPais(raiz, pCodPais);
    else
        return nullptr;
}

bool Paises::existeCiudad(int pCodPais, int pCodCiudad) {
    pNodoPais pais = obtenerNodoPais(pCodPais);
    if (pais != nullptr && pais->ciudades != nullptr)
        return existeCiudad(pCodCiudad, pais->ciudades);
    else
        return false;
}

void Paises::insertarPais(int pCodPais, string pNombre, pNodoPais R) {
    if (pCodPais <= R->codPais) {
        if (R->Hizq == nullptr) {
            R->Hizq = new nodoPais(pCodPais, pNombre);
        } else {
            insertarPais(pCodPais, pNombre, R->Hizq );
        }
    } else {
        if (R->Hder == nullptr) {
            R->Hder = new nodoPais(pCodPais, pNombre);
        } else {
            insertarPais(pCodPais, pNombre, R->Hder);
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

void Paises::inOrdenPaises(pNodoPais R) {
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

pNodoCiudad Paises::insertarCiudad(int pCodPais, int pCodCiudad, string pNombre, pNodoCiudad t) {
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

pNodoCiudad Paises::rotacionSimpleDerechaAVL(pNodoCiudad &t) {
    pNodoCiudad u = t->Hizq;
    t->Hizq = u->Hder;
    u->Hder = t;
    t->altura = max(altura(t->Hizq), altura(t->Hder)) + 1;
    u->altura = max(altura(u->Hizq), t->altura) + 1;
    return u;
}

pNodoCiudad Paises::rotacionSimpleIzquierdaAVL(pNodoCiudad &t) {
    pNodoCiudad u = t->Hder;
    t->Hder = u->Hizq;
    u->Hizq = t;
    t->altura = max(altura(t->Hizq), altura(t->Hder)) + 1;
    u->altura = max(altura(t->Hder), t->altura) + 1;
    return u;
}

pNodoCiudad Paises::rotacionDobleIzquierdaAVL(pNodoCiudad &t) {
    t->Hder = rotacionSimpleDerechaAVL(t->Hder);
    return rotacionSimpleIzquierdaAVL(t);
}

pNodoCiudad Paises::rotacionDobleDerechaAVL(pNodoCiudad &t) {
    t->Hizq = rotacionSimpleIzquierdaAVL(t->Hizq);
    return rotacionSimpleDerechaAVL(t);
}

pNodoCiudad Paises::encontrarMinimo(pNodoCiudad t) {
    if (t == nullptr)
        return nullptr;
    else if (t->Hizq == nullptr)
        return t;
    else
        return encontrarMinimo(t->Hizq);
}

pNodoCiudad Paises::encontrarMaximo(pNodoCiudad t) {
    if (t == nullptr)
        return nullptr;
    else if (t->Hder == nullptr)
        return t;
    else
        return encontrarMaximo(t->Hder);
}

int Paises::altura(pNodoCiudad t) {
    return (t == nullptr ? -1 : t->altura);
}

int Paises::obtenerBalance(pNodoCiudad t) {
    if (t == nullptr)
        return 0;
    else
        return altura(t->Hizq) - altura(t->Hder);
}

bool Paises::existeCiudad(int pCodCiudad, pNodoCiudad t) {
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

void Paises::inordenCiudades(pNodoCiudad t) {
    if (t == nullptr)
        return;
    inordenCiudades(t->Hizq);
    cout << "Codigo de ciudad: " << t->codCiudad << " Nombre: " << t->nombre << "\n";
    inordenCiudades(t->Hder);
}

void Paises::mostrarCiudades(pNodoPais R) {
    if (R == nullptr) {
        return;
    } else {
        mostrarCiudades(R->Hizq);
        cout << "Codigo del pais: " << R->codPais << "\n";
        inordenCiudades(R->ciudades);
        mostrarCiudades(R->Hder);
    }
}

pNodoCiudad Paises::obtenerNodoCiudad(int pCodCiudad, pNodoCiudad t)
{
    if (t->codCiudad == pCodCiudad)
        return t;
    else if (pCodCiudad < t->codCiudad) {
        if (t->Hizq)
            return obtenerNodoCiudad(pCodCiudad, t->Hizq);
        else
            return nullptr;
    } else if (pCodCiudad > t->codPais) {
        if (t->Hder)
            return obtenerNodoCiudad(pCodCiudad, t->Hder);
        else
            return nullptr;
    } else
        return nullptr;
}

void Paises::insertarCiudad(int pCodPais, int pCodCiudad, string pNombre) {
    pNodoPais pais = obtenerNodoPais(pCodPais);
    if (pais != nullptr) {
        if (!existeCiudad(pCodPais, pCodCiudad)) {
            if (pais->ciudades != nullptr)
                pais->ciudades = insertarCiudad(pCodPais, pCodCiudad, pNombre, pais->ciudades);
            else {
                pais->ciudades = new nodoCiudad(pCodPais, pCodPais, pNombre);
            }
        }
    }
}

pNodoCiudad Paises::obtenerNodoCiudad(int pCodPais, int pCodCiudad){
    pNodoPais pais = obtenerNodoPais(pCodPais);
    if (pais != nullptr && pais->ciudades != nullptr)
        return obtenerNodoCiudad(pCodCiudad, pais->ciudades);
    else
        return nullptr;
}

bool Paises::existeConexion(int pCodPaisSalida, int pCodCiudadSalida, int pCodConexion)
{
    pNodoCiudad ciudad = obtenerNodoCiudad(pCodPaisSalida, pCodCiudadSalida);
    if (ciudad != nullptr)
        return existeConexion(pCodConexion,ciudad->conexiones);
    else
        return false;
}

bool Paises::existeConexion(int pCodPaisSalida, int pCodCiudadSalida, int pCodPaisDestino, int pCodCiudadDestino){
    pNodoCiudad ciudad = obtenerNodoCiudad(pCodPaisSalida, pCodCiudadSalida);
    bool encontrado = false;
    if (ciudad != nullptr && ciudad->conexiones != nullptr) {
        existeConexion(pCodPaisDestino, pCodCiudadDestino, encontrado, ciudad->conexiones);
        return encontrado;
    }else
        return false;
}
// ##########################################################################################

int Paises::getColor(pNodoConexion &node) {
    if (node == nullptr)
        return BLACK;
    return node->color;
}

void Paises::setColor(pNodoConexion &node, int color) {
    if (node == nullptr)
        return;
    node->color = color;

}

pNodoConexion Paises::insertarConexion(pNodoConexion &R, pNodoConexion &ptr) {
    if (R == nullptr)
        return ptr;
    if (ptr->codConexion < R->codConexion) {
        R->Hizq = insertarConexion(R->Hizq, ptr);
        R->Hizq->padre = R;
    } else if (ptr->codConexion > R->codConexion) {
        R->Hder = insertarConexion(R->Hder, ptr);
        R->Hder->padre = R;
    }
    return R;
}

void Paises::insertarConexion(int pCodPaisSalida, int pCodCiudadSalida, int pCodConexion, int pCodPaisDestino, int pCodCiudadDestino, int pTiempo, int pPrecio) {
    pNodoCiudad ciudadRaiz = obtenerNodoCiudad(pCodPaisSalida, pCodCiudadSalida);
    if (ciudadRaiz != nullptr && existeCiudad(pCodPaisDestino, pCodCiudadDestino)) {
        if (ciudadRaiz->conexiones != nullptr && !existeConexion(pCodPaisSalida, pCodCiudadSalida, pCodConexion)){
            pNodoConexion node = new nodoConexion(pCodPaisSalida, pCodCiudadSalida, pCodConexion, pCodPaisDestino, pCodCiudadDestino, pTiempo, pPrecio);
            ciudadRaiz->conexiones = insertarConexion(ciudadRaiz->conexiones, node);
            arreglarInsercion(ciudadRaiz->conexiones, node);
        } else{
            ciudadRaiz->conexiones = new nodoConexion(pCodPaisSalida, pCodCiudadSalida, pCodConexion, pCodPaisDestino, pCodCiudadDestino, pTiempo, pPrecio);
            ciudadRaiz->conexiones->color = 1;
        }
    }
}

void Paises::rotacionIzquierdaRN(pNodoConexion &root, pNodoConexion &ptr) {
    pNodoConexion right_child = ptr->Hder;
    ptr->Hder = right_child->Hizq;
    if (ptr->Hder != nullptr)
        ptr->Hder->padre = ptr;
    right_child->padre = ptr->padre;
    if (ptr->padre == nullptr)
        root = right_child;
    else if (ptr == ptr->padre->Hizq)
        ptr->padre->Hizq = right_child;
    else
        ptr->padre->Hder = right_child;
    right_child->Hizq = ptr;
    ptr->padre = right_child;
}

void Paises::rotacionDerechaRN(pNodoConexion &root, pNodoConexion &ptr) {
    pNodoConexion left_child = ptr->Hizq;
    ptr->Hizq = left_child->Hder;
    if (ptr->Hizq != nullptr)
        ptr->Hizq->padre = ptr;
    left_child->padre = ptr->padre;
    if (ptr->padre == nullptr)
        root = left_child;
    else if (ptr == ptr->padre->Hizq)
        ptr->padre->Hizq = left_child;
    else
        ptr->padre->Hder = left_child;
    left_child->Hder = ptr;
    ptr->padre = left_child;
}

void Paises::arreglarInsercion(pNodoConexion &root, pNodoConexion &ptr) {
    pNodoConexion padre = nullptr;
    pNodoConexion grandparent = nullptr;
    while (ptr != root && getColor(ptr) == RED && getColor(ptr->padre) == RED) {
        padre = ptr->padre;
        grandparent = padre->padre;
        if (padre == grandparent->Hizq) {
            pNodoConexion uncle = grandparent->Hder;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(padre, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == padre->Hder) {
                    rotacionIzquierdaRN(root, padre);
                    ptr = padre;
                    padre = ptr->padre;
                }
                rotacionDerechaRN(root, grandparent);
                swap(padre->color, grandparent->color);
                ptr = padre;
            }
        } else {
            pNodoConexion uncle = grandparent->Hizq;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(padre, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == padre->Hizq) {
                    rotacionDerechaRN(root, padre);
                    ptr = padre;
                    padre = ptr->padre;
                }
                rotacionIzquierdaRN(root, grandparent);
                swap(padre->color, grandparent->color);
                ptr = padre;
            }
        }
    }
    setColor(root, BLACK);
}

pNodoConexion Paises::nodoValorMinimo(pNodoConexion &node) {
    pNodoConexion ptr = node;
    while (ptr->Hizq != nullptr)
        ptr = ptr->Hizq;
    return ptr;
}

pNodoConexion Paises::nodoValorMaximo(pNodoConexion &node) {
    pNodoConexion ptr = node;
    while (ptr->Hder != nullptr)
        ptr = ptr->Hder;
    return ptr;
}

bool Paises::existeConexion(int pCodConexion, pNodoConexion node)
{
    if (node->codConexion == pCodConexion)
        return true;
    else if (pCodConexion < node->codConexion) {
        if (node->Hizq)
            return existeConexion(pCodConexion, node->Hizq);
        else
            return false;
    } else if (pCodConexion > node->codConexion) {
        if (node->Hder)
            return existeConexion(pCodConexion, node->Hder);
        else
            return false;
    } else
        return false;
}

void Paises::existeConexion(int pCodPaisDestino, int pCodCiudadDestino, bool &encontrado,pNodoConexion node) {
    if (node == nullptr) {
        return;
    } else if (node->codPaisDestino == pCodPaisDestino && node->codCiudadDestino == pCodCiudadDestino){
        encontrado = true;
        return;
    } else if (!encontrado){
        existeConexion(pCodPaisDestino, pCodCiudadDestino, encontrado, node->Hizq);
        existeConexion(pCodPaisDestino, pCodCiudadDestino, encontrado, node->Hder);
    }
}


