#ifndef JUGADORHUMANO_H
#define JUGADORHUMANO_H

#include "Jugador.h"
#include <string>

    class JugadorHumano : public Jugador{ //herencia hacia jugador humano de Jugador


        public: 

        JugadorHumano(const std::string& nombre, char ficha); //constructor
        
       int elegirColumna(Tablero& tablero) override; //implementacion del metodo abstracto. 

    };

#endif // JUGADORHUMANO_H