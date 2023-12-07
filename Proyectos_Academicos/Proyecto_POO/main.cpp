#include <iostream>
#include "producto.h"
#include "tienda.h"
#include "planta.h"


using namespace std; 

void menu(){
    cout<< "Menu:\n";
    cout<< "1. Mostrar plantas registradas.\n";
    cout<< "2. Mostrar maquinas registradas.\n";
    cout<< "3. Calcular pago de renta de maquinas.\n";
    cout<< "4. Agrega nuevo tipo de planta\n";
    cout<< "5. Agrega nueva maquina \n";
    cout<< "6. Calcular costos de plantas.\n";

}
int main (){

    tienda Tienda;
    Tienda.creaEjemplosplantas();
    Tienda.creaejemplosmaquinas();
    string tem_nombre;

    int opcion = 0;
    int temp_costo = 0;
    int temp_horas = 0;
    int total = 0;

    while (opcion<5&& opcion>-1){
        menu();
        cin >> opcion;
        switch (opcion){
            case 1:
                Tienda.muestraplantas();
                    break;
            case 2: 
                Tienda.muestramaquinas();
                    break;
            case 3:
                Tienda.pagoxmaquinas();
                    break;
            case 4:
                cout<<"Escriba el nombre de la planta ";
                cin>> tem_nombre;
                cout << "Dime el Precio ";
                cin >> temp_costo;
                Tienda.agregaplanta(tem_nombre,temp_costo);
                    break;
            case 5:
                cout<<"Escriba el nombre de la máquina " ;
                cin>>tem_nombre;
                cout<<"Escriba el precio de renta ";
                cin>>temp_costo;
                cout<<"Escriba el numero de horas trabajadas ";
                cin>>temp_horas;
                Tienda.agregamaquinas(tem_nombre,temp_horas,temp_costo);
                    break;
        
            case 6:
               Tienda.pagoplantas();
                    break;
             
            
        }
    }
    return 0;

}