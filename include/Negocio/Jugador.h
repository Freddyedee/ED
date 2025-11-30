#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Tablero.h"

//
// Clase base abstracta que representa a un jugador del juego.
// Puede ser un jugador humano, una IA u otro tipo de jugador,
// ya que la clase define la interfaz común para todos.
//

class Jugador {

private:
    

public:
    std::string nombre; 
    // Nombre del jugador. Se usa para mostrar mensajes,
    // identificar a quién le toca el turno y guardar partidas.

    char ficha;          
    // Letra que representa la ficha del jugador (por ejemplo: 'X' o 'O').
    // Esta letra será colocada en el tablero por ese jugador.


    // -----------------------------------------------------------
    // Constructor del jugador.
    // Recibe un nombre y una ficha con la que jugará.
    // -----------------------------------------------------------
    Jugador(const std::string& nombre, char ficha);


    // Destructor virtual para permitir herencia correcta.
    // Obliga a que las clases derivadas destruyan recursos de manera segura.
    virtual ~Jugador() = default;


    // --- GETTERS ---

    std::string getNombre() const; 
    // Devuelve el nombre del jugador.

    char getFicha() const; 
    // Devuelve la ficha del jugador ('X', 'O', etc).


    // --- SETTERS ---

    void setNombre(const std::string& nombre);
    // Cambia el nombre del jugador.

    void setFicha(char ficha);
    // Cambia la ficha del jugador.


    // -----------------------------------------------------------
    // Método abstracto que debe implementar cualquier clase 
    // derivada (por ejemplo JugadorHumano, JugadorIA).
    //
    // Debe devolver la columna donde el jugador desea colocar
    // su ficha. El tablero se pasa por referencia para que el 
    // jugador pueda analizarlo y decidir una jugada.
    // -----------------------------------------------------------
    virtual int elegirColumna(Tablero& tablero) = 0;
};

#endif // JUGADOR_H
