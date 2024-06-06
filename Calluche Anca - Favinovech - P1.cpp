#include <iostream>
using namespace std;

int main() {
    int matriz[3][3];

    // Para alimentar la matriz
    cout << "Ingrese los elementos de la matriz 3x3:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> matriz[i][j];
        }
    }

    // Para desplegar la matriz original
    cout << "Matriz original:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Para suplir la diagonal con ceros
    for (int i = 0; i < 3; ++i) {
        matriz[i][i] = 0;
    }

    // Para desplegar la matriz modificada
    cout << "Matriz modificada:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

