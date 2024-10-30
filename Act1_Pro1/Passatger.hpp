#ifndef PASSATGER_HPP
#define PASSATGER_HPP

#include <string>
#include <iostream>

using namespace std;

class Passatger {
// Tipus de mòdul: dades
// Descripció del tipus: Representa un passatger que ha fet la reserva
// d'un vol, del que s'indiquen el seu nom, l'estat de la reserva i el
// número de seient assignat.

private:
    string nom, estatReserva, numSeient;

public:

    //*********************************************************
    // Constructors
    //*********************************************************

    /* Pre: Cert */
    /* Post: El passatger està inicialitzat amb tots els valors per defecte */
    Passatger();

    /* Pre: Cert */
    /* Post: El passatger està inicialitzat amb els valors passats per paràmetre */
    Passatger(string n, string eS, string nS);

    /* Pre: Cert */
    /* Post: El passatger està inicialitzat amb els mateixos atributs del passatger passat per paràmetre */
    Passatger(const Passatger &p);

    /* Pre: Cert */
    /* Post: Tots els atributs de `p` s'han copiat al p.i. */
    Passatger &operator=(const Passatger &p);

    //*********************************************************
    // Destructor
    //*********************************************************

    /* Post: Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
    ~Passatger();

    //*********************************************************
    // Consultors
    //*********************************************************

    /* Pre: Cert */
    /* Post: retorna el nom del p.i. */
    string getNom() const;

    /* Pre: Cert */
    /* Post: retorna l'estat de la reserva del p.i. */
    string getEstatReserva() const;

    /* Pre: Cert */
    /* Post: retorna el numero de seient del p.i. */
    string getNumSeient() const;

    //*********************************************************
    // Lectura i escriptura
    //*********************************************************

    /* Pre: Cert */
    /* Post: S'han escrit al canal estàndard de sortida els atributs del passatger p */
    friend ostream &operator<<(ostream &os, const Passatger &p);

    /* Pre: estan preparats al canal estandar d'entrada 3 strings */
    /* Post: El passatger p passa a tenir els atributs llegits del canal estàndard d'entrada */
    friend istream &operator>>(istream &is, Passatger &p);
};

#endif
