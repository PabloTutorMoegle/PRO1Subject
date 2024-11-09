#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Character.hpp"
#include "Equipment.hpp"

using namespace std;

class Game {
    private:
    
        vector <Player> players;
        vector <Character> characters;
        vector <Equipment> items;

    public:
        //############################################
        // Constructors
        //############################################

        // Pre: cert
        // Post: el resultat és un joc buit amb les llistes de jugadors, personatges i ítems inicialitzades buides
        Game();

        // Pre: cert
        // Post: el resultat és un joc amb els jugadors, personatges i ítems proporcionats com a paràmetres
        Game(vector <Player> p, vector <Character> c, vector <Equipment> i);

        // Pre: cert
        // Post: el resultat és una còpia exacta del joc passat com a paràmetre
        Game(const Game &G);

        // Pre: cert
        // Post: el joc actual és una còpia exacta del joc passat com a paràmetre
        Game& operator=(const Game &G);

        //############################################
        // Destructors
        //############################################

        // Pre: cert
        // Post: allibera els recursos utilitzats per l'objecte joc. En aquest cas, no hi ha cap acció específica per realitzar
        ~Game();

        //############################################
        // Consultors
        //############################################

        // Pre: cert
        // Post: mostra tots els jugadors per pantalla, o indica un error si no n'hi ha cap
        void showPlayers();

        // Pre: cert
        // Post: mostra tots els ítems d'equipament per pantalla, o indica un error si no n'hi ha cap
        void showItems();

        // Pre: cert
        // Post: mostra tots els personatges associats al jugador especificat, o indica un error si no existeix el jugador o si no té personatges
        void charactersFromPlayer(string p);

        // Pre: cert
        // Post: mostra els ítems d'equipament associats al personatge especificat, o indica un error si no existeix el personatge
        void itemsFromCharacter(string n);

        //############################################
        // Modifiers
        //############################################

        // Pre: cert
        // Post: equipa el personatge especificat amb l'ítem indicat, o mostra un error si no es pot realitzar per algun motiu
        void equipCharacter(string c, string i);

        // Pre: cert
        // Post: crea un nou jugador a partir de les dades introduïdes per l'usuari, o mostra un error si ja existeix
        void createPlayer();

        // Pre: cert
        // Post: crea un nou personatge associat a un jugador especificat, o mostra un error si el personatge ja existeix, el pes és massa elevat,
        // el tipus de personatge no és vàlid, o el jugador no existeix o ja té el nombre màxim de personatges (5)
        void createCharacter();

        // Pre: cert
        // Post: crea un nou ítem d'equipament amb les dades introduïdes per l'usuari, o mostra un error si l'ítem ja existeix,
        // el seu pes és massa elevat o el tipus d'ítem no és vàlid
        void createItem();

        // Pre: cert
        // Post: busca en el vector de jugadors si es troba el jugador en qüestió, retorna el jugador o mostra un error si no es troba
        Player searchPlayer(string n);

        // Pre: cert
        // Post: busca en el vector de personatges si es troba el personatge en qüestió, retorna el personatge o mostra un error si no es troba
        Character searchCharacter(string n);

        // Pre: cert
        // Post: busca en el vector d'equipaments si es troba l'ítem en qüestió, retorna l'ítem o mostra un error si no es troba
        Equipment searchItem(string n);

        // Pre: cert
        // Post: retorna true si existeix un jugador amb el nom indicat, false en cas contrari
        bool existPlayer(string n);

        // Pre: cert
        // Post: retorna true si existeix un personatge amb el nom indicat, false en cas contrari
        bool existCharacter(string n);

        // Pre: cert
        // Post: retorna true si existeix un ítem amb el nom indicat, false en cas contrari
        bool existItem(string n);

        // Pre: cert
        // Post: retorna la posició del jugador amb el nom indicat, o -1 si no existeix
        int returnPlayerIndex(string n);

        // Pre: cert
        // Post: retorna la posició del personatge amb el nom indicat, o -1 si no existeix
        int returnCharacterIndex(string n);
};

#endif
