#include <chrono>
#include <thread>
#include "Presentacion/Interaccion.h"
#include "Presentacion/Menus.h"
#include "Negocio/JugadorHumano.h"
#include "Negocio/JugadorMaquina.h"
#include "Negocio/GestorMemoria.h"
#include <iostream>

// ------------------------------
// Funciones de creación de jugadores
// ------------------------------
Jugador* crearJugadorHumanoPresentacion(const std::string& nombre, char ficha) {
    return new JugadorHumano(nombre, ficha);
}

Jugador* crearJugadorIAPresentacion(const std::string& nombre, char ficha, char fichaEnemiga) {
    return new JugadorMaquina(nombre, ficha, fichaEnemiga);
}

// ------------------------------
// Funciones de pedir nombres
// ------------------------------
void pedirNombresPvP(std::string& n1, std::string& n2) {
    std::cout << "\nIngrese nombre del Jugador 1: ";
    std::cin >> n1;
    std::cout << "Ingrese nombre del Jugador 2: ";
    std::cin >> n2;
}

void pedirNombrePvIA(std::string& n1) {
    std::cout << "\nIngrese nombre del Jugador: ";
    std::cin >> n1;
}

// ------------------------------
// Configuración de jugadores según tipo de partida
// ------------------------------
void configurarJugadores(int tipoPartida, Jugador*& j1, Jugador*& j2) {
    std::string n1, n2;

    switch (tipoPartida) {
    case 1: // P vs P
        pedirNombresPvP(n1, n2);
        j1 = crearJugadorHumanoPresentacion(n1, 'X');
        j2 = crearJugadorHumanoPresentacion(n2, 'O');
        break;

    case 2: // P vs IA
        pedirNombrePvIA(n1);
        j1 = crearJugadorHumanoPresentacion(n1, 'X');
        j2 = crearJugadorIAPresentacion("CPU", 'O', 'X');
        break;

    case 3: // IA vs IA
        j1 = crearJugadorIAPresentacion("CPU1", 'X', 'O');
        j2 = crearJugadorIAPresentacion("CPU2", 'O', 'X');
        std::cout << "\nSe ha iniciado una partida IA vs IA.\n";
        break;

    default:
        std::cout << "Opción inválida.\n";
        break;
    }
}


// ------------------------------
// Ejecutar menú del juego
// ------------------------------
void realizarTurno(Juego* juego) {
    while (true) {

        Jugador* actual = juego->getJugadorActual();
        int columna;

        std::cout << "\nTurno de " << actual->getNombre()
                  << " (" << actual->getFicha() << ")\n";

        // --- Si es humano ---
        if (dynamic_cast<JugadorMaquina*>(actual) == nullptr) {
            std::cout << "Ingrese columna (0-6): ";
            std::cin >> columna;
        }
        // --- Si es IA ---
        else {
            std::cout << "La IA está pensando...\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            columna = actual->elegirColumna(juego->getTablero());
            std::cout << "IA juega en columna: " << columna << "\n";
        }

        // Intentar movimiento
        if (!juego->realizarMovimiento(columna)) {
            std::cout << "Movimiento inválido.\n";

            // Si es IA y falla → reintenta automáticamente
            if (dynamic_cast<JugadorMaquina*>(actual) != nullptr)
                continue;

            return;
        }

        juego->getTablero().imprimirTablero();

        // Verificar fin del juego
        if (juego->hayGanador()) {
            std::cout << "\nGanador: " << juego->getGanador()->getNombre() << "\n";
            return;
        }

        if (juego->getTablero().estaLleno()) {
            std::cout << "\nTABLERO LLENO: EMPATE.\n";
            return;
        }

        // Si el siguiente jugador es IA → repetir automáticamente
        Jugador* siguiente = juego->getJugadorActual();
        if (dynamic_cast<JugadorMaquina*>(siguiente) != nullptr) {
            continue;
        }

        // Si el siguiente es humano → salir para que vuelva el menú
        break;
    }
}



void ejecutarMenuJuego(Juego* juego) {

    int opcion = 0;

    while (opcion != 4) {

        mostrarMenuJuego();
        std::cin >> opcion;

        switch (opcion) {

        case 1: { // Movimiento de jugador humano o IA
            realizarTurno(juego);
            break;
        }

        case 2: // Mostrar tablero
            std::cout << "\n=== ESTADO DEL TABLERO ===\n";
            juego->getTablero().imprimirTablero();
            break;

        case 3: { // Guardar en memoria
            int slot;
            gestorMemoria.listarSlots();
            std::cout << "Ingrese slot para guardar (0-4): ";
            std::cin >> slot;
            gestorMemoria.guardarJuego(juego, slot);
            break;
        }

        case 5: { // Cargar desde memoria
            int slot;
            gestorMemoria.listarSlots();
            std::cout << "Ingrese slot a cargar (0-4): ";
            std::cin >> slot;
            Juego* juegoCargado = gestorMemoria.cargarJuego(slot);
            if (juegoCargado != nullptr) {
                juego = juegoCargado;
                std::cout << "Partida cargada correctamente.\n";
                juego->getTablero().imprimirTablero();
            }
            break;
        }
        }
    }
}
