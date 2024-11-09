#include <iostream>
#include <vector>
#include "LlibreE.hpp"
#include "BinaryTree.hpp"
#include "Classificacio.hpp"
#include "PriorityQueue.hpp"

using namespace std;

class Plataforma {

    private:

    Queue<LlibreE> Libros;
    Queue<LlibreE> Pendents;
    Classificacio arbreDeClassificacio;

    public:
    
    //*********************************************************
    // Constructors
    //*********************************************************

    /* Pre: Cert */
    /* Post: la plataforma esta inicialitzada amb el valors per defecte */
    Plataforma();

    /* Pre: Cert */
    /* Post: la plataforma esta inicialitzada amb el valors de la plataforma pasada per parametre */
    Plataforma(const Plataforma &P);

    /* Pre: Cert */
    /* Post: tots els parametres de la plataforma pasada per parametre s'han passat al p.i. */
    Plataforma &operator=(const Plataforma &P);

    //*********************************************************
    // Destructor
    //*********************************************************

    /* Destructor per defecte */
    ~Plataforma();

    //*********************************************************
    // Consultors
    //*********************************************************

    /* Pre: Cert */
    /* Post: Retorna una còpia de la cua 'Libros' */
    Queue<LlibreE> consulta_Libros() const;

    /* Pre: Cert */
    /* Post: Retorna true si la llista 'Pendents' està buida. Altrament retorna false */
    bool sense_pendents();

    /* Pre: Cert */
    /* Post: Retorna true si el títol del llibre proporcionat es troba a la llista de llibres 'Libros'. 
             Altrament retorna false */
    bool llibre_repetit(const string titol);

    /* Pre: Cert */
    /* Post: Treu per pantalla els llibres continguts a la cua 'Pendents' */
    void llista_pendents();

    /* Pre: Cert */
    /* Post: Treu per pantalla els llibres continguts a la cua 'Libros' */
    void mostrarLlibres();

    /* Pre: Cert */
    /* Post: Si l'àrea 'a' no existeix a l'arbre de classificació, imprimeix "error". 
             Si l'àrea 'a' existeix a l'arbre de classificació i hi ha llibres en la cua 'Libros' d'aquesta àrea, 
	         imprimeix els llibres corresponents.
             Si l'àrea 'a' existeix a l'arbre de classificació però no hi ha cap llibre d'aquesta àrea a la cua 
	         'Libros', imprimeix "No hi ha cap llibre de l'àrea". */
    void mostrarLlibresArea(string a);

    //*********************************************************
    // Modificadors
    //*********************************************************

    /* Pre: Cert */
    /* Post: Actualitza l'arbre de classificació 'arbreDeClassificacio' 
             amb la nova classificació proporcionada 'C' */ 
    void setClassificacio(Classificacio &C);
    
    /* Pre: 'le' és un LlibreE vàlid */
    /* Post: Afegeix el llibre 'le' a les cues 'Libros' i 'Pendents' */
    void altaLlibre(LlibreE &le);

    /* Pre: Cert */
    /* Post: Si la cua 'Libros' està buida, imprimeix "error".
          Si es troba el llibre amb el títol 'titol' a la cua 'Libros', el llibre s'elimina tant de la cua 'Libros' 
	      com de la cua 'Pendents'.
          Si es troba el llibre amb el títol 'titol', el mètode no imprimeix cap missatge addicional */
    void baixaLlibre(string titol);

    /* Pre: Cert */
    /* Post: Si la cua 'Pendents' està buida, imprimeix "error".
             Si la cua 'Pendents' no està buida, es classifica el primer llibre de la cua 'Pendents' */
    void ClassificarLlibre();
    /* Pre: Cert */ 
    /* Post: Si la cua 'Pendents' està buida, imprimeix "error".
          Si la cua 'Pendents' no està buida, es troba l'àrea corresponent 
	      per a cada llibre de la cua utilitzant l'arbre de classificació i 
	      s'actualitza cada llibre amb l'àrea trobada */
    void Classifica();

    /* Pre: Cert */
    /* Post: Actualitza l'àrea del llibre 'le' amb el valor proporcionat 'area' a la cua 'Libros' */
    void actualitzaLlibre(LlibreE &le, string area);
};
