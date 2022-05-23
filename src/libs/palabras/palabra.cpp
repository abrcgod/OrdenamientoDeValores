#include "palabra.hpp"
#include <algorithm>
#include <cctype>
  
void palabra::operator =(std::string in) {
    if (es_palabra(in)) {
        this->valor = in;
    }
}

std::string hacer_mayusculas(std::string palabra) {
    std::for_each(palabra.begin(), palabra.end(), [](auto& letra){
        letra = std::toupper(letra);});
    
    return palabra;
}

bool palabra::operator <(palabra& p2) { 
    std::string palabra_1 = hacer_mayusculas(this->valor);
    std::string palabra_2 = hacer_mayusculas(p2.valor);
    
    if (palabra_1.compare(palabra_2) < 0) {return true;} else {return false;}
}

bool palabra::operator ==(palabra& p2) {
    std::string palabra_1 = hacer_mayusculas(this->valor);
    std::string palabra_2 = hacer_mayusculas(p2.valor);

    if (palabra_1.compare(palabra_2) == 0) {return true;} else {return false;}
}

bool palabra::operator ==(std::string& compare) {
    if (this->valor.compare(compare) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool palabra::operator >(palabra& p2) { 
    if (!(*this < p2) && !(*this == p2)) {return true;} else {return false;}
}

bool es_palabra(std::string valor) {
    for (char letra : valor) {
        if (!isalpha(letra)) {return false;} 
    }

    return true;
}

std::ostream& operator <<(std::ostream& COUT, palabra& salida) {
    COUT << salida.valor;

    return COUT;
}

std::istream& operator >>(std::istream& CIN, palabra& entrada) {
    std::string in;
    CIN >> in;


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