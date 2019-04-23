#include <iostream>
#include "abbPaises.h"

using namespace std;

int main()
{
    abbPaises paises;
    paises.insertarPais(150,"CR");
    paises.insertarPais(150,"CR");
    paises.insertarPais(151,"CR");
    inOrdenPaises(paises.raiz);

    return 0;
}
