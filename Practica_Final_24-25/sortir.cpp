#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <queue>
#include <map>

#include "util.hpp"
#include "laberint.hpp"
#include "coord.hpp"
#include "casella.hpp"
#include "direccio.hpp"

using namespace std;

int test = false;
bool b = false;

// Dibuixar el laberint lab, l'energia eb, i esperar t segons
void dibuixar(laberint lab, int en, float t) 
{
  util::neteja();
  lab.mostrar();
  cout << "Energia: " << en << endl;
  util::espera(t);
}

// Solució ITERATIVA: buscar sortida del laberint lab amb energia eng usant A*
bool buscar_sortida_it(laberint &lab, int eng) 
{
  bool trobat_sortida = false;
  int eng_necesaria = 0;
  stack<coord> pila;
  stack<direccio> camino;
  coord c = lab.entrada();
  pila.push(c);

  while (!pila.empty() && trobat_sortida == false) 
  {
    if (lab(c).es_energia()) 
    {
      eng += lab(c).bateria();
    }
    lab(c).marcar();
    lab(c).omplir('X');
    
    bool casella_trobada = false;
    bool avanza = false;
    for (direccio d = lab(c).direccio_actual(); d.is_stop() != true && casella_trobada == false; ++d) 
    {      
      coord z = c + d.despl();
      if(!lab(z).es_visitada() && !lab(z).es_obstacle())
      {
        pila.push(z);
        casella_trobada = true;
        camino.push(d);
        avanza = true;
        eng_necesaria++;
      }      
    }
    if(!avanza)
    {
      eng_necesaria--;
      camino.pop();
    } 

    c = pila.top();

    if (lab(c).es_sortida())
    {
      trobat_sortida = true;
    }
    
    if(trobat_sortida == false && casella_trobada == false)
    {
      lab(c).marcar();
      lab(c).omplir('.');
      pila.pop();
      c = pila.top();
      lab(c).desmarcar();
    }

    if (test) 
    {
      dibuixar(lab, eng, 0.2);
    }
  }

  return eng_necesaria <= eng;
}

bool buscar_sortida_rec2(laberint &lab, coord c, int eng, stack<direccio> &camino, int &eng_necesaria) 
{
    // Caso base: Si no queda energía suficiente
    if (eng < 0) return false;

    // Si la coordenada actual contiene energía, recargar batería
    if (lab(c).es_energia()) {
        eng += lab(c).bateria();
    }
    
    // Caso base: Si encontramos la salida
    if (lab(c).es_sortida()) {
        return true;
    }

    // Marcar la celda como visitada y rellenarla
    lab(c).marcar();
    lab(c).omplir('X');


    // Intentamos avanzar en todas las direcciones
    for (direccio d = lab(c).direccio_actual(); !d.is_stop(); ++d) {
        coord siguiente = c + d.despl();

        if (!lab(siguiente).es_visitada() && !lab(siguiente).es_obstacle()) {
            // Avanzar en la dirección actual
            camino.push(d);
            eng_necesaria++;
            
            if (buscar_sortida_rec2(lab, siguiente, eng - 1, camino, eng_necesaria)) {
                return true;  // Si encontramos la salida en este camino, terminamos
            }

            // Retroceder: Deshacer cambios si no encontramos la salida
            camino.pop();
            eng_necesaria--;
        }
    }

    // Si no podemos avanzar, desmarcar la celda y rellenarla con '.'
    lab(c).omplir('.');
    lab(c).desmarcar();

    if(test) {
        dibuixar(lab, eng, 0.2);
    }

    return false;
}

// Solució RECURSIVA (sin implementar A* por simplicidad)
bool buscar_sortida_rec(laberint &lab, int eng) 
{
  stack<direccio> camino;  // Almacena el camino tomado
  int eng_necesaria = 0;   // Energía necesaria acumulada
  coord entrada = lab.entrada();

  // Llamada inicial a la función recursiva
  bool trobat_sortida = buscar_sortida_rec2(lab, entrada, eng, camino, eng_necesaria);

  return trobat_sortida && eng_necesaria <= eng;
}

int main(int argc, char *argv[]) {
    // 1er paràmetre: Nom del fitxer que conté el laberint
    string nomfitxer = string(argv[1]);
    // 2on paràmetre: Energia inicial
    int energia = atoi(argv[2]);
    // 3er paràmetre: Tipus de solució a aplicar ('i'-iterativa, 'r'-recursiva)
    char tsolucio = argv[3][0];
    // 4at paràmetre opcional: Si hi és, es mostrarà l'evolució del robot pas a pas.
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

    return 0;
}
