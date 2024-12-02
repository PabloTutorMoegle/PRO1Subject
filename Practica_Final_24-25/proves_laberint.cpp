#include <iostream>
#include "laberint.hpp"
#include "direccio.hpp"
#include "coord.hpp"


using namespace std;

int main() {

  /// carregar el laberint del fitxer
  laberint lab("./proves/laberint.0.txt");

  cout << "Laberint carregat" << endl;
  /// dibuixar el laberint
  lab.mostrar();
  cout << endl;

  // Obtenir les coordenades de l'entrada del laberint
  coord p = lab.entrada();
  // Mostrar la casella entrada
  cout << "Entrada: "<<p.x<<","<<p.y<<" [" << lab(p) << "]" << endl;
  cout << endl;

  // Comprovar que podem accedir a diferents caselles del laberint
  direccio d;
  // Per cada direccio possible des de l'entrada
  for (d.init(); d.is_stop() != true; ++d) {
    coord z = p + d.despl();
    cout << d.nom()<<" -> casella ("<<z.x<<","<<z.y<<") = " << lab(z) << endl;
  }
  cout << endl;


  // Crear algunes direccions
  direccio s;
  s.init();  // s s'inicia a NORD
  ++s; ++s;  // Incrementar s fins a SUD
  cout << "s=" << s.nom() << endl;

  direccio e;
  e.init();  // s s'inicia a NORD
  ++e;       // Incrementar e fins a EST
  cout << "e=" << e.nom() << endl;

  // Llegir unes coordenades qualsevols
  int x, y;
  cout << "Entreu coordenades: ";
  cin >> x >> y;
  // Crear coord amb aquests valors
  coord c(x, y);

  cout << "coord c inicial = ("<<c.x<<","<<c.y<<") " << endl;
  // Anar al sud, a l'est, i al sud, i veure en quines coord acabem.
  c = c + s.despl() + e.despl() + s.despl();
  cout << "coord c final = ("<<c.x<<","<<c.y<<"). Al laberint: [" << lab(c) <<"]" << endl;
  cout << endl;
}
