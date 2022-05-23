# Instrucciones de compilación. Se necesita instalar cmake, make y un compilador
# se compiló con g++ por lo que la compatibilidad con otros no está garantizada
# En un terminal crear, sobre este directorio, un directorio llamado build 
# luego ejecutar "cmake" para preparar el compilador
# Finalmente para compilar usar "cmake --build build"
# El ejecutable se encuentra en la carpeta build.

cmake_minimum_required(VERSION 3.23.1)
project(OrdenamientoDeValores VERSION 1.0.0)

add_library(
    tipos-numericos
    src/libs/tipos-numericos/numero.hpp
    src/libs/tipos-numericos/numero.cpp
)

add_library (
    palabras 
    src/libs/palabras/palabra.hpp
    src/libs/palabras/palabra.cpp
)

add_executable(OrdenamientoDeValores src/main.cpp)

target_link_libraries(OrdenamientoDeValores PRIVATE tipos-numericos palabras)