/* Clase Nodo: guarda cada valor dentro del arbol de busqueda binaria (BST).
Es una clase generica, puede usarse con cualquier tipo de dato */

template <class T> // Sentencia que permite definir un tipo de dato generico
class Nodo {
public:
    T valor;
    Nodo<T>* ramaIzquierda;
    Nodo<T>* ramaDerecha;
    int vecesRepetido;

    Nodo(T _valor); // CONSTRUCTOR
};

template <class T>
void insertar(T _valor, Nodo<T>*& _raiz);

template <class T>
void imprimir(Nodo<T>*& _raiz);

template <class T>
void liberar(Nodo<T>*& _raiz);