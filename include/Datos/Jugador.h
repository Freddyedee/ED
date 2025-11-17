#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

class Jugador {
private:
    std::string nombre;
    char ficha;  // 'X' o 'O'

public:
    Jugador(const std::string& nombre, char ficha);
    
    // Getters
    std::string getNombre() const;
    char getFicha() const;
    
    // Setters
    void setNombre(const std::string& nombre);
    void setFicha(char ficha);
};

#endif