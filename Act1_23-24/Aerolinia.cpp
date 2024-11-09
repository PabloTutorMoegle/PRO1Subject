#include "Aerolinia.hpp"

using namespace std;

//*********************************************************
// Constructors
//*********************************************************

/* Pre: Cert */
/* Post: l'aerolinia està inicialitzada amb els valors per defecte */
Aerolinia::Aerolinia() {
    maxVols = 0;
    maxReserves = 0;
}

/* Pre: Cert */
/* Post: el vol està inicialitzada amb els mateixos valors de l'aerolínia passada per paràmetre */
Aerolinia::Aerolinia(const Aerolinia &a) {
    maxReserves = a.maxReserves;
    maxVols = a.maxVols;
    reserves = a.reserves;
    vols = a.vols;
}

/* Pre: Cert */
/* Post: Tots els atributs de l'Aerolínia passada per paràmetre s'han passat al p.i. */
Aerolinia &Aerolinia::operator=(const Aerolinia &a) {
    maxReserves = a.maxReserves;
    maxVols = a.maxVols;
    reserves = a.reserves;
    vols = a.vols;
    return *this;
}


/* Pre: Cert */
/* Post: L'aerolinia s'ha inicialitzat amb el nom, el nombre màxim de vols i el nombre màxim de reserves
 *        passats per paràmetre */
Aerolinia::Aerolinia(string nomAerolinia, unsigned int maxVols, unsigned int maxReserves) {
    this->nom = nomAerolinia;
    this->maxVols = maxVols;
    this->maxReserves = maxReserves;
    this->vols = vector<Vol>();
    this->reserves = vector<Reserva>();
}

//*********************************************************
// Destructor
//*********************************************************

/* Post: Esborra automaticament l'objecte en sortir d'un ambit de visibilitat local */
Aerolinia::~Aerolinia() {}

//*********************************************************
// Modificadors
//*********************************************************

/* Pre: Cert */
/* Post: En cas s'hagi arribat al nombre màxim de vols, o ja existeixi un vol amb el mateix número de vol de `v`:
 *          S'haurà mostrat un missatge d'error per la sortida estàndard.
 *      En cas contrari: El vector de vols conté ara tots els vols contenia abans de l'execució, més el vol `v`
 *          passat per paràmetre, el qual s'haurà inserit al final del vector `vols`. */
void Aerolinia::addVol(Vol &v) {
    cout << "Enregistrament vol: " << v.getNumVol() << endl;
    if (vols.size() >= maxVols) {
        cout << " Error: el vol supera el nombre màxim de vols a " << nom << ", no s'ha afegit el vol" << endl;
    } else if (getPosVol(v.getNumVol()) != -1) {
        cout << " Error: " << v.getNumVol() << " vol ja existent a " << nom << ", no s'ha afegit el vol" << endl;
    } else {
        vols.push_back(v);
        cout << " OK" << endl;
    }
}

/* Pre: Cert */
/* Post: En cas s'hagi arribat al nombre màxim de reserves, o ja existeix una reserva amb el mateix nombre de reserva
 *          de `r`, o no existeixi cap vol amb el número de vol indicat per la reserva `r`, o al vol amb el número de
 *          vol indicat per la reserva `r` no quedit seients disponibles: S'haurà mostrat un missatge d'error per la
 *          sortida estàndard.
 *      En cas contrari: El vector de reserves conté ara totes reserves que contenia abans de l'execució, més la reserva
 *          `r` passada per paràmetre, la qual s'haurà inserit mentenint l'ordre alfabétic en el vector de reserves.
 *          El nombre de seients disponibles al vol s'ha reduït en 1. */
void Aerolinia::addReserva(Reserva &r) {
    cout << "Enregistrament reserva: " << r.getNumReserva() << endl;
    unsigned int posReserva = 0;
    if (reserves.size() >= maxReserves) {
        cout << " Error: la reserva supera el nombre màxim de reserves a " << nom
             << ", no s'ha afegit la reserva" << endl;
    } else if (findReserva(r.getNumReserva(), posReserva)) {
        cout << " Error: " << r.getNumReserva() << " reserva ja existent a " << nom << ", no s'ha afegit la reserva" << endl;
    } else if (getPosVol(r.getNumVol()) == -1) {
        cout << " Error: vol " << r.getNumVol() << " no existent a " << nom << ", no s'ha afegit la reserva" << endl;
    } else if (getVol(r.getNumVol()).getSeientsDisponibles() == 0) {
        cout << " Error: vol " << r.getNumVol() << " no disposa de seients disponibles, no s'ha afegit la reserva" << endl;
    } else {
        cout << " OK" << endl;
        vector<Reserva>::iterator itR = reserves.begin();

        // Això no és costós ja que en un vector els elements estan posicionats secuencialment a memória.
        //  Tenim accés aleatori.
        itR += posReserva;

        // Però això si que és costós, concretament té complexitat mitjana O(n), ja que ha de copiar el vector
        //  al inserir elements al mig d'aquest. De totes maneres, és una decisió de disseny, ja que assumim que
        //  en un sistema real hi haurà més consultes que insercions, p.t. prioritzem l'eficiéncia d'aquestes.
        // Aquesta decisió en permet que la complexitat d'ordenació de les reserves sigui O(1) i la de les cerques sigui
        //  O(log n)
        reserves.insert(itR, r);

        getVol(r.getNumVol()).reduirSeients();
    }
}

//*********************************************************
// Consultors
//*********************************************************

/* Pre: Cert */
/* Post: Retorna el nom del p.i. */
string Aerolinia::getNom() const {
    return nom;
}

/* Pre: Cert */
/* Post: Retorna el nombre màxim de vols del p.i. (maxVols) */
unsigned int Aerolinia::getMaxVols() const {
    return maxVols;
}

/* Pre: Cert */
/* Post: Retorna el nombre màxim de reserves del p.i. (maxReserves) */
unsigned int Aerolinia::getMaxReserves() const {
    return maxReserves;
}

/* Pre: Cert */
/* Post: Retorna la posició que ocupa el vol amb el número passat per paràmetre dins del vector de vols del p.i.
 *        o -1 en cas que no hi hagi cap vol registrat amb aquest número. */
int Aerolinia::getPosVol(const string &numVol) const {
    bool trobat = false;
    int cont = 0;
    unsigned int vSize = vols.size();

    while (cont < vSize && !trobat) {
        /* Inv: Mentre estem dins del bucle significa que encara no hem trobat el vol amb número `numVol`
         *       ni hem acabat de recórrer el vector de vols.
         *      Al sortir del bucle, `trobat` ens indicarà si hem trobat el vol en el vecot, i en cas afirmatiu,
         *       `cont` ens indicarà la posició d'aquest. */
        if ((vols[cont]).getNumVol() == numVol)
            trobat = true;
        else
            cont++;
    }

    return trobat ? cont : -1;
}

/* Pre: Cert */
/* Post: Retorna un booleà indicant si existeix la reserva amb número `numReserva` al vector de reserves del p.i.,
 *          i, en cas d'existir, assigna `posReserva` a la posició que ocupa aquesta reserva en el vector de reserves,
 *          en cas contrari, assigna `posReserva` a la posició que ocupa el primer element superior a `numReserva`
 *          trobat en el vector. */
/* La cerca té complexitat mitjana O(log n), ja que inserim els elements de manera ordenada i fem una cerca dicotómica */
bool Aerolinia::findReserva(const string &numReserva, unsigned int &posReserva) const {
    int esq = 0, mid = 0, dre = reserves.size() - 1;
    bool trobat = false;

    while (!trobat && esq <= dre) {
        /* Inv: Mentres estem dins del bucle, encara no hem trobat la reserva que estem cercant.
         *       Al sortir del bucle, o bé hem trobat la reserva que estem cercant i mid indica la seva
         *       posició en el vector de reserves (si found == true), o bé no l'hem trobada i esq ens indica
         *       la posició en la qual hauria d'anar en cas de voler inserir-la. */
        mid = (esq + dre) / 2;
        string itNumReserva = reserves[mid].getNumReserva();
        if (numReserva < itNumReserva)
            dre = mid - 1;
        else if (numReserva > itNumReserva)
            esq = mid + 1;
        else
            trobat = true;
    }

    // posReserva = La posició que ocupa la reserva trobada, o en cas de no haber-la trobat, la posició que ocupa
    //  el primer element superior trobat.
    posReserva = trobat ? mid : esq;

    return trobat;
}

/* Pre: Hi ha un vol registrat al p.i. amb el número passat per paràmetre. */
/* Post: Retorna el vol amb el número passat per paràmetre. */
Vol &Aerolinia::getVol(const string &numVol) {
    return vols[getPosVol(numVol)];
}

//*********************************************************
//Lectura i escriptura
//********************************************************

/* Pre: Cert */
/* Post: S'han escrit al canal estàndard de sortida les dades dels vols de
l'aerolínia paràmetre implícit, en l'ordre en què han estat enregistrats.
En el cas que no hi hagués cap vol enregistrat en l'aerolínia p.i., s'ha
mostrat un missatge d'error. */
void Aerolinia::mostrarVols() const {
    cout << "Vols de " << nom << " (per ordre d'enregistrament):" << endl;

    if (vols.empty()) {
        cout << " Error: No hi ha vols enregistrats a " << nom << endl;
    } else {
        for (unsigned int i = 0; i < vols.size(); i++) {
            // Inv: Hem mostrat per pantalla tots els vols amb index < a `i` al vector de vols.
            cout << " " << i + 1 << "." << endl;
            cout << vols[i] << endl;
        }
    }
}

/* Pre: Cert */
/* Post: S'han escrit al canal estàndard de sortida les dades de les reserves
del paràmetre implícit, ordenades per número de reserva de forma creixent.
En el cas que no hi hagués cap reserva enregistrada en l'aerolínia p.i., s'ha
mostrat un missatge d'error. */
void Aerolinia::mostrarReserves() const {
    cout << "Reserves de " << nom << " (per número de reserva):" << endl;
    if (reserves.empty()) {
        cout << " Error: No hi ha reserves enregistrades a " << nom << endl;
    } else {
        for (int i = 0; i < reserves.size(); i++) {
            // Inv: Hem mostrat per pantalla totes les reserves amb index < i al vector de reserves.
            cout << " " << i + 1 << "." << endl;
            cout << reserves[i];
        }
    }
}

/* Pre: Cert */
/* Post: S'han escrit al canal estàndard de sortida les dades dels passatgers
que tenen una reserva de vol, enregistrada  en l'aerolínia paràmetre implícit,
amb el número de vol donat per paràmetre. L'ordre dels passatgers és alfabètic.
En el cas que no hi hagués cap vol enregistrat en l'aerolínia p.i. amb el número
de vol donat o que no hi hagués cap reserva feta per aquest número de vol, s'ha
mostrat un missatge d'error segons el cas */
void Aerolinia::mostrarPassatgersVol(const string &numVol) const {
    cout << "Passatgers del vol " << numVol << " de " << nom << " (en ordre alfabètic):" << endl;
    if (getPosVol(numVol) == -1) {
        cout << " Error: " << numVol << " vol no existent a " << nom << endl;
    } else {
        vector<Reserva> reservesVol;
        getReservesVol(numVol, reservesVol);
        if (reservesVol.empty()) {
            cout << " Error: No hi ha passatgers amb reserves pel vol " << numVol << endl;
        } else {
            list<Passatger> passatgers;
            ordenarPassatgers(reservesVol, passatgers);
            list<Passatger>::iterator itLP = passatgers.begin();
            unsigned int i = 1;
            while(itLP != passatgers.end()) {
                /* Inv: Hem mostrat per pantalla els passatgers del subvector passatgers[0..i-2]. */
                cout << ' ' << i++ << '.' << endl;
                cout << *itLP++;
            }
        }
    }
}

/* Pre: Cert */
/* Post: S'han escrit al canal estàndard de sortida les dades de les reserves
enregistrades en l'aerolínia p.i. que es troben en l'estat rebut per paràmetre.
Les reserves s'han escrit ordenades per número de reserva de forma creixent.
En el cas que no hi hagués cap reserva enregistrada en l'aerolínia p.i. o que no
hi hagués cap reserva que es trobés en l'estat rebut per paràmetre, s'ha mostrat
un missatge d'error segons el cas */
void Aerolinia::mostrarReservesEstat(const string& estatReserva) const {
    cout << "Reserves de " << nom << " amb estat \"" << estatReserva << "\" (per número de reserva):" << endl;
    unsigned int found = 0;
    for (unsigned int i = 0; i < reserves.size(); i++) {
        /* Hem mostrat per pantalla les reserves del subvector reserves[0..i-1] */
        if (reserves[i].getPassatger().getEstatReserva() == estatReserva) {
            cout << ' ' << ++found << '.' << endl;
            cout << reserves[i];
        }
    }

    if (found == 0)
        cout << " Error: No hi ha reserves enregistrades a " << nom << " amb estat " << estatReserva << endl;
}

/* Pre: El vector de reserves `reserves` passat per paràmetre conté totes les reserves a partir de les quals es volen
 *          obtenir els passatgers ordenars, i el vector de passatgers `passatgers` passat per paràmetre està buit. */
/* Post: El vector de passatgers `passatgers` passat per paràmetre s'haurà omplert amb tots el passatgers
 *          de les reserves que hi ha al `reserves`, ordenats alfabéticament pel nom del passatger. */
/* Aquesta funció és estàtica perquè no depén del p.i. */
/* Fem servir una llista per poder inserir en qualsevol posició amb un cost raonable */
void Aerolinia::ordenarPassatgers(const vector<Reserva> &reserves, list<Passatger> &passatgers) {
    /* Com els datasets de proves són prou petits, fem servir un algorisme d'ordenació simple.
     * Si tinguéssim moltes dades, hauríem de considerar fer servir un algorisme avançat com ara Merge Sort o Quick Sort.
     * També podríem millorar la eficiéncia d'aquest algorisme fent servir una mena de cerca dicotómica per
     *  trobar la posició on hem d'inserir cada passatgers, ja que els que estan dins de `passatgers` ja estan
     *  ordenats alfabéticament.
     * No ens hem preocupat massa d'aquests aspectes ja que assumim que l'objectiu d'aquesta activitat no és entendre
     *  els algorismes d'ordenació. */

    unsigned int mida = reserves.size();
    for (unsigned int i = 0; i < mida; i++) {
        // Inv: `passatgers` està ordenat de manera creixent en base del nom, i hem inserit tots els passatgers de
        //      reserves[0..i-1] a la llista de passatgers.
        Passatger passatgerI = reserves[i].getPassatger();
        list<Passatger>::iterator itLP = passatgers.begin();
        while(itLP != passatgers.end() && passatgerI.getNom() > itLP->getNom()) {
            /* Inv: Mentres estem dins del bucle, l'iterador apunta a una posició de la llista inferior respecte a ón
             *       hem de col·locar el passatger actual `passatgerI`.
             *      Quan sortim del bucle, l'iterador apunta a la posició immediatament superior a ón hem de col·locar
             *        `passatgerI`. */
            itLP++;
        }
        passatgers.insert(itLP, passatgerI);
    }
}

/* Pre: El vector `reservesVol` passat per paràmetre està buit */
/* Post: El vector `reservesVol` passat per paràmetre conté ara totes les reserves del vol `numVol` */
/* La ordenació té complexitat O(1) ja que ordenem en temps d'inserció */
void Aerolinia::getReservesVol(const string &numVol, vector<Reserva> &reservesVol) const {
    for (int i = 0; i < reserves.size(); i++) {
        /* Inv: Hem inserit en el vector `reservesVol` totes les reserves del subvector reserves[0..i-1] */
        if (reserves[i].getNumVol() == numVol)
            reservesVol.push_back(reserves[i]);
    }
}
