#pragma once

#include <iostream>

/*Clase para manejaar palabras, en este caso se trata de strings
    que contienen coaracteres alfabeticos, no se valida si la palabra
    existe en algun diccionario*/

class palabra {
    public:
        std::string valor; // Guarda valor en string
        palabra(std::string valor = "\0") : valor(valor) {}
        // Operadores para trabajar con la clase
        void operator =(std::string in);
        bool operator <(palabra& n2);
        bool operator ==(palabra& n2);
        bool operator ==(std::string& compare);
        bool operator >(palabra& n2);
};

bool es_palabra(std::string valor); // Valida el formato requerido
std::ostream& operator <<(std::ostream& COUT, palabra& salida);
std::istream& operator >>(std::istream& CIN, palabra& entrada);