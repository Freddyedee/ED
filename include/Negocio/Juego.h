#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include "Jugador.h"
#include <string>

// Clase principal que controla el flujo del juego 4 en línea
class Juego {

private:
    Tablero tablero;             // Representa el tablero del juego como objeto
    Jugador* jugador1;           // Primer jugador
    Jugador* jugador2;           // Segundo jugador
    Jugador* jugadorActual;      // Puntero al jugador que tiene el turno
    Jugador* ganador;            // Puntero al jugador que gana la partida (nullptr si no hay ganador aún)

    int modalidad;               // Modalidad del juego (1 = estándar, 2 = con reglas especiales)
    bool juegoCargado;           // Indica si se cargó una partida previamente

    int totalMovimientos;        // Cuenta los movimientos realizados en la partida

public:
    // Constructor: inicializa los jugadores y la modalidad
    Juego(Jugador* jugador1, Jugador* jugador2, int modalidad);

    // Flujo principal del juego
    void iniciarJuego();          // Comienza la partida
    bool jugarTurno(int columna); // Ejecuta un turno del jugador actual en la columna indicada
    void cambiarTurno();          // Cambia el turno al otro jugador
    bool juegoTerminado() const;  // Verifica si la partida ha terminado
    bool hayGanador() const;      // Verifica si hay un ganador
    void imprimirEstadoJuego();   // Muestra el estado actual del tablero y jugadores

    // Movimiento y reglas
    bool realizarMovimiento(int columna);   // Realiza el movimiento y actualiza el tablero
    void aplicarReglasModalidad2();         // Aplica reglas específicas si la modalidad es 2

    // Getters para acceder a atributos privados
    Tablero& getTablero();
    const Tablero& getTablero() const;

    Jugador* getJugador1() const;
    Jugador* getJugador2() const;
    Jugador* getJugadorActual() const;
    Jugador* getGanador() const;

    int getModalidad() const;
    int getTotalMovimientos() const { return totalMovimientos; }

    // Setters para modificar atributos privados
    void setTurno(Jugador* jugador);  // Asigna un jugador como el actual
    void setModalidad(int nueva);     // Cambia la modalidad del juego

    void reiniciarMovimientos() { totalMovimientos = 0; } // Reinicia el contador de movimientos

    // Funciones para guardar y cargar partidas
    void cargarPartida(const std::string& nombreArchivo); // Carga partida desde un archivo
    void guardarPartida(const std::string& nombreArchivo); // Guarda partida en un archivo
};

#endif
