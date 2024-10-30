#include "Passatger.hpp"
#include <string>
#include <iostream>

using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE PASSATGER
// (implementació del codi de tots els mètodes especificats en el fitxer Passatger.hpp)

//*********************************************************
// Constructors
//*********************************************************

/* Pre: Cert */
/* Post: El passatger està inicialitzat amb tots els valors per defecte */
Passatger::Passatger() {}

/* Pre: Cert */
/* Post: El passatger està inicialitzat amb els valors passats per paràmetre */
Passatger::Passatger(string n, string e, string s) {
    nom = n;
    estatReserva = e;
    numSeient = s;
}

/* Pre: Cert */
/* Post: El passatger està inicialitzat amb els mateixos atributs del passatger passat per paràmetre */
Passatger::Passatger(const Passatger &p) {
    nom = p.nom;
    estatReserva = p.estatReserva;
    numSeient = p.numSeient;
}

/* Pre: Cert */
/* Post: Tots els atributs de `p` s'han copiat al p.i. */
Passatger &Passatger::operator=(const Passatger &p) {
    nom = p.nom;
    estatReserva = p.estatReserva;
    numSeient = p.numSeient;
    return *this;
}

//*********************************************************
// Destructor
//*********************************************************

/* Post: Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
Passatger::~Passatger() {}

//*********************************************************
// Consultors
//*********************************************************

/* Pre: Cert */
/* Post: retorna el nom del p.i. */
string Passatger::getNom() const {
    return nom;
}

/* Pre: Cert */
/* Post: retorna l'estat de la reserva del p.i. */
string Passatger::getEstatReserva() const {
    return estatReserva;
}

/* Pre: Cert */
/* Post: retorna el numero de seient del p.i. */
string Passatger::getNumSeient() const {
    return numSeient;
}

//*********************************************************
// Lectura i escriptura
//*********************************************************

/* Pre: Cert */
/* Post: S'han escrit al canal estàndard de sortida els atributs del passatger p */
ostream &operator<<(ostream &os, const Passatger &p) {
    cout << " Nom passatger: " << p.nom << endl;
    cout << " Estat reserva: " << p.estatReserva << endl;
    cout << " Número seient: " << p.numSeient << endl;
    return os;
}

/* Pre: estan preparats al canal estandar d'entrada 3 strings */
/* Post: El passatger p passa a tenir els atributs llegits del canal estàndard d'entrada */
istream &operator>>(istream &is, Passatger &p) {
    is >> p.nom >> p.estatReserva >> p.numSeient;
    return is;
}
