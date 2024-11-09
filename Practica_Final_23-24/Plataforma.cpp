#include <iostream>
#include "Plataforma.hpp"

using namespace std;

//*********************************************************
// Constructors
//*********************************************************

/* Pre: Cert */
/* Post: la plataforma esta inicialitzada amb el valors per defecte */
Plataforma::Plataforma()
{}

/* Pre: Cert */
/* Post: la plataforma esta inicialitzada amb el valors de la plataforma pasada per parametre */
Plataforma::Plataforma(const Plataforma &P)
{
    Libros = P.Libros;
    Pendents = P.Pendents;
    arbreDeClassificacio = P.arbreDeClassificacio;
}

/* Pre: Cert */
/* Post: tots els parametres de la plataforma pasada per parametre s'han passat al p.i. */
Plataforma &Plataforma::operator=(const Plataforma &P)
{
    Libros = P.Libros;
    Pendents = P.Pendents;
    arbreDeClassificacio = P.arbreDeClassificacio;
    return *this;
}

//*********************************************************
// Destructor
//*********************************************************

/* Destructor per defecte */
Plataforma::~Plataforma()
{}

//*********************************************************
// Consultors
//*********************************************************

/* Pre: Cert */
/* Post: Retorna una còpia de la cua 'Libros' */
/*Queue<LlibreE> Plataforma::consulta_Libros() const
{
    //return Libros;
}*/

/* Pre: Cert */
/* Post: Retorna true si la llista 'Pendents' està buida. Altrament retorna false */
bool Plataforma::sense_pendents(){
    return Pendents.empty();
}
/* Pre: Cert */
/* Post: Retorna true si el títol del llibre proporcionat es troba a la llista de llibres 'Libros'. 
        Altrament retorna false */
bool Plataforma::llibre_repetit(const string titol)
{
    if (Libros.empty()) return false; //la llista està buida, no pot haber llibres repetits 
    else
    {
        Queue<LlibreE> auxQ = Libros;
        for(int i = 0; i < Libros.size(); i++)
        {    // Invariant: Aquest mètode retorna true si el títol del llibre 'le' és igual al títol 
             // proporcionat 'titol', indicant que el llibre ja existeix a la plataforma.
            LlibreE le = auxQ.front();
            if (le.consultar_titol() == titol)
            {
                return true;
            }
            auxQ.pop();
        }
    } 
    return false;
}
/* Pre: Cert */
/* Post: Treu per pantalla els llibres continguts a la cua 'Pendents' */
void Plataforma::llista_pendents()
{
    Queue<LlibreE> auxQ = Pendents;
    for(int i = 0; i < Pendents.size(); i++)
    { // Inv: S'imprimeixen per pantalla els llibres pendents de la plataforma.
        LlibreE le = auxQ.front();
        cout << le;
        auxQ.pop();
    }
}

/* Pre: Cert */
/* Post: Treu per pantalla els llibres continguts a la cua 'Libros' */
void Plataforma::mostrarLlibres()
{
    Queue<LlibreE> auxQ = Libros;
    for(int i = 0; i < Libros.size(); i++)
    { // Inv: S'imprimeixen per pantalla tots els llibres de la plataforma.
        LlibreE le = auxQ.front();
        cout << le;
        auxQ.pop();
    }
}
/* Pre: Cert */
/* Post: Si l'àrea 'a' no existeix a l'arbre de classificació, imprimeix "error". 
         Si l'àrea 'a' existeix a l'arbre de classificació i hi ha llibres en la cua 'Libros' d'aquesta àrea, 
	     imprimeix els llibres corresponents.
         Si l'àrea 'a' existeix a l'arbre de classificació però no hi ha cap llibre d'aquesta àrea a la cua 
	     'Libros', imprimeix "No hi ha cap llibre de l'àrea". */
void Plataforma::mostrarLlibresArea(string a)
{
    if (arbreDeClassificacio.existeixArea(a) == false)
    {
        cout << "  error" << endl;
    }
    else
    {
        Queue<LlibreE> auxQ = Libros;
        bool found = false;
        for(int i = 0; i < Libros.size(); i++)
        { // Invariant: S'imprimeixen a la sortida estàndard tots els llibres de l'àrea 'a' de la plataforma, si existeixen. 
          // En cas contrari, es mostra un missatge.
            LlibreE le = auxQ.front();
            if (le.consultar_area() == a)
            {
                found = true;
                cout << le;
            }
            auxQ.pop();
        }
        if (found == false) cout << "  No hi ha cap llibre de l'àrea " << a << endl;
    }
}
//*********************************************************
// Modificadors
//*********************************************************


/* Pre: Cert */
/* Post: Actualitza l'arbre de classificació 'arbreDeClassificacio' 
         amb la nova classificació proporcionada 'C' */ 
void Plataforma::setClassificacio(Classificacio &C)
{
    arbreDeClassificacio = C;
}

/* Pre: 'le' és un LlibreE vàlid */
/* Post: Afegeix el llibre 'le' a les cues 'Libros' i 'Pendents' */
void Plataforma::altaLlibre(LlibreE &le)
{
    Libros.push(le);  
    Pendents.push(le); 
}

/* Pre: Cert */
/* Post: Si la cua 'Libros' està buida, imprimeix "error".
         Si es troba el llibre amb el títol 'titol' a la cua 'Libros', 
         el llibre s'elimina tant de la cua 'Libros' com de la cua 'Pendents'.
         Si es troba el llibre amb el títol 'titol', el mètode no imprimeix cap missatge addicional */
void Plataforma::baixaLlibre(string titol)
{
    if (Libros.empty()) {
        cout << "  error" << endl;
    } else {
        Queue<LlibreE> auxQ;
        bool found = false;
        while (!Libros.empty()) {   // Inv: el llibre amb el títol proporcionat 'titol' es dóna de baixa de la plataforma i 
                                    // és eliminat de la cua de llibres 'Libros'. Si el llibre no es troba, es mostra un missatge d'error.
            LlibreE le = Libros.front();
            Libros.pop();
            if (le.consultar_titol() == titol) {
                found = true;
                Queue<LlibreE> auxP;
                while (!Pendents.empty()) {  // Inv: els llibres processats fins ara que no tenen el títol 'titol' es mantenen en 'auxP'

                    LlibreE leP = Pendents.front();
                    Pendents.pop();
                    if (leP.consultar_titol() != titol) {
                        auxP.push(leP);
                    }
                }
                Pendents = auxP;
            } else {
                auxQ.push(le);
            }
        }
        Libros = auxQ;
        if (found) {
        } else {
            cout << "  error" << endl;
        }
    }
}

/* Pre: Cert */
/* Post: Si la cua 'Pendents' està buida, imprimeix "error".
         Si la cua 'Pendents' no està buida, es classifica el primer llibre de la cua 'Pendents' */
void Plataforma::ClassificarLlibre() 
{
    if(Pendents.empty())
    {
        cout << "  error" << endl;
    }
    else
    {
        LlibreE le = Pendents.front();
        string area = arbreDeClassificacio.trobarArea(le);
        actualitzaLlibre(le, area);
        Pendents.pop();
    }
}
/* Pre: Cert */ 
/* Post: Si la cua 'Pendents' està buida, imprimeix "error".
         Si la cua 'Pendents' no està buida, es troba l'àrea corresponent 
         per a cada llibre de la cua utilitzant l'arbre de classificació i 
         s'actualitza cada llibre amb l'àrea trobada */
void Plataforma::Classifica(){
    BinaryTree<string> T = arbreDeClassificacio.consultar_arbre(arbreDeClassificacio);
    if (Pendents.empty()){
        cout << "  error" << endl; 
    } else {
        while (!Pendents.empty()){ // Inv: Tots els llibres pendents de la plataforma són classificats en les seves àrees corresponents. 
                                   // Si no hi ha llibres pendents, es mostra un missatge d'error.
            LlibreE le = Pendents.front();
            Pendents.pop();
            string area = arbreDeClassificacio.trobarArea(le);
            actualitzaLlibre(le, area);
        }
    }
}

/* Pre: Cert */
/* Post: Actualitza l'àrea del llibre 'le' amb el valor proporcionat 'area' a la cua 'Libros' */
void Plataforma::actualitzaLlibre (LlibreE &le, string area)
{
    Queue<LlibreE> auxQ;
    while (!Libros.empty()) { // Inv: el llibre 'le' de la plataforma té l'àrea actualitzada amb la nova àrea proporcionada 'area'. 
        LlibreE leAux = Libros.front();
        Libros.pop();
        if (le.consultar_titol() == leAux.consultar_titol()) {
            leAux.setArea(area);
            cout << leAux;
        }
        auxQ.push(leAux);
    }
    Libros = auxQ;
}
