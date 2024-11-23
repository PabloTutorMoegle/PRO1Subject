#include "direccio.hpp"

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

    // Atribut on guardar el contingut de la casella.
    char cont;
    // Atribut per saber si la casella està marcada com a visitada.
    bool visitada;
    // Atribut per recordar quina direcció hem de provar si
    // arribem a aquesta casella mentre tornem enrera.
    char next;
    // Recàrrega de bateria que ofereix la casella (entre 0 i 9).
    int bat;

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
    // Consulta la quantitat de recàrrega de bateria de la casella.
    int bateria() const;

    // Obtè el caràcter que representa el contingut de la casella.
    // 'E' si és entrada, 'S' si és sortida, '#' si és obstacle, 'o' si està
    // visitada, un dígit si hi ha recàrrega de bateria, '.' si està lliure
    void mostrar() const;
    // Modifica contingut de la casella.
    void omplir(char);

    // Marca la casella com a visitada.
    void marcar();
    // Desmarca la casella com a visitada.
    void desmarcar();

    // Reinicia direccions pendents de provar.
    direccio iniciar_direccions();
    // Avança a la següent direcció.
    direccio avancar_direccions();
    // Veure si queden direccions pendents per provar.
    direccio queden_direccions() const;
    // Obtenir la direcció actual pendent de provar.
    direccio direccio_actual() const;
};

