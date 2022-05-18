#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <windows.h>
#include "libs/tipos-numericos/numero.hpp"
#include "libs/palabras/palabra.hpp"

//#include "auxiliares.hpp"
using namespace std;

void mostrarEncabezado();
void mostrarMenu();
int obtenerOpcion();
int obtener_cantidad_datos();
template <class T> void obtener_datos(T* arr, int size);
template <class T> void bubble_sort(T arr[], int n);
template <class T> void print(T arr[], int size);
void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}

int main(void) {
    system("cls");
    mostrarEncabezado();
    
    while (true) {
        system("cls");
        mostrarMenu();

        int opcion = obtenerOpcion();

        if (opcion == 1) {
            int cant_datos = obtener_cantidad_datos();
            numero arr_numeros[cant_datos];
            obtener_datos<numero>(arr_numeros, cant_datos);
            bubble_sort(arr_numeros, cant_datos);
            print(arr_numeros, cant_datos);
            goto CONTINUA;
        } else if (opcion == 2) {
            int cant_datos = obtener_cantidad_datos();
            char arr_char[cant_datos];
            obtener_datos<char>(arr_char, cant_datos);
            bubble_sort(arr_char, cant_datos);
            print(arr_char, cant_datos);
            goto CONTINUA;
        } else if (opcion == 3) {
            int cant_datos = obtener_cantidad_datos();
            palabra arr_palabras[cant_datos];
            obtener_datos<palabra>(arr_palabras, cant_datos);
            bubble_sort(arr_palabras, cant_datos);
            print(arr_palabras, cant_datos);
            goto CONTINUA;
        } else if (opcion == 4) {
            goto SALIDA;
        }
    CONTINUA:
        cout << "Presiona Enter para volver al menú" << endl;
        cin.ignore();
        cin.get();
        continue;
    SALIDA:
        cout << "Gracias por usar el programa :)\n"
             << "Presiona Enter para salir" << endl;
             cin.ignore();
             cin.get();
        break;
    }

    return 0;
}
int obtener_cantidad_datos() {
    int cant_datos;
    while (true) {
        cout << "¿Cuantos datos quiere ingresar? ";
        cin >> cant_datos;
        
        if (cin.fail()) {
            cout << "Ingrese una cantidad numérica entera" << endl;
            continue;
        }

        break;
    }

    return cant_datos;
}

template <class T> void obtener_datos(T* arr, int size) {

    cout << "Ingresa los datos uno por uno, presiona Enter para enviar cada dato" << endl;
    for (int i = 0; i < size; i++) {
        cout << string(100, '_') << endl;
        while (true) {
            cout << "Dato " << i + 1 << ": ";
            cin >> arr[i];

            if (cin.fail()) {
                cout << "Formato invalido, respeta el formato seleccionado" << endl;
                cout << "Presiona Enter para volver a ingresar el dato" << endl;
                cin.ignore();
                cin.get();
                continue;
            }

            break;
        }
    }

    return;
}

template <class T> void bubble_sort(T arr[], int n) {
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(arr[j], arr[j+1]);
           swapped = true;
        }
     }
 
     // IF no two elements were swapped
     // by inner loop, then break
     if (swapped == false)
        break;
   }
}
 
template <class T> void print(T arr[], int size) {
    system("cls");
    cout << "Tus datos ordenados: " << endl;
    for (int i = 0; i < size; i++) {
        cout << string(100, '_') << endl;
        cout << i + 1 << ".- " << arr[i] << endl;
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
              << char(204) << setw(3) << " 4 " << separadorH << setw(12) << " Salida  " << separadorH << endl
              << char(204) << string(3, separadorV) << separadorHC << string(12, separadorV) << separadorHC << endl
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