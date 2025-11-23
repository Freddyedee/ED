<<<<<<< HEAD
#include <iostream>
#include "Negocio/Jugador.h"

using namespace std;
=======
#include "Negocio/Jugador.h"
#include <String>

using namespace std;

Jugador::Jugador(string nombre, char ficha) : nombre(nombre), ficha(ficha){

}

string Jugador::getNombre(){
    return this->nombre; 
}

char Jugador::getFicha(){
    return this->ficha; 
}
>>>>>>> 68452347eb23b311314e2cb13fd31c7108c3d516
