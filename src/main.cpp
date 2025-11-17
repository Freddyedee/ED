#include <iostream>
#include "Datos/Tablero.h"
#include "Datos/Jugador.h"
#include "Negocio/LogicaJuego.h"

int main() {
    std::cout << "=== JUEGO 4 EN RAYA ===" << std::endl;
    
    // Probar Jugador
    Jugador jugador("Ana", 'X');
    std::cout << "Jugador: " << jugador.getNombre() 
              << " - Ficha: " << jugador.getFicha() << std::endl;
    
    // Probar Lógica del Juego
    LogicaJuego juego;
    juego.inicializarJuego();
    
    std::cout << "Juego inicializado correctamente!" << std::endl;
    
    return 0;
}