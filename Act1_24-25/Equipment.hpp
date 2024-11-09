#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include <iostream>
#include <string>

using namespace std;

class Equipment {
    private:
        string name;
        string type;
        float weight;

    public:
        //############################################
        // Constructors
        //############################################

        // Pre: cert
        // Post: crea un objecte Equipment amb els atributs buits.
        Equipment();

        // Pre: cert
        // Post: crea un objecte Equipment amb el nom n, el tipus t i el pes w.
        Equipment(string n, string t, float w);

        // Pre: cert
        // Post: crea una còpia de l'objecte Equipment E.
        Equipment(const Equipment &E);

        // Pre: cert
        // Post: l'objecte actual Equipment es copia amb els mateixos valors que E.
        Equipment& operator=(const Equipment &E);
        
        //############################################
        // Destructors
        //############################################

        // Pre: cert
        // Post: destrueix l'objecte Equipment alliberant qualsevol recurs associat.
        ~Equipment();
        
        //############################################
        // Consultors
        //############################################

        // Pre: cert
        // Post: retorna el nom de l'equipament.
        string getName();

        // Pre: cert
        // Post: retorna el tipus de l'equipament.
        string getType();

        // Pre: cert
        // Post: retorna el pes de l'equipament.
        float getWeight();
        
        //############################################
        // Modificadors
        //############################################

        // Pre: cert
        // Post: assigna el nom n a l'equipament.
        void setName(string n);

        // Pre: cert
        // Post: assigna el tipus t a l'equipament.
        void setType(string t);

        // Pre: cert
        // Post: assigna el pes w a l'equipament.
        void setWeight(float w);

        //############################################
        // Entrada/Sortida
        //############################################

        // Pre: cert
        // Post: imprimeix els atributs de l'equipament e al canal estàndard de sortida.
        friend ostream &operator<<(ostream &os, const Equipment &e);

        // Pre: cert
        // Post: llegeix els atributs de l'equipament e des del canal estàndard d'entrada.
        friend istream &operator>>(istream &is, Equipment &e);
};

#endif
