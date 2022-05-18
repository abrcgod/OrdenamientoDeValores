#include "arbol.hpp"
#include <iostream>

using namespace std;

/* IMPORTANTE: En todos los casos pasamos los parametros por referencia (<PARAMETRO>&)
para asegurarnos que los punteros sean actualizados correctamente y no tener
nodos huerfanos perdidos en memoria */

template <class T>
void insertar(T& _valor, Nodo<T>*& _raiz) {
    // Caso base: Si se recibe un puntero vacio crea un nodo vacio en esa direccion de memoria
    if (_raiz == nullptr) {
        try {
            _raiz = new(Nodo<T>);
        }
        catch(...) {
            // Manejando el error de no tener suficiente memoria para guardar el nodo
            cout << "No hay memoria suficiente para agregar nuevo valor" << endl;
            return;
        }
        _raiz->valor = _valor.valor; 
        return;
    }

    // Casos recursivos: Se llama a la misma funcion insertar cambiando
    // el parametro de la raiz por la rama correspondiente segun el caso (ver arbol.hpp)
    if (_valor < _raiz->valor) {
        insertar(_valor, _raiz->ramaIzquierda);
        return;
    }
    else if (_valor > _raiz->valor ) {
        insertar(_valor, _raiz->ramaDerecha);
        return;
    }
    else { // CASO BASE 2: Cuando el valor ingresado ya se encuentra en el arbol se registra una repeticon mas
        _raiz->vecesRepetido += 1;
        return;
    }
}

template <class T>
void imprimir(Nodo<T>*& _raiz) {
    if (_raiz == nullptr) {return;} // Caso base

    /* Recorre el arbol BST e imprime su contenido con el metodo in-order. 
    Es decir primero lo menor a la raiz
    despues la raiz y al final lo mayor a la raiz */
    imprimir(_raiz->ramaIzquierda);
    cout << _raiz->valor;
    imprimir(_raiz->ramaDerecha);
    
    return;
}

template <class T>
void liberar(Nodo<T>*& _raiz) {
    if (_raiz == nullptr) {return;} // Caso base

    /* Para descargar correctamente de la memoria primero hay que descargar las ramas
    y al final la raiz del arbol */

    // Recursividad: para descargar las ramas
    liberar(_raiz->ramaIzquierda);
    liberar(_raiz->ramaDerecha);

    // descargar raiz
    delete(_raiz);

    return;
}