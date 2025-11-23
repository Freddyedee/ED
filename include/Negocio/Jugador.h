#ifndef JUGADOR_H
#define JUGADOR_H

<<<<<<< HEAD
#include <string>
#include <vector>

using namespace std; 

class Jugador
{
private:
    int score;
    string nombre;
    bool color;

public:
    virtual void movimiento() = 0;
};

class JugadorHumano : public Jugador{
    public:
    void movimiento() override;
};

class JugadorIA : public Jugador{
    public:
    void movimiento() override;
    int revisar4Personal();
};

#endif
=======

#include <string>
#include "Tablero.h" //inclusion para usar la clase Tablero

using namespace std; 

class Jugador{

    Tablero tablero;
    private :
        string nombre;
        char ficha; 

        public : 

        Jugador(string nombre, char ficha); 

        string getNombre(); 
        char getFicha(); 
        void setNombre(string nombre); 
        void setFicha(char ficha);

        virtual int elegirColumna(Tablero& tablero)=0; //convierte a una clase en abstracta

}; 









#endif // JUGADOR_H
>>>>>>> 68452347eb23b311314e2cb13fd31c7108c3d516
