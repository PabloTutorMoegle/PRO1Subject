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
int pasos_posibles = eng;
  eng = 1000;
  bool trobat_sortida=false;
  bool energia_acaba=false;
  stack<coord> pila;
  stack<direccio> camino;
  coord c = lab.entrada();
  pila.push(c);

  while (!pila.empty() and trobat_sortida==false and energia_acaba==false) 
  {
    //cout<<"Estat abans: "<< lab(c).mostrar() <<endl;
    if (lab(c).es_energia()) 
    {
      eng += lab(c).bateria();
    }
    lab(c).marcar();
    //cout<<"Estat despres: "<< lab(c).mostrar() <<endl;
    
    bool casella_trobada=false;
    bool avanza = false;
    for (direccio d = lab(c).direccio_actual(); d.is_stop() != true and casella_trobada==false; ++d) 
    {      
      coord z = c + d.despl();
      //cout << "Estat coordenada z: " << lab(z).mostrar() << " " << lab(z).es_visitada() << endl;
      if(!lab(z).es_visitada() and !lab(z).es_obstacle())
      {
        pila.push(z);
        casella_trobada=true;
        //cout << d << endl;
        camino.push(d);
        avanza = true;
      }      
    }

    if(!avanza)
    {
      if(lab(c).direccio_actual().is_stop())
      {
        eng++;
      }
      eng++;
      eng++;
      camino.pop();
    } 

    c = pila.top();

    if (lab(c).es_sortida())
    {
      trobat_sortida=true;
    }
    eng--;
    if (eng == 0) 
    {
      energia_acaba=true;               //si la energía termina, el bucle while termina y devuelve false SIEMPRE Y CUANDO NO HAYA TERMINADO PERO ESTÉ EN LA SALIDA
    }

    //cout << "Energia: " << eng << endl;
    
    if(trobat_sortida==false and casella_trobada==false)   //después de ni haber encontrado la salida ni otra casilla para seguir, retrocede una casilla
    {
      lab(c).marcar();
      pila.pop();
      c = pila.top();
      lab(c).desmarcar();
    }
    if(avanza) //cout << "-";

    if (test) 
    {
      dibuixar(lab, eng, 0.2);
    }
  }

  cout << "Camí final " << camino.size() << endl;
  //cout << eng << endl;

  //despintar todo lo que este marcado como visitado que no pertenezca al camino
  while(!pila.empty())
  {
    lab(pila.top()).omplir('X');
    pila.pop();
  }

  // Desmarcar todas las casillas visitadas que no pertenecen al camino
  for (int i = 0; i < lab.sizeR(); ++i) {
    for (int j = 0; j < lab.sizeC(); ++j) {
      coord c(i, j);
      if (lab(c).es_visitada() && lab(c).mostrar() != 'X') {
        lab(c).desmarcar();
      }
    }
  }

  lab.mostrar();

  return camino.size() <= pasos_posibles;
}

// Solució RECURSIVA (sin implementar A* por simplicidad)
bool buscar_sortida_rec(laberint &lab, int eng) 
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

//CODIGO 1
/*
int pasos_posibles = eng;
  eng = 1000;
  bool trobat_sortida=false;
  bool energia_acaba=false;
  stack<coord> pila;
  stack<direccio> camino;
  coord c = lab.entrada();
  pila.push(c);

  while (!pila.empty() and trobat_sortida==false and energia_acaba==false) 
  {
    //cout<<"Estat abans: "<< lab(c).mostrar() <<endl;
    if (lab(c).es_energia()) 
    {
      eng += lab(c).bateria();
    }
    lab(c).marcar();
    //cout<<"Estat despres: "<< lab(c).mostrar() <<endl;
    
    bool casella_trobada=false;
    bool avanza = false;
    for (direccio d = lab(c).direccio_actual(); d.is_stop() != true and casella_trobada==false; ++d) 
    {      
      coord z = c + d.despl();
      //cout << "Estat coordenada z: " << lab(z).mostrar() << " " << lab(z).es_visitada() << endl;
      if(!lab(z).es_visitada() and !lab(z).es_obstacle())
      {
        pila.push(z);
        casella_trobada=true;
        //cout << d << endl;
        camino.push(d);
        avanza = true;
      }      
    }

    if(!avanza)
    {
      if(lab(c).direccio_actual().is_stop())
      {
        eng++;
      }
      eng++;
      eng++;
      camino.pop();
    } 

    c = pila.top();

    if (lab(c).es_sortida())
    {
      trobat_sortida=true;
    }
    eng--;
    if (eng == 0) 
    {
      energia_acaba=true;               //si la energía termina, el bucle while termina y devuelve false SIEMPRE Y CUANDO NO HAYA TERMINADO PERO ESTÉ EN LA SALIDA
    }

    //cout << "Energia: " << eng << endl;
    
    if(trobat_sortida==false and casella_trobada==false)   //después de ni haber encontrado la salida ni otra casilla para seguir, retrocede una casilla
    {
      lab(c).marcar();
      pila.pop();
      c = pila.top();
      lab(c).desmarcar();
    }
    if(avanza) //cout << "-";

    if (test) 
    {
      dibuixar(lab, eng, 0.2);
    }
  }

  cout << "Camí final " << camino.size() << endl;
  //cout << eng << endl;

  //despintar todo lo que este marcado como visitado que no pertenezca al camino
  while(!pila.empty())
  {
    lab(pila.top()).omplir('X');
    pila.pop();
  }

  // Desmarcar todas las casillas visitadas que no pertenecen al camino
  for (int i = 0; i < lab.sizeR(); ++i) {
    for (int j = 0; j < lab.sizeC(); ++j) {
      coord c(i, j);
      if (lab(c).es_visitada() && lab(c).mostrar() != 'X') {
        lab(c).desmarcar();
      }
    }
  }

  lab.mostrar();

  return camino.size() <= pasos_posibles;
*/

//CODIGO 2
/*
  int pasos_posibles = eng; 
  eng = 1000;
  stack<coord> pila;
  coord c = lab.entrada();
  stack<coord> cami;
  pila.push(c);
  bool avanza = false;
  bool trobat_sortida = false;

  while (!pila.empty() && !trobat_sortida) {
    c = pila.top();
    pila.pop();

    if (lab(c).es_sortida()) {
      cout << "Camí final " << cami.size() << "---" << pasos_posibles << endl;
      trobat_sortida = true;
    }

    if (lab(c).es_energia()) {
      eng += lab(c).bateria();
      cout << "Recàrrega de bateria: " << eng << endl;
    }

    lab(c).marcar();

    avanza = false;

    for (direccio d; !d.is_stop(); ++d) {
      coord z = c + d.despl();
      if (!lab(z).es_visitada() && !lab(z).es_obstacle()) 
      {
        pila.push(z);
        cami.push(z);
        avanza = true;
      }
    }

    if (!avanza) {
      eng++;
      cami.pop();
    }

    eng--;

    if (eng == 0) {
      cout << "Camí final " << cami.size() << "---" << pasos_posibles << endl;
      return false;
    }

    if (test) {
      dibuixar(lab, eng, 0.2);
    }
  }

  cout << "Camí final " << cami.size() << "---" << pasos_posibles << endl;
  
  return cami.size() <= pasos_posibles;
*/

//CODIGO 3
/*
  stack<coord> pila;                // Pila de coordenadas
  stack<direccio> cami_actual;      // Camino actual (direcciones)
  coord c = lab.entrada();          // Entrada al laberinto
  pila.push(c);

  int pasos = 0;

  while (!pila.empty()) {
      c = pila.top();
      pila.pop();

      if (lab.es_sortida(c)) {
          cout << "Camino encontrado, pasos: " << pasos << endl;

          // Almacenar el camino actual
          caminos.push(cami_actual);

          // Retroceder para buscar otros caminos
          if (!cami_actual.empty()) cami_actual.pop();
          continue;
      }

      // Manejo de recarga de batería
      if (lab.es_energia(c)) {
          eng += lab.bateria(c);
          cout << "Recarga de batería: " << eng << endl;
      }

      lab.marcar(c);  // Marcar como visitado
      bool avanza = false;

      // Intentar avanzar en todas las direcciones
      for (direccio d; !d.is_stop(); ++d) {
          coord siguiente = c + d.despl();

          if (!lab.es_visitada(siguiente) && !lab.es_obstacle(siguiente)) {
              pila.push(siguiente);  // Avanzar a la siguiente coordenada
              cami_actual.push(d);   // Guardar la dirección
              avanza = true;
          }
      }

      if (!avanza) {
          // Retroceder: desmarcar la celda y ajustar la energía
          lab.desmarcar(c);
          if (!cami_actual.empty()) cami_actual.pop();
          eng++;
      } else {
          pasos++;
      }

      eng--;

      if (eng <= 0) {
          cout << "Sin batería en el camino actual." << endl;
          return false;
      }
  }

  return true;
*/