TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    administradores.cpp \
        main.cpp \
    listastrings.cpp \
    paises.cpp \
    trenes.cpp
    Paises.txt \

HEADERS += \
    administradores.h \
    listastrings.h \
    paises.h \
    trenes.h

DISTFILES += \
    Administradores.txt \
    Ciudades.txt \
    Conexiones.txt \
    Paises.txt \
    Rutas.txt \
    Trenes.txt \
    Usuarios.txt

RESOURCES += \
    resources.qrc
