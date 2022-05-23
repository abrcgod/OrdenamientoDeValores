#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <windows.h>

#include "libs/tipos-numericos/numero.hpp"
#include "libs/palabras/palabra.hpp"
#include "auxiliares.cpp"

using namespace std;

int obtenerOpcion();
int obtener_cantidad_datos();
template <class T> void obtener_datos(T* arr, int size);
template <class T> void bubble_sort(T arr[], int n);
template <class T> void print(T arr[], int size);

int main(void) {
    system("cls");
    mostrarEncabezado();

    // Bucle principal para que el programa no cierre al terminar de ordenar
    while (true) {
        system("cls");
        
        mostrarMenu();

        int opcion = obtenerOpcion();
        
        // Control de flujo principal de programa, desde aqui se controla el ordenamiento solicitado
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
        cout << "Presiona Enter para volver al menu" << endl;
        cin.ignore();
        cin.get();
        continue;
    SALIDA:
        cout << "\n\nGracias por usar el programa :)\n"
             << "Presiona Enter para salir" << endl;
             cin.ignore();
             cin.get();
        break;
    }

    return 0;
}


// recibe la opcion elegida por el usuario
int obtenerOpcion() {
    while (true) {
        cout << "\n\nIngresa la opcion deseada: ";
        string opc;
        cin >> opc;
        // instrucciones de validación para rechazar entraaas no validas
        if (cin.fail() || opc.size() != 1) {goto MENSAJE;}
        int opc_i;
        try {opc_i = stoi(opc);} catch(...) {opc_i = 0;}
        if (opc_i < 1 || opc_i > 4) {
            goto MENSAJE;
        } else {
            return opc_i;
        }  
MENSAJE: // Se despliega al detectar opciones no validas
        cout << "Opcion no valida\n" << "Presiona Enter para continuar . . .";
        cin.ignore();
        cin.get();
        system("cls");
        mostrarMenu();
        continue;
    }
}

// Pregunta la cantidad de datos que desea ingresar el usuario
int obtener_cantidad_datos() {
    string cant_datos;
    cout << "Cuantos datos quiere ingresar? ";
    cin >> cant_datos;
     // Valida el ingreso de una cantidad válida
    int cant_datos_i;
    try {cant_datos_i = stoi(cant_datos);} catch(...) {cant_datos_i = 0;}

    if (cant_datos_i == 0) {
        cout <<"Ingrese una cantidad numerica entera, diferente de 0" << endl;
        cin.clear();
        cant_datos_i = obtener_cantidad_datos();
    }

    return cant_datos_i;
}


// obtiene los datos del ususario
template <class T> void obtener_datos(T* arr, int size) {

    cout << "Ingresa los datos uno por uno, presiona Enter para enviar cada dato" << endl;
    // iteramos para ir ingresando cada dato al array uno por uno
    for (int i = 0; i < size; i++) {
        cout << string(100, '_') << endl;
        // Para validar que se ingresen datos correctos
        while (true) {
            cout << "Dato " << i + 1 << ": ";
            cin >> arr[i];

            if (cin.fail()) {
                cout << "Valor invalido \nReingresa un valor valido: " << endl;
                continue;
            }

            break;
        }
    }

    return;
}

template <class T> void bubble_sort(T arr[], int n) {
   /* Buble Sort funciona comparando un valor con el que le sigue en el array
        de acuerdo con la condicion de ordenamiento intercambia esos valores */
   int i, j;
   bool intercambio;
   // Elegimos ordenar de menor a mayor
   for (i = 0; i < n-1; i++) {
    intercambio = false;
    for (j = 0; j < n-i-1; j++) {
        // Si el elemento actual es mayor al elemento que le sigue los intercambia
        if (arr[j] > arr[j+1])
        {
           swap(arr[j], arr[j+1]);
           intercambio = true;
        }
    }
 
    // Si nungun elemento fue intercambiado termina el ordenamiento
    // ya que es un indicativo de que el arreglo ya está ordenado.
    if (intercambio == false)
        break;

   }
}

// Imprime el resultado 
template <class T> void print(T arr[], int size) {
    system("cls");
    cout << "Tus datos ordenados: " << endl;
    // Itera sobre el arreglo para imprimir uno por uno
    for (int i = 0; i < size; i++) {
        cout << string(100, '-') << endl;
        cout << i + 1 << ".- " << arr[i] << endl;
    }
    cout << string(100, '-') << endl;
}