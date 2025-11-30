#ifndef INTERACCION_H
#define INTERACCION_H

#include <string>
#include "Negocio/Jugador.h"
#include "Negocio/Juego.h"

Jugador* crearJugadorHumanoPresentacion(const std::string& nombre, char ficha);
Jugador* crearJugadorIAPresentacion(const std::string& nombre, char ficha, char fichaEnemiga);

// Funciones de captura y configuración
void pedirNombresPvP(std::string& n1, std::string& n2);
void pedirNombrePvIA(std::string& n1);

// Crear jugadores según tipo de partida
void configurarJugadores(int tipoPartida, Jugador*& j1, Jugador*& j2);

// Ejecutar submenú del juego
void ejecutarMenuJuego(Juego* juego);

#endif
