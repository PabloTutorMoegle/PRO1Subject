#include <iostream>
#include "laberint.hpp"

using namespace std;

//  Constructora. Serveix per declarar una variable
//  de tipus "laberint", donant el fitxer que en conté
//  les dades. Per exemple:  laberint lab("laber1.txt")
laberint::laberint(const std::string &s)
{
    int f, c;
    cin >> f >> c;
    taula = vector<vector<casella>>(f, vector<casella>(c));
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char c;
            cin >> c;
            taula[i][j].omplir(c);
        }
    }
}

// Obté quina és la casella d'entrada del laberint.
coord laberint::entrada() const
{
    bool trobat = false;
    coord c;
    for (int i = 0; i < (int)taula.size() && trobat == false; i++)
    {
        for (int j = 0; j < (int)taula[i].size() && trobat == false; j++)
        {
            if (taula[i][j].es_entrada())
            {
                trobat = true;
                c = coord(i, j);
            }
        }
    }
    return c;
}
// Imprimeix a cout el laberint.
void laberint::mostrar() const
{
    for (int i = 0; i < (int)taula.size(); i++)
    {
        for (int j = 0; j < (int)taula[i].size(); j++)
        {
            taula[i][j].mostrar();
        }
        cout << endl;
    }
}

// Accedeix a la casella de la coord donada del laberint.
casella& laberint::operator()(coord &c)
{
    return taula[c.x][c.y];
}
