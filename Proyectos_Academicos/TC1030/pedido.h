
#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Plato.h"
#include "bebida.h"
#include "postre.h"
#include "plato_principal.h"



const int MAX = 1000;

class pedido {
private:
    plato* alimentos[MAX];
    int menu;

public:
    pedido() : menu(0) {};

    void agregabebida(string nom, float pre);
    void agregapostre(string nom, float pre);
    void agregaplatoprin(string nom, float pre, string proteina);
    void creaejemplos();
    float calculartotal();
    void muestramenu();
    void realizarpedido();
    void agregarplato(int opcion);
    int get_Menu() {
        return menu;
    }
};
/*
Este método de la clase pedido crea ejemplos de bebidas, 
postres y platos principales. Inicializa el arreglo alimentos con objetos predefinidos.

*/
void pedido::creaejemplos() {
    alimentos[0] = new bebida("Agua natural", 12.0);
    menu++;
    alimentos[1] = new bebida("Limonada", 50);
    menu++;
    alimentos[2] = new postre("Cheese cake", 75);
    menu++;
    alimentos[3] = new postre("Bisquet", 50);
    menu++;
    alimentos[4] = new plato_principal("Chilaquiles", 200, "Arrachera");
    menu++;
    alimentos[5] = new plato_principal("Wrap", 150, "Jamon de pavo");
    menu++;
}


/*
Este método muestra el menú del restaurante.
Recorre el arreglo alimentos y muestra la descripción de cada plato utilizando el método to_string() de cada objeto.

*/

void pedido::muestramenu() {
    for (int i = 0; i < menu; i++)
        cout << "[" << i+1 << "] " << alimentos[i]->to_string();
}



float pedido::calculartotal() {
    float total = 0;
    for (int i = 0; i < menu; i++)
        total += alimentos[i]->calcular_cuenta();
    return total;
}

void pedido::agregabebida(string nombre, float precio) {
    alimentos[menu] = new bebida(nombre, precio);
    menu++;
}

void pedido::agregapostre(string nombre, float precio) {
    alimentos[menu] = new postre(nombre, precio);
    menu++;
}

void pedido::agregaplatoprin(string nombre, float precio, string proteina) {
    alimentos[menu] = new plato_principal(nombre, precio, proteina);
    menu++;
}

void pedido::agregarplato(int opcion) {
    if (opcion > 0 && opcion <= menu) {
        if (opcion != 0) {
            string nombre = alimentos[opcion - 1]->get_nombre();
            float precio = alimentos[opcion - 1]->get_precio();
            agregaplatoprin(nombre, precio, "Sin proteina");
            cout << "Plato agregado exitosamente." << endl;
        }
    }
    else if (opcion != 0) {
        cout << "Opción inválida. Por favor, seleccione un número válido del menú." << endl;
    }
}

void pedido::realizarpedido() {
    int opcion;
    float total_pedido = 0;
    do {
        cout << "\n-- Menú de Pedido --" << endl;
        muestramenu();
        cout << "[0] Salir" << endl;
        cout << "Ingrese el número del plato que desea ordenar (0 para salir): ";
        cin >> opcion;

        agregarplato(opcion);
        total_pedido = calculartotal();  // Calcular el total del pedido

    } while (opcion != 0);

    cout << "Total del pedido: " << total_pedido << " pesos" << endl;
}

#endif