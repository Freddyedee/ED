#include <iostream>
#include <thread>
#include <chrono>
#include "Negocio/Juego.h"
#include "Negocio/JugadorHumano.h"
#include "Negocio/JugadorMaquina.h"
#include "Negocio/GestorMemoria.h"
#include "Presentacion/Menus.h"
#include "Presentacion/Interaccion.h"

int main() {

    int opcion = 0;
    Juego* juego = nullptr;

    while (opcion != 3) {

        mostrarMenuPrincipal();
        std::cin >> opcion;

        // ===========================
        // 1. NUEVA PARTIDA
        // ===========================
        if (opcion == 1) {

            mostrarMenuTipoPartida();
            int tipo;
            std::cin >> tipo;

            Jugador* j1 = nullptr;
            Jugador* j2 = nullptr;
            configurarJugadores(tipo, j1, j2);

            int modalidad = pedirModalidad();

            juego = new Juego(j1, j2, modalidad);

            std::cout << "\nJuego iniciado correctamente.\n";
            juego->getTablero().imprimirTablero();

            ejecutarMenuJuego(juego);

            delete juego;
            juego = nullptr;
        }

        // ===========================
        // 2. CARGAR PARTIDA
        // ===========================
        else if (opcion == 2) {

            gestorMemoria.listarSlots();
            int slotCargar;
            std::cout << "Ingrese slot para cargar: ";
            std::cin >> slotCargar;

            Juego* juegoCargado = gestorMemoria.cargarJuego(slotCargar);

            if (juegoCargado != nullptr) {

                juego = juegoCargado;

                std::cout << "\nJuego cargado correctamente.\n";
                juego->getTablero().imprimirTablero();

                

                // Después de cargar, ir directo al menú del juego
                ejecutarMenuJuego(juego);

                delete juego;
                juego = nullptr;
            }
        }
    }

    std::cout << "\nGracias por jugar. ¡Hasta pronto!\n";
    return 0;
}