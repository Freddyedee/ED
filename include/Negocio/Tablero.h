#ifndef TABLERO_H
#define TABLERO_H

#include <vector>

// Clase que representa el tablero del juego 4 en línea
class Tablero {
private:
    int filas;  // Número de filas del tablero
    int columnas; // Número de columnas del tablero
    std::vector<std::vector<char>> matriz; // Matriz que contiene las fichas (' ' vacío, 'X', 'O', etc.)

public:
    // =========================
    // Constructor
    // =========================
    Tablero(int filas = 6, int columnas = 7);

    // =========================
    // Métodos básicos
    // =========================

    // Imprime el tablero por consola
    void imprimirTablero() const;

    // Coloca una ficha en la columna indicada
    // Devuelve true si se colocó, false si la columna está llena o es inválida
    bool colocarFicha(int columna, char ficha);

    // Verifica si el tablero está lleno
    bool estaLleno() const;

    // =========================
    // Getters y Setters
    // =========================
    char getCelda(int fila, int columna) const;
    void setCelda(int fila, int columna, char valor);

    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }

    // =========================
    // Modalidad 1 (4 en línea)
    // =========================

    // Verifica si el jugador tiene 4 fichas en línea en cualquier dirección
    bool hay4EnLinea(char ficha) const;

private:
    // =========================
    // Modalidad 2 (conteo de secuencias)
    // =========================

public:
    // Devuelve el total de secuencias de 4 del jugador en cualquier dirección
    int contarSecuencias(char ficha) const;

private:
    // Contadores privados por dirección
    int contarHorizontales(char ficha) const;
    int contarVerticales(char ficha) const;
    int contarDiagonalesPositivas(char ficha) const;
    int contarDiagonalesNegativas(char ficha) const;
};

#endif // TABLERO_H
