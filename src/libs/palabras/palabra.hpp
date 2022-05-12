#include <iostream>

class palabra {
    public:
        std::string valor;
        palabra(std::string valor = "\0") : valor(valor) {}
        int operator =(std::string in);
        bool operator <(palabra& n2);
        bool operator ==(palabra& n2);
        bool operator >(palabra& n2);
};