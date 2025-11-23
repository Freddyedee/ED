#ifndef JUGADORHUMANO_H
#define JUGADORHUMANO_H


#include "Jugador.h"
#include <string>

using namespace std;

    class JugadorHumano : public Jugador{ //herencia hacia jugador humano de Jugador


        public: 

        JugadorHumano(string nombre, char ficha); //constructor
        
       int elegirColumna(Tablero& tablero) override; //implementacion del metodo abstracto. 

    };

#endif // JUGADORHUMANO_H