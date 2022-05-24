#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>

using namespace std;

void mostrar_portada() {
    std::string line(100, char(196));
    std::string instituto = "INSTITUTO POLITECNICO NACIONAL";
    std::string escuela = "Unidad Profesional Interdisciplinaria de Ingenieria y Ciencias Sociales y Administrativas";
    std::string asignatura = "Logica de programacion";
    std::string proyecto = "Ordenamiento de Valores";
    
    std::cout << line << std::endl
              << string(35, ' ') << instituto << string(35, ' ') << std::endl
              << string(5, ' ') << escuela << string(5, ' ') << std::endl
              << line << std::endl
              << asignatura 
              << setw(100 - asignatura.size()) << setfill(' ') << proyecto << std::endl
              << line << endl
              << "Equipo 3: \n"
              << "Abarca Godoy Alvaro\n"
              << "Bautista Rojas Dante Alonso\n"
              << setw(100) << line << std::endl;
    std::cout << "\n\n" << "Presiona Enter para continuar........";
    cin.get();
    return;
}

void mostrar_menu() {
    string line(98, char(205));
    char separadorV = char(205);
    char separadorH = char(186);
    char separadorHC = char(206);
    
    std::cout << char(201) << line << char(187) << endl 
              << char(186) << string((98-35)/2, ' ') 
			  << "Formatos de ordenamiento disponible" << string((98-35)/2, ' ') << " " << char(186) << endl 
              << char(204) << string(3, separadorV) << char(203) << string(12, separadorV) << char(203) 
			  << string(99 - 18, char(205)) << char(185) << endl
              
              << separadorH << setw(3) << " 1 " << separadorH << setw(12) << " Numeros    " << separadorH
                << setw(81) << setfill(' ') << left << " Ordena numeros reales de menor a mayor" 
                << separadorH << endl
              << char(204) << string(3, separadorV) << separadorHC << string(12, separadorV) << separadorHC
                <<  string(99 - 18, char(205)) << char(185) << endl
              
              << separadorH << setw(3) << " 2 " << separadorH << setw(12) << " Caracteres " << separadorH
                << setw(81) << setfill(' ') << left << " Ordena alfabeticamente caracteres del codigo ASCII" 
                << separadorH << endl
              << char(204) << string(3, separadorV) << separadorHC << string(12, separadorV) << separadorHC
                <<  string(99 - 18, char(205)) << char(185) << endl
              
              << separadorH << setw(3) << " 3 " << separadorH << setw(12) << " Palabras   " << separadorH
                << setw(81) << setfill(' ') << left << " Ordena palabras alfabeticamente. Sin validar correcta escritura" 
                << separadorH << endl
              << char(204) << string(3, separadorV) << separadorHC << string(12, separadorV) << separadorHC
                <<  string(99 - 18, char(205)) << char(185) << endl
              
              << separadorH << setw(3) << " 4 " << separadorH << setw(12) << " Salida     " << separadorH
                << setw(81) << setfill(' ') << left << " Termina el programa" 
                << separadorH << endl
              << char(200) << string(3, char(205)) << char(202) << string(12, char(205)) << char(202)
			   << string(99 - 18, char(205)) << char(188) << endl;
    return;
}