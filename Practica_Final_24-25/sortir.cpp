#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

#include "util.hpp"
#include "laberint.hpp"
#include "coord.hpp"
#include "casella.hpp"
#include "direccio.hpp"

using namespace std;

int test = false;
bool b = false;

// Dibuixar el laberint lab, l'energia eb, i esperar t segons
void dibuixar(laberint lab, int en, float t) {
  util::neteja();
  lab.mostrar();
  cout << "Energia: " << en << endl;
  util::espera(t);
}

// Solució ITERATIVA: buscar sortida del laberint lab amb energia eng usant una pila.
bool buscar_sortida_it (laberint &lab, int eng) 
{
  bool trobat_sortida=false;
  bool energia_acaba=false;
  stack<coord> pila;
  coord c = lab.entrada();
  pila.push(c);

  while (!pila.empty() and trobat_sortida==false and energia_acaba==false) {

    direccio d;
    bool casella_trobada=false;
    for (d.init(); d.is_stop() != true and casella_trobada==false; ++d) {
      
      coord z = c + d.despl();
      if(!lab(z).es_visitada() and !lab(z).es_obstacle()){
        pila.push(z);
        lab(z).marcar();
        casella_trobada=true;
      }
    }

    c=pila.top();

    if (lab(c).es_sortida()){
          trobat_sortida=true;
        }
    if (lab(c).es_energia()) {
          eng += lab(c).bateria();
          cout << "Recàrrega de bateria: " << lab(c).bateria() << endl;
        }



    eng--;
    if (eng == 0) {
      energia_acaba=false;
    }
    cout << "Energia: " << eng << endl;
    if(trobat_sortida==false and casella_trobada==false)   //después de ni haber encontrado la salida ni otra casilla para seguir, retrocede una casilla
    {
      pila.pop();
    }
  }
  return trobat_sortida;
}


// Solució RECURSIVA: buscar sortida del laberint lab amb energia eng.
bool buscar_sortida_rec (laberint &lab, int eng) 
{
  lab.mostrar();
  cout << "Energia: " << eng << endl;
  return true;
}


int main(int argc, char *argv[]) {

  // 1er paràmetre: Nom del fitxer que conté el laberint
  string nomfitxer = string(argv[1]);
  // 2on paràmetre: Energia inicial
  int energia = atoi(argv[2]);
  // 3er paràmetre: Tipus de solució a aplicar ('i'-iterativa, 'r'-recursiva)
  char tsolucio = argv[3][0];
  // 4at paràmetre opcional: Si hi és, es mostrarà l'evolució del robot pas a pas.
  //                         Si no hi és, només es mostrarà el resultat final.
  if (argc > 4) test = true;

  // Crea laberint a partir del fitxer
  laberint lab(nomfitxer);

  // Mostra laberint i energia inicial
  lab.mostrar();
  
  if (tsolucio == 'i')
    b = buscar_sortida_it(lab, energia);
  else
    b = buscar_sortida_rec(lab, energia);

  if (b)
    cout << "Camí trobat." << endl;
  else
    cout << "No hi ha camí." << endl;

}
