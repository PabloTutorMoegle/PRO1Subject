#include <iostream>
#include "Game.hpp"

using namespace std;

//############################################
// Constructors
//############################################
 
// Pre: cert
// Post: el resultat és un joc buit amb les llistes de jugadors, personatges i ítems inicialitzades buides
Game::Game()
{
    players = {};
    characters = {};
    items = {};
}

// Pre: cert
// Post: el resultat és un joc amb els jugadors, personatges i ítems proporcionats com a paràmetres
Game::Game(vector <Player> p, vector <Character> c, vector <Equipment> i)
{
    players = p;
    characters = c;
    items = i;
}

// Pre: cert
// Post: el resultat és una còpia exacta del joc passat com a paràmetre
Game::Game(const Game &G)
{
    players = G.players;
    characters = G.characters;
    items = G.items;
}

// Pre: cert
// Post: el joc actual és una còpia exacta del joc passat com a paràmetre
Game& Game::operator=(const Game &G)
{
    this->players = G.players;
    this->characters = G.characters;
    this->items = G.items;
    return *this;
}

//############################################
// Destructors
//############################################

// Pre: cert
// Post: allibera els recursos utilitzats per l'objecte joc. En aquest cas, no hi ha cap acció específica per realitzar
Game::~Game()
{

}

//############################################
// Consultors
//############################################

// Pre: cert
// Post: mostra tots els jugadors per pantalla, o indica un error si no n'hi ha cap
void Game::showPlayers()
{
    cout << "--------------------" << endl;
    if (players.size() != 0)
    {
        cout << "Tots els jugadors" << endl;
        for(int i = 0; i < players.size(); i++)
        {
            cout << players[i] << endl;
        }
    }
    else
    {
        cout << "ERROR: No hi ha jugadors" << endl;
    }
}

// Pre: cert
// Post: mostra tots els ítems d'equipament per pantalla, o indica un error si no n'hi ha cap
void Game::showItems()
{
    cout << "--------------------" << endl;
    if (items.size() != 0)
    {
        cout << "Tots els Items d'equipament" << endl;
        for(int i = 0; i < items.size(); i++)
        {
            cout << items[i] << endl;
        }
    }
    else
    {
        cout << "ERROR: No hi ha items d'equipament" << endl;
    }
}

// Pre: cert
// Post: mostra tots els personatges associats al jugador especificat, o indica un error si no existeix el jugador o si no té personatges
void Game::charactersFromPlayer(string p)
{
    int n = returnPlayerIndex(p);
    if (n != -1)
    {
        if (players[n].getNumCharacters() == 0)
        {
            cout << "ERROR: El jugador " << p << " no té personatges " << endl;
            return;
        }
        else
        {    
            cout << "--------------------" << endl;
            cout << "Tots els personatges de " << "\n" << players[n] << endl;
            for(int i = 0; i < players[n].getNumCharacters(); i++)
            {
                cout << players[n].getCharacters(i) << endl;
                cout << "----------" << endl;
            }
        }
    }
    else 
    {
        cout << "ERROR: El jugador " << p << " no existeix " << endl;
    }
}

// Pre: cert
// Post: mostra els ítems d'equipament associats al personatge especificat, o indica un error si no existeix el personatge
void Game::itemsFromCharacter(string n)
{
    int num = returnCharacterIndex(n);
    if (num == -1)
    {
        cout << "ERROR: El personatge " << n << " no existeix " << endl;
        cout << "--------------------" << endl;
        return;
    }
    else
    {
        cout << "--------------------" << endl;
        cout << "Equipament de " << endl;
        cout << characters[num] << endl;
        cout << endl;
        for(int i = 0; i < characters[num].getNumEquipment(); i++)
        {
            Equipment tempE = characters[num].getEquipment(i);
            cout << tempE;
            cout << "----------" << endl;
        }
        if (characters[num].getNumEquipment() == 0)
        {
            cout << characters[num].getName() << " no té equipament" << "\n" << "----------" << endl;
        }
        else
        {
            cout << "Pes total per " << n << ": " << characters[num].getWeight() << "\n" << "----------" << endl;
        }
    }
}

//############################################
// Modificadors
//############################################

//############################################
// Modificadors
//############################################

// Pre: cert
// Post: equipa el personatge especificat amb l'ítem indicat, o mostra un error si no es pot realitzar per algun motiu
void Game::equipCharacter(string c, string i)
{
    bool foundCharacter = existCharacter(c);
    bool foundItem = existItem(i);
    if(foundCharacter && foundItem)
    {
        int num = returnCharacterIndex(c);
        Equipment tempE = searchItem(i);
        bool found = false;
        for(int a = 0; a < characters[num].getNumEquipment() && found == false; a++)
        {
            if(characters[num].getEquipment(a).getName() == tempE.getName())
            {
                found = true;
            }
        }
        if(found == true)
        {
            cout << "ERROR: El personatge " << c << " ja està equipat amb " << i << endl;
        }
        else if(characters[num].getWeight() + tempE.getWeight() > characters[num].getMaxWeight())
        {
            cout << "ERROR: L'item " << i << " sobrepassa el pes màxim per al personatge " << c << endl;
        }
        else if(characters[num].getNumEquipment() >= 6)
        {
            cout << "ERROR: El personatge " << c << " ja està equipat amb 6 ítems" << endl;
        }
        else
        {
            characters[num].addEquipment(tempE);
            cout << "Personatge " << c << " equipat amb " << i << endl;
        }
    }
    else
    {
        if (foundCharacter == false)
        {
            cout << "ERROR: El personatge " << c << " no existeix " << endl;
        }
        if (foundItem == false)
        {
            cout << "ERROR: L'item " << i << " no existeix. No es pot assignar a " << c << endl;
        }
    }
}

// Pre: cert
// Post: crea un nou jugador a partir de les dades introduïdes per l'usuari, o mostra un error si ja existeix
void Game::createPlayer()
{
    Player temp;
    cin >> temp;
    bool exist = existPlayer(temp.getName());
    if (exist)
    {
        cout << "ERROR: El jugador " << temp.getName() << " ja existeix " << endl;
    }
    else 
    {
        players.push_back(temp);
        cout << "Jugador " << temp.getName() << " creat correctament " << endl;
    }
}

// Pre: cert
// Post: crea un nou personatge associat a un jugador especificat, o mostra un error si el personatge ja existeix, el pes és massa elevat,
// el tipus de personatge no és vàlid, o el jugador no existeix o ja té el nombre màxim de personatges (5)
void Game::createCharacter()
{
    Character tempC;
    cin >> tempC;
    string playerName;
    cin >> playerName;
    bool exist = existCharacter(tempC.getName());
    if (exist == true)
    {
        for (int i = 0; i < players.size(); i++)
        {
            if (players[i].existCharacter(tempC.getName()))
            {
                cout << "ERROR: El jugador " << players[i].getName() << " ja té el personatge " << tempC.getName() << ". No es pot afegir a "
                     << playerName << endl;
                return;
            }
        }
    }
    else
    {
        if (tempC.getJob() == "Guerrer" || tempC.getJob() == "Mag" || tempC.getJob() == "Sacerdot" || tempC.getJob() == "Paladi")
        {
            if (tempC.getMaxWeight() < 75.0)
            {
                bool foundPlayer = existPlayer(playerName);
                if (foundPlayer)
                {
                    int n = returnPlayerIndex(playerName);
                    if (players[n].getNumCharacters() >= 5)
                    {
                        cout << "ERROR: El jugador " << players[n].getName() << " ja té 5 personatges. No es pot afegir el personatge " <<
                        tempC.getName() << endl;

                    }
                    else
                    {
                        characters.push_back(tempC);
                        players[n].addCharacter(tempC);
                        cout << "Personatge " << tempC.getName() << " creat correctament per al jugador " << players[n].getName() << endl;
                    }            
                }
                else 
                {
                    cout << "ERROR: El Jugador no existeix " << endl;
                }
            }
            else 
            {
                cout << "ERROR: El pes màxim del personatge " << tempC.getName() << " sobrepassa els 75kg: " 
                     << tempC.getMaxWeight() << endl;
            }
        }
        else
        {
            cout << "ERROR: El tipus del personatge " << tempC.getName() << " no és correcte: " << tempC.getJob() << endl;
        }
    }
}

// Pre: cert
// Post: crea un nou ítem d'equipament amb les dades introduïdes per l'usuari, o mostra un error si l'ítem ja existeix,
// el seu pes és massa elevat o el tipus d'ítem no és vàlid
void Game::createItem()
{
    Equipment temp;
    cin >> temp;
    bool found = existItem(temp.getName());
    if (found)
    {
        cout << "ERROR: L'item d'equipament " << temp.getName() << " ja existeix " << endl;
    }
    else 
    {
        if(temp.getType() == "Arma" || temp.getType() == "Roba" || temp.getType() == "Armadura" || temp.getType() == "Talisma")
        {
            float w = temp.getWeight();
            if (w < 30.0)
            {
                items.push_back(temp);
                cout << "Item " << temp.getName() << " creat correctament " << endl;
            }
            else 
            {
                cout << "ERROR: L'item d'equipament " << temp.getName() << " sobrepassa els 30kg " << endl;
            }
        }
        else
        {
            cout << "ERROR: L'item d'equipament " << temp.getName() << " té un tipus incorrecte " << temp.getType() << endl;
        }
    }
}
// Pre: cert
// Post: busca en el vector de jugados si es troba el jugador en questió que estem buscant, retorna true en cas de que es trobi i en cas contrari
// retorna una negació per dir que no existeix
Player Game::searchPlayer(string n)
{
    bool found = false;
    for(int i = 0; i < players.size(); i++)
    {
        if(players[i].getName() == n)
        {
            return players[i];
            found = true;
        }
    }
    if (!found)
    {
        cout << "Player not found" << endl;
    }
    return Player();
}
// Pre: cert
// Post: busca en el vector de personatges si es troba el personatge en questió que estem buscant, retorna true en cas de que es trobi i en cas contrari
// retorna una negació per dir que no existeix
Character Game::searchCharacter(string n)
{
    bool found = false;
    for(int i = 0; i < characters.size(); i++)
    {
        if(characters[i].getName() == n)
        {
            return characters[i];
            found = true;
        }
    }
    if (!found)
    {}
    return Character();
}
// Pre: cert
// Post: busca en el vector d'equipaments si es troba l'equipament en questió que estem buscant, retorna true en cas de que es trobi i en cas contrari
// retorna una negació per dir que no existeix
Equipment Game::searchItem(string n)
{
    bool found = false;
    for(int i = 0; i < items.size() && found == false; i++)
    {
        if(items[i].getName() == n)
        {
            return items[i];
            found = true;
        }
    }
    if (found == false)
    {
        cout << "Item not found" << endl;
    }
    else 
    {
    }
    return Equipment();
}
// Pre: cert
// Post: busca en el vector de jugados si existeix el jugador en questió que estem buscant, retorna true en cas de que existeixi i en cas contrari
// retorna una negació per dir que no existeix
bool Game::existPlayer(string n)
{
    bool found = false;
    for(int i = 0; i < players.size(); i++)
    {
        if(players[i].getName() == n)
        {
            found = true;
        }
    }
    return found;
}
// Pre: cert
// Post: busca en el vector de personatges si existeix el personatge en questió que estem buscant, retorna true en cas de que existeixi i en cas contrari
// retorna una negació per dir que no existeix
bool Game::existCharacter(string n)
{
    bool found = false;
    for(int i = 0; i < characters.size() && found == false; i++)
    {
        if(characters[i].getName() == n)
        {
            found = true;
        }
    }
    return found;
}
// Pre: cert
// Post: busca en el vector d'equipaments si existeix el equipament en questió que estem buscant, retorna true en cas de que existeixi i en cas contrari
// retorna una negació per dir que no existeix
bool Game::existItem(string n)
{
    bool found = false;
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i].getName() == n)
        {
            found = true;
        }
    }
    return found;
}
// Pre: cert
// Post: retorna el nom de tots els jugadors que han sigut enregistrats
int Game::returnPlayerIndex(string n)
{
    for(int i = 0; i < players.size(); i++)
    {
        if(players[i].getName() == n)
        {
            return i;
        }
    }
    return -1;
}
// Pre: cert
// Post: retorna el nom de tots els personatges que s'han enregistrat
int Game::returnCharacterIndex(string n)
{
    for(int i = 0; i < characters.size(); i++)
    {
        if(characters[i].getName() == n)
        {
            return i;
        }
    }
    return -1;
}
