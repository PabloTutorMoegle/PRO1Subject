#include <iostream>
#include "laberint.hpp"

using namespace std;

int main() {

  /// carregar el laberint del fitxer
  laberint lab(????);

  cout << "Laberint carregat" << endl;
  /// dibuixar el laberint
  lab.????;
  cout << endl;

  // Obtenir les coordenades de l'entrada del laberint
  coord p = lab.????;
  // Mostrar la casella entrada
  cout << "Entrada: "<<p.x<<","<<p.y<<" ["<<lab(p).mostrar()<<"]" << endl;
  cout << endl;

  // Comprovar que podem accedir a diferents caselles del laberint
  direccio d;
  // Per cada direccio possible des de l'entrada
  for (d.init(); not d.is_stop(); ++d) {
    coord z = lab.entrada() + d.????;
    cout << d.nom()<<" -> casella ("<<z.x<<","<<z.y<<") = "<<lab(z).mostrar() << endl;
  }
  cout << endl;


  // Crear algunes direccions
  direccio s;
  s.init();  // s s'inicia a NORD
  ++s; ++s;  // Incrementar s fins a SUD
  cout << "s=" << s.nom() << endl;

  direccio e;
  e.init();  // s s'inicia a NORD
  ????       // Incrementar e fins a EST
  cout << "e=" << e.nom() << endl;

  // Llegir unes coordenades qualsevols
  int x, y;
  cout << "Entreu coordenades: ";
  cin >> ????;
  // Crear coord amb aquests valors
  coord c(????);

  cout << "coord c inicial = ("<<c.x<<","<<c.y<<") " << endl;
  // Anar al sud, a l'est, i al sud, i veure en quines coord acabem.
  c = c + s.despl() + e.despl() + s.despl();
  cout << "coord c final = ("<<c.x<<","<<c.y<<"). Al laberint: ["<<lab(c).mostrar()<<"]" << endl;
  cout << endl;
}
