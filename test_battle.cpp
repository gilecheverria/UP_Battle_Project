/*
   Simple program to test the classes that we develop.
   This will likely become the main program, but for the moment it does not
   do anything useful.

   Gilberto Echeverria
   gilecheverria@yahoo.com
   27/10/2016
*/

#include <iostream>
#include "Character.h"

int main()
{
    Character goku;
    Character vegeta (200, 50, 10, 1, 5, 3, 2, 0.70, 0.30, 0.20, 0.10);

    std::cout << "Goku data:\n";
    goku.print();

    std::cout << "Vegeta data:\n";
    vegeta.print();

    std::cout << "Vegeta takes 15 damage:\n";
    vegeta.receive_damage(15);
    vegeta.print();

    return 0;
}
