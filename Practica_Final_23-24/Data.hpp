#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>

using namespace std;

class Data {
// Tipus de mòdul: dades
// Descripció del tipus: Representa una data que consta 
// de tres enters per emmagatzemar el dia, mes i any
// d'una data.
	
	private:
		int dia;
		int mes;
		int any;
		
	public:
		//*********************************************************
		// Constructors
		//*********************************************************

		/* Pre: cert */
		/* Post: crea una data buida */
		Data ();
	
		/* Pre: cert */
		/* Post: crea una data amb el dia, mes i any rebuts per paràmetre */	
		Data(int dia, int mes, int any);
		
		//*********************************************************
		// Destructor
		//*********************************************************
		
		/* Destructor per defecte */ 
		~Data();
		
		//*********************************************************
		// Consultors
		//*********************************************************

		/* Pre: cert */
		/* Post: retorna el dia de la data paràmetre implicit */
		int getDia() const;

		/* Pre: cert */
		/* Post: retorna el mes de la data paràmetre implicit */
		int getMes() const;

		/* Pre: cert */
		/* Post: retorna l'any de la data paràmetre implicit */
		int getAny() const;

		/* Pre: cert */
		/* Post: retorna un booleà que indica si la data paràmetre
		   implícit és posterior a la data 'd' rebuda (true) o
		   no ho és (false) */
		bool operator>(const Data &d) const;
			
		//*********************************************************
		// Lectura i escriptura
		//*********************************************************

		/* Pre: estan preparats al canal estàndard d'entrada tres enters */
		/* Post: la data 'd' passa a tenir els enters llegits del canal
		   estàndard d'entrada com a dia, mes i any, respectivament */		
		friend istream& operator>>(istream &is, Data &d); 
		
		/* Pre: cert */
		/* Post: s'han escrit els atributs dia, mes i any de la data 'd'
		   al canal estàndard de sortida */
		friend ostream& operator<<(ostream &os, const Data &d); 
};
#endif
