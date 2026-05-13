#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include "CitaMedica.h"
#include "Paciente.h"
using namespace std;

// funciones

void cargarBaseDeDatos(vector<Paciente>& lista, const string& nombreArc) {
    ifstream archivo(nombreArc, ios::in);
    if (not archivo.is_open()) {
        cout << "Error: archivo inexistente" << endl;
    }

    string nombre, apellido, motivo;
    long long telefono;
    int numCitas, dia, mes, anio, estado, edad;
    char slash;

    while (archivo>>nombre>>ws>>apellido>>ws>>edad>>ws>>telefono>>ws>>numCitas) {

        string nombreCompleto=nombre+ " " +apellido;

        Paciente nPaciente(nombreCompleto, edad, telefono);

        if (numCitas > 0) {
            archivo>>dia>>slash>>mes>>slash>>anio;
            archivo>>estado;
            archivo>>ws;
            getline(archivo, motivo);
            year_month_day fecha = year{anio} / month{(unsigned)mes} / day{(unsigned)dia};
            CitaMedica nuevaCita(fecha, motivo);
            if (estado!=1) {
                nuevaCita.setEstado(estado);
            }
            nPaciente.agregarCita(nuevaCita);
        }
        lista.push_back(nPaciente);
    }
    cout<<"Datos cargados"<<endl;
}
// void cargarBaseDeDatos(vector<Paciente>& lista, const string& nombreArc) {
//     ifstream archivo(nombreArc, ios::in);
//     if (not archivo.is_open()) {
//         cout << "Error: archivo inexistente" << endl;
//         return;
//     }
//
//     string nombre, apellido, motivo;
//     long long telefono;
//     int numCitas, dia, mes, anio, estado, edad;
//     char slash;
//
//     while (archivo>>nombre>>apellido>>edad>>telefono>>numCitas) {
//
//         string nombreCompleto=nombre+ " " +apellido;
//         Paciente nPaciente(nombreCompleto, edad, telefono);
//
//
//         if (numCitas>0) {
//             archivo>>dia>>slash>>mes>>slash>>anio;
//             archivo>>estado;
//             archivo>>ws;
//             getline(archivo, motivo);
//             year_month_day fecha = year{anio} / month{(unsigned)mes} / day{(unsigned)dia};
//             CitaMedica nuevaCita(fecha, motivo);
//             if (estado!=1) {
//                 nuevaCita.setEstado(estado);
//             }
//             nPaciente.agregarCita(nuevaCita);
//         }
//
//         lista.push_back(nPaciente);
//     }
// }

void registrarCita(Paciente &paciente) {
    string motivo;
    int dia, mes, anio;
    year_month_day fecha;

    cout << "Ingrese el anio (XXXX): ";
    cin >> anio;
    cout << "Ingrese el mes (1-12): ";
    cin >> mes;
    cout << "Ingrese el dia: ";
    cin >> dia;

    fecha = year{anio} / month{(unsigned)mes} / day{(unsigned)dia};
    if (!fecha.ok()) {
        cout << "Error: fecha invalida" << endl;
        return;
    }

    cout << "Motivo: ";
    getline(cin >> ws, motivo);
    if (motivo.empty()) {
        cout << "Error: motivo obligatorio" << endl;
        return;
    }

    paciente.agregarCita(CitaMedica(fecha, motivo));
}

int buscarPaciente(const vector<Paciente>& consultorio, const string& pacienteBuscado) {
    for (int i = 0; i < (int)consultorio.size(); i++) {
        if (pacienteBuscado == consultorio[i].getID() or pacienteBuscado == consultorio[i].getNombre()) {
            return i;
        }
    }
    return -1; //evitar una discrepancia si i=1
}

int main() {
    vector<Paciente> consultorio1;
    int opcion;

    // datos de prueba
    consultorio1.push_back(Paciente("Adolfo Villanueva", 20, 2761101670));
    consultorio1.push_back(Paciente("Bryan Guzman", 32, 2761101980));
    consultorio1.at(1).agregarCita(CitaMedica(year{2026}/month{5}/day{10},"gripa"));
    cargarBaseDeDatos(consultorio1, "C:\\Users\\bryan\\CLionProjects\\proyectoGestorMedico\\cmake-build-debug\\citasMedicas.txt");

    do {
        cout << "\n*** Registro de Citas medicas ***\n";
        cout << "1. Agregar paciente\n";
        cout << "2. Buscar paciente\n";
        cout << "3. Lista de pacientes\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";

        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int edad;
                long long numeroCelular;
                int opcionIndice;

                cout<<"Nombre: "<<endl;
                getline(cin >> ws, nombre);
                cout<<"Edad: "<<endl;
                cin>>edad;
                cout<<"Numero de telefono: "<<endl;
                cin>>numeroCelular;

                if (nombre.empty()) {
                    cout << "Error: nombre obligatorio" << endl;
                    break;
                }

                consultorio1.push_back(Paciente(nombre, edad, numeroCelular));

                cout<<"Paciente registrado \nID: "<< consultorio1.back().getID() << endl;
                cout<<"1. Registrar cita\n2. Salir"<<endl;
                cin>>opcionIndice;

                if (opcionIndice == 1) {
                    registrarCita(consultorio1.back());
                }

                break;
            }

            case 2: {
                string pacienteBuscado;
                int indicePaciente;
                int opcionIndice;

                cout << "Ingresa el ID o nombre del paciente:"  << endl;
                getline(cin >> ws, pacienteBuscado);

                indicePaciente = buscarPaciente(consultorio1, pacienteBuscado);
                if (indicePaciente == -1) {
                    cout << "No existe el paciente: " << pacienteBuscado << endl;
                    break;
                }

                consultorio1[indicePaciente].mostrar();

                cout << "\n1. Registrar cita" << endl;
                cout << "2. Listar citas" << endl;
                cout << "3. Cambiar estado de cita" << endl;
                cout << "4. Cancelar cita" << endl;
                cout << "5. Actualizar datos" << endl;
                cout << "6. Eliminar paciente" << endl;
                cout << "7. Volver" << endl;
                cin >> opcionIndice;

                switch (opcionIndice) {
                    case 1: {
                        registrarCita(consultorio1.at(indicePaciente));
                        break;
                    }
                    case 2: {
                        consultorio1[indicePaciente].mostrarCitas();
                        break;
                    }
                    case 3: {
                        int numeroCita;
                        int nuevoEstado;

                        consultorio1[indicePaciente].mostrarCitas();
                        cout << "Numero de cita a editar: " << endl;
                        cin >> numeroCita;
                        cout << "Estado (1=En espera, 2=Confirmada, 3=Finalizada): " << endl;
                        cin >> nuevoEstado;

                        consultorio1[indicePaciente].cambiarEstadoCita(numeroCita, nuevoEstado);
                        break;
                    }
                    case 4: {
                        int numeroCita;

                        consultorio1[indicePaciente].mostrarCitas();
                        cout << "Numero de cita a cancelar: " << endl;
                        cin >> numeroCita;

                        consultorio1[indicePaciente].cancelarCita(numeroCita);
                        break;
                    }
                    case 5: {
                        string nombre;
                        int edad;
                        long long numeroCelular;

                        cout<<"Nombre: "<<endl;
                        getline(cin >> ws, nombre);
                        consultorio1[indicePaciente].setNombre(nombre);
                        cout<<"Edad: "<<endl;
                        cin>>edad;
                        consultorio1[indicePaciente].setEdad(edad);
                        cout<<"Numero de telefono: "<<endl;
                        cin>>numeroCelular;
                        consultorio1[indicePaciente].setNumero(numeroCelular);
                        break;
                    }
                    case 6: {
                        int confirmar;
                        cout << "Seguro que quieres eliminar el paciente? \n 1)confirmar" << endl;

                        cin >> confirmar;
                        if (confirmar == 1) {
                        consultorio1.erase(consultorio1.begin() + indicePaciente);
                        cout << "Paciente eliminado" << endl;
                        } else {
                        cout << "Cancelado" << endl;
                        }
                        break;
                    }
                    case 7: {
                        break;
                    }
                    default:
                        cout << "Opcion invalida." << endl;
                }

                break;
            }

            case 3: {
                for (int i = 0; i < (int)consultorio1.size(); i++) {
                    consultorio1[i].mostrar();
                    cout << endl;
                }
                break;
            }

            case 4:
                cout << "Saliendo" << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);
}

