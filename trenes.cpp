#include "trenes.h"


nodoTipoDeTren::nodoTipoDeTren(int pTipoDeTren, string pNombre) {
    codTipoTren = pTipoDeTren;
    nombre = pNombre;
    Hizq = nullptr;
    Hder = nullptr;
    trenes = nullptr;
}

nodoTren::nodoTren(int pCodTipoTren, int pCodTren, string pNombre, int pNumDeAsientos, int pCodPais, int pCodCiudad) {
    codTipoTren = pCodTipoTren;
    codTren = pCodTren;
    nombre = pNombre;
    numDeAsientos = pNumDeAsientos;
    codPais = pCodPais;
    codCiudad = pCodCiudad;
    Hizq = nullptr;
    Hder = nullptr;
    rutas = nullptr;
    altura = 0;
}

bool Trenes::existeTipoTren(int pCodTipoTren, pNodoTipoDeTren R)
{
    if (R->codTipoTren == pCodTipoTren)
        return true;
    else if (pCodTipoTren < R->codTipoTren) {
        if (R->Hizq)
            return existeTipoTren(pCodTipoTren, R->Hizq);
        else
            return false;
    } else if (pCodTipoTren > R->codTipoTren) {
        if (R->Hder)
            return existeTipoTren(pCodTipoTren, R->Hder);
        else
            return false;
    } else
        return false;
}

void Trenes::insertarTipoTren(int pCodTipoTren, string pNombre, pNodoTipoDeTren R)
{
    if (pCodTipoTren <= R->codTipoTren) {
        if (R->Hizq == nullptr) {
            R->Hizq = new nodoTipoDeTren(pCodTipoTren, pNombre);
        } else {
            insertarTipoTren(pCodTipoTren, pNombre, R->Hizq );
        }
    } else {
        if (R->Hder == nullptr) {
            R->Hder = new nodoTipoDeTren(pCodTipoTren, pNombre);
        } else {
            insertarTipoTren(pCodTipoTren, pNombre, R->Hder);
        }
    }

}

pNodoTipoDeTren Trenes::obtenerNodoTipoTren(int pCodTipoTren, pNodoTipoDeTren R) {
    if (R->codTipoTren == pCodTipoTren)
        return R;
    else if (pCodTipoTren < R->codTipoTren) {
        if (R->Hizq)
            return obtenerNodoTipoTren(pCodTipoTren, R->Hizq);
        else
            return nullptr;
    } else if (pCodTipoTren > R->codTipoTren) {
        if (R->Hder)
            return obtenerNodoTipoTren(pCodTipoTren, R->Hder);
        else
            return nullptr;
    } else
        return nullptr;
}

bool Trenes::existeTren(int pCodTren, pNodoTren t) {
    if (t->codTren == pCodTren)
        return true;
    else if (pCodTren < t->codTren) {
        if (t->Hizq)
            return existeTren(pCodTren, t->Hizq);
        else
            return false;
    } else if (pCodTren > t->codTren) {
        if (t->Hder)
            return existeTren(pCodTren, t->Hder);
        else
            return false;
    } else
        return false;
}

pNodoTren Trenes::insertarTren(int pCodTipoTren, int pCodTren, string pNombre, int pNumDeAsientos, int pCodPais, int pCodCiudad, pNodoTren t) {
    if (t == nullptr) {
        t = new nodoTren(pCodTipoTren, pCodTren, pNombre, pNumDeAsientos, pCodPais, pCodCiudad);
    } else if (pCodTren <= t->codTren) {
        t->Hizq = insertarTren(pCodTipoTren, pCodTren, pNombre, pNumDeAsientos, pCodPais, pCodCiudad, t->Hizq);
        if (altura(t->Hizq) - altura(t->Hder) == 2) {
            if (pCodTren < t->Hizq->codTren)
                t = rotacionSimpleDerechaAVL(t);
            else
                t = rotacionDobleDerechaAVL(t);
        }
    } else if (pCodTren > t->codTren) {
        t->Hder = insertarTren(pCodTipoTren, pCodTren, pNombre, pNumDeAsientos, pCodPais, pCodCiudad, t->Hder);
        if (altura(t->Hder) - altura(t->Hizq) == 2) {
            if (pCodTren > t->Hder->codTren)
                t = rotacionSimpleIzquierdaAVL(t);
            else
                t = rotacionDobleIzquierdaAVL(t);
        }
    }
    t->altura = max(altura(t->Hizq), altura(t->Hder)) + 1;
    return t;
}

pNodoTren Trenes::obtenerNodoTren(int pCodTren, pNodoTren t){
    if (t->codTren == pCodTren)
        return t;
    else if (pCodTren < t->codTren) {
        if (t->Hizq)
            return obtenerNodoTren(pCodTren, t->Hizq);
        else
            return nullptr;
    } else if (pCodTren > t->codTren) {
        if (t->Hder)
            return obtenerNodoTren(pCodTren, t->Hder);
        else
            return nullptr;
    } else
        return nullptr;
}

Trenes::Trenes() {
    raiz = nullptr;
}

bool Trenes::existeTipoTren(int pCodTipoTren) {
    if (raiz != nullptr)
        return existeTipoTren(pCodTipoTren, raiz);
    else
        return false;
}

bool Trenes::existeTren(int pCodTipoTren, int pCodTren){
    pNodoTipoDeTren tipoTren = obtenerNodoTipoTren(pCodTipoTren);
    if (tipoTren != nullptr && tipoTren->trenes != nullptr)
        return existeTren(pCodTren, tipoTren->trenes);
    else
        return false;
}

pNodoTipoDeTren Trenes::obtenerNodoTipoTren(int pCodTipoTren)
{
    if (raiz != nullptr)
        return obtenerNodoTipoTren(pCodTipoTren, raiz);
    else
        return nullptr;
}

pNodoTren Trenes::obtenerNodoTren(int pCodTipoTren, int pCodTren){
    pNodoTipoDeTren tipoTren = obtenerNodoTipoTren(pCodTipoTren);
    if (tipoTren != nullptr && tipoTren->trenes != nullptr)
        return obtenerNodoTren(pCodTren, tipoTren->trenes);
    else
        return nullptr;
}

void Trenes::insertarTipoTren(int pCodTipoTren, string pNombre) {
    if (raiz != nullptr && !existeTipoTren(pCodTipoTren))
        insertarTipoTren(pCodTipoTren, pNombre, raiz);
    else
        raiz = new nodoTipoDeTren(pCodTipoTren, pNombre);
}

void Trenes::insertarTren(int pCodTipoTren, int pCodTren, string pNombre, int pNumDeAsientos, int pCodPais, int pCodCiudad, Paises paises) {
    pNodoTipoDeTren tipoTren = obtenerNodoTipoTren(pCodTipoTren);
    if (tipoTren != nullptr){
        if (tipoTren->trenes != nullptr && !existeTren(pCodTipoTren, pCodTren) && paises.existeCiudad(pCodPais, pCodCiudad))
            tipoTren->trenes = insertarTren(pCodTipoTren, pCodTren, pNombre, pNumDeAsientos, pCodPais, pCodCiudad, tipoTren->trenes);
        else if (paises.existeCiudad(pCodPais, pCodCiudad))
            tipoTren->trenes = new nodoTren(pCodTipoTren, pCodTren, pNombre, pNumDeAsientos, pCodPais, pCodCiudad);
    }
}

bool Trenes::existeRuta(int pCodTipoTren, int pCodTren, int pCodRuta){
    pNodoTren tren = obtenerNodoTren(pCodTipoTren, pCodTren);
    if (tren != nullptr && tren->rutas != nullptr)
        return existeRuta(pCodRuta, tren->rutas);
    else
        return false;
}

pNodoTren Trenes::rotacionSimpleDerechaAVL(pNodoTren &t) {
    pNodoTren u = t->Hizq;
    t->Hizq = u->Hder;
    u->Hder = t;
    t->altura = max(altura(t->Hizq), altura(t->Hder)) + 1;
    u->altura = max(altura(u->Hizq), t->altura) + 1;
    return u;
}

pNodoTren Trenes::rotacionSimpleIzquierdaAVL(pNodoTren &t) {
    pNodoTren u = t->Hder;
    t->Hder = u->Hizq;
    u->Hizq = t;
    t->altura = max(altura(t->Hizq), altura(t->Hder)) + 1;
    u->altura = max(altura(t->Hder), t->altura) + 1;
    return u;
}

pNodoTren Trenes::rotacionDobleIzquierdaAVL(pNodoTren &t) {
    t->Hder = rotacionSimpleDerechaAVL(t->Hder);
    return rotacionSimpleIzquierdaAVL(t);
}

pNodoTren Trenes::rotacionDobleDerechaAVL(pNodoTren &t) {
    t->Hizq = rotacionSimpleIzquierdaAVL(t->Hizq);
    return rotacionSimpleDerechaAVL(t);
}

pNodoTren Trenes::encontrarMinimo(pNodoTren t) {
    if (t == nullptr)
        return nullptr;
    else if (t->Hizq == nullptr)
        return t;
    else
        return encontrarMinimo(t->Hizq);
}

pNodoTren Trenes::encontrarMaximo(pNodoTren t) {
    if (t == nullptr)
        return nullptr;
    else if (t->Hder == nullptr)
        return t;
    else
        return encontrarMaximo(t->Hder);
}

int Trenes::altura(pNodoTren t) {
    return (t == nullptr ? -1 : t->altura);
}

int Trenes::obtenerBalance(pNodoTren t) {
    if (t == nullptr)
        return 0;
    else
        return altura(t->Hizq) - altura(t->Hder);
}

void Trenes::insertarRuta(int pCodTipoTren, int pCodTren, int pCodRuta, int pCodPaisSalida, int pCodCiudadSalida, int pCodPaisDestino, int pCodCiudadDestino,
                          int pPrecio, Paises paises) {
    pNodoTren tren = obtenerNodoTren(pCodTipoTren, pCodTren);
    if (tren != nullptr) {
        if (!existeRuta(pCodTipoTren, pCodTren, pCodRuta) && paises.existeConexion(pCodPaisSalida, pCodCiudadSalida, pCodPaisDestino, pCodCiudadDestino)) {
            if(paises.existeCiudad(pCodPaisSalida, pCodCiudadSalida) && paises.existeCiudad(pCodPaisDestino, pCodCiudadDestino)){
                if (tren->rutas != nullptr)
                    tren->rutas = insertarRuta(pCodTipoTren, pCodTren, pCodRuta, pCodPaisSalida, pCodCiudadSalida, pCodPaisDestino, pCodCiudadDestino, pPrecio, tren->rutas);
                else
                    tren->rutas = new nodoRuta(pCodTipoTren, pCodTren, pCodRuta, pCodPaisSalida, pCodCiudadSalida, pCodPaisDestino, pCodCiudadDestino, pPrecio);
            }
        }
    }
}

pNodoRuta Trenes::insertarRuta(int pCodTipoTren, int pCodTren, int pCodRuta, int pCodPaisSalida, int pCodCiudadSalida, int pCodPaisDestino, int pCodCiudadDestino,
                               int pPrecio, pNodoRuta nodo) {
    if (nodo == nullptr) {
        nodo = new nodoRuta(pCodTipoTren, pCodTren, pCodRuta, pCodPaisSalida, pCodCiudadSalida, pCodPaisDestino, pCodCiudadDestino, pPrecio);
    } else if (pCodRuta <= nodo->codRuta) {
        nodo->Hizq = insertarRuta(pCodTipoTren, pCodTren, pCodRuta, pCodPaisSalida, pCodCiudadSalida, pCodPaisDestino, pCodCiudadDestino, pPrecio, nodo->Hizq);
    } else if (pCodRuta > nodo->codRuta) {
        nodo->Hder = insertarRuta(pCodTipoTren, pCodTren, pCodRuta, pCodPaisSalida, pCodCiudadSalida, pCodPaisDestino, pCodCiudadDestino, pPrecio, nodo->Hder);
    }
    // Falta giro y reparto
    nodo = giro(nodo);
    nodo = reparto(nodo);
    return nodo;
}

bool Trenes::existeRuta(int pCodRuta, pNodoRuta nodo) {
    if (nodo->codRuta == pCodRuta)
        return true;
    else if (pCodRuta < nodo->codRuta) {
        if (nodo->Hizq)
            return existeRuta(pCodRuta, nodo->Hizq);
        else
            return false;
    } else if (pCodRuta > nodo->codRuta) {
        if (nodo->Hder)
            return existeRuta(pCodRuta, nodo->Hder);
        else
            return false;
    } else
        return false;
}

pNodoRuta Trenes::giro(pNodoRuta nodo) {
    if (nodo == nullptr)
        return nullptr;
    else if (nodo->Hizq == nullptr)
        return nodo;
    else if (nodo->Hizq->nivel == nodo->nivel) {
        pNodoRuta izquierdo = nodo->Hizq;
        nodo->Hizq = izquierdo->Hder;
        izquierdo->Hder = nodo;
        return izquierdo;
    } else
        return nodo;
}

pNodoRuta Trenes::reparto(pNodoRuta nodo) {
    if (nodo == nullptr)
        return nullptr;
    else if (nodo->Hder == nullptr || nodo->Hder->Hder == nullptr)
        return nodo;
    else if (nodo->nivel == nodo->Hder->Hder->nivel) {
        pNodoRuta derecho = nodo->Hder;
        nodo->Hder = derecho->Hizq;
        derecho->Hizq = nodo;
        derecho->nivel = derecho->nivel + 1;
        return derecho;
    } else
        return nodo;
}

nodoRuta::nodoRuta(int pCodTipoTren, int pCodTren, int pCodRuta, int pCodPaisSalida, int pCodCiudadSalida, int pCodPaisDestino, int pCodCiudadDestino,
                   int pPrecio) {
    codTipoTren = pCodTipoTren;
    codTren = pCodTren;
    codRuta = pCodRuta;
    codPaisSalida = pCodPaisSalida;
    codCiudadSalida = pCodCiudadSalida;
    codPaisDestino = pCodPaisDestino;
    codCiudadDestino = pCodCiudadDestino;
    precio = pPrecio;
    nivel = 0;
    Hizq = nullptr;
    Hder = nullptr;
}
