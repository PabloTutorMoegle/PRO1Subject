#include <iostream>
#include "Equipment.hpp"

using namespace std;

//############################################
// Constructors
//############################################

// Pre: cert
// Post: el resultat és un equipament buit amb els atributs buits
Equipment::Equipment()
{
    name = "";
    type = "";
    weight = 0.0;
}

// Pre: cert
// Post: el resultat és un equipament amb els valors donats: nom, tipus i pes
Equipment::Equipment(string n, string t, float w)
{
    name = n;
    type = t;
    weight = w;
}

// Pre: cert
// Post: el resultat és una còpia de l'equipament E, amb els 
// mateixos valors de nom, tipus i pes
Equipment::Equipment(const Equipment &E)
{
    this->name = E.name;
    this->type = E.type;
    this->weight = E.weight;
}

// Pre: cert
// Post: el resultat és una còpia de l'equipament E amb els 
// mateixos valors de nom, tipus i pes
Equipment& Equipment::operator=(const Equipment &E)
{
    this->name = E.name;
    this->type = E.type;
    this->weight = E.weight;
    return *this;
}

//############################################
// Destructors
//############################################

// Pre: cert
// Post: es destrueixen automàticament els objectes locals quan 
// surten del seu àmbit de visibilitat
Equipment::~Equipment()
{

}

//############################################
// Consultors
//############################################

// Pre: cert
// Post: retorna el nom de l'equipament
string Equipment::getName()
{
    return name;
}

// Pre: cert
// Post: retorna el tipus de l'equipament
string Equipment::getType()
{
    return type;
}

// Pre: cert
// Post: retorna el pes de l'equipament
float Equipment::getWeight()
{
    return weight;
}

//############################################
// Modificadors
//############################################

// Pre: cert
// Post: assigna el nom n a l'equipament
void Equipment::setName(string n)
{
    name = n;
}

// Pre: cert
// Post: assigna el tipus t a l'equipament
void Equipment::setType(string t)
{
    type = t;
}

// Pre: cert
// Post: assigna el pes w a l'equipament
void Equipment::setWeight(float w)
{
    weight = w;
}

//############################################
// Entrada/Sortida
//############################################

// Pre: cert
// Post: imprimeix els atributs de l'equipament e al canal estàndard de sortida
ostream &operator<<(ostream &os, const Equipment &e)
{
    os << "Nom: " << e.name << "\n" <<
    "Tipus: " << e.type << "\n" << 
    "Pes: " << e.weight << endl;
    return os;
}

// Pre: cert
// Post: llegeix els atributs de l'equipament e des del canal estàndard d'entrada
istream &operator>>(istream &is, Equipment &e)
{
    is >> e.name >> e.type >> e.weight;
    return is;
}
