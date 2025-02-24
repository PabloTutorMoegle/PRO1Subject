#include <iostream>
#include <fstream>
#include "laberint.hpp"

using namespace std;


bool laberint::dins_lab(coord c) const
{
    return c.x >= 0 && c.x < (int)taula.size() && c.y >= 0 && c.y < (int)taula[0].size();
}

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
            if (ch == 'E')
            {
                pos_entrada = taula[i][j];
            }
        }
    }
    file.close();
}

// Obté quina és la casella d'entrada del laberint.
coord laberint::entrada() const
{
    coord c(-1, -1);
    for (int i = 0; i < (int)taula.size(); i++)
    {
        for (int j = 0; j < (int)taula[i].size(); j++)
        {
            if (taula[i][j].es_entrada())
            {
                c.x = i;
                c.y = j;
                return c;
            }
        }
    }

    return c;
}

// Obté quina és la casella de sortida del laberint.
coord laberint::sortida() const
{
    coord c(-1, -1);
    for (int i = 0; i < (int)taula.size(); i++)
    {
        for (int j = 0; j < (int)taula[i].size(); j++)
        {
            if (taula[i][j].es_sortida())
            {
                c.x = i;
                c.y = j;
                return c;
            }
        }
    }

    return c;
}

int laberint::sizeR() const
{
    return taula.size();
}

int laberint::sizeC() const
{
    return taula[0].size();
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

void laberint::mostrar2() const
{
    for (int i = 0; i < (int)taula.size(); i++)
    {
        for (int j = 0; j < (int)taula[i].size(); j++)
        {
            if (taula[i][j].es_visitada())
                cout << "V";
            else
                cout << taula[i][j].bateria();
        }
        cout << endl;
    }
}

bool laberint::dins_labP(coord c) const
{
    return c.x >= 0 && c.x < (int)taula.size() && c.y >= 0 && c.y < (int)taula[0].size();
}

// Accedeix a la casella de la coord donada del laberint.
casella& laberint::operator()(coord &c)
{
    if (!dins_lab(c))
    {
        static casella cas;
        cas.casella_erronea();
        return cas;
    }
    else
    {
        return taula[c.x][c.y];
    }
}
