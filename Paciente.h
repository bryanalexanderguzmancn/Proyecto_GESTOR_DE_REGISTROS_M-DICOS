//
// Created by bryan on 11/04/2026.
//

#ifndef PROYECTOGESTORMEDICO_PACIENTE_H
#define PROYECTOGESTORMEDICO_PACIENTE_H
#include <string>
#include <vector>
#include "CitaMedica.h"
using namespace std;


class Paciente {
private:
    string nombre;
    int edad;
    string ID;

    //datos personales extras
    long long numeroCelular;


    vector<CitaMedica> citas;

public:
    Paciente(const string& nombre, int edad, long long numeroCelular);

    //getters
    string getNombre() const;
    int getEdad() const;
    string getID() const;
    long long getNumero() const;
    const vector<CitaMedica>& getCitas() const;

    int getNumeroCitas() const;
    void mostrarCita(int numeroCita) const;
    void mostrarCitas() const;
    year_month_day getFechaCitas(int indice) const;

    //setters
    void setNombre(const string& nombre);
    void setEdad(int edad);
    void setNumero(long long telefono);

    //Metodos especificos
    void agregarCita(const CitaMedica& nuevaCita);
    void mostrar() const;

    //metodos experimentales
    void cancelarCita(int numeroCita);
    void cambiarEstadoCita(int numeroCita, int nuevoEstado);
};


#endif //PROYECTOGESTORMEDICO_PACIENTE_H
