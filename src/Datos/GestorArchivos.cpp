#include "GestorArchivos.h"
#include <fstream>
#include <iostream>


bool GestorArchivos::guardarJuego(const Juego& juego, const string &nombreArchivo){

    ofstream archivoSalida(nombreArchivo, ios::out);

    if(!archivoSalida.is_open()){
        cerr << "Error al abrir el archivo para guardar el juego." << endl;
        return false;
    }

    Jugador *jugador1 = juego.getJugadorActual();

    archivoSalida   << juego.getTablero().getFilas() << " "
                    << juego.getTablero().getColumnas() << endl;
    
    archivoSalida << juego.getModalidad() << endl;

    archivoSalida << juego.getJugador1()->getNombre() << " "
                  << juego.getJugador1()->getFicha() << "\n";

    archivoSalida << juego.getJugador2()->getNombre() << " "
                  << juego.getJugador2()->getFicha() << "\n";


    archivoSalida << juego.getJugadorActual()->getFicha() << "\n";

    //guardado del tablero celda por celda

    Tablero tableroCopia = juego.getTablero();

    for (int i = 0; i < tableroCopia.getFilas; i++)
    {
        for (int j = 0; j < tableroCopia.getColumnas; j++)
        {
            archivoSalida << tableroCopia.getCelda(i, j);
        }

        archivoSalida << "\n";
        
    }

    archivoSalida.close();
    return true;

}


// -------------------------------------------------------------
// Carga el estado completo del juego desde un archivo TXT
// -------------------------------------------------------------

bool GestorArchivos::cargarJuego(Juego& juego, const string& nombreArchivo){


    ifstream nombreArchivo(nombreArchivo);

    if(!archivoEntrada.is_open()){
        return false;
    }

    int filas, columnas; 
    archivoEntrada >> filas >> columnas;

    int modalidad;
    archivoEntrada >> modalidad;
    juego.setModelidad(modalidad);


    // Cargar datos de jugadores

    string nombreJugador1, nombreJugador2;
    char fichaJ1, fichaJ2;

    archivo >> nombreJugador1 >> fichaJ1;
    archivo >> nombreJugador2 >> fichaJ2;

    juego.getJugador1()->setNombre(nombreJugador1);
    juego.getJugador1()->setFicha(fichaJ1);

    juego.getJugador2()->setNombre(nombreJugador2);
    juego.getJugador2()->setFicha(fichaJ2);

    char fichaTurno; 
    archivo >> fichaTurno; 

    if(juego.getJugador1()->getFicha() == fichaTurno){
        juego.setTurno(juego.getJugador1());
    }
    else{
        juego.setTurno(juego.getJugador2());
    }

    Tablero& tableroCopia = juego.getTablero();

    string linea; 
    getline(archivoEntrada, linea); // Limpiar el salto de línea restante

    for (int i = 0; i < filas; i++){
        getline(archivoEntrada, linea);
        for (int j = 0; j < columnas; j++){
           
            char c = linea[i]; 
            tableroCopia.setCelda(i, j, c);
        }
    }

    archivoEntrada.close();
    return true;

}

    








    
