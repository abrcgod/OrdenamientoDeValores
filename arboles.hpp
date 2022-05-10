#include <iostream>

#include "tipos.hpp"

struct nodoNumero {
        numero dato;
        nodoNumero* ramaIzquierda;
        nodoNumero* ramaDerecha;
        nodoNumero* raiz;
};

void insertar(numero valor,nodoNumero* arbol);
void imprimir_inorder(nodoNumero* arbol);
void liberar(nodoNumero* arbol);

struct nodoMonetario {
        monetario dato;
        nodoMonetario* ramaIzquierda;
        nodoMonetario* ramaDerecha;
        nodoMonetario* raiz;
};

void insertar(monetario nodo ,nodoMonetario* arbol);
void imprimir_inorder(nodoMonetario* arbol);
void liberar(nodoMonetario* arbol);

struct nodoPalabra {
        palabra dato;
        nodoPalabra* ramaIzquierda;
        nodoPalabra* ramaDerecha;
        nodoPalabra* raiz;
};

void insertar(palabra nodo,nodoPalabra* arbol);
void imprimir_inorder(nodoPalabra* arbol);
void liberar(nodoPalabra* arbol);

struct nodoChar {
        char dato;
        nodoChar* ramaIzquierda;
        nodoChar* ramaDerecha;
        nodoChar* raiz;
};

void insertar(char valor,nodoChar* arbol);
void imprimir_inorder(nodoChar* arbol);
void liberar(nodoChar* arbol);

