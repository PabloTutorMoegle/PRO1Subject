#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Character.hpp"

using namespace std;

class Player {
    private:
        string name;
        string login;
        string password;

        vector<Character> characters;

    public:
        //############################################
        // Constructors
        //############################################
        
        // Pre: cert
        // Post: el resultat és un jugador buit amb els atributs inicialitzats a valors buits
        Player();

        // Pre: cert
        // Post: el resultat és un jugador amb el nom, login, contrasenya i vector de personatges proporcionats com a paràmetres
        Player(string n, string l, string p, vector<Character> c);

        // Pre: cert
        // Post: el resultat és una còpia exacta del jugador passat com a paràmetre
        Player(const Player &J);

        // Pre: cert
        // Post: el jugador actual és una còpia exacta del jugador passat com a paràmetre
        Player& operator=(const Player &J);

        //############################################
        // Destructors
        //############################################

        // Pre: cert
        // Post: allibera els recursos utilitzats per l'objecte jugador. En aquest cas, no hi ha cap acció específica per realitzar
        ~Player();

        //############################################
        // Consultors
        //############################################

        // Pre: cert
        // Post: retorna el nom del jugador
        string getName();

        // Pre: cert
        // Post: retorna el login del jugador
        string setLogIn();

        // Pre: cert
        // Post: retorna la contrasenya del jugador
        string getPassword();

        // Pre: 0 <= n < characters.size()
        // Post: retorna el personatge en la posició n del vector de personatges
        Character getCharacters(int n);

        // Pre: cert
        // Post: retorna el nombre de personatges que té el jugador
        int getNumCharacters();

        // Pre: cert
        // Post: retorna true si hi ha un personatge amb el nom especificat, false en cas contrari
        bool existCharacter(string n);

        //############################################
        // Modifiers
        //############################################

        // Pre: cert
        // Post: el nom del jugador passa a ser el nom especificat
        void setName(string name);

        // Pre: cert
        // Post: el login del jugador passa a ser el login especificat
        void setLogIn(string login);

        // Pre: cert
        // Post: la contrasenya del jugador passa a ser la contrasenya especificada
        void setPassword(string password);

        // Pre: cert
        // Post: s'afegeix un nou personatge al vector de personatges del jugador
        void addCharacter(Character &c);

        //############################################
        // Reading and writing
        //############################################

        // Pre: cert
        // Post: escriu la informació del jugador (nom, login, contrasenya) en el flux de sortida especificat
        friend ostream &operator<<(ostream &os, const Player &p);

        // Pre: cert
        // Post: llegeix la informació del jugador (nom, login, contrasenya) del flux d'entrada especificat
        friend istream &operator>>(istream &is, Player &p);
};

#endif
