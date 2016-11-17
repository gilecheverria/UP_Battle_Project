/*
   Class for the enemies to be faced

   Gilberto Echeverria
   gilecheverria@yahoo.com
   08/11/2016
*/

#pragma once

#include "Randomizer.hpp"
#include "Character.hpp"

#define NUM_ACTIONS 3
#define NUM_TYPES 4

enum monster_t { GOBLIN, TROLL, GIANT, DRAGON };
enum action_t { ATTACK, DEFEND, HEAL };

class Monster : public Character {
    private:
        monster_t type;
        float action_percent[NUM_ACTIONS];
		int gold;
		float drop_rate;
		// Item treasure;       // There is no Item class yet

        static std::string text_names[NUM_TYPES];
        int validateMonsterType();

	public:
		Monster(monster_t _type);
		action_t selectAction();
        // Access methods
        std::string getName();
        monster_t getType() { return type; }
        // Helper methods
        void inputData();
        void print();
        void print(int line);
};
