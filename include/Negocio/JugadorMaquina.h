#ifndef JUGADORMAQUINA_H
#define JUGADORMAQUINA_H


#include "Jugador.h"
#include <string>
#include <vector>

using namespace std;

    class JugadorMaquina : public Jugador {
    private:
        char fichaEnemiga;

        int buscarJugadaGanadora(Tablero& t);
        int bloquearEnemigo(Tablero& t);
        int evitarAutoDerrota(Tablero& t);
        vector<int> ordenColumnas(Tablero& t);
        int crearLineaDe3(Tablero& t);
        int tomarCentro(Tablero& t);
        int mejorColumnaSegura(Tablero& t);

        bool jugadaPermiteGanarAlRival(Tablero& t, int col);

    public:
        JugadorMaquina(const std::string& n, char f, char enemigo)
            : Jugador(n, f), fichaEnemiga(enemigo) {}

        int elegirColumna(Tablero& t) override;
};

#endif // JUGADORMAQUINA_H