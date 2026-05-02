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
    year_month_day fecha;
    string motivo;

    //extra
    int estadoCita;
    /* la declaro como int con los siguientes significados:
     * 1=En espera
     * 2=Confirmada
     * 3=Finalizada
     */

public:
    CitaMedica(year_month_day fecha, const string& motivo);
    ~CitaMedica();

    //getters
    year_month_day getFechaIngreso();
    string getMotivo();
    int getEstado();

    //setters
    void setFecha(const year_month_day& fecha);
    void setMotivo(const string& motivo);
    void setEstado (int estado);

    //funcion especial
    void mostrar();


};


#endif //PROYECTOGESTORMEDICO_CITAMEDICA_H