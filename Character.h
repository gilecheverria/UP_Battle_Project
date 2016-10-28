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

class Character {
	private:
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
    	int status;

	public:
		// Constructor methods
		Character() {}
		Character(int _HP, int _MP, int _speed, int _character_class, int _attack, int _defense, int _magic,
			double _attack_percent, double _defense_percent, double _magic_percent, double _critical_percent);

		// Utility methods
		void print();
		/*
    	int performAttack();
    	bool defend();
    	bool heal();
    	bool specialAction();
		*/
    	void receive_damage(int base_damage);
};
