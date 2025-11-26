#include "Negocio/Tablero.h"
#include <iostream>
#include <vector>

using namespace std;

// =========================
// Constructor
// =========================
Tablero::Tablero(int filas, int columnas) 
    : filas(filas), columnas(columnas) 
{
    // Inicializa la matriz con espacios vacíos
    matriz = vector<vector<char>>(filas, vector<char>(columnas, ' '));
}

// =========================
// Métodos básicos
// =========================

// Imprime el tablero por consola
void Tablero::imprimirTablero() const {
    for (int i = 0; i < filas; i++) {
        cout << "|";
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " |"; 
        }
        cout << "\n";
    }

    // Imprime números de columna
    for (int j = 0; j < columnas; j++) {
        cout << " " << j << " ";
    }
    cout << "\n";
}

// Coloca una ficha en la columna indicada (cae hasta la fila más baja disponible)
// Devuelve true si la ficha se colocó, false si la columna está llena o inválida
bool Tablero::colocarFicha(int columna, char ficha) {
    if (columna < 0 || columna >= columnas) return false;

    for (int i = filas - 1; i >= 0; i--) {
        if (matriz[i][columna] == ' ') {
            matriz[i][columna] = ficha;
            return true;
        }
    }

    return false; // Columna llena
}

// Verifica si el tablero está completamente lleno
bool Tablero::estaLleno() const {
    for (int j = 0; j < columnas; j++) {
        if (matriz[0][j] == ' ') return false;
    }
    return true;
}

// =========================
// Verificación de líneas (Modalidad 1)
// =========================

// Verifica si el jugador tiene 4 en línea en cualquier dirección
bool Tablero::hay4EnLinea(char ficha) const {
    return hay4EnLineaHorizontal(ficha) || 
           hay4EnLineaVertical(ficha) || 
           hay4EnLineaDiagonal(ficha);
}

// Horizontal
bool Tablero::hay4EnLineaHorizontal(char ficha) const {
    return contarHorizontales(ficha) > 0;
}

// Vertical
bool Tablero::hay4EnLineaVertical(char ficha) const {
    return contarVerticales(ficha) > 0;
}

// Diagonal
bool Tablero::hay4EnLineaDiagonal(char ficha) const {
    return (contarDiagonalesPositivas(ficha) + contarDiagonalesNegativas(ficha)) > 0;
}

// =========================
// Conteo de secuencias (Modalidad 2)
// =========================

// Devuelve el total de secuencias de 4 del jugador en cualquier dirección
int Tablero::contarSecuencias(char ficha) const {
    return contarHorizontales(ficha)
         + contarVerticales(ficha)
         + contarDiagonalesPositivas(ficha)
         + contarDiagonalesNegativas(ficha);
}

// =========================
// Contadores privados
// =========================

// Horizontal
int Tablero::contarHorizontales(char ficha) const {
    int total = 0;

    for (int i = 0; i < filas; i++) {
        int contador = 0;
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] == ficha) {
                contador++;
                if (contador == 4) {
                    total++;
                    contador = 0; // evita superposición
                }
            } else {
                contador = 0;
            }
        }
    }

    return total;
}

// Vertical
int Tablero::contarVerticales(char ficha) const {
    int total = 0;

    for (int j = 0; j < columnas; j++) {
        int contador = 0;
        for (int i = 0; i < filas; i++) {
            if (matriz[i][j] == ficha) {
                contador++;
                if (contador == 4) {
                    total++;
                    contador = 0;
                }
            } else {
                contador = 0;
            }
        }
    }

    return total;
}

// Diagonales positivas (de arriba-izquierda a abajo-derecha)
int Tablero::contarDiagonalesPositivas(char ficha) const {
    int total = 0;

    for (int i = 0; i < filas - 3; i++) {
        for (int j = 0; j < columnas - 3; j++) {
            if (matriz[i][j] == ficha &&
                matriz[i+1][j+1] == ficha &&
                matriz[i+2][j+2] == ficha &&
                matriz[i+3][j+3] == ficha) 
            {
                total++;
            }
        }
    }

    return total;
}

// Diagonales negativas (de arriba-derecha a abajo-izquierda)
int Tablero::contarDiagonalesNegativas(char ficha) const {
    int total = 0;

    for (int i = 0; i < filas - 3; i++) {
        for (int j = 3; j < columnas; j++) {
            if (matriz[i][j] == ficha &&
                matriz[i+1][j-1] == ficha &&
                matriz[i+2][j-2] == ficha &&
                matriz[i+3][j-3] == ficha) 
            {
                total++;
            }
        }
    }

    return total;
}

// =========================
// Getters y Setters
// =========================

char Tablero::getCelda(int fila, int columna) const {
    return matriz[fila][columna];
}

void Tablero::setCelda(int fila, int columna, char valor) {
    matriz[fila][columna] = valor;
}
