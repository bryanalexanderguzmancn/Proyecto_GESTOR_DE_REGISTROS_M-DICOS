cmake_minimum_required(VERSION 4.1)
project(proyectoGestorMedico)

set(CMAKE_CXX_STANDARD 20)

add_executable(proyectoGestorMedico main.cpp
        Paciente.cpp
        Paciente.h
        CitaMedica.cpp
        CitaMedica.h)
