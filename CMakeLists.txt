cmake_minimum_required(VERSION 3.20)

project(proyectoGestorMedico LANGUAGES CXX)

add_executable(proyectoGestorMedico
        main.cpp
        Paciente.cpp
        CitaMedica.cpp
)

# Copia la base de datos de ejemplo al directorio de ejecucion (build dir),
# para que `cargarBaseDeDatos(..., "citasMedicas.txt")` funcione sin depender
# del "working directory" del IDE/terminal.
configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/citasMedicas.txt
        ${CMAKE_CURRENT_BINARY_DIR}/citasMedicas.txt
        COPYONLY
)

# year_month_day (std::chrono) requiere C++20.
target_compile_features(proyectoGestorMedico PRIVATE cxx_std_20)

if (MSVC)
    target_compile_options(proyectoGestorMedico PRIVATE /W4 /permissive-)
else()
    target_compile_options(proyectoGestorMedico PRIVATE -Wall -Wextra -Wpedantic)
endif()
