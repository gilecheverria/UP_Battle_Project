/*
   Class for any type of character, with the main properties shared by all
   This will be the parent to both the user controlled and computer controlled
   characters in a battle

   Gilberto Echeverria
   gilecheverria@yahoo.com
   20/10/2016
*/
#pragma once

#include <iostream>
#include <iomanip>

#define PRINT_LINES 4

// Declare an enumeration type for the possible states a character can be in
enum status_t { NORMAL, DEAD, POISONED, PARALIZED };

class Character {
	protected:      // These properties can be used by classes inheriting from me
    	int HP;
    	int current_HP;
    	int MP;
    	int current_MP;
    	int speed;
    	int character_class;
    	unsigned int level;
    	int attack;
    	int defense;
    	int magic;
    	double attack_percent;
    	double defense_percent;
    	double magic_percent;
    	double critical_percent;
    	status_t status;

	public:
		// Constructor methods
		Character(int _HP=100, int _MP=20, int _speed=5, int _character_class=0,
                int _attack=1, int _defense=0, int _magic=0, double _attack_percent=0.5,
                double _defense_percent=0.2, double _magic_percent=0.2,
                double _critical_percent=0.1);

    	int performAttack();
    	void receiveDamage(int base_damage);
    	void healDamage(int base_recovery);
    	void defend();
		/*
    	bool specialAction();
		*/
        // Access methods
        status_t getStatus() { return status; }
		// Utility methods
		void print();
		void print(int line);
};
