#include <iostream>
#include <fstream>
#include "laberint.hpp"

using namespace std;

//  Constructora. Serveix per declarar una variable
//  de tipus "laberint", donant el fitxer que en conté
//  les dades. Per exemple:  laberint lab("laber1.txt")
laberint::laberint(const std::string &s)
{
    ifstream file(s);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << s << endl;
        exit(1);
    }

    int f, c;
    file >> f >> c;
    taula = vector<vector<casella>>(f, vector<casella>(c));
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char ch;
            file >> ch;
            taula[i][j].omplir(ch);
        }
    }
    file.close();
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
            cout << taula[i][j];
        }
        cout << endl;
    }
}

// Accedeix a la casella de la coord donada del laberint.
casella& laberint::operator()(coord &c)
{
    return taula[c.x][c.y];
}
