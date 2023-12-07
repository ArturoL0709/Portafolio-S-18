// =================================================================
//
// File: Act_2_3_Actividad_Integral_estructura_de_datos_lineales 
// Author: Arturo Lopez Garcia - A01276405
// Date: 02/12/2023
//
// =================================================================

#include <iostream>
#include <list>

using namespace std;

// =================================================================
// Funcion para determinar la posicion segura del sobreviviente
// dada una cantidad de personas y el conteo para eliminar
//
// @param totalPersonas Cantidad total de personas
// @param conteoEliminacion Numero de personas a contar para eliminar
// @return Posicion segura del sobreviviente
// @Complejidad (n^2)
// =================================================================
int encontrarPosicionSegura(int totalPersonas, int conteoEliminacion) {
    list<int> personas;
    list<int>::iterator it;
    int aux, posicionSegura;

    for (int i = 1; i <= totalPersonas; i++){
        personas.push_back(i);
    }

    while (personas.size() > 1) {

        // Recorrer la lista y eliminar la cantidad de personas especificada
        for (int i = 1; i < conteoEliminacion; i++) {
            personas.push_back(personas.front());
            personas.pop_front();
        }
        personas.pop_front();

        // Encontrar la persona que se reubicará
        for (int i = 1; i < conteoEliminacion; i++) {
            personas.push_back(personas.front());
            personas.pop_front();
        }
        
        // Guardar la persona que se reubicará en una variable auxiliar
        aux = personas.front();
        personas.pop_front();
        
        // Reorganizar la lista para continuar con la eliminación posterior
        for (int i = 1; i < conteoEliminacion; i++) {
            personas.push_front(personas.back());
            personas.pop_back();
        }
        
        // Insertar la persona en la posición del eliminado anteriormente
        personas.push_back(aux);
    }

    // Calcular la posición segura
    posicionSegura = (totalPersonas - personas.front()) + 2;
    
    // Casos especiales
    if(personas.front() == 1){
        return 1;
    } else {
        return posicionSegura;
    }
}

int main(){
    int totalPersonas, conteoEliminacion;
    cin >> totalPersonas >> conteoEliminacion;
    cout << encontrarPosicionSegura(totalPersonas, conteoEliminacion);
    return 0;
}
