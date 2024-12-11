#ifndef _CASELLA_HPP
#define _CASELLA_HPP

#include <iostream>
#include "direccio.hpp"
#include "coord.hpp"

//  La classe "casella" guarda la informació de les caselles del laberint
//  És una classe privada a la que no es pot accedir (ni cal) des del
//  programa. La informació sobre les caselles d'un laberint s'obté
//  a través de les operacions de la classe "laberint".

class casella {
  private:
    // Possibles continguts de les caselles.
    static const char OBSTACLE='#';
    static const char ENTRADA='E';
    static const char SORTIDA='S';
    static const char LLIURE='.';
    static const char VISITADA='o';

    // Atribut on guardar el contingut de la casella.
    char cont;
    // Atribut per saber si la casella està marcada com a visitada.
    bool visitada;
    // Atribut per recordar quina direcció hem de provar si
    // arribem a aquesta casella mentre tornem enrera.
    char next;
    // Recàrrega de bateria que ofereix la casella (entre 0 i 9).
    int bat;

    direccio dir;

  public:
    // Crea una casella buida, amb valor OBSTACLE, no visitada, direcció inicial i
    // bateria a zero.
    casella();

    // Consulta si la casella és una entrada.
    bool es_entrada() const;
    // Consulta si la casella és una sortida.
    bool es_sortida() const;
    // Consulta si la casella és un obstacle.
    bool es_obstacle() const;
    // Consulta si la casella està marcada com visitada.
    bool es_visitada() const;
    // Consulta si la casella és una recàrrega de bateria.
    bool es_energia() const;
    // Consulta la quantitat de recàrrega de bateria de la casella.
    int bateria() const;

    void casella_erronea();

    // Obtè el caràcter que representa el contingut de la casella.
    // 'E' si és entrada, 'S' si és sortida, '#' si és obstacle, 'o' si està
    // visitada, un dígit si hi ha recàrrega de bateria, '.' si està lliure
    char mostrar() const;
    // Modifica contingut de la casella.
    void omplir(char c);

    // Marca la casella com a visitada.
    void marcar();
    // Desmarca la casella com a visitada.
    void desmarcar();

    // Reinicia direccions pendents de provar.
    direccio iniciar_direccions();
    // Avança a la següent direcció.
    direccio avancar_direccions();
    // Veure si queden direccions pendents per provar.
    bool queden_direccions() const;
    // Obtenir la direcció actual pendent de provar.
    void direccio_actual() const;

    //motode de escriture d'una coordenada
    friend std::ostream &operator<<(std::ostream &os, const casella &c);

};

#endif