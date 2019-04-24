#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "paises.h"
#include "listastrings.h"
#include "Binario.h"

using namespace std;

void cargarArchivos(Paises &paises) {
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

    archivo.open("Conexiones.txt");
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            listaStrings palabras = split(linea, ';');
            string codPaisSalida = palabras.retornarPrimero();
            palabras.borrarInicio();
            string codCiudadSalida = palabras.retornarPrimero();
            palabras.borrarInicio();
            string codConexion = palabras.retornarPrimero();
            palabras.borrarInicio();
            string codPaisDestino = palabras.retornarPrimero();
            palabras.borrarInicio();
            string codCiudadDestino = palabras.retornarPrimero();
            palabras.borrarInicio();
            string tiempo = palabras.retornarPrimero();
            palabras.borrarInicio();
            string precio = palabras.retornarPrimero();
            palabras.borrarInicio();
            paises.insertarConexion(stoi(codPaisSalida), stoi(codCiudadSalida), stoi(codConexion), stoi(codPaisDestino), stoi(codCiudadDestino),
                                    stoi(tiempo), stoi(precio));
        }
    }
    archivo.close();
}

int main() {
    Paises paises;
    cargarArchivos(paises);
    paises.mostrarPaises();
    cout << "\n";
    paises.mostrarCiudades();
    cout << "\n";
    return 0;
}
