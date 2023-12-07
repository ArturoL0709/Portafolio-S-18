//Arturo López García
//Jardin botanico
//Pensamiento Computacional Orientado a Objetos 

//Librerias 

#ifndef TIENDA_H
#define TIENDA_H
#include <iostream>
#include <string>
#include <sstream> 

#include "producto.h"
#include "planta.h"
#include "maquinas.h"

using namespace std;

const int MAX = 100; //Constante de tamaño de arreglos

/*
 * Creacion de clase tienda que maneja a la clase planta
 clase producto y clase maquinas
 *
 */


class tienda { 
private: //Variables de instancia

maquinas maq [MAX];
planta  plant [MAX]; 

int  imaq, plants; 


public://Constructor

tienda ();

//Metodos de la clase
void agregamaquinas (string nombre, int horas, float pago);
void agregaplanta (string especie, float precio);
void creaejemplosmaquinas ();
void creaEjemplosplantas ();
void muestramaquinas ();
void pagoxmaquinas();
void muestraplantas ();
void pagoplantas();
};
//Constructor por default
tienda::tienda (){
    
    imaq = 0; 
    plants = 0 ;

}

/**
 * Utliza el arreglo de tipo maquinas.
 * Llena el arreglo con 3 ejemplos. Los identificadores de maquina
 * van de 1 a 99.
 
 *
 * @param
 * @return
*/

void tienda::creaejemplosmaquinas (){ 
    maq [0] = maquinas (imaq+150, "Desbrozadora ",5, 200 );
    imaq +=1;
    maq [1] = maquinas (imaq+100, "Podadora ", 10, 350);
    imaq += 1;
    maq [2] = maquinas (imaq + 200, "Desbeozadpra de uso rudo ", 15, 400);

}
/**
 * Utliza el arreglo de tipo planta.
 * Llena el arreglo con 3 ejemplos. Los identificadores de planta
 * van de 1 a 99.
 
 *
 * @param
 * @return
*/
void tienda::creaEjemplosplantas(){
    plant [0] = planta (plants, "Gypsophila paniculata ", 153.5);
    plants +=1;
    plant [1] = planta (plants, "Aylostera ", 200 );
    plants +=1;
    plant [2]=planta (plants , "Buganvilia ", 321);

}
/**
 * Utiliza el arreglo maquinas y su indice.
 * Recorra todo el arreglo, imprimiendo cada uno de los objetos que
 * pertenecen al mismo.
 *
 * @param
 * @return
*/

void tienda ::muestramaquinas(){
    for (int i=0; i <=imaq;i++){
        cout <<maq[i].toString ();
    }
}

/**
 * Utiliza el arreglo plantas y su indice.
 * Recorra todo el arreglo, imprimiendo cada uno de los objetos que
 * pertenecen al mismo.
 *
 * @param
 * @return
*/
void tienda::muestraplantas(){ 
    for (int i=0; i<= plants;i++){
        cout <<plant [i].toString ();
    } 
}

/**
 * Utiliza el arreglo maquinas y su ultimo indice.
 * Almacena en una variable auxiliar la suma de los costos de cada objeto
 * mientras los recorre.
 *
 * Imprime el total.
 *
 * @param
 * @return
*/

  void tienda:: pagoxmaquinas(){
   int total=0;
    for(int i=0;i<= imaq; i++){
        total = total + maq[i].pagoSemanal();

    }
    cout<<total<<"\n";
  }

/**
 * Utiliza el arreglo plantas y su ultimo indice.
 * Almacena en una variable auxiliar la suma de los costos de cada objeto
 * mientras los recorre.
 *
 * Imprime el total.
 *
 * @param
 * @return
*/
void tienda::pagoplantas(){
    int total=0;
    for (int i=0;i<=plants;i++){
        total=total + plant [i].pagoSemanal();
    }
    cout <<total<<"\n";
}

/**
 * Utiliza arreglo de plantas y maquinas y su ultimo indice.
 * Recibe el nombre y costos.
 * El metodo genera el nuevo id, crea el objeto planta o maquinas y lo
 * agrega al arreglo
 *
 * @param
 * @return
 */




void tienda::agregamaquinas(string nombre, int horas, float pago){
    imaq +=1;
    maquinas aux(imaq+150, nombre,horas, pago );
    maq[imaq]=aux;
}
void tienda::agregaplanta(string especie, float precio){
    plants +=1;
    planta aux(plants, especie, precio);
    plant [plants]= aux;

}
 
#endif