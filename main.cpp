#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "paises.h"
#include "trenes.h"
#include "listastrings.h"
#include "Binario.h"

using namespace std;

void cargarArchivos(Paises &paises, Trenes &trenes) {
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

    archivo.open("Trenes.txt");
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            listaStrings palabras = split(linea, ';');
            string codTipoTren = palabras.retornarPrimero();
            palabras.borrarInicio();
            string codTren = palabras.retornarPrimero();
            palabras.borrarInicio();
            string nombre = palabras.retornarPrimero();
            palabras.borrarInicio();
            string numDeAsientos = palabras.retornarPrimero();
            palabras.borrarInicio();
            string paisActual = palabras.retornarPrimero();
            palabras.borrarInicio();
            string ciudadActual = palabras.retornarPrimero();
            palabras.borrarInicio();
            trenes.insertarTren(stoi(codTipoTren), stoi(codTren), nombre, stoi(numDeAsientos), stoi(paisActual), stoi(ciudadActual), paises);
        }
    }
    archivo.close();

    archivo.open("Rutas.txt");
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            listaStrings palabras = split(linea, ';');
            string codTipoTren = palabras.retornarPrimero();
            palabras.borrarInicio();
            string codTren = palabras.retornarPrimero();
            palabras.borrarInicio();
            string codRuta = palabras.retornarPrimero();
            palabras.borrarInicio();
            string codPaisSalida = palabras.retornarPrimero();
            palabras.borrarInicio();
            string codCiudadSalida = palabras.retornarPrimero();
            palabras.borrarInicio();
            string codPaisDestino = palabras.retornarPrimero();
            palabras.borrarInicio();
            string codCiudadDestino = palabras.retornarPrimero();
            palabras.borrarInicio();
            string precio = palabras.retornarPrimero();
            palabras.borrarInicio();
            trenes.insertarRuta(stoi(codTipoTren), stoi(codTren), stoi(codRuta), stoi(codPaisSalida), stoi(codCiudadSalida), stoi(codPaisDestino),
                                stoi(codCiudadDestino), stoi(precio), paises);
        }
    }
    archivo.close();
}

int main() {
    Paises paises;
    Trenes trenes;
    trenes.insertarTipoTren(01,"Interrail");
    trenes.insertarTipoTren(02,"Eurail");
    trenes.insertarTipoTren(03,"Panoramico");
    trenes.insertarTipoTren(04,"Nocturno");

    cargarArchivos(paises, trenes);
    paises.mostrarPaises();
    cout << "\n";
    paises.mostrarCiudades();
    cout << "\n";
    trenes.insertarTren(01,95,"JAJ", 96,12,90, paises);
    trenes.insertarTren(01,90,"JAJ", 96,12,90, paises);
    trenes.insertarTren(01,85,"JAJ", 96,12,90, paises);
    bool a = paises.existeConexion(12,90,45,11);
    return 0;
}
