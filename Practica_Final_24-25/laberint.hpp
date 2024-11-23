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
   laberint(const std::string &s);

   // Obté quina és la casella d'entrada del laberint.
   coord entrada() const;
   // Imprimeix a cout el laberint.
   void mostrar() const;

   // Accedeix a la casella de la coord donada del laberint.
   casella& operator()(coord &c);

 private:
   // Taula per guardar les caselles del laberint.
   std::vector<std::vector<casella> > taula;
   // coord marcada com a casella d'entrada.
   casella pos_entrada;
   // Indica si una coord és dins del laberint.
   bool dins_lab(coord) const;
};

