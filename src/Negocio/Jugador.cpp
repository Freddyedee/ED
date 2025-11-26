<<<<<<< HEAD
#include "Jugador.h"
=======
<<<<<<< HEAD
#include <iostream>
#include "Negocio/Jugador.h"

using namespace std;
=======
#include "Negocio/Jugador.h"
#include <String>
>>>>>>> d309bf43f6dfcab0bcc5a1aba00d0a7813a5ab10

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
>>>>>>> 68452347eb23b311314e2cb13fd31c7108c3d516
