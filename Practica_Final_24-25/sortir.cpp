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

/*bool buscar_sortida_it(laberint &lab, int eng) 
{
  bool trobat_sortida = false; // Indica si hemos encontrado la salida
  int eng_necesaria = 0;       // Energía acumulada necesaria
  stack<coord> pila;           // Pila para almacenar las coordenadas del camino
  stack<direccio> camino;      // Pila para almacenar las direcciones tomadas
  coord c = lab.entrada();     // Coordenada de entrada del laberinto
  pila.push(c);                // Inicializar la pila con la posición inicial

  while (!pila.empty() && !trobat_sortida) 
  {
    c = pila.top(); // Obtener la coordenada actual

    // Si la casilla contiene energía, recargar la batería
    if (lab(c).es_energia()) {
      eng += lab(c).bateria();
    }

    // Caso base: Si encontramos la salida
    if (lab(c).es_sortida()) {
      trobat_sortida = true;
      break;
    }

    // Marcar la celda como visitada y rellenarla
    lab(c).marcar();
    lab(c).omplir('P');

    if (test) {
      dibuixar(lab, eng, 0.05); // Visualización opcional
    }

    bool casella_trobada = false; // Flag para saber si podemos avanzar

    // Intentamos avanzar en todas las direcciones
    for (direccio d = lab(c).direccio_actual(); !d.is_stop(); ++d) 
    {
      coord siguiente = c + d.despl();
      lab(c).avancar_direccions(); // Actualizar la dirección actual
      // Comprobar si podemos avanzar: no visitada, no es obstáculo y tenemos energía
      if (!lab(siguiente).es_visitada() && !lab(siguiente).es_obstacle() && eng_necesaria < eng) 
      {
        // Avanzamos a la siguiente posición
        pila.push(siguiente);
        camino.push(d);
        eng_necesaria++;
        casella_trobada = true;
        break;
      }
    }

    // Si no encontramos casillas válidas, retrocedemos
    if (!casella_trobada) 
    {
      lab(c).omplir('.');   // Marcar como explorada sin salida
      lab(c).desmarcar();   // Desmarcar como visitada
      pila.pop();           // Retroceder en la pila
      eng_necesaria--;      // Restar energía usada
      if (!camino.empty()) {
        camino.pop();       // Eliminar la última dirección tomada
      }
    }
  }

  // Mostrar el resultado de energía
  int engf = eng - eng_necesaria;
  cout << "Energia inicial: " << eng << endl;
  cout << "Energia necesaria: " << eng_necesaria << endl;
  cout << "Energia final: " << (engf < 0 ? 0 : engf) << endl;

  return trobat_sortida && eng_necesaria <= eng;
}*/


// Solució ITERATIVA: buscar sortida del laberint lab amb energia eng 
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
    
    if(!lab(c).direccio_actual().is_nord())
      {
        lab(c).iniciar_direccions();  ///esto no funcniona SIGUE PENSANDO
      }

    for (direccio d = lab(c).direccio_actual(); !d.is_stop() && !casella_trobada; ++d) 
    {      
      coord z = c + d.despl();
      lab(c).avancar_direccions();
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
    lab(c).omplir('P');

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
