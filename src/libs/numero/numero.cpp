#include "numero.hpp"

#include <cctype>
#include <iostream>     
#include <string>
#include <sstream>

std::string obtener_parte_entera(std::string& num) {
    int posicionDelPunto = num.find('.');
    std::string parteEntera = num.substr(0, posicionDelPunto);
    
    std::cout << parteEntera << std::endl;

    return parteEntera;
}

std::string obtener_parte_decimal(std::string& num) {
    int posicionDelPunto = num.find('.');
    std::string parteDecimal = num.substr(posicionDelPunto + 1);
    
    std::cout << parteDecimal << std::endl;

    return parteDecimal;
}

bool es_negativo(std::string& num) {
    if (num[0] == '-') {
        return true;
    } else {
        return false;
    }
}
   

bool numero::operator <(numero& n2) {
    // Comapra primero las partes enteras de los numeros
    std::string parteEnteraN1 = obtener_parte_entera(this->valor);
    std::string parteEnteraN2 = obtener_parte_entera(n2.valor);

    int cmp = parteEnteraN1.compare(parteEnteraN2);
    if (cmp < 0) {
        // Cuando se comparan dos numeros negativos la lógica se invierte:
        // Lo mismo sucede en otros bloques de codigo mas adelante
        if (es_negativo(this->valor) && es_negativo(n2.valor)) {
                return false;
            } else {
                return true;
            }
    } else if (cmp > 0) {
        if (es_negativo(this->valor) && es_negativo(n2.valor)) {
                return true;
            } else {
                return false;
            }
    } else {
        // Cuando las partes enteras son iguales compara la parte decimal
        std::string parteDecimalN1 = obtener_parte_decimal(this->valor);
        std::string parteDecimalN2 = obtener_parte_decimal(n2.valor);

        // Obtiene iteradoes al inicio de la string para comparar
        auto digitoDecimalN1 = std::begin(parteDecimalN1);
        auto digitoDecimalN2 = std::begin(parteDecimalN2);

        while (true) {
            if (*digitoDecimalN1 < *digitoDecimalN2) {
                if (es_negativo(this->valor) && es_negativo(n2.valor)) {
                    return false;
                } else {
                    return true;
                }
            } else if (*digitoDecimalN1 == *digitoDecimalN2) {
                digitoDecimalN1++;
                digitoDecimalN2++;
                continue;
            } else {
                 if (es_negativo(this->valor) && es_negativo(n2.valor)) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    return false;
}

bool numero::operator ==(numero& n2) {
    if (this->valor.compare(n2.valor) == 0) {
        return true;
    } else {
        return false;
    }
}

bool numero::operator >(numero& n2) {
    if (!(*this < n2) && !(*this == n2)) {
        return true;
    } else {
        return false;
    }
}

int numero::operator =(std::string entrada) {
    if (isNumber(entrada)) {
        this->valor = entrada;
        return 0;
    } else {
        return 1;
    }
}

// Para validar que el string tenga el formato correcto de numero real
bool isNumber(std::string valor) {
    int dotCount = 0; // Para verificar que tenga solo un punto decimal
    for (int i = 0; i < valor.length(); i++) { // Itera a traves del string
        char digit = valor[i];
        if (digit == '.') {dotCount += 1;}
        if (isdigit(digit) == 0) { // Cuando el digito actual no es un numero
            if (digit == '.' && dotCount <= 1) {
                // Acepta solo un punto decimal para continuar 
                continue;
            } else if (digit == '-' && i == 0) {
                // Acepta el signo '-' solo al principio del string para manejar numeros negativos
                continue;
            } else {
                // Si el digito actual no es un numero y ademas no cumple nigun criterio de arriba lo rechaza
                return false;
            }
        }   
    }
    return true;
}

std::ostream& operator <<(std::ostream& COUT, numero& salida) {
    COUT << salida.valor; 
    return COUT;
}

std::istream& operator >>(std::istream& CIN, numero& entrada) {
    std::string valor;
    CIN >> valor;
    if (isNumber(valor)) {
        entrada.valor = valor;
    }
    return CIN;
}
