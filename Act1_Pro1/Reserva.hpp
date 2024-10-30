#ifndef RESERVA_HPP
#define RESERVA_HPP

#include "Passatger.hpp"
#include "Vol.hpp"
#include <string>
#include <iostream>

using namespace std;

class Reserva {
// Tipus de mòdul: dades
// Descripció del tipus: Representa una reserva d'un vol de la que
// s'indiquen el seu número, el passatger que ha fet la reserva
// el número de vol que ha reservat i el mètode de pagament que ha
// fer servir en reservar.

private:
    Passatger passatger;
    string numReserva;      // Número de la reserva.
    string numVol;          // Número del vol que es reserva
    string metodePagament;  // Mètode de pagament utilitzat per a realitzar la reserva

public:

    //*********************************************************
    // Constructors
    //*********************************************************

    /* Pre: Cert */
    /* Post: La reserva s'ha inicialitzat sense número de reserva, passatger, número de vol ni mètode de pagament */
    Reserva();

    /* Pre: Cert */
    /* Post: Construeix una reserva amb tots els valors passats per paràmetre */
    Reserva(string nR, string nV, string mP, Passatger p);

    /* Pre: Cert */
    /* Post: La reserva s'ha inicialitzat amb tots els valors passats per paràmetre, inicialitzant també un nou passatger i
     *        associant-lo a aquesta */
    Reserva(string nR, string nV, string mP, string nP, string eR, string nS);

    /* Pre: Cert */
    /* Post: La reserva s'ha inicialitzat amb tots els valors passats per la reserva donada com a paràmetre*/
    Reserva(const Reserva &r);

    /* Pre: Cert */
    /* Post: Tots els atributs de la reserva `r` s'han copiat al p.i. */
    Reserva &operator=(const Reserva &r);

    //*********************************************************
    // Destructor
    //*********************************************************

    /* Post: Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
    ~Reserva();

    //*********************************************************
    // Consultors
    //*********************************************************

    /* Pre: Cert */
    /* Post: El valor retornat és el número de vol associat a aquesta reserva */
    string getNumVol() const;

    /* Pre: Cert */
    /* Post: El valor retornat número de reserva d'aquesta instància */
    string getNumReserva() const;

    /* Pre: Cert */
    /* Post: El valor retornat és el passatger d'aquesta reserva. */
    Passatger getPassatger() const;

    //*********************************************************
    // Lectura i escriptura
    //*********************************************************

    /* Pre: Cert */
    /* Post: S'han escrit al canal estàndard de sortida els atributs de la reserva r */
    friend ostream &operator<<(ostream &os, const Reserva &r);

    /* Pre: estan preparats al canal estandar d'entrada 6 strings */
    /* Post: La reserva r passa a tenir els atributs llegits del canal estàndard d'entrada */
    friend istream &operator>>(istream &is, Reserva &r);
};

#endif
