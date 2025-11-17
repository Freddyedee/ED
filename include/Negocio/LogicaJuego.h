#ifndef LOGICAJUEGO_H
#define LOGICAJUEGO_H

class Tablero;  // Forward declaration
class Jugador;

class LogicaJuego {
private:
    Tablero* tablero;
    Jugador* jugador1;
    Jugador* jugador2;
    Jugador* jugadorActual;
    bool juegoTerminado;

public:
    LogicaJuego();
    ~LogicaJuego();
    
    void inicializarJuego();
    bool hacerMovimiento(int columna);
    bool verificarGanador() const;
    bool esEmpate() const;
    void cambiarTurno();
    Jugador* getJugadorActual() const;
    bool getJuegoTerminado() const;
};

#endif