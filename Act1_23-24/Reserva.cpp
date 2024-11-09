#include "Reserva.hpp"

using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE RESERVA
// (implementació del codi de tots els mètodes especificats en el fitxer Reserva.hpp)

//*********************************************************
// Constructors
//*********************************************************

/* Pre: Cert */
/* Post: La reserva s'ha inicialitzat sense número de reserva, passatger, número de vol ni mètode de pagament */
Reserva::Reserva() {}

/* Pre: Cert */
/* Post: Construeix una reserva amb tots els valors passats per paràmetre */
Reserva::Reserva(string nR, string nV, string mP, Passatger p) {
    numReserva = nR;
    numVol = nV;
    metodePagament = mP;
    passatger = p;
}

/* Pre: Cert */
/* Post: La reserva s'ha inicialitzat amb tots els valors passats per paràmetre, inicialitzant també un nou passatger i
 *        associant-lo a aquesta */
Reserva::Reserva(string nR, string nV, string mP, string nP, string eR, string nS) {
    numReserva = nR;
    numVol = nV;
    metodePagament = mP;
    passatger = Passatger(nP, eR, nS);
}

/* Pre: Cert */
/* Post: La reserva s'ha inicialitzat amb tots els valors passats per la reserva donada com a paràmetre*/
Reserva::Reserva(const Reserva &r) {
    numReserva = r.numReserva;
    numVol = r.numVol;
    metodePagament = r.metodePagament;
    passatger = r.passatger;
}

/* Pre: Cert */
/* Post: Tots els atributs de la reserva `r` s'han copiat al p.i. */
Reserva &Reserva::operator=(const Reserva &r) {
    this->numReserva = r.numReserva;
    this->numVol = r.numVol;
    this->metodePagament = r.metodePagament;
    this->passatger = r.passatger;
    return *this;
}

//*********************************************************
// Destructor
//*********************************************************

/* Post: Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
Reserva::~Reserva() {}

//*********************************************************
// Consultors
//*********************************************************

/* Pre: Cert */
/* Post: El valor retornat és el número de vol associat a aquesta reserva */
string Reserva::getNumVol() const {
    return numVol;
}

/* Pre: Cert */
/* Post: El valor retornat número de reserva d'aquesta instància */
string Reserva::getNumReserva() const {
    return numReserva;
}

/* Pre: Cert */
/* Post: El valor retornat és el passatger d'aquesta reserva. */
Passatger Reserva::getPassatger() const {
    return passatger;
}

//*********************************************************
// Lectura i escriptura
//*********************************************************

/* Pre: Cert */
/* Post: S'han escrit al canal estàndard de sortida els atributs de la reserva r passada per paràmetre */
ostream &operator<<(ostream &os, const Reserva &r) {
    os << " Número reserva: " << r.numReserva << endl;
    os << " Nom passatger: " << r.passatger.getNom() << endl;
    os << " Número vol: " << r.numVol << endl;
    os << " Pagament: " << r.metodePagament << endl;
    return os;
}

/* Pre: estan preparats al canal estandar d'entrada 6 strings */
/* Post: La reserva r passa a tenir els atributs llegits del canal estàndard d'entrada */
istream &operator>>(istream &is, Reserva &r) {
    string nomPassatger, estatReserva, numSeient;
    is >> r.numReserva >> nomPassatger >> estatReserva >> numSeient >> r.numVol >> r.metodePagament;
    r.passatger = Passatger(nomPassatger, estatReserva, numSeient);
    return is;
}
