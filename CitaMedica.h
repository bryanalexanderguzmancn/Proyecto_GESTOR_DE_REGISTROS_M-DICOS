//
// Created by bryan on 11/04/2026.
//

#ifndef PROYECTOGESTORMEDICO_CITAMEDICA_H
#define PROYECTOGESTORMEDICO_CITAMEDICA_H
#include <iostream>
#include <chrono>
#include <string>

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
    CitaMedica(const year_month_day& fecha, const string& motivo);


    //getters
    year_month_day getFechaIngreso() const;
    string getMotivo() const;
    int getEstado() const;

    //setters
    void setFecha(const year_month_day& fecha);
    void setMotivo(const string& motivo);
    void setEstado (int estado);

    //funcion especial
    void mostrar() const;


};


#endif //PROYECTOGESTORMEDICO_CITAMEDICA_H
