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

class Hero : public Character {
    private:
        std::string name;
        int experience;
        int gold;
        //int AP;    // Ability points
        //- inventory

    public:
        // Constructor
        Hero() {}
        Hero(std::string _name, int _HP, int _MP, int _speed, int _character_class,
                int _attack, int _defense, int _magic, double _attack_percent,
                double _defense_percent, double _magic_percent, double _critical_percent);
        /*
        void escape();
        void useItem();
        void equipItem();
        void levelUP();
        */
};
