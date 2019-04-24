#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "abbPaises.h"
#include "listastrings.h"
#include "Binario.h"

using namespace std;

void cargarArchivos(abbPaises &paises) {
    ifstream archivo;
    archivo.open("Paises.txt");
    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            listaStrings palabras = split(linea, ';');
            string codPais = palabras.retornarPrimero();
            palabras.borrarInicio();
            string nombrePais = palabras.retornarPrimero();
            palabras.borrarInicio();
            paises.insertarPais(stoi(codPais), nombrePais);
        }
    }
    archivo.close();

    archivo.open("Ciudades.txt");
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            listaStrings palabras = split(linea, ';');
            string codPais = palabras.retornarPrimero();
            palabras.borrarInicio();
            string codCiudad = palabras.retornarPrimero();
            palabras.borrarInicio();
            string nombre = palabras.retornarPrimero();
            palabras.borrarInicio();
            paises.insertarCiudad(stoi(codPais), stoi(codCiudad), nombre);
        }
    }
    archivo.close();
}

int main() {
    abbPaises paises;
    cargarArchivos(paises);
    paises.mostrarPaises();
    cout << "\n";
    paises.mostrarCiudades();
    cout << "\n";
    return 0;
}
