#include <iostream>

class palabra {
    public:
        std::string valor;
        palabra(std::string valor = "\0") : valor(valor) {}
        void operator =(std::string in);
        bool operator <(palabra& n2);
        bool operator ==(palabra& n2);
        bool operator >(palabra& n2);
};

bool es_palabra(std::string valor);
std::ostream& operator <<(std::ostream& COUT, palabra& salida);
std::istream& operator >>(std::istream& CIN, palabra& entrada);