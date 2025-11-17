#include "Negocio/LogicaJuego.h"
#include "Datos/Tablero.h"
#include "Datos/Jugador.h"

LogicaJuego::LogicaJuego() 
    : tablero(nullptr), jugador1(nullptr), jugador2(nullptr), 
      jugadorActual(nullptr), juegoTerminado(false) {
}

LogicaJuego::~LogicaJuego() {
    delete tablero;
    delete jugador1;
    delete jugador2;
}

void LogicaJuego::inicializarJuego() {
    // Crear tablero estándar de 6x7
    tablero = new Tablero(6, 7);
    
    // Crear jugadores
    jugador1 = new Jugador("Jugador 1", 'X');
    jugador2 = new Jugador("Jugador 2", 'O');
    
    jugadorActual = jugador1;
    juegoTerminado = false;
}

bool LogicaJuego::hacerMovimiento(int columna) {
    if (juegoTerminado || !tablero) {
        return false;
    }
    
    // Aquí iría la lógica para colocar ficha
    // Por ahora simulamos que siempre funciona
    return true;
}

bool LogicaJuego::verificarGanador() const {
    if (!tablero) return false;
    // Lógica para verificar 4 en raya
    return false;  // Simulación
}

bool LogicaJuego::esEmpate() const {
    if (!tablero) return false;
    // Verificar si el tablero está lleno
    return false;  // Simulación
}

void LogicaJuego::cambiarTurno() {
    if (jugadorActual == jugador1) {
        jugadorActual = jugador2;
    } else {
        jugadorActual = jugador1;
    }
}

Jugador* LogicaJuego::getJugadorActual() const {
    return jugadorActual;
}

bool LogicaJuego::getJuegoTerminado() const {
    return juegoTerminado;
}