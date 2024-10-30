#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
#include "Character.hpp"
#include "Equipment.hpp"

using namespace std;

int main()
{
    string action;
    Game game;

    // Inv: Mentre el programa principal rep entrades i mentres no rebi l'entrada acabar, depenent d'aquesta, realitza l'acció dessitjada
    while (cin >> action && action != "acabar")
    {
        if (action == "crearJugador")
        {
            game.createPlayer();
        }
        if(action == "crearPersonatge")
        {
            game.createCharacter();
        }
        if(action == "crearItem")
        {
            game.createItem();
        }
        if(action == "mostrarJugadors")
        {
            game.showPlayers();
        }
        if(action == "mostrarItems")
        {
            game.showItems();
        }
        if(action == "equipamentDePersonatge")
        {
            string name;
            cin >> name;
            game.itemsFromCharacter(name);
        }
        if(action == "equiparPersonatge")
        {
            string characterName, item;
            cin >> characterName >> item;
            game.equipCharacter(characterName, item);
        }
        if(action == "personatgesDeJugador")
        {
            string playerName;
            cin >> playerName;
            game.charactersFromPlayer(playerName);
        }
    }
}
