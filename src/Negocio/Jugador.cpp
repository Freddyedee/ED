#include "Jugador.h"

// Constructor
Jugador::Jugador(const std::string& nombre, char ficha)
    : nombre(nombre), ficha(ficha) {}

// Getters
std::string Jugador::getNombre() const {
    return nombre;
}

char Jugador::getFicha() const {
    return ficha;
}

// Setters
void Jugador::setNombre(const std::string& n) {
    nombre = n;
}

void Jugador::setFicha(char f) {
    ficha = f;
}
