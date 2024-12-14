#ifndef _DIRECCIO_HPP
#define _DIRECCIO_HPP

#include <string>
#include "coord.hpp"

// La classe "direccio" guarda una de les quatre possibles direccions
// que pot prendre el robot des d'un punt en concret. Aquest tipus té
// l'operador d'autoincrement que permet modificar una variable de tipus
// "direccio" amb el valor de la següent direcció en el sentit de les
// agulles del rellotge.

class direccio {
   private:
      // Llista de direccions possibles, més STOP per marcar
      // que no n'hi ha més.
      enum dirs {NORD, EST, SUD, OEST, STOP};
      dirs d;

    public:
      // Crea una direcció nova, amb el primer valor de la llista.
      direccio();

      // Veure si el valor de la direcció és el del final de la llista.
      bool is_stop() const;

      // Canvia el valor de la direcció, posant-li el primer de la llista.
      const direccio& init();

      // Canvia el valor de la direcció pel següent de la llista.
      // Permet usar instruccions "d++" (on d és de tipus direccio).
      const direccio& operator++();

      //programar el operador de != 
      bool operator!=(const direccio &d) const;

      // Obté la coordenada de components x,y que significa un moviment en
      // aquesta direcció en el pla 2D de la pantalla, o sigui amb aquest criteri:
      // * La primera component (x) indica la fila i creix de dalt a baix
      // * La segona component (y) indica la columna i creix d'esquerra a dreta
      // per exemple:  NORD -> (-1,0), EST -> (0, 1)
      coord despl() const;

      // Obtenir un string amb el nom de la direcció.
      // Aquest mètode és útil per fer debugging.
      std::string nom() const;

      //metode escritura 
      friend std::ostream &operator<<(std::ostream &os, const direccio &d);
};

#endif  