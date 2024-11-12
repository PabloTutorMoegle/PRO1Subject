#include <iostream>
#include "direccio.hpp"

using namespace std;

int main() {
  int x,y;

  // Pregunta components
  cout << " Entreu coordenades: ";
  cin >> x >> y;
  // Crea variable coord amb aquestes coordenades
  coord p(????);

  // Variable direccio
  direccio dir;
  dir.????;    // Iniciar-la al primer valor de la llista (NORD)
  while (not dir.is_stop()) {
    // Obtenir el moviment en (x,y) que suposa la direccio dir,
    // i sumar-lo a la coordenada base (p)
    coord z= p + ????;

    // Imprimeix resultat
    cout << "("<<p.x<<","<<p.y<<") + "<<dir.????<<" = ("<<z.x<<","<<z.y<<")" << endl;

    // Següent direcció de la llista
    ++dir;
  }
}
