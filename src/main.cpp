#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <windows.h>

//#include "auxiliares.hpp"
using namespace std;

void mostrarEncabezado();
void mostrarMenu();
int obtenerOpcion();
void lanzarOpcion(int opcion);
void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}

int main(void) {
    system("cls");
    mostrarEncabezado();

    system("cls");
    mostrarMenu();

    int opcion = obtenerOpcion();

    switch (opcion) {
        case 1:
            //ordenarNumeros();
            std::cout << "Uno\n";
            break;
        case 2:
            //ordenarCaracteres();
            std::cout << "Dos\n";
            break;
        case 3:
            //ordenarPalabras();
            std::cout << "Tres\n";
            break;
        case 4:
            //ordenarMonetario();
            std::cout << "Cuatro\n";
            break;
        case 5:
            std::cout <<"Salida\n";
            break;
    }
}

void mostrarEncabezado() {
    std::string line(100, '-');
    std::string instituto = "INSTITUTO POLITECNICO NACIONAL";
    std::string escuela = "Unidad Politécnica Interdisciplinaria de Ingenieria y Ciencias Sociales y Administrativas";
    std::string asignatura = "Logica de programacion";
    std::string proyecto = "Ordenamiento de Valores";
    
    std::cout << line << std::endl
              << string(35, ' ') << instituto << string(35, ' ') << std::endl
              << string(5, ' ') << escuela << string(5, ' ') << std::endl
              << line << std::endl
              << asignatura 
              << setw(100 - asignatura.size()) << setfill(' ') << proyecto << std::endl
              << setw(100) << line << std::endl;
    std::cout << "\n\n" << "Presiona Enter para continuar........";
    cin.get();
    return;
}

void mostrarMenu() {
    string line(98, char(205));
    char separadorV = char(205);
    char separadorH = char(186);
    char separadorHC = char(206);
    std::cout << char(201) << line << char(187) << endl 
              << char(186) << string((98-35)/2, ' ') 
			   << "Formatos de ordenamiento disponible" << string((98-35)/2, ' ') << " " << char(186) << endl 
              << char(204) << string(3, separadorV) << separadorH << string(12, separadorV) << separadorH 
			   << string(99 - 18, char(205)) << char(185) << endl
              << char(204) << setw(3) << " 1 " << separadorH << setw(12) << " Numeros    " << separadorH << endl
              << char(204) << string(3, separadorV) << separadorHC << string(12, separadorV) << separadorHC << endl
              << char(204) << setw(3) << " 2 " << separadorH << setw(12) << " Caracteres " << separadorH << endl
              << char(204) << string(3, separadorV) << separadorHC << string(12, separadorV) << separadorHC << endl
              << char(204) << setw(3) << " 3 " << separadorH << setw(12) << " Palabras   " << separadorH << endl
              << char(204) << string(3, separadorV) << separadorHC << string(12, separadorV) << separadorHC << endl
              << char(204) << setw(3) << " 4 " << separadorH << setw(12) << " Monetario  " << separadorH << endl
              << char(204) << string(3, separadorV) << separadorHC << string(12, separadorV) << separadorHC << endl
              << char(204) << setw(3) << " 5 " << separadorH << setw(12) << " Salir      " << separadorH << endl
              << char(200) << string(3, char(205)) << char(202) << string(12, char(205)) << char(202)
			   << string(99 - 18, char(205)) << char(188) << endl;
    return;
}

int obtenerOpcion() {
    while (true) {
        cout << "\n\nIngresa la opcion deseada: ";
        string opc;
        cin >> opc;
        if (cin.fail() || opc.size() != 1) {goto MENSAJE;}
        int opc_i;
        try {opc_i = stoi(opc);} catch(...) {opc_i = 0;}
        if (opc_i < 1 || opc_i > 5) {
            goto MENSAJE;
        } else {
        return opc_i;
        }  
MENSAJE:
        cout << "Opcion no valida\n" << "Presiona Enter para continuar . . .";
        cin.ignore();
        cin.get();
        system("cls");
        mostrarMenu();
        continue;
    }
}