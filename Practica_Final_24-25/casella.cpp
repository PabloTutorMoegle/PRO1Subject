#include <iostream>
#include "casella.hpp"

using namespace std;

// Crea una casella buida, amb valor OBSTACLE, no visitada, direcció inicial i
// bateria a zero.
casella::casella()
{
    cont = LLIURE;
    visitada = false;
    next = 'N';
    bat = 0;
}

// Consulta si la casella és una entrada.
bool casella::es_entrada() const
{
    return cont == ENTRADA;
}
// Consulta si la casella és una sortida.
bool casella::es_sortida() const
{
    return cont == SORTIDA;
}
// Consulta si la casella és un obstacle.
bool casella::es_obstacle() const
{
    return cont == OBSTACLE;
}
// Consulta si la casella està marcada com visitada.
bool casella::es_visitada() const
{
    return visitada;
}
// Consulta si la casella és una recàrrega de bateria.
bool casella::es_energia() const
{
    return bat > 0;
}
// Consulta la quantitat de recàrrega de bateria de la casella.
int casella::bateria() const
{
    return bat;
}

void casella::casella_erronea()
{
    cont = OBSTACLE;
}

// Obtè el caràcter que representa el contingut de la casella.
// 'E' si és entrada, 'S' si és sortida, '#' si és obstacle, 'o' si està
// visitada, un dígit si hi ha recàrrega de bateria, '.' si està lliure
char casella::mostrar() const
{
    return cont;
}
// Modifica contingut de la casella.
void casella::omplir(char c)
{
    cont = c;
}

// Marca la casella com a visitada.
void casella::marcar()
{
    cont = VISITADA;
    visitada = true;
}
// Desmarca la casella com a visitada.
void casella::desmarcar()
{
    cont = LLIURE;
    visitada = false;
}

// Reinicia direccions pendents de provar.
direccio casella::iniciar_direccions()
{
    direccio d = direccio();
    return d;
}
// Avança a la següent direcció.
direccio casella::avancar_direccions()
{
   ++dir;
   return dir;
}
// Veure si queden direccions pendents per provar.
bool casella::queden_direccions() const
{
    return !dir.is_stop();
}
// Obtenir la direcció actual pendent de provar.
direccio casella::direccio_actual() const
{
    return dir;
}

//motode de escriture d'una coordenada
ostream &operator<<(ostream &os, const casella &c)
{
    os << c.cont;
    return os;
}

//edu ha estado aqui