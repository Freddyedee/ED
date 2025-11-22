#ifndef JUGADOR_H
#define JUGADOR_H

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