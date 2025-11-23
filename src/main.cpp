#include <iostream>
<<<<<<< HEAD
#include "../include/Negocio/Tablero.h"
=======
#include "Negocio/Tablero.h"
#include "Negocio/Jugador.h"
#include "Negocio/JugadorHumano.h"
>>>>>>> 68452347eb23b311314e2cb13fd31c7108c3d516

int main() {
    //Opcion 1 de creacion : 

    Tablero* tablero1 = new Tablero(); 
    Jugador* jugador1 = new JugadorHumano("Alice", 'O');
    

    cout << "===== PRUIEBA JUGADOR HUMANO =====" << endl;
    tablero1->imprimirTablero();

    int columnaJugador = jugador1->elegirColumna(*tablero1);
    cout << "El jugador eligio la columna: " << columnaJugador << endl;
    
    if(tablero1->colocarFicha(columnaJugador, jugador1->getFicha())){
        cout << "Ficha colocada exitosamente." << endl;
    }else{
        cout << "Columna llena o invalida. Intente de nuevo." << endl;  
    }

    tablero1->imprimirTablero();



    //PRUEBA DE JUGAROR HUMANO



    /*bool turnoX = true; 
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

        turnoX = !turnoX;*/
    

    
    
    return 0;
}