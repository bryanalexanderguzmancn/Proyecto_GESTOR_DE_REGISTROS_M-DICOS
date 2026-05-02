#include <iostream>
#include <fstream>
#include "CitaMedica.h"
#include "Paciente.h"
using namespace std;

//funciones


int main() {
//prueba de metodos con pacientes
    vector<Paciente> consultorio1;

    consultorio1.push_back(Paciente("Adolfo Villanueva", 20, 2761101670));
    consultorio1.push_back(Paciente("Bryan Guzman", 32, 2761101980));

    for (int i = 0; i < consultorio1.size(); i++) {
        consultorio1[i].mostrar();
        cout << endl;
    }


    consultorio1.at(1).agregarCita(CitaMedica(2026y/May/10d,"Cancer" ));

    int opcion;
    //prueba de interfaz
    do {
cout << "\n*** Registro de Citas medicas ***\n";
cout << "1. Agregar paciente\n";
cout << "2. Buscar Paciente\n";
cout << "3. Lista de pacientes\n";
cout << "4. Salir\n";
cout << "Opción: ";

cin >> opcion;

switch (opcion) {
    case 1: {

        //variables a usar:
        string nombre;
        int edad, numeroCelular;
        int opcion2;

        cout<<"Nombre: "<<endl;
        getline(cin >> ws, nombre);
        cout<<"Edad: "<<endl;
        cin>>edad;
        cout<<"Numero de telefono"<<endl;
        cin>>numeroCelular;
        consultorio1.push_back(Paciente(nombre, edad, numeroCelular));

        cout<<"Paciente registrado"<<endl;
        cout<<"1.Registrar cita \n 2.Salir"<<endl;
        cin>>opcion2;
        if (opcion2==1) {
            string motivo;
            int d, m, a;

            cout << "Ingrese el ano (ej. 2026): ";
            cin >> a;
            cout << "Ingrese el mes (1-12): ";
            cin >> m;
            cout << "Ingrese el dia: ";
            cin >> d;
            year_month_day fecha = year{a} / m / d;

            cout<<"Motivo: "<<endl;
            getline(cin >> ws, motivo);

            consultorio1.at(consultorio1.size()-1).agregarCita(CitaMedica(fecha, motivo));
            break;
        }
        break;
    }


        case 2: {
// TODO: Llamar a simularBatalla y guardar resultado en ultimoGanador, ultimaSaludA, ultimaSaludB
// Mostrar mensaje de quién ganó y las vidas totales


    cout << "\nResultado de la batalla:\n";
    cout << "Salud total Equipo A: "  << endl;
    cout << "Salud total Equipo B: "  << endl;




break;
}
case 3:
// TODO: Mostrar estadísticas de la última batalla (si no se ha hecho, avisar)

        for (int i = 0; i < consultorio1.size(); i++) {
            consultorio1[i].mostrar();
            cout << endl;
        }
break;
case 4:
cout << "Saliendo...\n";
break;
default:
cout << "Opción inválida.\n";
}
} while (opcion != 4);
}