#include <iostream>
#include <string>
#include <list>
#include "Plataforma.hpp"

using namespace std;

/** Programa principal
 *
 * main() crea la plataforma, fa la lectura d'instruccions i
 * l'escriptura de resultats. Les operacions estan definides i
 * implementades en les classes Plataforma, Classificacio, LlibreE i Data.
 */

int main() {
	
	Plataforma P;
	Classificacio C;
    string inst = " ";
	
    BinaryTree<string> ArbreAreas;
    cin >> ArbreAreas;

    C.setArbreAreas(ArbreAreas);
    P.setClassificacio(C);

    while (cin >> inst && inst != "fi")
    {
        if(inst == "alta_llibre")
        {
            cout << inst << " " << endl;
            LlibreE le;
            cin >> le;
            cout << le;
            if (P.llibre_repetit(le.consultar_titol()) == true){
                cout << "  error" << endl;
            } 
            else{
                P.altaLlibre(le);
            }
        }
        else if(inst == "baixa_llibre")
        {
            string t;
            cin >> t;
            cout << inst << " " << t << endl;
            P.baixaLlibre(t);
        }
        else if(inst == "classifica_llibre")
        {
            cout << inst << endl;
            P.ClassificarLlibre();
        }
        else if(inst == "classifica")
        {
            cout << inst << endl;
            P.Classifica();
        }
        else if(inst == "mostra_llibres")
        {
            cout << inst << " " << endl;
            P.mostrarLlibres();
        }
        else if(inst == "mostra_llibres_area")
        {
            string area;
            cin >> area;
            cout << inst << " " <<  area << endl;
            P.mostrarLlibresArea(area);
        }
        else if(inst == "llista_pendents")
        {
            cout << inst << endl;
            P.llista_pendents();
        }
        else
        {
            cout << inst << endl;
            cout << "  error" << endl;
        }
	}
    cout << "fi" << endl;
}
