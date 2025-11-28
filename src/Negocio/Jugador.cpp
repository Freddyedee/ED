#include "Negocio/Jugador.h"

//
// Constructor de Jugador.
// Recibe un nombre y una ficha y los asigna a sus variables internas.
//
Jugador::Jugador(const std::string& nombre, char ficha)
    : nombre(nombre), ficha(ficha) {}

//
// Devuelve el nombre del jugador.
//
std::string Jugador::getNombre() const {
    return nombre;
}

//
// Devuelve la ficha del jugador.
//
char Jugador::getFicha() const {
    return ficha;
}

//
// Cambia el nombre del jugador.
//
void Jugador::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

//
// Cambia la ficha del jugador.
//
void Jugador::setFicha(char ficha) {
    this->ficha = ficha;
}
