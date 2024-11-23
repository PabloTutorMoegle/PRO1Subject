#include <iostream>
#include "direccio.hpp"

using namespace std;

// Crea una direcció nova, amb el primer valor de la llista.
direccio::direccio()
{
    d = NORD;
}

// Veure si el valor de la direcció és el del final de la llista.
bool direccio::is_stop() const
{
    return d == STOP;
}

// Canvia el valor de la direcció, posant-li el primer de la llista.
const direccio& direccio::init()
{
    d = NORD;
}

// Canvia el valor de la direcció pel següent de la llista.
// Permet usar instruccions "d++" (on d és de tipus direccio).
const direccio& direccio::operator++()
{
    d = static_cast<dirs>((d + 1) % 4);
}

// Obté la coordenada de components x,y que significa un moviment en
// aquesta direcció en el pla 2D de la pantalla, o sigui amb aquest criteri:
// * La primera component (x) indica la fila i creix de dalt a baix
// * La segona component (y) indica la columna i creix d'esquerra a dreta
// per exemple:  NORD -> (-1,0), EST -> (0, 1)
coord direccio::despl() const
{
    switch (d)
    {
    case NORD:
        return coord(-1, 0);
    case EST:
        return coord(0, 1);
    case SUD:
        return coord(1, 0);
    case OEST:
        return coord(0, -1);
    }
}

// Obtenir un string amb el nom de la direcció.
// Aquest mètode és útil per fer debugging.
string direccio::nom() const
{
    switch (d)
    {
    case NORD:
        return "NORD";
    case EST:
        return "EST";
    case SUD:
        return "SUD";
    case OEST:
        return "OEST";
    }
}