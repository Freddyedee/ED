#ifndef JUGADORHUMANO_H
#define JUGADORHUMANO_H

#include "Jugador.h"
#include <string>

//
// Clase JugadorHumano
// -------------------
// Representa a un jugador controlado por una persona.
// Hereda de la clase base Jugador, por lo que mantiene
// atributos como nombre y ficha, y también implementa el
// método abstracto elegirColumna().
//
class JugadorHumano : public Jugador {  // Herencia desde Jugador

public:

    // -----------------------------------------------------------
    // Constructor
    // Recibe el nombre del jugador y la ficha ('X' o 'O')
    // y se los pasa al constructor de la clase base (Jugador).
    // -----------------------------------------------------------
    JugadorHumano(const std::string& nombre, char ficha);

    // -----------------------------------------------------------
    // Implementación del método abstracto de la clase Jugador.
    //
    // En el caso del jugador humano, simplemente se pide por
    // consola que ingrese el número de columna donde desea jugar.
    //
    // Devuelve un entero que representa la columna elegida.
    // -----------------------------------------------------------
    int elegirColumna(Tablero& tablero) override;
};

#endif // JUGADORHUMANO_H
