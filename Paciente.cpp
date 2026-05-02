//
// Created by bryan on 11/04/2026.
//

#include "Paciente.h"
#include "CitaMedica.h" //llama a la clase para la composicion
#include <iostream>
#include <random>
#include <unordered_set>
using namespace std;

namespace {
    string generarId() {
        static mt19937_64 rng(random_device{}());
        uniform_int_distribution<unsigned long long> dist;

        stringstream numero; //transforma el numero de id
        // Convierte el número a hexadecimal y rellena con ceros a la izquierda
        numero << hex << setw(10) << setfill('0') << dist(rng);

        return numero.str();
    }
}



//Inicializa los valores de la clase
Paciente::Paciente(string nombre, int edad, long long numeroCelular) {
    this->nombre = nombre;
    this->edad = edad;
    this->numeroCelular=numeroCelular;
    numeroCitas=0;
    citas.empty();
    ID = generarId();
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

void Paciente::getCita(int numeroCita) {
    if (numeroCitas > 0) {
        numeroCita--;
        if (numeroCita < 0 or numeroCita>numeroCitas) { /*no admite numeros negativos
                                                            o que sean mayores al numero de citas ligadas al paciente*/
            cout<<"\nNumero de cita invalido"<<endl;
        }
        else {
            cout<<"Paciente: "<<nombre<<" ("<<ID<<")"<<endl;
            citas.at(numeroCita).mostrar();
        }
    }
    else {
        cout<<"\nEl paciente no tiene citas registradas"<<endl;
    }
}

//Setters
void Paciente::setNombre(string nombre) {
    if (nombre.empty()) { //evita que el nuevo nombre este vacio
        cout<<"Error. Ingresa un nombre valido"<<endl;
    } else this->nombre = nombre;
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

void Paciente::setNumero(long long telefono) {
    numeroCelular=telefono;
}

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

void Paciente::cancelarCita(int indice) {
    citas.erase(citas.begin()+indice);
    cout<<"La cita "<<indice<<"ha sido eliminada"<<endl;
    numeroCitas--;
}

