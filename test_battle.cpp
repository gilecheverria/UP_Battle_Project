/*
   Simple program to test the classes that we develop.
   This will likely become the main program, but for the moment it does not
   do anything useful.

   Gilberto Echeverria
   gilecheverria@yahoo.com
   27/10/2016
*/

#include <iostream>
#include "Battle.hpp"
#include "FileIOMonster.hpp"

void simulateBattle();
void createMonsters();

int main()
{
    std::cout << "=== BATTLE TEST PROGRAM ===" << std::endl;
    createMonsters();
    //simulateBattle();

    return 0;
}

void createMonsters()
{
    FileIOTemplate<Monster> monsterWriter;
    FileIOTemplate<Hero> heroWriter;

    Monster dummy (GOBLIN);
    FileIOMonster::writeNewData(dummy, "monter_db.bin");
}

void simulateBattle()
{
    // Constructors for the heros
    Hero goku ("Goku", 270, 40, 15, 1, 4, 2, 4, 0.60, 0.35, 0.25, 0.12);
    Hero vegeta ("Vegeta", 200, 50, 10, 1, 5, 3, 2, 0.70, 0.30, 0.20, 0.10);

    // Constructors for the monsters
    Monster troll_1 (TROLL);
    Monster troll_2 (TROLL);
    Monster giant_1 (GIANT);

    // Create both parties
    Party the_heros(2, HERO);
    Party the_monsters(3);
    
    // Fill the parties with the characters
    the_heros.setMember(0, &goku);
    the_heros.setMember(1, &vegeta);
    the_monsters.setMember(0, &troll_1);
    the_monsters.setMember(1, &troll_2);
    the_monsters.setMember(2, &giant_1);

    // Get them into a fight
    Battle the_battle(the_heros, the_monsters);
    the_battle.battleLoop();
}
