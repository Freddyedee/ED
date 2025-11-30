/*#include "Datos/GestorArchivos.h"
#include <fstream>
#include <filesystem>
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>

bool GestorArchivos::guardarJuego(const Juego& juego, const std::string& nombreArchivo) {

    std::ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para guardar.\n";
        return false;
    }

    // -------------------------------------------
    // Guardar dimensiones del tablero
    // -------------------------------------------
    const Tablero& t = juego.getTablero();
    int filas = t.getFilas();
    int columnas = t.getColumnas();

    archivo << filas << " " << columnas << "\n";

    // -------------------------------------------
    // Guardar modalidad
    // -------------------------------------------
    int modalidad = juego.getModalidad();
    archivo << modalidad << "\n";

    // -------------------------------------------
    // Guardar jugador 1
    // -------------------------------------------
    std::string nombre1 = juego.getJugador1()->getNombre();
    char ficha1 = juego.getJugador1()->getFicha();
    archivo << nombre1 << " " << ficha1 << "\n";

    // -------------------------------------------
    // Guardar jugador 2
    // -------------------------------------------
    std::string nombre2 = juego.getJugador2()->getNombre();
    char ficha2 = juego.getJugador2()->getFicha();
    archivo << nombre2 << " " << ficha2 << "\n";

    // -------------------------------------------
    // Guardar jugador en turno
    // -------------------------------------------
    std::string nombreTurno = juego.getJugadorActual()->getNombre();
    char fichaTurno = juego.getJugadorActual()->getFicha();
    archivo << nombreTurno << " " << fichaTurno << "\n";

    // -------------------------------------------
    // Guardar total de movimientos
    // -------------------------------------------
    int movimientos = juego.getTotalMovimientos();
    archivo << movimientos << "\n";

    // -------------------------------------------
    // Guardar tablero
    // -------------------------------------------
    archivo << "Tablero:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            char celda = t.getCelda(i, j);
            archivo << celda;
        }
        archivo << "\n";
    }

    archivo.close();
    return true;
}


// -------------------------------------------------------------
// Carga el estado completo del juego desde un archivo TXT
// -------------------------------------------------------------
bool GestorArchivos::cargarJuego(Juego& juego, const std::string& nombreArchivo) {

    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para cargar.\n";
        return false;
    }

    // -------------------------------------------
    // Leer dimensiones del tablero
    // -------------------------------------------
    int filas = 0;
    int columnas = 0;
    archivo >> filas;
    archivo >> columnas;

    // -------------------------------------------
    // Leer modalidad
    // -------------------------------------------
    int modalidad = 0;
    archivo >> modalidad;
    juego.setModalidad(modalidad);

    // -------------------------------------------
    // Leer jugador 1
    // -------------------------------------------
    std::string nombre1;
    char ficha1;

    archivo >> nombre1;
    archivo >> ficha1;

    juego.getJugador1()->setNombre(nombre1);
    juego.getJugador1()->setFicha(ficha1);

    // -------------------------------------------
    // Leer jugador 2
    // -------------------------------------------
    std::string nombre2;
    char ficha2;

    archivo >> nombre2;
    archivo >> ficha2;

    juego.getJugador2()->setNombre(nombre2);
    juego.getJugador2()->setFicha(ficha2);

    // -------------------------------------------
    // Leer turno
    // -------------------------------------------
    std::string nombreTurno;
    char fichaTurno;

    archivo >> nombreTurno;
    archivo >> fichaTurno;

    if (fichaTurno == juego.getJugador1()->getFicha()) {
        juego.setTurno(juego.getJugador1());
    } else {
        juego.setTurno(juego.getJugador2());
    }

    // -------------------------------------------
    // Leer tablero
    // -------------------------------------------
    std::string linea;
    getline(archivo, linea); // Limpiar \n pendiente

    Tablero& t = juego.getTablero();

    for (int i = 0; i < filas; i++) {

        getline(archivo, linea);

        for (int j = 0; j < columnas; j++) {

            char celda = linea[j];
            t.setCelda(i, j, celda);
        }
    }

    archivo.close();
    return true;
}
*/









    
