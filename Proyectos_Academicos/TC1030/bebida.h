#ifndef BEBIDA_H
#define BEBIDA_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Plato.h"



class bebida : public plato {
private:
    float cuenta_bebida;
    float tamanio;

public:
    bebida() : plato("", 0, "Bebida") {};
    bebida(string nom, float pre) : plato(nom, pre, "Bebida"), cuenta_bebida(pre) {};

    float calcular_cuenta() {
        return cuenta_bebida;
    }

    string to_string() {
        stringstream aux;
        aux << "La bebida es " << nombre << " y su precio es de " << precio << " pesos" << "\n";
        return aux.str();
    }
};
#endif