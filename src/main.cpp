#include <iostream>
#include <windows.h>
#include "Negocio/Tablero.h"
#include "Negocio/Jugador.h"
#include "Negocio/JugadorHumano.h"
#include "Negocio/JugadorMaquina.h"

int main() {
    bool turnoX = false;
    Tablero* tablero1 = new Tablero();
    Tablero* tablerocopia = new Tablero();
    Jugador* jugador1 = new JugadorHumano("Alice", 'O');
    Jugador* jugadorIA = new JugadorMaquina("CPU", 'X', 'O');  // <-- NUEVO

    while (!tablero1->estaLleno())
    {
         cout << "===== PRUEBA JUGADOR HUMANO =====" << endl;
        tablero1->imprimirTablero();

        // -------------------------------
        // Movimiento del jugador humano
        // -------------------------------
        int columnaJugador = jugador1->elegirColumna(*tablero1);
        cout << "El jugador eligio la columna: " << columnaJugador << endl;

        if (tablero1->colocarFicha(columnaJugador, jugador1->getFicha())) {
            cout << "Ficha colocada exitosamente." << endl;
        } else {
            cout << "Columna llena o invalida. Intente de nuevo." << endl;
        }

        tablero1->imprimirTablero();
        if (tablero1->hay4EnLinea(turnoX ? 'X' : 'O')) {
            std::cout << "Jugador " << (turnoX ? 'X' : 'O') << " gana!\n";
            break;
        }

        Sleep(2000);
        // ================================
        // PRUEBA JUGADOR MAQUINA (IA)
        // ================================
        cout << "\n===== PRUEBA JUGADOR MAQUINA =====" << endl;

        tablerocopia = tablero1;
        int columnaIA = jugadorIA->elegirColumna(*tablerocopia);
        cout << "La IA eligio la columna: " << columnaIA << endl;

        if (tablero1->colocarFicha(columnaIA, jugadorIA->getFicha())) {
            cout << "IA coloco su ficha." << endl;
        } else {
            cout << "La IA intento una columna invalida (lo cual no deberia pasar)." << endl;
        }

        tablero1->imprimirTablero();

        if (tablero1->hay4EnLinea(turnoX ? 'X' : 'O')) {
            std::cout << "Jugador " << (turnoX ? 'X' : 'O') << " gana!\n";
            break;
        }
        turnoX = !turnoX;
    }
    
   


    // ================================
    // Limpieza de memoria (tu estilo)
    // ================================
    delete tablero1;



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