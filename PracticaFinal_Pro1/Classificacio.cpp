#include <iostream>
#include "Classificacio.hpp"

using namespace std;

/* Pre: cert */
/* Post: Crea una nova instància de la classe Classificacio i inicialitza els seus atributs al seu estat inicial */
Classificacio::Classificacio()
{}

/* Pre: 'T' és un arbre binari vàlid */
/* Post: Crea una nova instància de la classe Classificacio i inicialitza l'atribut 'arbolAreas' amb una còpia de 'T' */
Classificacio::Classificacio(BinaryTree<string> &T)
{
    arbolAreas = T;
}

/* Pre: 'C' és una instància vàlida de la classe Classificacio */
/* Post: L'objecte actual ha copiat tots els atributs de 'C' i és retornat per permetre assignacions en cadena */
Classificacio &Classificacio::operator=(const Classificacio &C)
{
    arbolAreas = C.arbolAreas;
    return *this;
}

/* Pre: L'objecte 'Classificacio' és una instància vàlida de la classe Classificacio */
/* Post: l'objecte ha estat destruït */
Classificacio::~Classificacio()
{}

/* Pre: 'T' és un arbre binari vàlid del tipus BinaryTree<string> */
/* Post: L'atribut 'arbolAreas' de l'objecte Classificacio ha estat actualitzat per ser una còpia de 'T' */
void Classificacio::setArbreAreas(BinaryTree<string> &T)
{
    arbolAreas = T;
}

/* Pre: 'area' és un 'string' vàlid */
/* Post: Retorna 'true' si 'area' es troba a 'arbolAreas'. Altrament retorna 'false' */
bool Classificacio::existeixArea(string area)
{
    return arbolAreas.search(area);
}

/* Pre: 'C' és una instància vàlida de la classe Classificacio */
/* Post: Retorna una còpia de l'arbre binari 'arbolAreas' de l'objecte 'C' */
BinaryTree<string> Classificacio::consultar_arbre(Classificacio &C)
{
    return C.arbolAreas;
}

/* Pre: 'le' és una instància vàlida de la classe LlibreE */
/* Post: Retorna una cadena que representa l'àrea a la qual pertany el llibre 'le' */
string Classificacio::trobarArea(LlibreE &le)
{   
    string result;
    vector<string> paraulesClau = le.consultar_paraulesClau();
    if (paraulesClau.size() == 1)
    {
        result = paraulesClau[0];
        // Invariant: 'result' conté l'àrea del llibre 'le', sent 'result' igual a la paraula clau si només n'hi ha una, 
        // i si n'hi ha més d'una, utilitza l'arbre binari de classificació per trobar l'àrea.
    }
    else
    {
        BinaryTree<string> T = consultar_arbre(*this);
        result = T.findDeepestCommonNode(paraulesClau, T);
        // HI: findDeepestCommonNode retorna l'àrea a partir de les paraules clau en un arbre binari amb alçada màxima.
        // FF: l'alçada màxima de l'arbre de classificació.
    }
    return result;
}

