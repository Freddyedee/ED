#include "Negocio/JugadorMaquina.h"
#include "Negocio/Jugador.h"
#include <iostream>
#include <string>


// ---------------------------------------------------------
// 1. Revisar si la máquina puede GANAR YA
// ---------------------------------------------------------
int JugadorMaquina::buscarJugadaGanadora(Tablero& t) {
    for (int col = 0; col < t.getColumnas(); col++) {
        if (t.columnaLlena(col)) continue;

        Tablero copia = t;
        copia.colocarFicha(col, ficha);

        if (copia.hay4EnLinea(ficha))
            return col;
    }
    return -1;
}


std::vector<int> JugadorMaquina::ordenColumnas(Tablero& t) {
    vector<int> orden;
    int c = t.getColumnas();
    int centro = c / 2;

    orden.push_back(centro);

    for (int i = 1; i <= centro; i++) {
        if (centro - i >= 0) orden.push_back(centro - i);
        if (centro + i < c)  orden.push_back(centro + i);
    }
    return orden;
}


// ---------------------------------------------------------
// 2. Revisar si el rival puede ganar y BLOQUEAR
// ---------------------------------------------------------
int JugadorMaquina::bloquearEnemigo(Tablero& t) {
    for (int col = 0; col < t.getColumnas(); col++) {
        if (t.columnaLlena(col)) continue;

        Tablero copia = t;
        copia.colocarFicha(col, fichaEnemiga);

        if (copia.hay4EnLinea(fichaEnemiga))
            return col;
    }
    return -1;
}

// ---------------------------------------------------------
// 3. Evitar dejar una jugada ganadora para el rival
// ---------------------------------------------------------
bool JugadorMaquina::jugadaPermiteGanarAlRival(Tablero& t, int col) {
    Tablero copia = t;
    copia.colocarFicha(col, ficha);

    // Luego de nuestra jugada, ¿qué columnas le permitirían ganar?
    for (int c = 0; c < copia.getColumnas(); c++) {
        if (copia.columnaLlena(c)) continue;

        Tablero after = copia;
        after.colocarFicha(c, fichaEnemiga);

        if (after.hay4EnLinea(fichaEnemiga))
            return true;
    }
    return false;
}

// ---------------------------------------------------------
// 4. Crear línea de 3 (amenaza futura)
// ---------------------------------------------------------
int JugadorMaquina::crearLineaDe3(Tablero& t) {
    for (int col = 0; col < t.getColumnas(); col++) {
        if (t.columnaLlena(col)) continue;

        Tablero copia = t;
        copia.colocarFicha(col, ficha);

        if (copia.hay3EnLinea(ficha) && !jugadaPermiteGanarAlRival(t, col))
            return col;
    }
    return -1;
}

// ---------------------------------------------------------
// 5. Tomar el centro
// ---------------------------------------------------------
int JugadorMaquina::tomarCentro(Tablero& t) {
    int centro = t.getColumnas() / 2;
    if (!t.columnaLlena(centro))
        return centro;
    return -1;
}

int JugadorMaquina::columnaAleatoriaValida(Tablero& t) {
    std::vector<int> validas;

    for (int col = 0; col < t.getColumnas(); col++) {
        if (!t.columnaLlena(col)) {
            validas.push_back(col);
        }
    }

    if (validas.empty()) return -1;

    int idx = rand() % validas.size();
    return validas[idx];
}


// ---------------------------------------------------------
// 6. Elegir columna más "segura"
// ---------------------------------------------------------
int JugadorMaquina::mejorColumnaSegura(Tablero& t) {


    //  Si no toca aleatorio, sigue el comportamiento normal
    auto orden = ordenColumnas(t);

    for (int col : orden) {
        if (!t.columnaLlena(col) && !jugadaPermiteGanarAlRival(t, col))
            return col;
    }

    // Si no encontró jugada segura → random
    return columnaAleatoriaValida(t);
}


// ---------------------------------------------------------
// FUNCIÓN PRINCIPAL DE LA IA
// ---------------------------------------------------------
int JugadorMaquina::elegirColumna(Tablero& t) {

    
    // 1. Intentar ganar
    int col = buscarJugadaGanadora(t);
    if (col != -1){
        cout << "buscarJugadaGanadora " << col; 
        return col;
    }
    
    // 2. Bloquear al enemigo
    col = bloquearEnemigo(t);
    if (col != -1){
        cout << "bloquear enemigo " << col; 
        return col;
    }

    // 6. Última opción segura
    if (rand() % 100 < 10) {
        return columnaAleatoriaValida(t);
    }

    // 3. Crear línea de 3
    col = crearLineaDe3(t);
    if (col != -1){
        cout << "crearLineaDe3 " << col; 
        return col;
    }
    
    // 4. Tomar el centro
    col = tomarCentro(t);
    if (col != -1){
        cout << "tomarCentro " << col; 
        return col;
    }
    
    
    // Si no queda nada seguro, jugar la primera disponible
    for (int c = 0; c < t.getColumnas(); c++)
    if (!t.columnaLlena(c))
    return c;

    return 0; // En caso extremo
}
