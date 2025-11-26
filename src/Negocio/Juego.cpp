#include "Negocio/Juego.h"
#include <iostream>

// Constructor: inicializa el juego con dos jugadores y una modalidad
// El tablero se crea con 6 filas y 7 columnas
Juego::Juego(Jugador* pj1, Jugador* pj2, int modalidad)
    : tablero(6, 7), jugador1(pj1), jugador2(pj2), jugadorActual(pj1),
      ganador(nullptr), modalidad(modalidad), juegoCargado(false),
      totalMovimientos(0) {}

// Realiza un movimiento del jugador actual en la columna indicada
// Devuelve true si el movimiento fue exitoso
bool Juego::realizarMovimiento(int columna) {
    if (!tablero.colocarFicha(columna, jugadorActual->getFicha())) {
        std::cout << "Columna llena. Intenta otra.\n";
        return false;
    }

    totalMovimientos++; // Incrementa el contador de movimientos

    // Verifica ganador según modalidad
    if (modalidad == 1) {
        if (tablero.hay4EnLinea(jugadorActual->getFicha())) {
            ganador = jugadorActual;
            return true;
        }
    } else {
        aplicarReglasModalidad2();
    }

    cambiarTurno(); // Cambia turno
    return true;
}

// Cambia el turno al siguiente jugador
void Juego::cambiarTurno() {
    jugadorActual = (jugadorActual == jugador1) ? jugador2 : jugador1;
}

// Devuelve true si ya hay un ganador
bool Juego::hayGanador() const {
    return ganador != nullptr;
}

// Verifica si el juego ha terminado
bool Juego::juegoTerminado() const {
    if (modalidad == 1) return hayGanador();
    return tablero.estaLleno();
}

// Getters del tablero
Tablero& Juego::getTablero() { return tablero; }
const Tablero& Juego::getTablero() const { return tablero; }

// Getters de los jugadores
Jugador* Juego::getJugador1() const { return jugador1; }
Jugador* Juego::getJugador2() const { return jugador2; }
Jugador* Juego::getJugadorActual() const { return jugadorActual; }
Jugador* Juego::getGanador() const { return ganador; }

// Getter de la modalidad
int Juego::getModalidad() const { return modalidad; }

// Aplica las reglas de la modalidad 2 para determinar ganador según secuencias
void Juego::aplicarReglasModalidad2() {
    int s1 = tablero.contarSecuencias(jugador1->getFicha());
    int s2 = tablero.contarSecuencias(jugador2->getFicha());
    if (s1 != s2) {
        ganador = (s1 > s2) ? jugador1 : jugador2;
    }
}

// Setters simples
void Juego::setTurno(Jugador* jugador) { jugadorActual = jugador; }
void Juego::setModalidad(int nueva) { modalidad = nueva; }

// Guardado y carga todavía no implementados
void Juego::cargarPartida(const std::string& nombreArchivo) {
    std::cout << "Cargar partida no implementado.\n";
}
void Juego::guardarPartida(const std::string& nombreArchivo) {
    std::cout << "Guardar partida no implementado.\n";
}
