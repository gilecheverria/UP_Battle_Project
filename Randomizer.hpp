/*
   Class with static methods to generate random numbers during the game

   Gilberto Echeverria
   gilecheverria@yahoo.com
   15/11/2016
*/
#pragma once

#include <cstdlib>
#include <ctime>

class Randomizer {
    public:
        static void init();
        static int randomRange(int start, int end);
};
