#include "palabra.hpp"
#include <algorithm>
#include <cctype>

// Asignacion  
void palabra::operator =(std::string in) {
    if (es_palabra(in)) {
        this->valor = in;
    }
}

// Pasa una copia del string a mayusculas para hacer comparaciones
// case-insensitive
std::string hacer_mayusculas(std::string palabra) {
    std::for_each(palabra.begin(), palabra.end(), [](auto& letra){
        letra = std::toupper(letra);});
    
    return palabra;
}

// Operador clave para ordenar las palabras
bool palabra::operator <(palabra& p2) { 
    std::string palabra_1 = hacer_mayusculas(this->valor);
    std::string palabra_2 = hacer_mayusculas(p2.valor);
    
    // Es muy simple, el metodo compare() ya nos dice que cadena va antes que otra
    // Solo hay que convertirlas a mayuculas ya que en el codigo ASCII(usado por el metodo)
    // las mayusculas y minusculas tienen valores diferentes
    if (palabra_1.compare(palabra_2) < 0) {return true;} else {return false;}
}

bool palabra::operator ==(palabra& p2) {
    std::string palabra_1 = hacer_mayusculas(this->valor);
    std::string palabra_2 = hacer_mayusculas(p2.valor);

    if (palabra_1.compare(palabra_2) == 0) {return true;} else {return false;}
}

// Operador de igualdad
bool palabra::operator ==(std::string& compare) {
    // El metodo compare() facilita el trabajo
    if (this->valor.compare(compare) == 0) {
        return true;
    }
    else {
        return false;
    }
}

// El operador mayor que aprovecha la lógica invertida de los operadores anteriores
bool palabra::operator >(palabra& p2) { 
    if (!(*this < p2) && !(*this == p2)) {return true;} else {return false;}
}

// Metodo para validar el formato
bool es_palabra(std::string valor) {
    // Es muy sencillo, solo hay que validar que cada caracter sea alfabetico
    for (char letra : valor) {
        // cuando encuentra un caracter no alfabetico rechaza el dato
        if (!isalpha(letra)) {return false;} 
    }

    return true;
}

// Operador para imprimir los datos
std::ostream& operator <<(std::ostream& COUT, palabra& salida) {
    COUT << salida.valor;

    return COUT;
}

// Operador para leer datos
std::istream& operator >>(std::istream& CIN, palabra& entrada) {
    std::string in;
    CIN >> in;

// Se hace una validacion del dato antes de ingresarlo a la clase
    while (true) {
        if (es_palabra(in)) {
            entrada.valor = in;
            break;
        } else {
            std::cout << "Valor invalido" << std::endl;
            std::cout << "Reingresa un valor valido: ";

             CIN >> in;
             continue;
        }
    }

    return CIN;
}