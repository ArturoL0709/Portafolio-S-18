
// =========================================================
// File: main.cpp
// Author: Arturo Lopez Garcia - A01276405
// Date: 03/11/2023
//Complejidad O(n)
//=========================================================


#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> children; // Una lista de adyacencia para representar el árbol.
// children[v] contiene los hijos del vértice v.

bool isAbeto(int v) {
    if (children[v].empty()) {
        return true; // Si el vértice no tiene hijos, es una hoja, por lo que cumple automáticamente.
    }

    int leafChildren = 0;
    for (int u : children[v]) {
        if (!isAbeto(u)) {
            return false; // Si uno de los hijos no cumple con las condiciones, el árbol no es un abeto.
        }
        if (children[u].empty()) {
            leafChildren++; // Contamos los hijos hojas.
        }
    }

    if (v == 0) {
        // Raíz
        return leafChildren >= 3; // La raíz debe tener al menos 3 hijos hojas.
    } else {
        // Nodos no raíz
        return leafChildren >= 3; // Los nodos no raíz deben tener al menos 3 hijos hojas.
    }
}

int main() {
    int n;
    cin >> n;

    children.resize(n);

    for (int i = 1; i < n; i++) {
        int parent;
        cin >> parent;
        parent--;
        children[parent].push_back(i); // Construye la lista de adyacencia.
    }

    if (isAbeto(0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
