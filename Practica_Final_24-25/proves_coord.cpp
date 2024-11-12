#include <iostream>
#include "coord.hpp"

using namespace std;

int main() {

  int x,y;

  // Pregunta components
  cout << " Entreu coordenades: ";
  cin >> x >> y;
  // Crea variable coord amb aquestes coordenades
  coord p(????);

  cout << " Entreu desplacament: ";
  cin >> x >> y;
  // Crear variable coord amb aquestes coordenades
  coord d(????);

  // Suma els dos parells de coordenades p + d
  coord z = ????;
  cout << "("<<p.x<<","<<p.y<<") + ("<<d.x<<","<<d.y<<") = ("<<z.x<<","<<z.y<<")" << endl;

  // Comprova si les coordenades p i d són iguals
  cout << "("<<p.x<<","<<p.y<<") i ("<<d.x<<","<<d.y<<") són iguals? " << ???? << endl;
}
