#include <iostream>
#include "Data.hpp"

using namespace std;

//*********************************************************
// Constructors
//*********************************************************

/* Pre: cert */
/* Post: crea una data buida */
Data::Data ()
{
    dia = 0;
    mes = 0;
    any = 0;
}

/* Pre: cert */
/* Post: crea una data amb el dia, mes i any rebuts per paràmetre */	
Data::Data(int dia, int mes, int any)
{
    this->dia = dia;
    this->mes = mes;
    this->any = any;
}

//*********************************************************
// Destructor
//*********************************************************

/* Destructor per defecte */ 
Data::~Data()
{

}

//*********************************************************
// Consultors
//*********************************************************

/* Pre: cert */
/* Post: retorna el dia de la data paràmetre implicit */
int Data::getDia() const
{
    return dia;
}

/* Pre: cert */
/* Post: retorna el mes de la data paràmetre implicit */
int Data::getMes() const
{
    return mes;
}

/* Pre: cert */
/* Post: retorna l'any de la data paràmetre implicit */
int Data::getAny() const
{
    return any;
}

/* Pre: cert */
/* Post: retorna un booleà que indica si la data paràmetre
    implícit és posterior a la data 'd' rebuda (true) o
    no ho és (false) */
bool Data::operator>(const Data &d) const
{
    if (any > d.any) return true;
    else if (any == d.any)
    {
        if (mes > d.mes) return true;
        else if (mes == d.mes)
        {
            if (dia > d.dia) return true;
        }
    }
    return false;
}

//*********************************************************
// Lectura i escriptura
//*********************************************************

/* Pre: estan preparats al canal estàndard d'entrada tres enters */
/* Post: la data 'd' passa a tenir els enters llegits del canal
    estàndard d'entrada com a dia, mes i any, respectivament */		
istream& operator>>(istream &is, Data &d)
{
    char c;
    is >> d.dia >> c >> d.mes >> c >> d.any;
    return is;
}

/* Pre: cert */
/* Post: s'han escrit els atributs dia, mes i any de la data 'd'
    al canal estàndard de sortida */
ostream& operator<<(ostream &os, const Data &d)
{
    os << d.dia << "/" << d.mes << "/" << d.any;
    return os;
} 
