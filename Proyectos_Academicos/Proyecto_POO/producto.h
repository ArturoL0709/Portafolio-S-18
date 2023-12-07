
//Arturo López García
//Jardin botanico
//Pensamiento Computacional Orientado a Objetos 

//Librerias 

#ifndef PRODUCTO_H
#define PRODUCTO_H


#include <string>
#include <sstream> 
using namespace std;

//Creacion de la clase 
class producto{
    //Clase abtracta
    protected: //atributos
        int id;
        string nombre;

       
    public: //metodos 
        producto ();
        producto (int id, string nombre);

        int getId () ;
        string getNombre() ;
        virtual float pagoSemanal ()=0;
        string toString();
};
//constructor Definido por Default 
producto::producto(){
     id = 0 ;
     nombre = "";

}

producto::producto(int i, string nom){
    id = i ;
    nombre = nom;
}
//Getters
//Getter de id 

int producto::getId()  {
    return id ;

}

//Getter de nombre del empleado
string producto::getNombre()  { 
    return nombre ; 
}

string producto::toString ()  {

    stringstream aux;
    aux << "El ID es " << id << "y su nombre es " << nombre << "\n";
    return aux.str();
}






#endif