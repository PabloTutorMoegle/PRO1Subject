#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Equipment.hpp"

using namespace std;

class Character {
    private:
        string name;
        string job;
        string gender;
        float maxWeight;

        vector <Equipment> equipment;

    public:
        //############################################
        // Constructors
        //############################################
        
        // Pre: cert
        // Post: el resultat és un personatge buit amb els atributs inicialitzats a valors buits o per defecte.
        Character();

        // Pre: cert
        // Post: el resultat és un personatge amb els valors assignats a nom, treball, gènere, pes màxim, i equipament.
        Character(string n, string j, string g, float mw, vector <Equipment> e);

        // Pre: cert
        // Post: el resultat és una còpia del personatge P amb les mateixes propietats (nom, treball, gènere, pes màxim i equipament).
        Character(const Character &P);

        // Pre: cert
        // Post: assigna les propietats del personatge P a l'objecte actual. El resultat és una còpia de P.
        Character& operator=(const Character &P);

        //############################################
        // Destructors
        //############################################

        // Pre: cert
        // Post: destrueix els objectes locals quan surten del seu àmbit de visibilitat. Allibera la memòria ocupada pels atributs de l'objecte.
        ~Character();

        //############################################
        // Consultors
        //############################################

        // Pre: cert
        // Post: retorna el nom del personatge.
        string getName();

        // Pre: cert
        // Post: retorna el treball del personatge.
        string getJob();

        // Pre: cert
        // Post: retorna el gènere del personatge.
        string getGender();

        // Pre: cert
        // Post: retorna el pes màxim que pot suportar el personatge.
        float getMaxWeight();

        // Pre: cert
        // Post: retorna el pes total actual dels equipaments que el personatge porta.
        float getWeight();

        // Pre: 0 <= n < nombre d'equipaments del personatge.
        // Post: retorna l'equipament que es troba a la posició n de la llista d'equipaments.
        Equipment getEquipment(int n);

        // Pre: cert
        // Post: retorna el nombre d'equipaments que té el personatge.
        int getNumEquipment();

        //############################################
        // Modificadors
        //############################################

        // Pre: cert
        // Post: assigna el nom n al personatge.
        void setName(string n);

        // Pre: cert
        // Post: assigna el treball j al personatge.
        void setJob(string j);

        // Pre: cert
        // Post: assigna el gènere g al personatge.
        void setGender(string g);

        // Pre: cert
        // Post: assigna el pes màxim mw al personatge.
        void setMaxWeight(float mw);

        // Pre: cert
        // Post: afegeix l'equipament e al personatge si el pes total no excedeix el pes màxim. Si el pes és superior, mostra un missatge d'error i no afegeix l'equipament.
        void addEquipment(Equipment &e);

        //############################################
        // Entrada/Sortida
        //############################################

        // Pre: cert
        // Post: imprimeix els atributs del personatge (nom, treball, gènere, pes màxim) al canal estàndard de sortida.
        friend ostream &operator<<(ostream &os, const Character &c);

        // Pre: cert
        // Post: llegeix els atributs del personatge (nom, treball, gènere, pes màxim) del canal estàndard d'entrada.
        friend istream &operator>>(istream &is, Character &c);
};

#endif
