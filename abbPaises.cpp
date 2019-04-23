#include "abbPaises.h"

nodoPais::nodoPais(int pCodPais, string pNombre){
    codPais = pCodPais;
    nombrePais = pNombre;
    Hizq = nullptr;
    Hder = nullptr;
};

bool nodoPais::existePais(int pCodPais)
{
    if (codPais == pCodPais)
        return true;
    else if (pCodPais < codPais){
        if (Hizq)
            return Hizq->existePais(pCodPais);
        else
            return false;
    }
    else if(pCodPais > codPais){
        if (Hder)
            return Hder->existePais(pCodPais);
        else
            return false;
    } else
        return false;
}

bool abbPaises::existePais(int pCodPais)
{
    if (raiz == nullptr)
        return false;
    else
        return raiz->existePais(pCodPais);
}

void abbPaises::insertarPais(int pCodPais, string pNombre){
    if (!existePais(pCodPais)) {
        if (raiz == nullptr){
            raiz = new nodoPais(pCodPais, pNombre);
        } else {
            raiz->insertarPais(pCodPais, pNombre);
        }
    }
    
}

void nodoPais::insertarPais(int pCodPais, string pNombre){
    if(pCodPais<=codPais){
        if(Hizq==nullptr){
            Hizq = new nodoPais(pCodPais, pNombre);
        }else{
            Hizq->insertarPais(pCodPais, pNombre);
        }
    }else{
         if(Hder==nullptr){
             Hder = new nodoPais(pCodPais, pNombre);
         }else{
            Hder->insertarPais(pCodPais, pNombre);
         }
    }

}

void preOrdenPaises(pNodoPais R){

    if(R==nullptr){
        return;
    }else{
        cout<< "Codigo de pais: " << R->codPais << " Nombre:" << R->nombrePais << "\n";
        preOrdenPaises(R->Hizq);
        preOrdenPaises(R->Hder);
    }
}

void inOrdenPaises(pNodoPais R){

    if(R==nullptr){
        return;
    }else{
        inOrdenPaises(R->Hizq);
        cout<< "Codigo de pais: " << R->codPais << " Nombre:" << R->nombrePais << "\n";
        inOrdenPaises(R->Hder);
    }
}

void postOrdenPaises(pNodoPais R){

    if(R==nullptr){
        return;
    }else{
        postOrdenPaises(R->Hizq);
        postOrdenPaises(R->Hder);
        cout<< "Codigo de pais: " << R->codPais << " Nombre:" << R->nombrePais << "\n";
    }
}
