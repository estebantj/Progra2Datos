#include "listastrings.h"

#include <string>
#include <iostream>

nodoString::nodoString(std::string pPalabra){
    palabra = pPalabra;
    siguiente = nullptr;
}

listaStrings::~listaStrings(){
    pnodoString aux;
    while(primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}

//###############################################

void listaStrings::mostar() {
    pnodoString aux = primero;
    while(aux){
        std::cout << aux->palabra << " ";
        aux = aux->siguiente;
    }
    std::cout << std::endl;
}

void listaStrings::borrarInicio() {
    if(primero->siguiente == nullptr){
        pnodoString aux = primero;
        primero = nullptr;
        delete aux;
    }
    else{
        pnodoString aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}

void listaStrings::insertarFinal(std::string valor){
    if(listaVacia()){
        primero = new nodoString(valor);
    }
    else{
        pnodoString aux = primero;
        while(aux->siguiente != nullptr){
            aux = aux->siguiente;
        }
        aux->siguiente = new nodoString(valor);
    }
}

std::string listaStrings::retornarPrimero(){
    return primero->palabra;
}

bool listaStrings::existePalabra(std::string pPalabra) {
    if (!listaVacia()){
        pnodoString aux = primero;
        while (aux){
            if (aux->palabra == pPalabra){
                return true;
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

// Este metodo es el que se encarga de separar el string y retornar la lista
listaStrings split(std::string pString, char separador){
    std::string parte;
    listaStrings partes;
    for(char c: pString){
        if(c != separador){
            parte += c;
        }
        else{
            partes.insertarFinal(parte);
            parte.clear();
        }
    }
    partes.insertarFinal(parte);
    return partes;
}
