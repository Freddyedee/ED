#ifndef JUGADOR_H
#define JUGADOR_H


#include <string>
#include "Tablero.h" //inclusion para usar la clase Tablero

using namespace std; 

class Jugador{

    Tablero tablero;
    protected:
        string nombre;
        char ficha; 

        public : 

        Jugador(string nombre, char ficha); 

        string getNombre(); 
        char getFicha(); 
        void setNombre(string nombre); 
        void setFicha(char ficha);

        virtual int elegirColumna(Tablero& tablero)=0; //convierte a una clase en abstracta

}; 









#endif // JUGADOR_H