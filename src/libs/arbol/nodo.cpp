#include "arbol.hpp"

// Crea una instancia de Nodo que guarda un valor del tipo deseaodo
// hay que escribir Nodo<"Tipo de dato a guardar">::Nodo("valor a guardar") al iniciar el objeto
template <class T>
Nodo<T>::Nodo(T _valor) {
    this->valor = _valor;
    this->ramaDerecha = nullptr;
    this->ramaIzquierda = nullptr;
    this->vecesRepetido = 1;
}