//
// Created by bryan on 11/04/2026.
//

#ifndef PROYECTOGESTORMEDICO_CITAMEDICA_H
#define PROYECTOGESTORMEDICO_CITAMEDICA_H
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


class CitaMedica {
private:
    year_month_day fechaIngreso;
    string motivo;

public:
    CitaMedica(year_month_day fecha, const string& motivo);
    ~CitaMedica();

    //getters
    year_month_day getFechaIngreso();
    string getMotivo();

    //setters
    void setFecha(const year_month_day& fecha);
    void setMotivo(const string& motivo);


};


#endif //PROYECTOGESTORMEDICO_CITAMEDICA_H