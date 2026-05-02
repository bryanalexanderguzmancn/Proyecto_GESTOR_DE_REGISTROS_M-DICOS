cmake_minimum_required(VERSION 3.20)

project(proyectoGestorMedico LANGUAGES CXX)

add_executable(proyectoGestorMedico
        main.cpp
        Paciente.cpp
        CitaMedica.cpp
)

# year_month_day (std::chrono) requiere C++20.
target_compile_features(proyectoGestorMedico PRIVATE cxx_std_20)

if (MSVC)
    target_compile_options(proyectoGestorMedico PRIVATE /W4 /permissive-)
else()
    target_compile_options(proyectoGestorMedico PRIVATE -Wall -Wextra -Wpedantic)
endif()

