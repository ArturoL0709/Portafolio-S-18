

#ifndef PLANTA_H
#define PLANTA_H

#include <string>
#include <sstream> 
using namespace std;

#include "producto.h"

//Herencia de clase producto

class planta: public  producto { 
    private:
    //Atributos
    float costosemanal;

    public:
    //Metodos del objeto
    planta(); // constructor 
    planta (int i, string nom, float precio);
        int getId() const;
        string getNombre()const;
        float pagoSemanal();
        string toString();
        float getpi()const ; // constructor inicializador de nada esto lo invente 

    };
//constructor
planta::planta(){

    id=0;
    nombre= "";

}

//Contrctor recibidor 

planta::planta (int i, string nom, float precio){
     id= i;
     nombre = nom;
     costosemanal= precio; 
}

//Getters

//Getter id 
 int planta::getId() const {
    return id;
 }

 //Getter nombre

 string planta::getNombre () const { 
    return nombre; 
 }

//Return costo semanal 

float planta:: pagoSemanal(){
    return costosemanal;
}

//Valores guardados

string planta::toString (){
    stringstream aux;
    aux << "El ID es " << id << "su nombre es " << nombre << " y su costo es de " << costosemanal  <<"\n";
    return aux.str ();

}
#endif 