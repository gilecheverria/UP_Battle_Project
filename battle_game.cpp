/*
   Program to run the game using the classes creted

   Gilberto Echeverria
   gilecheverria@yahoo.com
   22/11/2016
*/

#include <iostream>
#include "Game.hpp"

int main()
{
    Game test_game;

    std::cout << "=== RPG BATTLE GAME PROGRAM ===" << std::endl;
    test_game.gameMenu();

    return 0;
}
