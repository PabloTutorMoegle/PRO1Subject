#include <iostream> 
#include "coord.hpp"

using namespace std;

// La constructora "coord" permet declarar
// variables del tipus, per exemple:  coord p;
coord::coord()
{
    x = 0;
    y = 0;
}

// La constructora "coord(int,int)" permet declarar i
// inicialitzar variables del tipus, per exemple: coord p(3,5);
// i també permet construir objectes del tipus "coord" sense
// declarar cap variable, per exemple:  if (lab.entrada() == coord(4,5))...
coord::coord(int x, int y)
{
    this->x = x;
    this->y = y;
}

// Suma a la coordenada actual el parell de coordenades donat,
// per exemple:  coord(3,5) + coord(1,-2) donaria la coordenada (4,3)
coord coord::operator+(const coord &c) const
{
    coord z;
    z.x = x + c.x;
    z.y = y + c.y;
    return z;
}

// Igualtat entre dues coordenades,
// per exemple:  coord(3,5) == coord(1,-2)
bool coord::operator==(const coord &c) const
{
    return x == c.x && y == c.y;
}

//operador de <
bool coord::operator<(const coord &c) const
{
    if (x != c.x) return x < c.x;
    return y < c.y;
}

ostream &operator<<(ostream &os, const coord &c)
{
    os << "(" << c.x << "," << c.y << ")";
    return os;
}