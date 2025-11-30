#ifndef GESTORMEMORIA_H
#define GESTORMEMORIA_H

#include "Juego.h"
#include <iostream>

class GestorMemoria {
private:
    Juego* slots[5];  // Array de 5 slots para guardar partidas

public:
    GestorMemoria();
    ~GestorMemoria();
    bool guardarJuego(Juego* juego, int slot);

    Juego* cargarJuego(int slot);
    void listarSlots() const;
};

// Declaración de la instancia global
extern GestorMemoria gestorMemoria;

#endif
