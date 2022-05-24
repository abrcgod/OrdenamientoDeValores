#pragma once

#include <iostream>
/*Clase enfocada en manejar datos de tipo numero real, incluyendo enteros y decimales*/
class numero {
    public:
        std::string valor; // El valor se guarda en un string pero el formato es especifioc
        numero(std::string valor = "\0") : valor(valor) {} // Constructor
        // operadores para trabajar con la clase
        void operator =(std::string in);
        bool operator <(numero& n2);
        bool operator ==(numero& n2);
        bool operator ==(std::string& compare);
        bool operator >(numero& n2);
};
bool isNumber(std::string valor); // Controla el fromato requerido
std::ostream& operator <<(std::ostream& COUT, numero& salida);
std::istream& operator >>(std::istream& CIN, numero& entrada);
