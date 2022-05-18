/* Clase Nodo: guarda cada valor dentro del arbol de busqueda binaria (BST).
Es una clase generica, puede usarse con cualquier tipo de dato */

template <class T> // Sentencia que permite definir un tipo de dato generico
class Nodo {
public:
    T valor;
    Nodo<T>* ramaIzquierda; // Apunta a nodo con valor menor a raiz
    Nodo<T>* ramaDerecha; // Apunta a nodo con valor mayor a raiz
    int vecesRepetido; // Maneja valores repetidos

    Nodo(T _valor); // CONSTRUCTOR
};

// Para insertar un nodo en un arbol
template <class T>
void insertar(T& _valor, Nodo<T>*& _raiz);

// Imprime el arbol entero en orden
template <class T>
void imprimir(Nodo<T>*& _raiz);

// Descarga el arbol de la memoria
template <class T>
void liberar(Nodo<T>*& _raiz);