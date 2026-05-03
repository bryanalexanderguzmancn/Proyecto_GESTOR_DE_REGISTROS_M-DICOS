#include <iostream>
#include <fstream>
#include "CitaMedica.h"
#include "Paciente.h"
using namespace std;

//funciones

void registrarCita(Paciente &p) {
    string motivo;
    int d, m, a;

    cout << "Ingrese el anio (XXXX): ";
    cin >> a;
    cout << "Ingrese el mes (1-12): ";
    cin >> m;
    cout << "Ingrese el dia: ";
    cin >> d;

    // Crear la fecha usando chrono
    year_month_day fecha = year{a} / m / d;

    cout << "Motivo: ";
    getline(cin >> ws, motivo);

    // Agregamos la cita al paciente recibido por parámetro
    p.agregarCita(CitaMedica(fecha, motivo));
}


int main() {
//prueba de metodos con pacientes
    vector<Paciente> consultorio1;

//Pruebas de sintaxis
    consultorio1.push_back(Paciente("Adolfo Villanueva", 20, 2761101670));
    consultorio1.push_back(Paciente("Bryan Guzman", 32, 2761101980));

    consultorio1.at(1).agregarCita(CitaMedica(2026y/May/10d,"Cancer" ));

    int opcion;
    //prueba de interfaz
    do {
cout << "\n*** Registro de Citas medicas ***\n";
cout << "1. Agregar paciente\n";
cout << "2. Buscar Paciente\n";
cout << "3. Lista de pacientes\n";
cout << "4. Salir\n";
cout << "Opcion: ";

cin >> opcion;

switch (opcion) {
    case 1: {

        //variables a usar:
        string nombre;
        int edad, numeroCelular;
        int opcionIndice;

        cout<<"Nombre: "<<endl;
        getline(cin >> ws, nombre);
        cout<<"Edad: "<<endl;
        cin>>edad;
        cout<<"Numero de telefono"<<endl;
        cin>>numeroCelular;
        consultorio1.push_back(Paciente(nombre, edad, numeroCelular));

        cout<<"Paciente registrado"<<endl;
        cout<<"1.Registrar cita \n2.Salir"<<endl;
        cin>>opcionIndice;
        if (opcionIndice==1) {
            registrarCita(consultorio1.back());
            break;
        }
        cout<<"opcion invalida"<<endl;
        break;
    }


    case 2: {
        string pacienteBuscado;
        int opcionIndice;
        int indicePaciente=0;

        cout << "Ingresa el nombre o ID del paciente"  << endl;
        getline(cin >> ws, pacienteBuscado);

        for (int i=0; i<consultorio1.size(); i++) {
            if (pacienteBuscado==consultorio1[i].getNombre() or pacienteBuscado==consultorio1[i].getID()) {
                consultorio1[i].mostrar();
                indicePaciente = i;
            }
            //else cout<<"No existe el paciente: "<<pacienteBuscado<<endl;
        }

        cout<<"1.Registrar cita"<<endl;
        cout<<"2.Cancelar cita"<<endl;
        cout<<"3.Actualizar datos"<<endl;
        cout<<"4.Salir"<<endl;
        cin>>opcionIndice;

        switch (opcionIndice) {
            case 1: {
                registrarCita(consultorio1.at(indicePaciente));

                break;
            }
            case 2: {
                if (consultorio1[indicePaciente].getNumeroCitas()>0) {
                    int indiceCita;

                    cout<<"Cita a cancelar: "<<endl;
                    cin>>indiceCita;

                    consultorio1[indicePaciente].cancelarCita(indiceCita-1);
                }
                else cout<<"Error: el paciente no tiene citas registradas "<<endl;

                break;
            }
            case 3: {

                string nombre;
                int edad, numeroCelular;

                cout<<"Nombre: "<<endl;
                getline(cin >> ws, nombre);
                consultorio1[indicePaciente].setNombre(nombre);
                cout<<"Edad: "<<endl;
                cin>>edad;
                consultorio1[indicePaciente].setEdad(edad);
                cout<<"Numero de telefono"<<endl;
                cin>>numeroCelular;
                consultorio1[indicePaciente].setNumero(numeroCelular);

                break;
            }
            case 4: {
                cout << "Saliendo...\n";
                break;
            }
            default: cout << "Opcion invalida.\n";
        }


        break;
}
    case 3:
//

        for (int i = 0; i < consultorio1.size(); i++) {
            consultorio1[i].mostrar();
            cout << endl;
        }

        break;

    case 4:
        cout << "Saliendo\n";
        break;

    default:
        cout << "Opcion invalida.\n";
}
} while (opcion != 4);
}