#include "GestorArchivos.h"
#include <fstream>
#include <iostream>


bool GestorArchivos::guardarJuego(const Juego& juego, const string &nombreArchivo){

    ofstream archivo(nombreArchivo);

    if(!archivo.is_open()){
        cerr << "Error al abrir el archivo para guardar el juego." << endl;
        return false;
    }

    Jugador *jugador1 = juego.getJugadorActual();

   
    // 1. Guardar dimensiones del tablero
    archivo << juego.getTablero().getFilas() << " "
            << juego.getTablero().getColumnas() << "\n";

      // 2. Guardar modalidad
    archivo << juego.getModalidad() << "\n";

     // 3. Guardar jugadores
    archivo << juego.getJugador1()->getNombre() << " "
            << juego.getJugador1()->getFicha() << "\n";

    archivo << juego.getJugador2()->getNombre() << " "
            << juego.getJugador2()->getFicha() << "\n";


     // 4. Guardar ficha del jugador en turno
    archivo << juego.getJugadorActual()->getFicha() << "\n";

    // 5. Guardar contador de movimientos
    archivo << juego.getTotalMovimientos() << "\n";


    //guardado del tablero celda por celda

      // 6. Guardar el tablero
    const Tablero& t = juego.getTablero();

    for (int i = 0; i < t.getFilas(); i++) {
        for (int j = 0; j < t.getColumnas(); j++) {
            archivo << t.getCelda(i, j);
        }
        archivo << "\n";
    }

    archivo.close();
    return true;
}


// -------------------------------------------------------------
// Carga el estado completo del juego desde un archivo TXT
// -------------------------------------------------------------

bool GestorArchivos::cargarJuego(Juego& juego, const string& nombreArchivo){


    ifstream archivo(nombreArchivo);

    if(!archivo.is_open()){
        cerr << "Error al abrir el archivo para cargar el juego." << endl;
        return false;
    }

    int filas, columnas; 
    archivo >> filas >> columnas;

    int modalidad;
    archivo >> modalidad;
    juego.setModelidad(modalidad);


    // Cargar datos de jugadores
    string nombreJugador1, nombreJugador2;
    char fichaJugador1, fichaJugador2;

    archivo >> nombreJugador1 >> fichaJugador1;
    archivo >> nombreJugador2 >> fichaJugador2;

    juego.getJugador1()->setNombre(nombreJugador1);
    juego.getJugador1()->setFicha(fichaJugador1);

    juego.getJugador2()->setNombre(nombreJugador2);
    juego.getJugador2()->setFicha(fichaJugador2);

    //Turno actual
    char fichaTurno; 
    archivo >> fichaTurno; 

    if(juego.getJugador1()->getFicha() == fichaTurno){
        juego.setTurno(juego.getJugador1());
    }
    else{
        juego.setTurno(juego.getJugador2());
    }

    // --- Movimientos ---
    int movimientos;
    archivo >> movimientos;
    juego.reiniciarMovimientos();
    
    Tablero &tableroCopia = juego.getTablero(); 
    string linea; 
    getline(archivo, linea); // Limpiar el salto de línea restante

    for (int i = 0; i < filas; i++){
        getline(archivo, linea);
        for (int j = 0; j < columnas; j++){
           tableroCopia.setCelda(i, j, linea[j]);
        }
    }

    archivoEntrada.close();
    return true;

}

    








    
