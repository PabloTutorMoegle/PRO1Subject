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
  stack<coord> pila;
  coord c = lab.entrada();
  pila.push(c);
  while (!pila.empty())
  {
      c = pila.top();
      pila.pop();
      if (lab(c).es_sortida())
      {
          return true;
      }
      if (lab(c).es_obstacle() || lab(c).es_visitada())
      {
          continue;
      }
      lab(c).marcar();
      if (test)
      {
          dibuixar(lab, eng, 0.1);
      }
      if (lab(c).es_energia())
      {
          eng++;
      }
      if (eng > 0)
      {
          coord c2 = c;
          c2.x++;
          if (lab.dins_labP(c2))
          {
              pila.push(c2);
          }
          c2 = c;
          c2.x--;
          if (lab.dins_labP(c2))
          {
              pila.push(c2);
          }
          c2 = c;
          c2.y++;
          if (lab.dins_labP(c2))
          {
              pila.push(c2);
          }
          c2 = c;
          c2.y--;
          if (lab.dins_labP(c2))
          {
              pila.push(c2);
          }
      }
  }
  return false;
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
