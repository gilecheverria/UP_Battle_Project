/*
   Class for the user controlled heros
   Inherits from the Character class

   Gilberto Echeverria
   gilecheverria@yahoo.com
   01/11/2016
*/
// Make sure the file can only be included one time
#pragma once

#include "Character.hpp"

#define NAME_LENGTH 9

class Hero : public Character {
    private:
        int experience;
        int gold;
        //int AP;    // Ability points
        //- inventory
        char name[NAME_LENGTH];
        //std::string name;

    public:
        // Constructor
        Hero() {}
        Hero(char * _name, int _HP, int _MP, int _speed, int _character_class,
        //Hero(std::string _name, int _HP, int _MP, int _speed, int _character_class,
                int _attack, int _defense, int _magic, double _attack_percent,
                double _defense_percent, double _magic_percent, double _critical_percent);
        /*
        void escape();
        void useItem();
        void equipItem();
        void levelUP();
        */
        // Access methods
        char * getName() { return name; }
        //std::string getName() { return name; }
        // Helper methods
        void print();
        void print(int line);
        void inputData();
};
