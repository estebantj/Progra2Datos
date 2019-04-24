TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    abbPaises.cpp \
    listastrings.cpp
    Paises.txt \

HEADERS += \
    abbPaises.h \
    listastrings.h

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
