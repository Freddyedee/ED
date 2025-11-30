#include "Negocio/Juego.h"
#include "Negocio/JugadorHumano.h"
#include "Negocio/JugadorMaquina.h"
#include <iostream>

/*
==========================================================
                CONSTRUCTOR DEL JUEGO
==========================================================

Inicializa un objeto Juego asignándole:
- Dos jugadores (pj1 y pj2)
- La modalidad de juego (1 o 2)
- Un tablero de tamaño fijo 6x7
- El primer turno para jugador1
- Sin ganador al inicio
- Contador de movimientos en 0
- Bandera de carga en false
*/
Juego::Juego(Jugador* pj1, Jugador* pj2, int modalidad)
    : tablero(6, 7),          // Crea un tablero de 6 filas y 7 columnas
      jugador1(pj1),          // Jugador 1
      jugador2(pj2),          // Jugador 2
      jugadorActual(pj1),     // Comienza jugando jugador 1
      ganador(nullptr),       // No hay ganador al principio
      modalidad(modalidad),   // Modalidad seleccionada
      juegoCargado(false),    // Indica si se cargó desde archivo
      totalMovimientos(0)     // Movimientos realizados
{}

// Constructor de copia
Juego::Juego(const Juego& otro) {
    modalidad = otro.modalidad;
    totalMovimientos = otro.totalMovimientos;

    // Copiar jugadores
    if (dynamic_cast<JugadorHumano*>(otro.jugador1))
        jugador1 = new JugadorHumano(*static_cast<JugadorHumano*>(otro.jugador1));
    else
        jugador1 = new JugadorMaquina(*static_cast<JugadorMaquina*>(otro.jugador1));

    if (dynamic_cast<JugadorHumano*>(otro.jugador2))
        jugador2 = new JugadorHumano(*static_cast<JugadorHumano*>(otro.jugador2));
    else
        jugador2 = new JugadorMaquina(*static_cast<JugadorMaquina*>(otro.jugador2));

    // Mantener turno
    if (otro.jugadorActual == otro.jugador1) jugadorActual = jugador1;
    else jugadorActual = jugador2;

    ganador = nullptr; // o copiar si ya hay ganador

    tablero = otro.tablero; // Asumiendo que Tablero tiene operador= o constructor de copia
    juegoCargado = otro.juegoCargado;
}

/*
==========================================================
            REALIZAR MOVIMIENTO DE UNA COLUMNA
==========================================================

Intentar colocar una ficha del jugador actual en la columna indicada.

Proceso:
1) Colocar ficha en el tablero (si la columna está llena → falla)
2) Aumentar contador de movimientos
3) Verificar si hay ganador (según modalidad)
4) Si no hay ganador, cambiar el turno al otro jugador

Devuelve:
- true si el movimiento fue válido
- false si no se pudo colocar la ficha
*/
bool Juego::realizarMovimiento(int columna) {

    // 1. Intentar colocar ficha
    if (!tablero.colocarFicha(columna, jugadorActual->getFicha())) {
        std::cout << "Columna llena. Intenta otra.\n";
        return false;
    }

    // 2. Contar movimiento
    totalMovimientos++;

    // 3. Verificar si el jugador actual ganó
    if (modalidad == 1) {
        // Modalidad clásica: gana el primero con 4 en línea
        if (tablero.hay4EnLinea(jugadorActual->getFicha())) {
            ganador = jugadorActual;
            return true;
        }
    }
    else {
        // Modalidad alternativa: gana el que tenga más secuencias
        aplicarReglasModalidad2();
    }

    // 4. Si no ganó, entonces cambiar turno
    cambiarTurno();
    return true;
}

/*
==========================================================
                    CAMBIAR TURNO
==========================================================

Si el jugador actual es el jugador1 → pasa a jugador2.
Si es jugador2 → pasa a jugador1.
*/
void Juego::cambiarTurno() {
    jugadorActual = (jugadorActual == jugador1) ? jugador2 : jugador1;
}

/*
==========================================================
              ¿HAY GANADOR DEL JUEGO?
==========================================================

Devuelve true si la variable 'ganador' NO es nullptr.
*/
bool Juego::hayGanador() const {
    return ganador != nullptr;
}

/*
==========================================================
                ¿EL JUEGO YA TERMINÓ?
==========================================================

Depende de la modalidad:
- Modalidad 1 → termina si alguien gana
- Modalidad 2 → termina cuando el tablero está lleno
*/
bool Juego::juegoTerminado() const {
    if (modalidad == 1)
        return hayGanador();

    // Modalidad 2: tablero lleno = fin de juego
    return tablero.estaLleno();
}



/*
==========================================================
                    GETTERS DEL TABLERO
==========================================================
*/
Tablero& Juego::getTablero() { return tablero; }
const Tablero& Juego::getTablero() const { return tablero; }



/*
==========================================================
                    GETTERS DE JUGADORES
==========================================================
*/
Jugador* Juego::getJugador1() const { return jugador1; }
Jugador* Juego::getJugador2() const { return jugador2; }
Jugador* Juego::getJugadorActual() const { return jugadorActual; }
Jugador* Juego::getGanador() const { return ganador; }


/*
==========================================================
                    GETTER DE MODALIDAD
==========================================================
*/
int Juego::getModalidad() const { return modalidad; }

/*
==========================================================
            APLICAR REGLAS DE LA MODALIDAD 2
==========================================================

Modalidad 2:
- No se busca 4 en línea.
- Se cuentan secuencias válidas del jugador 1 y jugador 2.
- Gana el que tenga más secuencias.

Si empatan → no se asigna ganador (se define al final del juego).
*/
void Juego::aplicarReglasModalidad2() {
    int s1 = tablero.contarSecuencias(jugador1->getFicha());
    int s2 = tablero.contarSecuencias(jugador2->getFicha());

    if (s1 != s2) {
        ganador = (s1 > s2) ? jugador1 : jugador2;
    }
}

/*
==========================================================
                    SETTERS ÚTILES
==========================================================
*/
void Juego::setTurno(Jugador* jugador) { jugadorActual = jugador; }
void Juego::setModalidad(int nueva) { modalidad = nueva; }


/*
==========================================================
        FUNCIONES DE GUARDADO Y CARGA (NO USADAS)
==========================================================

Estas funciones están aquí para cumplir estructura,
pero la lógica real de guardado/carga se hace en GestorArchivos.
*/
void Juego::cargarPartida(const std::string& nombreArchivo) {
    std::cout << "Cargar partida no implementado.\n";
}

void Juego::guardarPartida(const std::string& nombreArchivo) {
    std::cout << "Guardar partida no implementado.\n";
}
