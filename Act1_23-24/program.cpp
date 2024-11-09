#include "Passatger.hpp"
#include "Vol.hpp"
#include "Reserva.hpp"
#include "Aerolinia.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int maxVols, maxReserves;
    cin >> maxVols >> maxReserves;
    Aerolinia aerolinia("Voling", maxVols, maxReserves);

    string opcio;
    cin >> opcio;

    while (opcio != "acabar") {
        // Inv: La opció escollida és diferent de "acabar"
        if (opcio == "enregistrarVol") {
            Vol v;
            cin >> v;
            aerolinia.addVol(v);
        } else if (opcio == "enregistrarReserva") {
            Reserva r;
            cin >> r;
            aerolinia.addReserva(r);
        } else if (opcio == "mostrarVols") {
            aerolinia.mostrarVols();
        } else if (opcio == "mostrarReserves") {
            aerolinia.mostrarReserves();
        } else if (opcio == "mostrarPassatgersVol") {
            cin >> opcio;
            aerolinia.mostrarPassatgersVol(opcio);
        } else if (opcio == "mostrarReservesEstat") {
            cin >> opcio;
            aerolinia.mostrarReservesEstat(opcio);
        } else {
            cout << "\"" << opcio << "\"" << endl;
            cout << " Error: Opció no vàlida" << endl;
        }
        cout << endl;

        cin >> opcio;
    }


}
