#include "Negocio/GestorMemoria.h"
#include <iostream>

GestorMemoria gestorMemoria; // Definición de la instancia global


GestorMemoria::GestorMemoria() {
    for (int i = 0; i < 5; ++i)
        slots[i] = nullptr;
}

GestorMemoria::~GestorMemoria() {
    for (int i = 0; i < 5; ++i)
        delete slots[i];
}

bool GestorMemoria::guardarJuego(Juego* juego, int slot) {
    if (slot < 0 || slot >= 5) return false;
    delete slots[slot];
    slots[slot] = new Juego(*juego); // Guardar copia profunda
    std::cout << "Juego guardado en slot " << slot << ".\n";
    return true;
}

Juego* GestorMemoria::cargarJuego(int slot) {
    if (slot < 0 || slot >= 5) {
        std::cout << "Slot invalido.\n";
        return nullptr;
    }
    if (slots[slot] == nullptr) {
        std::cout << "Slot vacio.\n";
        return nullptr;
    }
    return slots[slot];
}

void GestorMemoria::listarSlots() const {
    std::cout << "Estado de slots:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Slot " << i << ": "
                  << (slots[i] ? "OCUPADO" : "VACIO") << "\n";
    }
}