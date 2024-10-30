#ifndef AEROLINIA_HPP
#define AEROLINIA_HPP

#include "Passatger.hpp"
#include "Vol.hpp"
#include "Reserva.hpp"
#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;

class Aerolinia {
// Tipus de modul: dades
// Descripcio del tipus: Una aerolínia té un nom que la identifica i està
// formada per un conjunt de vols i un conjunt de reserves. El nombre de vols i
// el de reserves estan limitats. Ofereix les operacions necessàries per a un
// sistema de gestió de reserves de vols.

private:
    string nom;
    unsigned int maxVols, maxReserves;
    vector<Vol> vols;

    // El vector de reserves podría estar dins de Vol, però ens aporta tant avantatges com inconvenients,
    //  p.t. el deixem aquí.
    vector<Reserva> reserves;

public:

    //*********************************************************
    // Constructors
    //*********************************************************

    /* Pre: Cert */
    /* Post: l'aerolinia està inicialitzada amb els valors per defecte */
    Aerolinia();

    /* Pre: Cert */
    /* Post: el vol està inicialitzada amb els mateixos valors de l'aerolínia passada per paràmetre */
    Aerolinia(const Aerolinia &a);

    /* Pre: Cert */
    /* Post: Tots els atributs de l'Aerolínia passada per paràmetre s'han passat al p.i. */
    Aerolinia &operator=(const Aerolinia &a);

    /* Pre: Cert */
    /* Post: L'aerolinia s'ha inicialitzat amb el nom, el nombre màxim de vols i el nombre màxim de reserves
     *        passats per paràmetre */
    Aerolinia(string nomAerolinia, unsigned int maxVols, unsigned int maxReserves);

    //*********************************************************
    // Destructor
    //*********************************************************

    /* Post: Esborra automaticament l'objecte en sortir d'un ambit de visibilitat local */
    ~Aerolinia();

    //*********************************************************
    // Modificadors
    //*********************************************************

    /* Pre: Cert */
    /* Post: En cas s'hagi arribat al nombre màxim de vols, o ja existeixi un vol amb el mateix número de vol de `v`:
     *          S'haurà mostrat un missatge d'error per la sortida estàndard.
     *      En cas contrari: El vector de vols conté ara tots els vols contenia abans de l'execució, més el vol `v`
     *          passat per paràmetre, el qual s'haurà inserit al final del vector `vols`. */
    void addVol(Vol &v);

    /* Pre: Cert */
    /* Post: En cas s'hagi arribat al nombre màxim de reserves, o ja existeix una reserva amb el mateix nombre de reserva
     *          de `r`, o no existeixi cap vol amb el número de vol indicat per la reserva `r`, o al vol amb el número de
     *          vol indicat per la reserva `r` no quedit seients disponibles: S'haurà mostrat un missatge d'error per la
     *          sortida estàndard.
     *      En cas contrari: El vector de reserves conté ara totes les reserves que contenia abans de l'execució, més la reserva
     *          `r` passada per paràmetre, la qual s'haurà inserit mentenint l'ordre alfabétic en el vector de reserves.
     *          El nombre de seients disponibles al vol s'ha reduït en 1. */
    void addReserva(Reserva &r);

    //*********************************************************
    // Consultors
    //*********************************************************

    /* Pre: Cert */
    /* Post: Retorna el nom del p.i. */
    string getNom() const;

    /* Pre: Cert */
    /* Post: Retorna el nombre màxim de vols del p.i. (maxVols) */
    unsigned int getMaxVols() const;

    /* Pre: Cert */
    /* Post: Retorna el nombre màxim de reserves del p.i. (maxReserves) */
    unsigned int getMaxReserves() const;

    /* Pre: Cert */
    /* Post: Retorna la posició que ocupa el vol amb el número passat per paràmetre dins del vector de vols del p.i.
     *        o -1 en cas que no hi hagi cap vol registrat amb aquest número. */
    int getPosVol(const string& numVol) const;

    /* Pre: Cert */
    /* Post: Retorna un booleà indicant si existeix la reserva amb número `numReserva` al vector de reserves del p.i.,
     *          i, en cas d'existir, assigna `posReserva` a la posició que ocupa aquesta reserva en el vector de reserves,
     *          en cas contrari, assigna `posReserva` a la posició que ocupa el primer element superior a `numReserva`
     *          trobat en el vector. */
    /* La cerca té complexitat mitjana O(log n), ja que inserim els elements de manera ordenada i fem una cerca dicotómica */
    bool findReserva(const string &numReserva, unsigned int &posReserva) const;

    /* Pre: Hi ha un vol registrat al p.i. amb el número passat per paràmetre. */
    /* Post: Retorna el vol amb el número passat per paràmetre. */
    Vol& getVol(const string& numVol);

    //*********************************************************
    // Lectura i escriptura
    //********************************************************

    /* Pre: Cert */
    /* Post: S'han escrit al canal estàndard de sortida les dades dels vols de
    l'aerolínia paràmetre implícit, en l'ordre en què han estat enregistrats.
    En el cas que no hi hagués cap vol enregistrat en l'aerolínia p.i., s'ha
    mostrat un missatge d'error. */
    void mostrarVols() const;

    /* Pre: Cert */
    /* Post: S'han escrit al canal estàndard de sortida les dades de les reserves
    del paràmetre implícit, ordenades per número de reserva de forma creixent.
    En el cas que no hi hagués cap reserva enregistrada en l'aerolínia p.i., s'ha
    mostrat un missatge d'error. */
    void mostrarReserves() const;

    /* Pre: Cert */
    /* Post: S'han escrit al canal estàndard de sortida les dades dels passatgers
    que tenen una reserva de vol, enregistrada  en l'aerolínia paràmetre implícit,
    amb el número de vol donat per paràmetre. L'ordre dels passatgers és alfabètic.
    En el cas que no hi hagués cap vol enregistrat en l'aerolínia p.i. amb el número
    de vol donat o que no hi hagués cap reserva feta per aquest número de vol, s'ha
    mostrat un missatge d'error segons el cas */
    void mostrarPassatgersVol(const string &numVol) const;

    /* Pre: Cert */
    /* Post: S'han escrit al canal estàndard de sortida les dades de les reserves
    enregistrades en l'aerolínia p.i. que es troben en l'estat rebut per paràmetre.
    Les reserves s'han escrit ordenades per número de reserva de forma creixent.
    En el cas que no hi hagués cap reserva enregistrada en l'aerolínia p.i. o que no
    hi hagués cap reserva que es trobés en l'estat rebut per paràmetre, s'ha mostrat
    un missatge d'error segons el cas */
    void mostrarReservesEstat(const string& estatReserva) const;

    private:

    /* Pre: El vector de reserves `reserves` passat per paràmetre conté totes les reserves a partir de les quals es volen
     *          obtenir els passatgers ordenars, i el vector de passatgers `passatgers` passat per paràmetre està buit. */
    /* Post: El vector de passatgers `passatgers` passat per paràmetre s'haurà omplert amb tots el passatgers
     *          de les reserves que hi ha al `reserves`, ordenats alfabéticament pel nom del passatger. */
    /* Aquesta funció és estàtica perquè no depén del p.i. */
    /* Fem servir una llista per poder inserir en qualsevol posició amb un cost raonable */
    static void ordenarPassatgers(const vector<Reserva> &reserves, list<Passatger> &passatgers);

    /* Pre: El vector `reservesVol` passat per paràmetre està buit */
    /* Post: El vector `reservesVol` passat per paràmetre conté ara totes les reserves del vol `numVol` */
    /* La ordenació té complexitat O(1) ja que ordenem en temps d'inserció */
    void getReservesVol(const string& numVol, vector<Reserva> &reservesVol) const;

};

#endif
