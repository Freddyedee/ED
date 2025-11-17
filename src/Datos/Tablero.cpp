#include "Datos/Tablero.h"
#include <iostream>

Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
    // Crear matriz dinámica
    matriz = new char*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new char[columnas];
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = ' ';  // Inicializar vacío
        }
    }
    std::cout << "Tablero " << filas << "x" << columnas << " creado" << std::endl;
}

// ¡AGREGAR ESTE DESTRUCTOR!
Tablero::~Tablero() {
    // Liberar memoria de la matriz
    if (matriz) {
        for (int i = 0; i < filas; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }
    std::cout << "Tablero destruido" << std::endl;
}

bool Tablero::colocarFicha(int columna, char ficha) {
    // Implementación básica
    if (columna < 0 || columna >= columnas) return false;
    
    for (int i = filas - 1; i >= 0; i--) {
        if (matriz[i][columna] == ' ') {
            matriz[i][columna] = ficha;
            return true;
        }
    }
    return false;  // Columna llena
}

bool Tablero::columnaLlena(int columna) const {
    if (columna < 0 || columna >= columnas) return true;
    return matriz[0][columna] != ' ';
}