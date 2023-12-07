
//Jardín botanico
//Arturo lÓPEZ García
//Declaro "maquinas" que es gerencia de la clase producto
//Librerias

#ifndef MAQUINAS_H
#define MAQUINAS_h

#include <string>
#include <sstream> 
using namespace std;

#include "producto.h"

class maquinas: public producto { 
 
 private:
   int horastrabajadas ; // Atributos
   float pagoporhora ;// Atributos

public:
    maquinas();
    maquinas(int id, string nombre, int horas, float pago);
    float pagoSemanal();
    string toString (); 

};

maquinas::maquinas(){
    id=0;
    nombre="";

    
}

maquinas::maquinas(int i, string nom, int hor, float pag){

    id= i;
    nombre =nom;
    horastrabajadas=hor;
    pagoporhora=pag;
}

float maquinas::pagoSemanal(){
    int total;
    total=horastrabajadas*pagoporhora;
    return total;
}

string maquinas::toString(){


stringstream aux;
aux << "El id es "<<id<<" la maquina tiene el nombre de " <<nombre<<"Su pago de la semana es "<< pagoSemanal() <<"\n";
    return aux.str();
}
#endif