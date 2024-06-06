#include <iostream>
#include <string>
using namespace std;

struct Empleado {
    string nombre;
    char tipo;
    float sueldo_basico;
    float deduccion_afp;
    float deduccion_seguro;
    float bonificacion;
    float sueldo_neto;
};

int main() {
    const int MAX_EMPLEADOS = 100;
    Empleado empleados[MAX_EMPLEADOS];
    int total_empleados = 0;
    float total_sueldo_neto_C = 0, total_sueldo_neto_N = 0;
    int count_C = 0, count_N = 0;

    // Para solicitar número de empleados
    cout << "Ingrese el numero de empleados: ";
    cin >> total_empleados;

    // Para solicitar datos de cada empleado
    for (int i = 0; i < total_empleados; ++i) {
        cout << "Empleado " << i+1 << ":" << endl;
        cout << "Nombre: ";
        cin >> empleados[i].nombre;
        cout << "Tipo (C-contratado, N-nombrado): ";
        cin >> empleados[i].tipo;

        // Para convertir tipo a mayúscula para manejo uniforme (sin cctype)
        if (empleados[i].tipo >= 'a' && empleados[i].tipo <= 'z') {
            empleados[i].tipo -= ('a' - 'A');
        }

        cout << "Sueldo basico: ";
        cin >> empleados[i].sueldo_basico;

        // Para calcular deducciones
        empleados[i].deduccion_afp = empleados[i].sueldo_basico * 0.08;
        empleados[i].deduccion_seguro = empleados[i].sueldo_basico * 0.05;

        // Para calcular bonificación y contar empleados por tipo
        if (empleados[i].tipo == 'C') {
            empleados[i].bonificacion = empleados[i].sueldo_basico * 0.08;
            count_C++;
        } else if (empleados[i].tipo == 'N') {
            empleados[i].bonificacion = empleados[i].sueldo_basico * 0.12;
            count_N++;
        }

        // Para calcular sueldo neto
        empleados[i].sueldo_neto = empleados[i].sueldo_basico - empleados[i].deduccion_afp - empleados[i].deduccion_seguro + empleados[i].bonificacion;

        // Para acumular sueldos netos por tipo de empleado
        if (empleados[i].tipo == 'C') {
            total_sueldo_neto_C += empleados[i].sueldo_neto;
        } else if (empleados[i].tipo == 'N') {
            total_sueldo_neto_N += empleados[i].sueldo_neto;
        }
    }

    // Para mostrar los detalles de cada empleado
    cout << "\nDetalles de cada empleado:" << endl;
    for (int i = 0; i < total_empleados; ++i) {
        cout << "Nombre: " << empleados[i].nombre << ", Tipo: " << empleados[i].tipo
             << ", Sueldo basico: " << empleados[i].sueldo_basico << ", Deduccion AFP: " << empleados[i].deduccion_afp
             << ", Deducción Seguro: " << empleados[i].deduccion_seguro << ", Bonificacion: " << empleados[i].bonificacion
             << ", Sueldo neto: " << empleados[i].sueldo_neto << endl;
    }

    // Para mostrar el resumen consolidado
    cout << "\nResumen consolidado:" << endl;
    cout << "Total empleados contratados: " << count_C << ", Total sueldo neto C: " << total_sueldo_neto_C << endl;
    cout << "Total empleados nombrados: " << count_N << ", Total sueldo neto N: " << total_sueldo_neto_N << endl;

    return 0;
}

