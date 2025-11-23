#include "Negocio/JugadorHumano.h"
#include "Negocio/Jugador.h"
#include <iostream>
#include <string>
using namespace std;

JugadorHumano::JugadorHumano(string nombre, char ficha) 
: Jugador(nombre, ficha){}
    // Constructor del jugador humano que llama al constructor de la clase base Jugador


int JugadorHumano::elegirColumna(Tablero& tablero){
     int columna = 0; 

     cout << "\n Turno del jugadorr:" << getNombre()  << " (" << getFicha() << ")\n";
     cout << "Seleccione una columna"; 
     cin >> columna; 

     return columna; 
}



