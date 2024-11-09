#include <iostream>
#include "Character.hpp"

using namespace std;

//############################################
// Constructors
//############################################

// Pre: cert
// Post: el resultat és un personatge buit amb els atributs buits
Character::Character()
{
	name = "";
	job = "";
	gender = "";
	maxWeight = 0.0;
	equipment = {};
}

// Pre: cert
// Post: el resultat és un personatge amb els valors donats: 
// nom, treball, gènere, pes màxim i equipament
Character::Character(string n, string j, string g, float mw, vector <Equipment> e)
{
	name = n;
	job = j;
	gender = g;
	maxWeight = mw;
	equipment = e;
}

// Pre: cert
// Post: el resultat és una còpia del personatge P amb les mateixes propietats
Character::Character(const Character &P)
{
	this->name = P.name;
	this->job = P.job;
	this->gender = P.gender;
	this->maxWeight = P.maxWeight;
	this->equipment = P.equipment;
}

// Pre: cert
// Post: el resultat és una còpia del personatge P amb les mateixes propietats
Character& Character::operator=(const Character& P)
{
	this->name = P.name;
	this->job = P.job;
	this->gender = P.gender;
	this->maxWeight = P.maxWeight;
	this->equipment = P.equipment;
	return *this;
}

//############################################
// Destructors
//############################################

// Pre: cert
// Post: es destrueixen automàticament els objectes locals quan surten del seu àmbit de visibilitat
Character::~Character()
{
}

//############################################
// Consultors
//############################################

// Pre: cert
// Post: retorna el nom del personatge
string Character::getName()
{
	return name;
}

// Pre: cert
// Post: retorna el treball del personatge
string Character::getJob()
{
	return job;
}

// Pre: cert
// Post: retorna el gènere del personatge
string Character::getGender()
{
	return gender;
}

// Pre: cert
// Post: retorna el pes màxim que pot suportar el personatge
float Character::getMaxWeight()
{
	return maxWeight;
}

// Pre: cert
// Post: retorna el pes total actual dels equipaments del personatge
float Character::getWeight()
{
	float weight = 0.0;
	for(int i = 0; i < equipment.size(); i++)
	{
		weight += equipment[i].getWeight();
	}
	return weight;	
}

// Pre: 0 <= n < nombre d'equipaments del personatge
// Post: retorna l'equipament en la posició n
Equipment Character::getEquipment(int n)
{
	return equipment[n];
}

// Pre: cert
// Post: retorna el nombre d'equipaments del personatge
int Character::getNumEquipment()
{
	return equipment.size();
}

//############################################
// Modificadors
//############################################

// Pre: cert
// Post: assigna el nom n al personatge
void Character::setName(string n)
{
	name = n;
}

// Pre: cert
// Post: assigna el treball j al personatge
void Character::setJob(string j)
{
	job = j;
}

// Pre: cert
// Post: assigna el gènere g al personatge
void Character::setGender(string g)
{
	gender = g;
}

// Pre: cert
// Post: assigna el pes màxim mw al personatge
void Character::setMaxWeight(float mw)
{
	maxWeight = mw;
}

// Pre: cert
// Post: afegeix l'equipament e al personatgesi no se 
// sobrepassa el pes màxim, en cas contrari mostra un missatge d'error
void Character::addEquipment(Equipment &e)
{
	if(getWeight() + e.getWeight() > maxWeight)
	{
		cout << "No es pot afegir l'equipament, supera el pes màxim" << endl;
	}
	else
	{
		equipment.push_back(e);
	}
}

//############################################
// Entrada/Sortida
//############################################

// Pre: cert
// Post: imprimeix els atributs del personatge c al canal estàndard de sortida
ostream &operator<<(ostream &os, const Character &c)
{
	os << "Nom: " << c.name << "\n" << 
	"Treball: " << c.job << "\n" << 
	"Gènere: " << c.gender << "\n" <<
	"Pes Màxim: " << c.maxWeight;
	return os;
}

// Pre: cert
// Post: llegeix els atributs del personatge c des del canal estàndard d'entrada
istream &operator>>(istream &is, Character &c)
{
	is >> c.name >> c.job >> c.gender >> c.maxWeight;
	return is;
}
