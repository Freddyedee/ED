#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include "Jugador.h"
#include <string>

//
// Clase principal que controla el flujo del juego 4 en línea.
// Se encarga de manejar turnos, movimientos, reglas, ganador
// y comunicación con el tablero.
//

class Juego {

private:
    // --- ESTADO INTERNO DEL JUEGO ---

    int secuenciasJ1 = 0;
    int secuenciasJ2 = 0;

    Tablero tablero;             
    // Objeto que representa la matriz del tablero y gestiona
    // la inserción de fichas y detección de líneas ganadoras.

    Jugador* jugador1;           
    // Puntero al primer jugador (X u O según configuración).

    Jugador* jugador2;           
    // Puntero al segundo jugador.

    Jugador* jugadorActual;      
    // Puntero al jugador que tiene el turno en este momento.
    // Alterna entre jugador1 y jugador2.

    Jugador* ganador;            
    // Puntero al jugador ganador de la partida.
    // Permanece en nullptr hasta que alguien gana.

    int modalidad;               
    // Modalidad de juego:
    // 1 = juego estándar
    // 2 = juego con reglas especiales adicionales.

    bool juegoCargado;           
    // Indica si se cargó una partida desde archivo.
    // Permite reanudar una partida guardada.

    int totalMovimientos;        
    // Número total de movimientos realizados en la partida.
    // Útil para detectar empates o estadísticas.


public:

    // -----------------------------------------------------------
    // Constructor: recibe los dos jugadores y la modalidad inicial.
    // Inicializa el tablero y asigna jugadorActual al jugador1.
    // -----------------------------------------------------------
    Juego(Jugador* jugador1, Jugador* jugador2, int modalidad);
    // Constructor de copia
    Juego(const Juego& otro);

    int getSecuenciasJ1() const { return secuenciasJ1; }
    int getSecuenciasJ2() const { return secuenciasJ2; }

    // --- CONTROL DE FLUJO DEL JUEGO ---

    void cambiarTurno();
    // Cambia el turno alternando entre jugador1 y jugador2.

    bool juegoTerminado() const;
    // Devuelve true si hay un ganador o si el tablero está lleno.

    bool hayGanador() const;
    // Devuelve true si existe un jugador que ya ganó.


    // --- MOVIMIENTOS Y REGLAS ---

    bool realizarMovimiento(int columna);
    // Inserta la ficha del jugadorActual en la columna indicada.
    // Si el movimiento es válido, actualiza tablero, verifica ganador
    // y aumenta totalMovimientos.

    void aplicarReglasModalidad2();
    // Aplica reglas adicionales para la modalidad 2
    // (solo si se activa esa modalidad).


    // --- GETTERS ---

    Tablero& getTablero();
    // Devuelve referencia modificable al tablero.

    const Tablero& getTablero() const;
    // Devuelve referencia NO modificable al tablero.

    Jugador* getJugador1() const;
    Jugador* getJugador2() const;
    Jugador* getJugadorActual() const;
    Jugador* getGanador() const;

    int getModalidad() const;
    int getTotalMovimientos() const { return totalMovimientos; }


    // --- SETTERS ---

    void setTurno(Jugador* jugador);
    // Cambia quién es el jugadorActual.

    void setModalidad(int nueva);
    // Cambia la modalidad del juego (1 o 2).

    void reiniciarMovimientos() { totalMovimientos = 0; }
    // Reinicia el contador de movimientos.


    // --- GUARDAR Y CARGAR PARTIDAS ---

    void cargarPartida(const std::string& nombreArchivo);
    // Carga todos los datos del juego desde un archivo.
    // Restaura turno, modalidad, tablero y movimientos.

    void guardarPartida(const std::string& nombreArchivo);
    // Guarda el estado del juego actual en un archivo para continuar luego.
};

#endif
