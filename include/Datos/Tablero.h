#ifndef TABLERO_H
#define TABLERO_H

class Tablero {
private:
    int filas;
    int columnas;
    char** matriz;
    
public:
    Tablero(int filas, int columnas);
    ~Tablero();  // ¡AGREGAR ESTO!
    
    bool colocarFicha(int columna, char ficha);
    bool columnaLlena(int columna) const;
    // ... más métodos
};

#endif