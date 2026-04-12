//
// Created by bryan on 11/04/2026.
//

#include "Paciente.h"
#include "CitaMedica.h" //llama a la clase para la composicion
#include <iostream>
#include <random>
using namespace std;



//Inicializa los valores de la clase
Paciente::Paciente(string nombre_, int edad_) {
    nombre = nombre_;
    edad = edad_;
    numeroCitas=0;

    srand(time(NULL));
    int v1 = rand();
    string nomb = nombre;
    ID=to_string(v1+edad+nomb[1]+nomb[2]+nomb[3]); //crea ids distintos segun el nombre
}

//Getters
string Paciente::getNombre() {
    return nombre;
}
int Paciente::getEdad() {
    return edad;
}

string Paciente::getID() {
    return ID;
}

void Paciente::getCita(int numeroCita_) {
    if (numeroCitas > 0) {
        numeroCita_--;
        if (numeroCita_ < 0 or numeroCita_>numeroCitas) { /*no admite numeros negativos
                                                            o que sean mayores al numero de citas ligadas al paciente*/
            cout<<"\nNumero de cita invalido"<<endl;
        }
        else {
            cout<<"Paciente: "<<nombre<<" ("<<ID<<")"<<endl;
            citas.at(numeroCita_).mostrar();
        }
    }
    else {
        cout<<"\nEl paciente no tiene citas registradas"<<endl;
    }
}

//Setters
void Paciente::setNombre(const string& nombre_) {
    if (nombre_.empty()) { //evita que el nuevo nombre este vacio
        cout<<"Error. Ingresa un nombre valido"<<endl;
    } else {nombre = nombre_;}
}
void Paciente::setEdad(int edad_) {
    if (edad_ < 0 or edad_ > 120) { //imposibilita registrar edades negativas o inalcanzables
        cout<<"Error. Ingresa una edad valido"<<endl;
    } else {edad = edad_;}
}
// void Paciente::setID() {
//     static int digitos=000;
//     char nomb[50]= nombre;
//     ID=digitos+nomb[0];
// }

//Metodos especificos
void Paciente::agregarCita(CitaMedica nuevaCita) {
    citas.push_back(nuevaCita);
    cout << "Cita de " << getNombre()<< " agregada" << endl;
    numeroCitas++;
}

void Paciente::mostrar(){
    cout << "\nNombre: " << getNombre() << endl;
    cout << "Edad: " << getEdad() << endl;
    cout << "ID: " << getID() << endl;

    if (citas.size() > 0) {
        cout << "Citas medicas: "<< numeroCitas << endl;
    } else {
        cout<<"No hay citas medicas registradas"<<endl;
    }

}

