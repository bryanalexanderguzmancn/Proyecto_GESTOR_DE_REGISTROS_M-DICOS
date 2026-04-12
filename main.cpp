#include <iostream>
#include "CitaMedica.h"
#include "Paciente.h"
using namespace std;

int main() {
//prueba de metodos con pacientes
    vector<Paciente> consultorio1;

    consultorio1.push_back(Paciente("Adolfo Villanueva", 20));
    consultorio1.push_back(Paciente("Bryan Guzman", 32));
    consultorio1.push_back(Paciente("Alex Guzman", 32));
    consultorio1.push_back(Paciente("Alex Guzman", 22));

    for (int i = 0; i < consultorio1.size(); i++) {
        consultorio1[i].mostrar();
        cout << endl;
    }

    cout<<"Soy: "<<consultorio1.at(1).getNombre()<<endl;

    consultorio1.at(1).agregarCita(CitaMedica(2026y/May/10d,"Cancer" ));

    for (int i = 0; i < consultorio1.size(); i++) {
        consultorio1[i].mostrar();
        cout << endl;
    }

}