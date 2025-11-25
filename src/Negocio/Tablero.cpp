#include <iostream>
#include "Negocio/Tablero.h"

using namespace std; 

Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
    
    matriz = vector<vector<char>>(filas, vector<char>(columnas, ' '));

}


void Tablero::imprimirTablero() const{
  
    for (int i = 0; i < filas; i++){
            cout << "|";
            for (int j = 0; j < columnas; j++){
                cout << matriz[i][j] << " |"; 
        }
        cout << "\n";
    }


    for (int j = 0; j < columnas; j++)
    {
        cout << " " << j << " ";

    }
    cout << "\n";
    
}

int Tablero::getColumnas() {
    return columnas;
}

int Tablero::getFilas()  {
    return filas;
}

bool Tablero::colocarFicha(int columna, char ficha){
        
    if (columna < 0 || columna >= columnas) { return false; }
    
    for (int i = filas - 1; i >=0; i--){
        
        if (matriz[i][columna] ==  ' ' ){
            matriz[i][columna] = ficha; 
            return true; 
        }
        
    }
        
    return false;
}

bool Tablero::estaLleno() const{
    
    for (int j = 0; j < columnas; j++){
        
        if(matriz[0][j] == ' '){
            return false; 
        }
    }
    return true;
    
}

bool Tablero::hay4EnLinea(char ficha) const{
    return hay4EnLineaHorizontal(ficha) || 
    hay4EnLineaVertical(ficha) || 
    hay4EnLineaDiagonal(ficha);
}


bool Tablero::hay4EnLineaHorizontal(char ficha) const {
    
    for (int i = 0; i < filas; i++) {
        int contador = 0; 
        
        for (int j = 0; j < columnas; j++){
            
            if(matriz[i][j] == ficha){
                contador+=1; 
            }else{
                contador = 0; 
            }

            if(contador == 4){
                return true; 
            }
        }
        
    }
    return false; 
}

bool Tablero::hay4EnLineaVertical(char ficha) const{
    
    for (int j = 0; j < columnas; j++){
        int contador = 0; 
        for (int i = 0; i < filas; i++){
            
            if(matriz[i][j] == ficha){
                contador+=1;
            }else{
                contador = 0; 
            }

            if (contador == 4){
                return true; 
            }
        }
    }

    return false; 
}

bool Tablero::hay4EnLineaDiagonal(char ficha) const{

    /*
    Diagonal Pendiente negativa \
    */

   for (int i = 0; i < (filas-3); i++){
    for (int j = 0; j < (columnas-3); j++){
        
        if( matriz[i][j] == ficha && 
            matriz[i+1][j+1] == ficha && 
            matriz [i+2][j+2] == ficha && 
            matriz[i+3][j+3] == ficha){
            return true; 

        }
    }
   }

    /*
    Diagonal Pendiente positiva \
    */

    for (int i = 0; i < filas-3; i++){
        for (int j = 3; j < columnas; j++)
        {
             if( matriz[i][j] == ficha && 
                matriz[i+1][j-1] == ficha &&
                matriz[i+2][j-2] == ficha &&
                matriz[i+3][j-3] == ficha) {
                    return true;
                }
        }
        
    }
   
   

    return false; 
}

bool Tablero::columnaLlena(int columna) const {

    if (columna < 0 || columna >= columnas) { 
        return true; 
    }

    return matriz[0][columna] != ' ';
}

bool Tablero::hay3EnLinea(char ficha) const {
    return hay3Horizontal(ficha) ||
           hay3Vertical(ficha) ||
           hay3Diagonal(ficha);
}

bool Tablero::hay3Horizontal(char ficha) const {

    for (int i = 0; i < filas; i++) {
        int contador = 0;

        for (int j = 0; j < columnas; j++) {

            if (matriz[i][j] == ficha) {
                contador++;
            } else {
                contador = 0;
            }

            if (contador == 3) {
                return true;
            }
        }
    }

    return false;
}

bool Tablero::hay3Vertical(char ficha) const {

    for (int j = 0; j < columnas; j++) {
        int contador = 0;

        for (int i = 0; i < filas; i++) {

            if (matriz[i][j] == ficha) {
                contador++;
            } else {
                contador = 0;
            }

            if (contador == 3) {
                return true;
            }
        }
    }

    return false;
}

bool Tablero::hay3Diagonal(char ficha) const {

    /*
    Diagonal \ (pendiente positiva)
    */
    for (int i = 0; i < filas - 2; i++) {
        for (int j = 0; j < columnas - 2; j++) {

            if (matriz[i][j] == ficha &&
                matriz[i+1][j+1] == ficha &&
                matriz[i+2][j+2] == ficha) {
                    return true;
            }
        }
    }

    /*
    Diagonal / (pendiente negativa)
    */
    for (int i = 2; i < filas; i++) {
        for (int j = 0; j < columnas - 2; j++) {

            if (matriz[i][j] == ficha &&
                matriz[i-1][j+1] == ficha &&
                matriz[i-2][j+2] == ficha) {
                    return true;
            }
        }
    }

    return false;
}

bool Tablero::esPosicionSegura(int columna, char fichaJugador) const {

    if (columnaLlena(columna)) {
        return false;
    }

    char fichaOponente = (fichaJugador == 'X' ? 'O' : 'X');

    // Copia del tablero
    Tablero copia = *this;
    copia.colocarFicha(columna, fichaJugador);

    // Probar todas las columnas posibles del oponente
    for (int col = 0; col < columnas; col++) {

        if (!copia.columnaLlena(col)) {

            Tablero copia2 = copia;
            copia2.colocarFicha(col, fichaOponente);

            if (copia2.hay4EnLinea(fichaOponente)) {
                return false;   // el oponente podría ganar
            }
        }
    }

    return true; // no da victoria inmediata al rival
}