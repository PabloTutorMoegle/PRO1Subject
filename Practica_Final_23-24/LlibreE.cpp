#include <iostream>
#include <string>
#include "Data.hpp"
#include "LlibreE.hpp"

using namespace std;

//*********************************************************
// Constructors i assignació
//*********************************************************

/* Pre: cert */ 
/* Post: crea un llibre amb el títol, data de publicació i 
    àrea buits, i sense paraules clau */
LlibreE::LlibreE()
{}

/* Pre: cert */ 
/* Post: crea un llibre amb el títol, data de publicació, 
    àrea i paraules clau del llibre 'le' */
LlibreE::LlibreE(const LlibreE &le)
{
    titol = le.titol;
    data = le.data;
    paraulesClau = le.paraulesClau;
    area = le.area;
}
    
/* Pre: cert */
/* Post: el resultat és un llibre amb el títol, data de 
    publicació, àrea i paraules clau del llibre 'le' */	 
LlibreE& LlibreE::operator=(const LlibreE &le)
{
    this->titol = le.titol;
    this->data = le.data;
    this->paraulesClau = le.paraulesClau;
    this->area = le.area;
    return *this;
}

//*********************************************************
// Destructor
//*********************************************************

/* Destructor per defecte */ 
LlibreE::~LlibreE()
{}

//*********************************************************
// Modificadors
//*********************************************************

/* Pre: _area no és una cadena de caràcters buida. */
/* Post: L'atribut 'area' de l'objecte LlibreE s'estableix amb el valor proporcionat com a paràmetre. */
void LlibreE::setArea(const string & _area){
    this->area = _area; 
}


//*********************************************************
// Consultors
//*********************************************************

/* Pre: 'paraulesClau' conté les paraules clau (string) del llibre */
/* Post: Les paraules clau del llibre ('paraulesClau') estan ordenades 
alfabèticament en ordre creixent, i després d'això, estan invertides 
perquè estiguin en ordre alfabètic invers */
void LlibreE::ordenaParaulesClau()
{
    int n = paraulesClau.size();
    for (int i = 0; i < n - 1; i++) { // Inv: Després de cada iteració d'i, els últims i elements de paraulesClau estan ordenats.
        for (int j = 0; j < n - i - 1; j++) { // Inv: Després de cada iteració de j, els elements paraulesClau[0..n-i-1] estan parcialment ordenats,
                                              // de manera que el valor més gran es desplaça cap al final.
            if (paraulesClau[j] > paraulesClau[j + 1]) {
                // Swap the words
                string temp = paraulesClau[j];
                paraulesClau[j] = paraulesClau[j + 1];
                paraulesClau[j + 1] = temp;
            }
        }
    }
    int start = 0;
    int end = n - 1;
    while (start < end) { // Inv: El vector de paraules clau està ordenat alfabèticament*.
        string temp = paraulesClau[start];
        paraulesClau[start] = paraulesClau[end];
        paraulesClau[end] = temp;
        start++;
        end--;
    }
}

/* Pre: cert */ 
/* Post: el resultat és el títol del llibre p.i. */
string LlibreE::consultar_titol() const
{
    return titol;
}

/* Pre: cert */ 
/* Post: el resultat és la data de publicació del llibre p.i. */
Data LlibreE::consultar_dataPub() const
{
    return data;
}

/* Pre: cert */ 
/* Post: el resultat les paraules clau del llibre p.i. */
vector<string> LlibreE::consultar_paraulesClau() const
{
    return paraulesClau;
}

/* Pre: cert */ 
/* Post: el resultat és l'àrea temàtica del llibre p.i. */
string LlibreE::consultar_area() const
{
    return area;
}

/* Pre: cert */
/* Post: retorna un booleà que indica si la data de publicació del 
    llibre p.i. és posterior a la del llibre 'le' (true) o no ho és (false) */
bool LlibreE::compare(const LlibreE &le) const
{   //compara las fechas de publicacion de dos libros
    return data > le.data;    
}

/* Pre: 'le' és una instància vàlida de la classe LlibreE */
/* Post: Retorna 'true' si el títol del llibre actual ('*this') és igual al títol del llibre 'le'. Altrament retorna 'false' */
bool LlibreE::operator==(const LlibreE &le) const
{
    return le.titol == titol;
}

//*********************************************************
// Lectura i escriptura
//*********************************************************

/* Pre: estan preparats al canal estàndard d'entrada totes les dades del llibre */
/* Post: el llibre 'libro' passa a tenir les dades llegides del canal
    estàndard d'entrada com a titulo, data i area/as, respectivament */		
istream& operator>>(istream &is, LlibreE &libro)
{
    bool punt = false;
    is >> libro.titol >> libro.data;
    string s;
    while (!punt) { // Invariant: el llibre 'libro' té les dades correctament llegides del canal d'entrada estàndard i 
                    // les seves paraules clau estan ordenades alfabèticament.
        is >> s;
        libro.paraulesClau.push_back(s);
        punt = s == ".";
    }
    libro.paraulesClau.pop_back();
    libro.ordenaParaulesClau();
    return is;
}

/* Pre: cert */
/* Post: s'han escrit els atributs titol, data i area/as del llibreE 'libro'
    al canal estàndard de sortida */
ostream& operator<<(ostream &os, const LlibreE &libro)
{
    os << "  títol: " << libro.titol << "\n" << 
    "  data publicació: " << libro.data << "\n" <<
    "  paraules clau: ";
    int i = libro.paraulesClau.size() - 1;
    while (i >= 0)
    {    // Invariant: S'escriuen els atributs titol, data, 
         // paraules clau i àrea/as del llibreE 'libro' al canal d'entrada estàndard de sortida.
        if (i == 0) os << libro.paraulesClau[i];
        else        os << libro.paraulesClau[i] << " ";
        i--;
    }
    os << "\n" << "  àrea temàtica: " << libro.area << "\n"
    "  --------------------" << endl;
    return os;
}
