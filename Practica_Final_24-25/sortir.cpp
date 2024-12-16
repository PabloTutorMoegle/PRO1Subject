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
  lab.mostrar2();
  util::espera(t);
}

bool buscar_sortida_it(laberint &lab, int eng) 
{
  //Este algoritmo es el que encuentra un camino y te dice si puedes o no 
  //recorrerlo con la energía que tienes, no encuentra el mas corto o util 
  //para la energia que tienes
  
  bool trobat_sortida = false;
  bool no_exit = false; //si no hay salida
  int eng_necesaria = 0;
  stack<coord> pila;
  stack<direccio> camino;
  coord c = lab.entrada();
  pila.push(c);

  while (!pila.empty() && trobat_sortida == false) 
  {
    if (lab(c).es_energia()) 
    {  //suma las energias que encuentre a la energia inicial
      eng += lab(c).bateria();
    }

    lab(c).marcar();
    
    if (test) 
    {
      dibuixar(lab, eng, 0.02);
    }

    bool casella_trobada = false;
    bool avanza = false;
    
    for (direccio d = lab(c).direccio_actual(); d.is_stop() != true && casella_trobada == false; ++d) 
    {       //recorre las direcciones de la casilla actual
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
    {  //si no puede avanzar retrocede
      eng_necesaria--;
      if (!camino.empty())
          camino.pop();
    } 

    if (!pila.empty())    c = pila.top();
    else  no_exit = true;
    
    if (lab(c).es_sortida())
    {  //si encuentra la salida termina
      trobat_sortida = true;
    }
    
    if(trobat_sortida == false && casella_trobada == false)
    {  //si no encuentra la salida y no puede avanzar retrocede
      lab(c).marcar();
      lab(c).omplir('.');
      if (!pila.empty())    pila.pop();
      else    no_exit = true;
      if (!pila.empty())    c = pila.top();
      else    no_exit = true;
      lab(c).desmarcar();
    }
  }
  if(no_exit)    return false;
  else    return eng_necesaria <= eng;
}

bool buscar_sortida_rec2(laberint &lab, coord c, int eng, stack<direccio> &camino, int &eng_necesaria, bool &trobat_sortida) 
{  
    // Caso base: Si no queda energía suficiente
    if (eng < 0) return false;

    if (trobat_sortida)
    {
      return true;
    } 

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

    if(test) {
      dibuixar(lab, eng, 0.02);
    }

    trobat_sortida = false;

    // Intentamos avanzar en todas las direcciones
    for (direccio d = lab(c).direccio_actual(); !d.is_stop() && !trobat_sortida; ++d) {
      coord siguiente = c + d.despl();

      if (!lab(siguiente).es_visitada() && !lab(siguiente).es_obstacle()) {
        // Avanzar en la dirección actual
        camino.push(d);
        eng_necesaria++;
        
        if (buscar_sortida_rec2(lab, siguiente, eng - 1, camino, eng_necesaria, trobat_sortida)) {
          trobat_sortida = true;  // Si encontramos la salida en este camino, terminamos
        } else {
          // Retroceder: Deshacer cambios si no encontramos la salida
          camino.pop();
          eng_necesaria--;
        }
      }
    }

    // Si no podemos avanzar, desmarcar la celda y rellenarla con '.'
    if (!trobat_sortida) {
      lab(c).omplir('.');
      lab(c).desmarcar();
    }


    return trobat_sortida;
}

// Solució RECURSIVA (sin implementar A* por simplicidad)
bool buscar_sortida_rec(laberint &lab, int eng) 
{
  stack<direccio> camino;  // Almacena el camino tomado
  int eng_necesaria = 0;   // Energía necesaria acumulada
  coord entrada = lab.entrada();

  // Llamada inicial a la función recursiva
  bool trobat_sortida = false;
  trobat_sortida = buscar_sortida_rec2(lab, entrada, eng, camino, eng_necesaria, trobat_sortida);

  int engf = eng - eng_necesaria;
  cout << "Energia inicial: " << eng << endl;
  cout << "Energia necesaria: " << eng_necesaria << endl;
  if (engf < 0) {
    cout << "Energia final: " << 0 << endl;
  } else {
    cout << "Energia final: " << engf << endl;
  }

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


/*

Hola Alejandro este es el codigo que estube trabajando, 
no pude terminarlo a tiempo, he puesto el codigo anterior, el que buscaba un camino y ya,
espero te sirva de algo, saludos.

bool buscar_sortida_it(laberint &lab, int eng) 
{
  bool trobat_sortida = false;
  int eng_necesaria = 0;
  stack<coord> pila;
  stack<direccio> camino;
  coord c = lab.entrada();
  pila.push(c);

  while (!pila.empty() && !trobat_sortida) 
  {
    if (lab(c).es_energia()) 
    {
      eng += lab(c).bateria();
    }

    lab(c).marcar();
    
    if (test) 
    {
      dibuixar(lab, eng, 0.05);
    }
    
    bool casella_trobada = false;

    if(lab(c).direccio_actual().is_nord())
    {
      lab(c).iniciar_direccions();
    }

    for (direccio d = lab(c).direccio_actual(); !d.is_stop() && !casella_trobada; ++d) 
    {      
      coord z = c + d.despl();
      if(!lab(z).es_visitada() && !lab(z).es_obstacle() && eng_necesaria < eng)
      {
        pila.push(z);
        casella_trobada = true;
        camino.push(d);
        eng_necesaria++;
      }      
    }
    if(!casella_trobada)
    {
      lab(c).desmarcar();
      eng_necesaria--;
      camino.pop();
    } 

    c = pila.top();

    if (lab(c).es_sortida())
    {
      trobat_sortida = true;
    }
    
    if(!trobat_sortida && !casella_trobada)
    {
      lab(c).omplir('.');
      pila.pop();
      lab(c).desmarcar();
      if (!pila.empty()) {
        c = pila.top();
      }
    }
  }

  return trobat_sortida && eng_necesaria <= eng;
}

*/
