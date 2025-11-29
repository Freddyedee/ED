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

void mostrarMenuTipoPartida() {
    cout << "\n======= SELECCIONAR TIPO DE PARTIDA =======\n";
    cout << "1. Jugador vs Jugador\n";
    cout << "2. Jugador vs IA\n";
    cout << "3. IA vs IA\n";
    cout << "Seleccione una opcion: ";
}

Jugador* crearJugadorHumano(const string& nombre, char ficha) {
    return new JugadorHumano(nombre, ficha);
}

Jugador* crearJugadorIA(const string& nombre, char ficha, char fichaEnemiga) {
    return new JugadorMaquina(nombre, ficha, fichaEnemiga);
}

int pedirModalidad() {
    int modalidad;
    cout << "\nSeleccione modalidad:\n";
    cout << "1. Modo clasico (4 en linea)\n";
    cout << "2. Modo puntaje\n";
    cout << "Opcion: ";
    cin >> modalidad;
    return modalidad;
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

            int tipoPartida;
            mostrarMenuTipoPartida();
            cin >> tipoPartida;

            string nombre1, nombre2;
            Jugador* j1 = nullptr;
            Jugador* j2 = nullptr;

            if (tipoPartida == 1) { 
                // ============ P vs P ============
                cout << "\nIngrese nombre del Jugador 1: ";
                cin >> nombre1;
                cout << "Ingrese nombre del Jugador 2: ";
                cin >> nombre2;

                j1 = crearJugadorHumano(nombre1, 'X');
                j2 = crearJugadorHumano(nombre2, 'O');
            }

            else if (tipoPartida == 2) {
                // ============ P vs IA ============
                cout << "\nIngrese nombre del Jugador: ";
                cin >> nombre1;

                j1 = crearJugadorHumano(nombre1, 'X');
                j2 = crearJugadorIA("CPU", 'O', 'X');
            }

            else if (tipoPartida == 3) {
                // ============ IA vs IA ============
                j1 = crearJugadorIA("CPU1", 'X', 'O');
                j2 = crearJugadorIA("CPU2", 'O', 'X');

                cout << "\nSe ha iniciado una partida IA vs IA.\n";
            }

            else {
                cout << "Opcion invalida.\n";
                continue;
            }

            // Pedir modalidad
            int modalidad = pedirModalidad();

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
