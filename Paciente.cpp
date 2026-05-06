//
// Created by bryan on 11/04/2026.
//

#include "Paciente.h"
#include "CitaMedica.h" //llama a la clase para la composicion
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
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
Paciente::Paciente(const string& nombre, int edad, long long numeroCelular) {
    this->nombre = nombre;
    this->edad = edad;
    this->numeroCelular = numeroCelular;
    this->ID = generarId();
}

//Getters
string Paciente::getNombre() const {
    return nombre;
}
int Paciente::getEdad() const {
    return edad;
}

string Paciente::getID() const {
    return ID;
}

long long Paciente::getNumero() const {
    return numeroCelular;
}

int Paciente::getNumeroCitas() const {
    return (int)citas.size();
}

//Setters
void Paciente::setNombre(const string& nombre) {
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
    this->numeroCelular = telefono;
}

//Metodos especificos
void Paciente::agregarCita(const CitaMedica& nuevaCita) {
    citas.push_back(nuevaCita);
    cout << "Cita de " << getNombre()<< " agregada" << endl;
}

void Paciente::mostrar() const {
    cout << "\nNombre: " << getNombre() << endl;
    cout << "Edad: " << getEdad() << endl;
    cout << "ID: " << getID() << endl;
    cout << "Telefono: " << getNumero() << endl;

    if (citas.size() > 0) {
        cout << "Citas medicas: "<< getNumeroCitas() << endl;
    } else {
        cout<<"No hay citas medicas registradas"<<endl;
    }
}

void Paciente::mostrarCita(int numeroCita) const {
    int indice;

    if (getNumeroCitas() == 0) {
        cout << "El paciente no tiene citas registradas" << endl;
        return;
    }

    if (numeroCita < 1 or numeroCita > getNumeroCitas()) {
        cout << "Numero de cita invalido" << endl;
        return;
    }

    indice = numeroCita - 1;
    cout << "Paciente: " << nombre << " (" << ID << ")" << endl;
    citas.at(indice).mostrar();
}

void Paciente::mostrarCitas() const {
    int i;

    if (getNumeroCitas() == 0) {
        cout << "No hay citas registradas" << endl;
        return;
    }

    cout << "Lista de citas (" << getNumeroCitas() << "):" << endl;
    for (i = 0; i < (int)citas.size(); i++) {
        cout << "Cita: " << (i + 1) << endl;
        citas[i].mostrar();
    }
}

void Paciente::cancelarCita(int numeroCita) {
    int indice;

    if (getNumeroCitas() == 0) {
        cout << "Error: no hay citas para eliminar" << endl;
        return;
    }

    if (numeroCita < 1 or numeroCita > getNumeroCitas()) {
        cout << "Error: numero de cita invalido" << endl;
        return;
    }

    indice = numeroCita - 1;
    citas.erase(citas.begin() + indice);
    cout << "La cita: " << numeroCita << " ha sido eliminada" << endl;
}

void Paciente::cambiarEstadoCita(int numeroCita, int nuevoEstado) {
    int indice;

    if (getNumeroCitas() == 0) {
        cout << "Error: el paciente no tiene citas registradas" << endl;
        return;
    }

    if (numeroCita < 1 or numeroCita > getNumeroCitas()) {
        cout << "Error: numero de cita invalido" << endl;
        return;
    }

    if (nuevoEstado < 1 or nuevoEstado > 3) {
        cout << "Error: estado invalido (usa 1, 2 o 3)" << endl;
        return;
    }

    indice = numeroCita - 1;
    citas[indice].setEstado(nuevoEstado);
}

