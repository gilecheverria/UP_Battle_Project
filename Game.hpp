/*
   Class that controlls the flow of the game
   It allows the creation of heroes and monsters, and the battling between them

   Gilberto Echeverria
   gilecheverria@yahoo.com
   22/11/2016
*/

#pragma once

#include <iostream>
#include "Battle.hpp"
#include "FileIOTemplate.hpp"

#define MAX_HEROS 3
#define MAX_MONSTERS 4

class Game {
    private:
        // Properties
        int num_heroes = 0;
        int num_monsters = 0;
        int hero_party_size = 2;
        int monster_party_size = 3;
        Hero hero_database[MAX_HEROS];
        Monster monster_database[MAX_MONSTERS];

        Battle * the_battle;
        Party * the_heros = nullptr;
        Party * the_monsters = nullptr;

        // Methods
        void createHero();
        void createMonster();
        void createHeroParty();
        void createMonsterParty();
        void printHeroArray();
        void printMonsterArray();
    public:
        // Constructor
        Game();
        // Destructor
        ~Game();
        // Methods
        void gameMenu();
};
