#ifndef VOL_HPP
#define VOL_HPP

#include <string>
#include <iostream>
#include <vector>
#include "Passatger.hpp"

using namespace std;

class Vol {
// Tipus de mòdul: dades
// Descripció del tipus: Representa un vol del que s'indiquen
// el seu número, ciutat origen, ciutat destinació, hora de
// sortida, hora d'arribada, estat del vol i nombre de seientsDisponibles
// disponibles.

private:
    string numVol, ciutatOrigen, ciutatDestinacio, estat, horaSortida, horaArribada;
    int seientsDisponibles;

public:

    //*********************************************************
    // Constructors
    //*********************************************************

    /* Pre: Cert */
    /* Post: el vol està inicialitzat amb tots els valors per defecte */
    Vol();

    /* Pre: Cert */
    /* Post: el vol està inicialitzat amb els valors passats per paràmetre */
    Vol(string nV, string cO, string cD, string hS, string hA, string e, int sD);

    /* Pre: Cert */
    /* Post: el vol està inicialitzat amb els mateixos atributs del vol passat per paràmetre */
    Vol(const Vol &v);

    /* Pre: Cert */
    /* Post: tots els atributs del vol passat per paràmetre s'han copiat al p.i. */
    Vol &operator=(const Vol &v);

    //*********************************************************
    // Destructor
    //*********************************************************

    /* Post: Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
    ~Vol();

    //*********************************************************
    // Modificadors
    //*********************************************************

    /* Pre: El nombre de seients disponibles és superior a 0 */
    /* Post: Els seients disponibles del vol s'han reduït en una unitat */
    void reduirSeients();

    //*********************************************************
    // Consultors
    //*********************************************************

    /* Pre: Cert */
    /* Post: S'ha retornat el número de vol del p.i. */
    string getNumVol() const;

    /* Pre: Cert */
    /* Post: S'ha retornat la ciutat d'origen del p.i. */
    string getCiutatOrigen() const;

    /* Pre: Cert */
    /* Post: S'ha retornat la ciutat destinació del p.i. */
    string getCiutatDest() const;

    /* Pre: Cert */
    /* Post: S'ha retornat l'hora de sortida del p.i. */
    string getHoraSortida() const;

    /* Pre: Cert */
    /* Post: S'ha retornat l'hora d'arribada del p.i. */
    string getHoraArribada() const;

    /* Pre: Cert */
    /* Post: S'ha retornat l'estat del p.i. */
    string getEstat() const;

    /* Pre: Cert */
    /* Post: S'ha retornat el nombre de seientsDisponibles disponibles del p.i. */
    int getSeientsDisponibles() const;

    //*********************************************************
    // Lectura i escriptura
    //*********************************************************

    /* Pre: Cert */
    /* Post: S'han escrit al canal estàndard de sortida els atributs del vol v */
    friend ostream &operator<<(ostream &os, const Vol &v);

    /* Pre: Estan preparats al canal estandar d'entrada 6 strings i un enter, en aquest ordre */
    /* Post: El vol v passa a tenir els atributs llegits del canal estàndard d'entrada */
    friend istream &operator>>(istream &is, Vol &v);

};

#endif
