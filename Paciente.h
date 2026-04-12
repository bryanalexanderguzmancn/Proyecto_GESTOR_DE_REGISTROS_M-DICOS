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
    vector<CitaMedica> citas;
    int numeroCitas;

public:
    Paciente(string nombre_, int edad_);

    //getters
    string getNombre();
    int getEdad();
    string getID();
    void getCita(int numeroCita);

    //setters
    void setNombre(const string& nombre_);
    void setEdad(int edad_);

    //Metodos especificos
    void agregarCita(CitaMedica cita);
    void mostrar();
};


#endif //PROYECTOGESTORMEDICO_PACIENTE_H