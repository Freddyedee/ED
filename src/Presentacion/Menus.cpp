#include "Presentacion/Menus.h"
#include <iostream>

void mostrarMenuPrincipal() {
    std::cout << "\n========== MENU PRINCIPAL ==========\n";
    std::cout << "1. Iniciar nuevo juego\n";
    std::cout << "2. Cargar juego desde archivo\n";
    std::cout << "3. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

void mostrarMenuJuego() {
    std::cout << "\n========== MENU DEL JUEGO ==========\n";
    std::cout << "1. Hacer un movimiento\n";
    std::cout << "2. Mostrar tablero\n";
    std::cout << "3. Guardar partida\n";
    std::cout << "4. Volver al menu principal\n";
    std::cout << "Seleccione una opcion: ";
}

void mostrarMenuTipoPartida() {
    std::cout << "\n======= SELECCIONAR TIPO DE PARTIDA =======\n";
    std::cout << "1. Jugador vs Jugador\n";
    std::cout << "2. Jugador vs IA\n";
    std::cout << "3. IA vs IA\n";
    std::cout << "Seleccione una opcion: ";
}

int pedirModalidad() {
    int modalidad;
    std::cout << "\nSeleccione modalidad:\n";
    std::cout << "1. Modo clasico (4 en linea)\n";
    std::cout << "2. Modo puntaje\n";
    std::cout << "Opcion: ";
    std::cin >> modalidad;
    return modalidad;
}

