#include <iostream>
#include "casella.hpp"

using namespace std;

// Funció que ensenya el que té la casella per dins, usant
// els mètodes de la classe.
void llistar_casella(casella c) {
  cout << "["<<c.mostrar()<<"]";
  cout << boolalpha;
  cout <<  "  visitada="  << c.????;
  cout << ", obstacle="   << c.????;
  cout << ", entrada="    << c.????;
  cout << ", sortida="    << c.???? << endl;
  cout << "     bateria=" << c.????;
  cout << ", next="       << c.????.nom();
  cout << ", queden="     << c.???? << endl;
  cout << endl;
}

int main() {

  // Proves amb les operacions de 'casella':
  // omplir-la de diferents maneres, i cridar les operacions
  // de marcar, desmarcar, direccions, etc, per comprovar si funcionen
  casella c;

  c.omplir('#');  // una casella obstacle
  llistar_casella(c);

  c.omplir('4');  // una casella lliure amb 4 de bateria
  llistar_casella(c);

  c.omplir('3');  // una casella lliure amb 3 de bateria
  c.marcar();     // i marcada com a visitada
  llistar_casella(c);

  c.desmarcar();  // la mateixa, desmarcada
  llistar_casella(c);

  c.omplir('E');  // una casella entrada
  llistar_casella(c);

  c.avancar_direccions(); // la mateixa, amb 'pendents' avançat 2 cops
  c.avancar_direccions();
  llistar_casella(c);

  c.avancar_direccions(); // la mateixa, amb 'pendents' avançat 2 cops mes
  c.avancar_direccions();
  llistar_casella(c);

  c.iniciar_direccions();  // la mateixa, amb 'pendents' reiniciat
  llistar_casella(c);
}
