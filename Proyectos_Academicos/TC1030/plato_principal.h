/*
Esta es una clase derivada más de plato llamada plato_principal.
También hereda las características de la clase base y añade un miembro llamado proteina y otro llamado cuenta_plato.
Implementa los métodos virtuales calcular_cuenta() y to_string().
*/

#ifndef PLATO_PRINCIPAL_H
#define PLATO_PRINCIPAL_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Plato.h"




class plato_principal : public plato {
private:
    string proteina;
    float cuenta_plato;

public:
    plato_principal() : plato("", 0, "Plato principal"), cuenta_plato(0) {};

    plato_principal(string nom, float pre, string prote) : plato(nom, pre, "Plato principal"), proteina(prote), cuenta_plato(pre) {};

    float calcular_cuenta() {
        return cuenta_plato;
    }

    string to_string() {
        stringstream aux;
        aux << "El plato principal es " << nombre << " va acompañado de " << proteina << " y su precio es de " << precio << " pesos" << "\n";
        return aux.str();
    }
};

#endif