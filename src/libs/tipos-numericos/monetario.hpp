#include<iostream>
#include "numero.hpp"

/* El tipo de dato monetario está basado en el tipo numero, pero acepta como entrada
    un formato monetario. Por ejemplo 1,000,000.00 Seria rechazado por la clase numero
    sin embargo la clase monetario sí lo aceptará, pero internamente cambiará el formato a 
    1000000.00 para hacerlo coincidir o con un formato aceptado en su valor de tipo numero */
class monetario {
    public:
        numero valor;
        monetario(std::string valor = "\0") : valor(valor) {}
        void operator =(std::string in);
        bool operator <(monetario& n2);
        bool operator ==(monetario& n2);
        bool operator >(monetario& n2);
};

std::string transformar_a_numero(std::string&);
bool es_monetario(std::string valor);
std::ostream& operator <<(std::ostream& COUT, monetario& salida);
std::istream& operator >>(std::istream& CIN, monetario& entrada);
