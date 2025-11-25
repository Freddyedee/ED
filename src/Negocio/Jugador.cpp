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
