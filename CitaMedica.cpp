//
// Created by bryan on 11/04/2026.
//

#include "CitaMedica.h"
#include <iostream>
#include <utility>
using namespace std;

CitaMedica::CitaMedica(year_month_day fecha, const string& motivo) {
    this->fecha = fecha;

    if (motivo.empty()) {
        cout << "Error. Campo obligatoriio" << endl;
    } else {this->motivo = motivo;}

    estadoCita=1; //por defecto la cita esta en espera

}

CitaMedica::~CitaMedica() = default;

//getters
year_month_day CitaMedica::getFechaIngreso() {
    return fecha;
}

string CitaMedica::getMotivo() {
    return motivo;
}

int CitaMedica::getEstado() {
    return estadoCita;
}

//setters
void CitaMedica::setMotivo(const string& motivo) {
    if (motivo.empty()) {
        cout << "Error. Campo obligatoriio" << endl;
    }else {this->motivo = motivo;}
}

void CitaMedica::setFecha(const year_month_day &fecha) {
    if (!fecha.ok()) {
        cout << "Fecha invalida" << endl;
    } else {this->fecha = fecha;}
}

void CitaMedica::setEstado(int estado) {
    if (estado != 3) {
        estadoCita=estado;
    }
    cout<<"Error: cita finalizada"<<endl;
}

void CitaMedica::mostrar() {
    cout<<"Fecha: "<<getFechaIngreso()<<endl;
    cout<<"Motivo: "<<getMotivo()<<endl;

    if (getEstado()==1) {
        cout<<"Estado: En espera"<<endl;
    } else if (getEstado()==2) {
        cout<<"Estado: Confirmada"<<endl;
    } else cout<<"Estado: Finalizada"<<endl;
}
