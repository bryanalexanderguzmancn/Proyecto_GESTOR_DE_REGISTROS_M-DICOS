//
// Created by bryan on 11/04/2026.
//

#include "CitaMedica.h"
#include <iostream>
#include <utility>
using namespace std;

CitaMedica::CitaMedica(year_month_day fecha, const string& motivo) {
    fechaIngreso = fecha;

    if (motivo.empty()) {
        cout << "Error. Campo obligatoriio" << endl;
    } else {this->motivo = motivo;}

}

CitaMedica::~CitaMedica() = default;

//getters
year_month_day CitaMedica::getFechaIngreso() {
    return fechaIngreso;
}

string CitaMedica::getMotivo() {
    return motivo;
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
    } else {fechaIngreso = fecha;}
}

