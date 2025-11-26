#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Tablero.h"

class Jugador {

private:
    std::string nombre;
    char ficha;

public:
    // Constructor
    Jugador(const std::string& nombre, char ficha);

    // Destructor virtual obligatorio
    virtual ~Jugador() = default;

    // Getters
    std::string getNombre() const;
    char getFicha() const;

    // Setters
    void setNombre(const std::string& nombre);
    void setFicha(char ficha);

    // Método abstracto
    virtual int elegirColumna(Tablero& tablero) = 0;
};

#endif // JUGADOR_H

