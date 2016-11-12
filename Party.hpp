/*
   Class to group a number of characters,
   either controlled by the user or by the computer

   Gilberto Echeverria
   gilecheverria@yahoo.com
   03/11/2016
*/

#pragma once

#include <iostream>
#include <stdexcept>
#include "Hero.hpp"
#include "Monster.hpp"

enum party_t { HERO, MONSTER };

class Party {
    private:
        int size;
        party_t type;
        // The party will have an array of pointers to Character
        // The array will be stored in a pointer variable, so we need
        //  a pointer to pointers
        Character ** members = nullptr;

    public:
        Party(int _size=2, party_t _type=MONSTER);
        ~Party();
        // Access methods
        Character * getMember(int index);
        void setMember(int index, Character * _character);
        int getSize() { return size; }
        // Helper methods
        void print();
};
