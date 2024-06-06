#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX_TRABAJADORES = 100;
    string codigo[MAX_TRABAJADORES], nombre[MAX_TRABAJADORES];
    float talla[MAX_TRABAJADORES], peso[MAX_TRABAJADORES], sueldo[MAX_TRABAJADORES];
    int total_trabajadores = 0, sueldo_mayor_1000 = 0;

    // Para solicitar número de trabajadores
    cout << "Ingrese el numero de trabajadores: ";
    cin >> total_trabajadores;

    // Para solicitar datos de cada trabajador
    for (int i = 0; i < total_trabajadores; ++i) {
        cout << "Trabajador " << i+1 << ":" << endl;
        cout << "Codigo: ";
        cin >> codigo[i];
        cout << "Nombre: ";
        cin >> nombre[i];
        cout << "Talla: ";
        cin >> talla[i];
        cout << "Peso: ";
        cin >> peso[i];
        cout << "Sueldo: ";
        cin >> sueldo[i];

        // Para contar trabajadores con sueldo mayor a 1000
        if (sueldo[i] > 1000.00) {
            sueldo_mayor_1000++;
        }
    }

    // Para ordenar por código de mayor a menor
    for (int i = 0; i < total_trabajadores - 1; ++i) {
        for (int j = i + 1; j < total_trabajadores; ++j) {
            if (codigo[i] < codigo[j]) {
                swap(codigo[i], codigo[j]);
                swap(nombre[i], nombre[j]);
                swap(talla[i], talla[j]);
                swap(peso[i], peso[j]);
                swap(sueldo[i], sueldo[j]);
            }
        }
    }

    // Para mostrar datos almacenados
    cout << "\nDatos de los trabajadores:" << endl;
    for (int i = 0; i < total_trabajadores; ++i) {
        cout << "Codigo: " << codigo[i] << ", Nombre: " << nombre[i]
             << ", Talla: " << talla[i] << ", Peso: " << peso[i]
             << ", Sueldo: " << sueldo[i] << endl;
    }

    // Para mostrar total de trabajadores y trabajadores con sueldo mayor a 1000
    cout << "\nTotal de trabajadores: " << total_trabajadores << endl;
    cout << "Total de trabajadores con sueldo mayor a S/ 1000.00: " << sueldo_mayor_1000 << endl;

    return 0;
}


