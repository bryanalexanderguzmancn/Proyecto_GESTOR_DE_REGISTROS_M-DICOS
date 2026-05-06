//
// Created by bryan on 11/04/2026.
//

#include "CitaMedica.h"
#include <iostream>
using namespace std;

CitaMedica::CitaMedica(const year_month_day& fecha, const string& motivo) {
    // si la fecha es invalida, dejo una por defecto para no guardar basura
    if (!fecha.ok()) {
        cout << "Error. Fecha invalida" << endl;
        this->fecha = year{2026} / month{1} / day{1};
    } else {
        this->fecha = fecha;
    }

    if (motivo.empty()) {
        cout << "Error. Campo obligatorio" << endl;
        this->motivo = "Sin motivo";
    } else {
        this->motivo = motivo;
    }

    estadoCita = 1; //por defecto la cita esta en espera
}


//getters
year_month_day CitaMedica::getFechaIngreso() const {
    return fecha;
}

string CitaMedica::getMotivo() const {
    return motivo;
}

int CitaMedica::getEstado() const {
    return estadoCita;
}

//setters
void CitaMedica::setMotivo(const string& motivo) {
    if (motivo.empty()) {
        cout << "Error. Campo obligatorio" << endl;
    } else {this->motivo = motivo;}
}

void CitaMedica::setFecha(const year_month_day &fecha) {
    if (!fecha.ok()) {
        cout << "Fecha invalida" << endl;
    } else {this->fecha = fecha;}
}

void CitaMedica::setEstado(int estado) {
    // si ya esta finalizada, no la dejo cambiar
    if (estadoCita == 3) {
        cout << "Error: la cita ya esta finalizada" << endl;
        return;
    }

    if (estado < 1 or estado > 3) {
        cout << "Error: estado invalido" << endl;
        return;
    }

    estadoCita = estado;
}

void CitaMedica::mostrar() const {
    cout<<"Fecha: "<<getFechaIngreso()<<endl;
    cout<<"Motivo: "<<getMotivo()<<endl;

    if (getEstado()==1) {
        cout<<"Estado: En espera"<<endl;
    } else if (getEstado()==2) {
        cout<<"Estado: Confirmada"<<endl;
    } else cout<<"Estado: Finalizada"<<endl;
}
