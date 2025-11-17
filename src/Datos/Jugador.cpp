#include "Datos/Jugador.h"

//Implementación de la clase Jugador

Jugador::Jugador(const std::string& nombre, char ficha) 
    : nombre(nombre), ficha(ficha) {
}

std::string Jugador::getNombre() const {
    return nombre;
}

char Jugador::getFicha() const {
    return ficha;
}

void Jugador::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Jugador::setFicha(char ficha) {
    this->ficha = ficha;
}