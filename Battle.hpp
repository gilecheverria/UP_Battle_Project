/*
   Class to control the flow of a battle in the game

   Gilberto Echeverria
   gilecheverria@yahoo.com
   08/11/2016
*/

#pragma once

#include <iostream>
#include "Randomizer.hpp"
#include "Hero.hpp"
#include "Monster.hpp"
#include "Party.hpp"

// Create constants for the state of the battle
enum battle_state_t { FIGHTING, HERO_WON, ENEMY_WON };

class Battle {
    private:
        // Properties
        Party hero_party;
        Party enemy_party;
        battle_state_t state;
        int num_heroes;
        int num_enemies;

        // Methods
        void playerAction(int index);
        void enemyAction(int index);
        int selectEnemyTarget();
        int selectHeroTarget();
        void updateBattleState();
    public:
        Battle(Party & _hero_party, Party & _enemy_party);
        void initialize(Party & _hero_party, Party & _enemy_party);
        void battleLoop();
};
