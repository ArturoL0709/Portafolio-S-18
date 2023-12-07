


#ifndef PLATO_H
#define PLATO_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class plato {
protected:
    string nombre;
    string tipo;
    float precio;

public:
    plato() : nombre(""), precio(0), tipo("") {};
    plato(string nom, float pre, string tip) : nombre(nom), precio(pre), tipo(tip) {};

    string get_nombre() {
        return nombre;
    }
    float get_precio() {
        return precio;
    }
    string get_tipo() {
        return tipo;
    }

    virtual float calcular_cuenta() = 0;
    virtual string to_string() = 0;
};


#endif