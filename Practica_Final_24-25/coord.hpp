#ifndef _COORD_HPP
#define _COORD_HPP

#include <iostream>

// La classe "coord" guarda una parella de coordenades enteres en el pla 2D

class coord {
  public:
    // Com que x i y són atributs públics, són accessibles
    // des del programa. Per exemple:  coord p;  p.x=3;
    int x, y;

    // La constructora "coord" permet declarar
    // variables del tipus, per exemple:  coord p;
    coord();

    // La constructora "coord(int,int)" permet declarar i
    // inicialitzar variables del tipus, per exemple: coord p(3,5);
    // i també permet construir objectes del tipus "coord" sense
    // declarar cap variable, per exemple:  if (lab.entrada() == coord(4,5))...
    coord(int x, int y);

    // Suma a la coordenada actual el parell de coordenades donat,
    // per exemple:  coord(3,5) + coord(1,-2) donaria la coordenada (4,3)
    coord operator+(const coord &c) const;

    // Igualtat entre dues coordenades,
    // per exemple:  coord(3,5) == coord(1,-2)
    bool operator==(const coord &c) const;

    // metode de escritura
    friend std::ostream &operator<<(std::ostream &os, const coord &c);
};

#endif