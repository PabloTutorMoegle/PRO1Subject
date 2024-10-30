#include "Vol.hpp"
#include <iostream>
#include <string>

using namespace std;

//*********************************************************
// Constructors
//*********************************************************

/* Pre: Cert */
/* Post: el vol està inicialitzat amb tots els valors per defecte */
Vol::Vol() {
    estat = "On-time";
    horaSortida = "00:00";
    horaArribada = "00:00";
    seientsDisponibles = 0;
}

/* Pre: Cert */
/* Post: el vol està inicialitzat amb els valors passats per paràmetre */
Vol::Vol(string nV, string cO, string cD, string hS, string hA, string e, int sD) {
    numVol = nV;
    ciutatOrigen = cO;
    ciutatDestinacio = cD;
    estat = e;
    horaSortida = hS;
    horaArribada = hA;
    seientsDisponibles = sD;
}

/* Pre: Cert */
/* Post: el vol està inicialitzat amb els mateixos atributs del vol passat per paràmetre */
Vol::Vol(const Vol &v) {
    numVol = v.numVol;
    ciutatOrigen = v.ciutatOrigen;
    ciutatDestinacio = v.ciutatDestinacio;
    estat = v.estat;
    horaSortida = v.horaSortida;
    horaArribada = v.horaArribada;
    seientsDisponibles = v.seientsDisponibles;
}

/* Pre: Cert */
/* Post: tots els atributs de p s'han copiat al p.i. */
Vol &Vol::operator=(const Vol &v) {
    numVol = v.numVol;
    ciutatOrigen = v.ciutatOrigen;
    ciutatDestinacio = v.ciutatDestinacio;
    estat = v.estat;
    horaSortida = v.horaArribada;
    seientsDisponibles = v.seientsDisponibles;
    return *this;
}

//*********************************************************
// Destructor
//*********************************************************

/* Post: Esborra automaticament l'objecte en sortir d'un ambit de visibilitat local */
Vol::~Vol() {}

//*********************************************************
// Modificadors
//*********************************************************

/* Pre: El nombre de seients disponibles és superior a 0 */
/* Post: Els seients disponibles del vol s'han reduït en una unitat */
void Vol::reduirSeients() {
    this->seientsDisponibles--;
}

//*********************************************************
// Consultors
//*********************************************************

/* Pre: Cert */
/* Post: S'ha retornat el número de vol del p.i. */
string Vol::getNumVol() const {
    return numVol;
}

/* Pre: Cert */
/* Post: S'ha retornat la ciutat d'origen del p.i. */
string Vol::getCiutatOrigen() const {
    return ciutatOrigen;
}

/* Pre: Cert */
/* Post: S'ha retornat la ciutat destinació del p.i. */
string Vol::getCiutatDest() const {
    return ciutatDestinacio;
}

/* Pre: Cert */
/* Post: S'ha retornat l'hora de sortida del p.i. */
string Vol::getHoraSortida() const {
    return horaSortida;
}

/* Pre: Cert */
/* Post: S'ha retornat l'hora d'arribada del p.i. */
string Vol::getHoraArribada() const {
    return horaArribada;
}

/* Pre: Cert */
/* Post: S'ha retornat l'estat del p.i. */
string Vol::getEstat() const {
    return estat;
}

/* Pre: Cert */
/* Post: S'ha retornat el nombre de seientsDisponibles disponibles del p.i. */
int Vol::getSeientsDisponibles() const {
    return seientsDisponibles;
}

//*********************************************************
// Lectura i escriptura
//*********************************************************

/* Pre: Cert */
/* Post: S'han escrit al canal estàndard de sortida els atributs del vol v */
ostream &operator<<(ostream &os, const Vol &v) {
    os << " Número vol: " << v.numVol << endl;
    os << " Ciutat origen: " << v.ciutatOrigen << endl;
    os << " Ciutat destinació: " << v.ciutatDestinacio << endl;
    os << " Hora sortida: " << v.horaSortida << endl;
    os << " Hora arribada: " << v.horaArribada << endl;
    os << " Estat vol: " << v.estat << endl;
    os << " Seients disponibles: " << v.seientsDisponibles;
    return os;
}

/* Pre: Estan preparats al canal estandar d'entrada 6 strings i un enter, en aquest ordre */
/* Post: El vol v passa a tenir els atributs llegits del canal estàndard d'entrada */
istream &operator>>(istream &is, Vol &v) {
    is >> v.numVol >> v.ciutatOrigen >> v.ciutatDestinacio >> v.horaSortida;
    is >> v.horaArribada >> v.estat >> v.seientsDisponibles;
    return is;
}
