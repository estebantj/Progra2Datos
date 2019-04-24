#ifndef LISTASTRINGS_H
#define LISTASTRINGS_H
#include <string>

class nodoString;
class listaStrings;
typedef nodoString *pnodoString;

listaStrings split(std::string pString, char separador);

class nodoString{
public:
    explicit nodoString(std::string pPalabra);

private:
    std::string palabra;
    pnodoString siguiente;

    friend class listaStrings;
};

class listaStrings{
public:
    listaStrings(){primero = nullptr;}
    ~listaStrings();
    bool existePalabra(std::string pPalabra);
    void insertarFinal(std::string valor);
    void borrarInicio();
    bool listaVacia(){ return primero== nullptr;}
    std::string retornarPrimero();
    void mostar();

private:
    pnodoString primero;
};

#endif // LISTASTRINGS_H
