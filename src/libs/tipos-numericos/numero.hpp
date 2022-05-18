#pragma once

#include <iostream>

class numero {
    public:
        std::string valor;
        numero(std::string valor = "\0") : valor(valor) {}
        void operator =(std::string in);
        bool operator <(numero& n2);
        bool operator ==(numero& n2);
        bool operator ==(std::string& compare);
        bool operator >(numero& n2);
};

bool isNumber(std::string valor);
std::ostream& operator <<(std::ostream& COUT, numero& salida);
std::istream& operator >>(std::istream& CIN, numero& entrada);
