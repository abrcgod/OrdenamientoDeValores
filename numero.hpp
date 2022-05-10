#include <iostream>

struct numero {
        std::string valor;
        numero(std::string valor = "\0") : valor(valor) {}
        int operator =(std::string in);
        bool operator <(numero& n2);
        bool operator ==(numero& n2);
        bool operator >(numero& n2);
};

bool isNumber(std::string valor);
std::ostream& operator <<(std::ostream& COUT, numero& salida);
std::istream& operator >>(std::istream& CIN, numero& entrada);

struct monetario {
        std::string valor;
        monetario(std::string valor = "\0") : valor(valor) {}
        int operator =(std::string in);
        bool operator <(monetario& n2);
        bool operator ==(monetario& n2);
        bool operator >(monetario& n2);
};

bool esMonetario(std::string valor);
std::ostream& operator <<(std::ostream& COUT, monetario& salida);
std::istream& operator >>(std::istream& CIN, monetario& entrada);

struct palabra {
        std::string valor;
        palabra(std::string valor = "\0") : valor(valor) {}
        int operator =(std::string in);
        bool operator <(palabra& n2);
        bool operator ==(palabra& n2);
        bool operator >(palabra& n2);
};

bool esPalabra(std::string valor);
std::ostream& operator <<(std::ostream& COUT, palabra& salida);
std::istream& operator >>(std::istream& CIN, palabra& entrada);

