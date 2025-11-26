#include <iostream>
<<<<<<< HEAD
#include <string>
#include "Negocio/Tablero.h"
#include "Negocio/Jugador.h"
#include "Negocio/JugadorHumano.h"
#include "Negocio/Juego.h"
=======
<<<<<<< HEAD
#include "../include/Negocio/Tablero.h"
=======
#include "Negocio/Tablero.h"
#include "Negocio/Jugador.h"
#include "Negocio/JugadorHumano.h"
>>>>>>> 68452347eb23b311314e2cb13fd31c7108c3d516
>>>>>>> d309bf43f6dfcab0bcc5a1aba00d0a7813a5ab10

using namespace std;

// -----------------------------------------------------
// Mostrar un menú simple
// -----------------------------------------------------
void mostrarMenu() {
    cout << "\n========== MENU PRINCIPAL ==========\n";
    cout << "1. Nueva partida (Humano vs Humano)\n";
    cout << "2. Salir\n";
    cout << "Seleccione una opcion: ";
}

// -----------------------------------------------------
// Imprimir tablero
// -----------------------------------------------------
void imprimirTablero(const Tablero& t) {
    cout << "\n";
    t.imprimirTablero();
    cout << "\n";
}

// -----------------------------------------------------
// Ejecutar una partida completa
// -----------------------------------------------------
void jugarPartida(Juego& juego) {

    while (!juego.juegoTerminado()) {

        system("cls"); // Para Windows

        cout << "\n=========== 4 EN LINEA ===========\n";
        cout << "Turno de: "
             << juego.getJugadorActual()->getNombre()
             << " (" << juego.getJugadorActual()->getFicha() << ")\n";

        imprimirTablero(juego.getTablero());

        int columna;
        cout << "Ingrese columna (0 - "
             << juego.getTablero().getColumnas() - 1 << "): ";
        cin >> columna;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida.\n";
            system("pause");
            continue;
        }

        if (!juego.realizarMovimiento(columna)) {
            cout << "Movimiento no valido.\n";
            system("pause");
        }
    }

    // Final de la partida
    system("cls");
    imprimirTablero(juego.getTablero());

    cout << "\n============== RESULTADO ==============\n";

    if (juego.getGanador() == nullptr)
        cout << "La partida terminó en EMPATE.\n";
    else
        cout << "El GANADOR es: "
             << juego.getGanador()->getNombre()
             << " (" << juego.getGanador()->getFicha() << ")\n";

    cout << "Total de movimientos: " << juego.getTotalMovimientos() << "\n";

    system("pause");
}

// -----------------------------------------------------
// PROGRAMA PRINCIPAL DE PRUEBA
// -----------------------------------------------------
int main() {

    while (true) {
        mostrarMenu();

        int opcion;
        cin >> opcion;

        if (opcion == 1) {

            string n1, n2;
            cout << "Nombre jugador 1: ";
            cin >> n1;
            cout << "Nombre jugador 2: ";
            cin >> n2;

            // Crear jugadores humanos
            Jugador* j1 = new JugadorHumano(n1, 'X');
            Jugador* j2 = new JugadorHumano(n2, 'O');

            int modalidad;
            cout << "\nSeleccione modalidad:\n";
            cout << "1. Primer 4 en línea\n";
            cout << "2. Mayor número de secuencias\n";
            cout << "Modalidad: ";
            cin >> modalidad;

            Juego juego(j1, j2, modalidad);

            jugarPartida(juego);

            
        }
        else if (opcion == 2) {
            cout << "Saliendo...\n";
            break;
        }
        else {
            cout << "Opcion invalida.\n";
        }
    }

    return 0;
}
