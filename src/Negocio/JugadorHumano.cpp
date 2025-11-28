#include "Negocio/JugadorHumano.h"
#include <iostream>

//
// Constructor de JugadorHumano.
// Llama directamente al constructor de Jugador (clase base)
// para inicializar el nombre y la ficha.
//
JugadorHumano::JugadorHumano(const std::string& nombre, char ficha)
    : Jugador(nombre, ficha) {}


//
// Método que permite al jugador humano elegir la columna.
//
// Se muestra un mensaje indicando de quién es el turno y cuál es su ficha.
// Luego se pide por consola que introduzca el número de columna donde quiere jugar.
// El valor ingresado se devuelve para que el Juego lo procese.
//
// Nota: No se valida aquí si la columna es correcta;
//       esa validación suele hacerse en la lógica del Juego.
//
int JugadorHumano::elegirColumna(Tablero& tablero) {
    int columna;

    std::cout << "\nTurno del jugador: "
              << getNombre() << " (" << getFicha() << ")\n";

    std::cout << "Seleccione una columna: ";
    std::cin >> columna;

    return columna;
}
