#include <iostream>
#include "Negocio/Juego.h"
#include "Negocio/JugadorHumano.h"
#include "Datos/GestorArchivos.h"

using namespace std;

void mostrarMenuPrincipal() {
    cout << "\n========== MENU PRINCIPAL ==========\n";
    cout << "1. Iniciar nuevo juego\n";
    cout << "2. Cargar juego desde archivo\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opcion: ";
}

void mostrarMenuJuego() {
    cout << "\n========== MENU DEL JUEGO ==========\n";
    cout << "1. Hacer un movimiento\n";
    cout << "2. Mostrar tablero\n";
    cout << "3. Guardar partida\n";
    cout << "4. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
}

int main() {

    GestorArchivos gestor;
    Juego* juego = nullptr;   // Se creará dinámicamente

    int opcionMenu = 0;

    while (opcionMenu != 3) {
        mostrarMenuPrincipal();
        cin >> opcionMenu;

        if (opcionMenu == 1) {
            // ======== NUEVO JUEGO =========

            string nombre1, nombre2;
            int modalidad;

            cout << "\nIngrese nombre del jugador 1: ";
            cin >> nombre1;
            cout << "Ingrese nombre del jugador 2: ";
            cin >> nombre2;

            cout << "\nSeleccione modalidad:\n";
            cout << "1. Modo clásico (4 en línea)\n";
            cout << "2. Modo puntaje (contar secuencias)\n";
            cout << "Opcion: ";
            cin >> modalidad;

            // Crear jugadores
            Jugador* j1 = new JugadorHumano(nombre1, 'X');
            Jugador* j2 = new JugadorHumano(nombre2, 'O');

            // Crear juego
            juego = new Juego(j1, j2, modalidad);

            cout << "\nJuego iniciado correctamente.\n";
            juego->getTablero().imprimirTablero();

            // ======== SUBMENÚ DEL JUEGO =========
            int opcionJuego = 0;
            while (opcionJuego != 4) {

                mostrarMenuJuego();
                cin >> opcionJuego;

                if (opcionJuego == 1) {
                    // Movimiento
                    int columna;

                    cout << "\nTurno de: " << juego->getJugadorActual()->getNombre()
                         << " (" << juego->getJugadorActual()->getFicha() << ")\n";
                    cout << "Ingrese columna (0 - 6): ";
                    cin >> columna;

                    if (!juego->realizarMovimiento(columna)) {
                        cout << "Movimiento invalido.\n";
                        continue;
                    }

                    juego->getTablero().imprimirTablero();
                    cout << "Movimientos: " << juego->getTotalMovimientos() << "\n";

                    if (juego->hayGanador()) {
                        cout << "\nGanador!\n";
                        cout << "Ganador: " << juego->getGanador()->getNombre() << "\n";
                        opcionJuego = 4; // salir al menú principal
                    }

                    else if (juego->getTablero().estaLleno()) {
                        cout << "\nTABLERO LLENO: EMPATE\n";
                        opcionJuego = 4;
                    }
                }

                else if (opcionJuego == 2) {
                    cout << "\n=== ESTADO DEL TABLERO ===\n";
                    juego->getTablero().imprimirTablero();
                    cout << "Turno: " << juego->getJugadorActual()->getNombre()
                         << " (" << juego->getJugadorActual()->getFicha() << ")\n";
                }

                else if (opcionJuego == 3) {
                    cout << "\nGuardando partida...\n";
                    if (gestor.guardarJuego(*juego, "partida.txt"))
                        cout << "Partida guardada correctamente.\n";
                }
            }

            delete juego; // elimina j1 y j2 internamente si así lo programaste
            juego = nullptr;
        }

        else if (opcionMenu == 2) {
            // ======== CARGAR JUEGO =========

            cout << "\nCargando partida...\n";

            // Creamos un juego vacío provisional
            Jugador* j1 = new JugadorHumano("TEMP1", 'X');
            Jugador* j2 = new JugadorHumano("TEMP2", 'O');

            juego = new Juego(j1, j2, 1);

            if (gestor.cargarJuego(*juego, "partida.txt")) {
                cout << "Partida cargada exitosamente.\n";
                juego->getTablero().imprimirTablero();
            } else {
                cout << "No se pudo cargar la partida.\n";
                delete juego;
                juego = nullptr;
                continue;
            }

            // Submenú igual que antes
            int opcionJuego = 0;
            while (opcionJuego != 4) {

                mostrarMenuJuego();
                cin >> opcionJuego;

                if (opcionJuego == 1) {
                    int columna;
                    cout << "\nTurno de: " << juego->getJugadorActual()->getNombre()
                         << " (" << juego->getJugadorActual()->getFicha() << ")\n";
                    cout << "Ingrese columna: ";
                    cin >> columna;

                    juego->realizarMovimiento(columna);
                    juego->getTablero().imprimirTablero();

                    if (juego->hayGanador()) {
                        cout << "Ganador: " << juego->getGanador()->getNombre() << "\n";
                        opcionJuego = 4;
                    }
                }

                else if (opcionJuego == 2) {
                    juego->getTablero().imprimirTablero();
                }

                else if (opcionJuego == 3) {
                    gestor.guardarJuego(*juego, "partida.txt");
                }
            }

            delete juego;
            juego = nullptr;
        }
    }

    cout << "\nGracias por jugar. ¡Hasta pronto!\n";
    return 0;
}
