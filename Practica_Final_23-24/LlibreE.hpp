#ifndef LLIBREE_HPP
#define LLIBREE_HPP
#include "Data.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define nat unsigned int

class LlibreE {
// Tipus de mòdul: dades
// Descripció del tipus: Representa un llibre electrònic
// que consta de títol, data de publicació, àrea temàtica
// i paraules clau que descriuen el seu contingut.

	private:

	string titol;
	Data data;
	vector<string> paraulesClau;
	string area;

	public:

		//*********************************************************
		// Constructors i assignació
		//*********************************************************
		
		/* Pre: cert */ 
		/* Post: crea un llibre amb el títol, data de publicació i 
		   àrea buits, i sense paraules clau */
		LlibreE();
		
		/* Pre: cert */ 
		/* Post: crea un llibre amb el títol, data de publicació, 
		   àrea i paraules clau del llibre 'le' */
		LlibreE(const LlibreE &le);
		  
		/* Pre: cert */
		/* Post: el resultat és un llibre amb el títol, data de 
		   publicació, àrea i paraules clau del llibre 'le' */	 
		LlibreE& operator=(const LlibreE &le);
		  
		//*********************************************************
		// Destructor
		//*********************************************************
		
		/* Destructor per defecte */ 
		~LlibreE();
	  
	    //*********************************************************
		// Modificadors
		//*********************************************************

		/* Pre: _area no és una cadena de caràcters buida. */
		/* Post: L'atribut 'area' de l'objecte LlibreE s'estableix amb el valor proporcionat com a paràmetre. */
		void setArea(const string &_area);


	    //*********************************************************
		// Consultors
		//*********************************************************

		/* Pre: 'paraulesClau' conté les paraules clau (string) del llibre */
		/* Post: Les paraules clau del llibre ('paraulesClau') estan ordenades 
		alfabèticament en ordre decreixent, i després d'això, estan invertides 
		perquè estiguin en ordre alfabètic */
		void ordenaParaulesClau();
		
		/* Pre: cert */ 
		/* Post: el resultat és el títol del llibre p.i. */
		string consultar_titol() const;
	  
		/* Pre: cert */ 
		/* Post: el resultat és la data de publicació del llibre p.i. */
		Data consultar_dataPub() const;

		/* Pre: cert */ 
		/* Post: el resultat les paraules clau del llibre p.i. */
		vector<string> consultar_paraulesClau() const;

		/* Pre: cert */ 
		/* Post: el resultat és l'àrea temàtica del llibre p.i. */
		string consultar_area() const;
	  
		/* Pre: cert */
		/* Post: retorna un booleà que indica si la data de publicació del 
		llibre p.i. és posterior a la del llibre 'le' (true) o no ho és (false) */
		bool compare(const LlibreE &le) const;
		
		/* Pre: 'le' és una instància vàlida de la classe LlibreE */
		/* Post: Retorna 'true' si el títol del llibre actual ('*this') és igual al títol del llibre 'le'. Altrament retorna 'false' */
		bool operator==(const LlibreE &le) const;
		
		//*********************************************************
		// Lectura i escriptura
		//*********************************************************

		/* Pre: estan preparats al canal estàndard d'entrada totes les dades del llibre */
		/* Post: el llibre 'libro' passa a tenir les dades llegides del canal
		   estàndard d'entrada com a titulo, fecha i area/as, respectivament */		
		friend istream& operator>>(istream &is, LlibreE &libro); 
		
		/* Pre: cert */
		/* Post: s'han escrit els atributs titulo, fecha i area/as del llibreE 'libro'
		   al canal estàndard de sortida */
		friend ostream& operator<<(ostream &os, const LlibreE &libro); 
};
#endif
