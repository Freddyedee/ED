#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H

#include <string>
#include "Negocio/Juego.h"


class GestorArchivos {
    public: 
        bool guardarJuego(const Juego& juego, const std::string& nombreArchivo); 
        bool cargarJuego(Juego& juego, const std::string& nombreArchivo);
}; 

#endif // GESTORARCHIVOS_H