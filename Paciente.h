//
// Created by bryan on 11/04/2026.
//

#ifndef PROYECTOGESTORMEDICO_PACIENTE_H
#define PROYECTOGESTORMEDICO_PACIENTE_H
#include <string>
#include "CitaMedica.h"
using namespace std;


class Paciente {
private:
    string nombre;
    int edad;
    string ID;

    //datos personales extras
    int numeroCelular;


    vector<CitaMedica> citas;
    int numeroCitas;

public:
    Paciente(string nombre, int edad, long long numeroCelular);

    //getters
    string getNombre();
    int getEdad();
    string getID();
    void getCita(int numeroCita);

    //setters
    void setNombre(string nombre);
    void setEdad(int edad);
    void setNumero(long long telefono);

    //Metodos especificos
    void agregarCita(CitaMedica nuevaCita);
    void mostrar();

    //metodos experimentales
    void cancelarCita(int indice);
};


#endif //PROYECTOGESTORMEDICO_PACIENTE_H