#include <iostream>
#include "Player.hpp"

using namespace std;

//############################################
// Constructors
//############################################
 
// Pre: cert
// Post: el resultat és un jugador buit amb els atributs inicialitzats a valors buits
Player::Player() 
{
    name = "";
    login = "";
    password = "";
    characters = {};
}

// Pre: cert
// Post: el resultat és un jugador amb el nom, login, contrasenya i vector de personatges proporcionats com a paràmetres
Player::Player(string n, string l, string p, vector <Character> c)
{
    name = n;
    login = l;
    password = p;
    characters = c;
}

// Pre: cert
// Post: el resultat és una còpia exacta del jugador passat com a paràmetre
Player::Player(const Player &J)
{
    this->name = J.name;
    this->login = J.login;
    this->password = J.password;
    this->characters = J.characters;
}

// Pre: cert
// Post: el jugador actual és una còpia exacta del jugador passat com a paràmetre
Player& Player::operator=(const Player &J)
{
    this->name = J.name;
    this->login = J.login;
    this->password = J.password;
    this->characters = J.characters;
    return *this;
}

//############################################
// Destructors
//############################################

// Pre: cert
// Post: allibera els recursos utilitzats per l'objecte jugador. En aquest cas, no hi ha cap acció específica per realitzar
Player::~Player()
{

}

//############################################
// Consultors
//############################################

// Pre: cert
// Post: retorna el nom del jugador
string Player::getName()
{
    return name;
}

// Pre: cert
// Post: retorna el login del jugador
string Player::setLogIn()
{
    return login;
}

// Pre: cert
// Post: retorna la contrasenya del jugador
string Player::getPassword()
{
    return password;
}

// Pre: 0 <= n < characters.size()
// Post: retorna el personatge en la posició n del vector de personatges
Character Player::getCharacters(int n)
{
    return characters[n];
}

// Pre: cert
// Post: retorna el nombre de personatges que té el jugador
int Player::getNumCharacters()
{
    return characters.size();
}

// Pre: cert
// Post: retorna true si hi ha un personatge amb el nom especificat, false en cas contrari
bool Player::existCharacter(string n)
{
    bool found = false;
    for(int i = 0; i < characters.size() && found == false; i++)
    {
        if(characters[i].getName() == n)
        {
            return true;
            found = true;
        }
    }
    if (!found)
    {}
    return false;
}

//############################################
// Modificadors
//############################################

// Pre: cert
// Post: el nom del jugador passa a ser el nom especificat
void Player::setName(string n)
{
    name = n;
}

// Pre: cert
// Post: el login del jugador passa a ser el login especificat
void Player::setLogIn(string l)
{
    login = l;
}

// Pre: cert
// Post: la contrasenya del jugador passa a ser la contrasenya especificada
void Player::setPassword(string p)
{
    password = p;
}

// Pre: cert
// Post: s'afegeix un nou personatge al vector de personatges del jugador
void Player::addCharacter(Character &c)
{
    characters.push_back(c);
}

//############################################
// Lectura i escriptura
//############################################

// Pre: cert
// Post: escriu la informació del jugador (nom, login, contrasenya) en el flux de sortida especificat
ostream &operator<<(ostream &os, const Player &p)
{
    os << "Nom: " << p.name << endl;
    os << "Login: " << p.login << endl;
    os << "Password: " << p.password << endl;
    return os;
}

// Pre: cert
// Post: llegeix la informació del jugador (nom, login, contrasenya) del flux d'entrada especificat
istream &operator>>(istream &is, Player &p)
{
    is >> p.name >> p.login >> p.password;
    return is;
}
