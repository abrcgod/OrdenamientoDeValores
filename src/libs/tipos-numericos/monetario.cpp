#include "monetario.hpp"

#include <cctype>
#include <iostream>     
#include <string>

void monetario::operator =(std::string in) {
    if (es_monetario(in)) {
        this->valor = transformar_a_numero(in);
    }
}

bool monetario::operator <(monetario& n2) {
    return this->valor < n2.valor;
}

bool monetario::operator ==(monetario& n2) {
    return this->valor == n2.valor;
}

bool monetario::operator >(monetario& n2) {
    return this->valor > n2.valor;
}

std::string transformar_a_numero(std::string& valor) {
    std::string numero;
    for (char digit : valor) {
        if (isdigit(digit) || digit == '-' || digit == '.') {
            numero += digit;
        }
    }

    return numero;
}

bool es_monetario(std::string valor) {
    int dot_count = 0;
    for (int i = 0; i < valor.size(); i++) {
        if (!isdigit(valor[i])) {
            if (valor[i] == '-') {
                if (i == 0) {continue;} else {return false;}
            }
            if (valor[i] == ',') {
                if (i != 0 && (valor[i + 4] == ',' || valor [i + 4] == '.'))  {
                    continue;
                } else {
                    return false;
                }
            }
            if (valor[i] == '.') {
                dot_count += 1;
                if (dot_count != 1) {return false;}
                std::string parte_decimal = valor.substr(i + 1);
                if (parte_decimal.size() != 2) {return false;} else {continue;}
            }

            return false;
        }
    }
    return true;
}

std::ostream& operator <<(std::ostream& COUT, monetario& salida) {
    COUT << salida.valor;

    return COUT;
}

std::istream& operator >>(std::istream& CIN, monetario& entrada) {
    std::string tmp;
    CIN >> tmp;

    if (es_monetario(tmp)) {
        entrada.valor = transformar_a_numero(tmp);
    }

    return CIN;
}
