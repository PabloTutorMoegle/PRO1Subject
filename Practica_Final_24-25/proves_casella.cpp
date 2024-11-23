#include <iostream>
#include "casella.hpp"

using namespace std;

// Funció que ensenya el que té la casella per dins, usant
// els mètodes de la classe.
void llistar_casella(casella c) {
  cout << "[" << c.mostrar() << "]";
  cout << boolalpha;
  cout <<  "  visitada="  << c.es_visitada();
  cout << ", obstacle="   << c.es_obstacle();
  cout << ", entrada="    << c.es_entrada();
  cout << ", sortida="    << c.es_sortida() << endl;
  cout << "     bateria=" << c.bateria();
  cout << ", next="       << c.avancar_direccions().nom();
  cout << ", queden="     << c.queden_direccions() << endl;
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
