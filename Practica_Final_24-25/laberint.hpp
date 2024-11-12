#include <vector>
#include <string>

#include "casella.hpp"

//  La classe "laberint" és l'estructura de dades principal de la
//  pràctica. Guarda la taula NxM amb la informació de les caselles.

class laberint {

 public:
   //  Constructora. Serveix per declarar una variable
   //  de tipus "laberint", donant el fitxer que en conté
   //  les dades. Per exemple:  laberint lab("laber1.txt")
   laberint(const std::string &);

   // Obté quina és la casella d'entrada del laberint.
   ???? entrada() const;
   // Imprimeix a cout el laberint.
   ???? mostrar() const;

   // Accedeix a la casella de la coord donada del laberint.
   casella& operator()(coord);

 private:
   // Taula per guardar les caselles del laberint.
   std::vector<std::vector<casella> > taula;
   // coord marcada com a casella d'entrada.
   ???? pos_entrada;
   // Indica si una coord és dins del laberint.
   ???? dins_lab(coord) const;
};

