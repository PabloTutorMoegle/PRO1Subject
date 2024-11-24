#include <iostream>
#include "casella.hpp"

using namespace std;

// Crea una casella buida, amb valor OBSTACLE, no visitada, direcció inicial i
// bateria a zero.
casella::casella()
{
    cont = OBSTACLE;
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
// Consulta la quantitat de recàrrega de bateria de la casella.
int casella::bateria() const
{
    return bat;
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
    cont = 'o';
    visitada = true;
}
// Desmarca la casella com a visitada.
void casella::desmarcar()
{
    cont = LLIURE;
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
    bat -= 1;
    return direccio();
}
// Veure si queden direccions pendents per provar.
direccio casella::queden_direccions() const
{
    direccio d = direccio();
    return d;
}
// Obtenir la direcció actual pendent de provar.
direccio casella::direccio_actual() const
{
    direccio d = direccio();
    return d;
}

//motode de escriture d'una coordenada
ostream &operator<<(ostream &os, const casella &c)
{
    os << c.cont;
    return os;
}