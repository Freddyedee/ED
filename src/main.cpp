#include <iostream>
#include "../include/Negocio/Tablero.h"

int main() {
    //Opcion 1 de creacion : 

   Tablero* tablero1 = new Tablero(); 
   
    bool turnoX = true; 
    int col; 

     while (!tablero1->estaLleno()) {
        tablero1->imprimirTablero();
        std::cout << "Jugador " << (turnoX ? 'X' : 'O') << ", elige columna: ";
        std::cin >> col;

        if (!tablero1->colocarFicha(col, turnoX ? 'X' : 'O')) {
            std::cout << "Movimiento inválido\n";
            continue;
        }

        if (tablero1->hay4EnLinea(turnoX ? 'X' : 'O')) {
            tablero1->imprimirTablero();
            std::cout << "Jugador " << (turnoX ? 'X' : 'O') << " gana!\n";
            break;
        }

        turnoX = !turnoX;
    }
    
    
    return 0;
}