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
#include "Character.hpp"

class Party {
    private:
        int size;
        Character * members = nullptr;

    public:
        Party(int _size=2);
        ~Party();
        // Access methods
        Character getMember(int i);
        void setMember(int i, Character _character);
        int getSize() { return size; }
};
