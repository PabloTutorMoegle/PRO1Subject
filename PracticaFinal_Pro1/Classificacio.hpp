#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "BinaryTree.hpp"
#include "LlibreE.hpp"

using namespace std;

class Classificacio{

    private:

    BinaryTree<string> arbolAreas; 

    public:
    /* Pre: cert */
    /* Post: Crea una nova instància de la classe Classificacio i inicialitza els seus atributs al seu estat inicial */
    Classificacio();

    /* Pre: 'T' és un arbre binari vàlid */
    /* Post: Crea una nova instància de la classe Classificacio i inicialitza l'atribut 'arbolAreas' amb una còpia de 'T' */
    Classificacio(BinaryTree<string> &T);

    Classificacio(const Classificacio &C);

    /* Pre: 'C' és una instància vàlida de la classe Classificacio */
    /* Post: L'objecte actual ha copiat tots els atributs de 'C' i és retornat per permetre assignacions en cadena */	
    Classificacio &operator=(const Classificacio &C);

    /* Pre: L'objecte 'Classificacio' és una instància vàlida de la classe Classificacio */
    /* Post: Tots els recursos ocupats per l'objecte 'Classificacio' han estat alliberats i l'objecte ha estat destruït */
    ~Classificacio();

    /* Pre: 'T' és un arbre binari vàlid del tipus BinaryTree<string> */
    /* Post: L'atribut 'arbolAreas' de l'objecte Classificacio ha estat actualitzat per ser una còpia de 'T' */
    void setArbreAreas(BinaryTree<string> &T);

    /* Pre: 'area' és un 'string' vàlid */
    /* Post: Retorna 'true' si 'area' es troba a 'arbolAreas'. Altrament retorna 'false' */
    bool existeixArea(string area);

    /* Pre: 'C' és una instància vàlida de la classe Classificacio */
    /* Post: Retorna una còpia de l'arbre binari 'arbolAreas' de l'objecte 'C' */
    BinaryTree<string> consultar_arbre(Classificacio &C);

    /* Pre: 'le' és una instància vàlida de la classe LlibreE */
    /* Post: Retorna una cadena que representa l'àrea a la qual pertany el llibre 'le' */
    string trobarArea(LlibreE &le);

};
