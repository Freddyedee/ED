#ifndef TABLERO_H
#define TABLERO_H

#include <string>
#include <vector>

using namespace std; 

class Tablero{

    private:
        int filas; 
        int columnas;
        vector<vector<char>> matriz;

     
    public: 

        //Constructor
        Tablero(int filas = 6, int columnas = 7);
        bool colocarFicha(int columna, char ficha);
        bool hay4EnLinea(char ficha) const;
        bool estaLleno() const;
        void imprimirTablero() const;
        
        
        //Metodos (getters y setters)

        void setFilas(int filas);
        int getFilas();

        void setColumnas(int columnas);
        int getColumnas();

    private:
        bool hay4EnLineaHorizontal(char ficha) const;
        bool hay4EnLineaVertical(char ficha) const;
        bool hay4EnLineaDiagonal(char ficha) const;

};



#endif