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
#include "Hero.h"

int main()
{
    // Call the default constructor of the class
    Hero goku;
    // Call a constructor that receives initial data
    Hero vegeta ("Vegeta", 200, 50, 10, 1, 5, 3, 2, 0.70, 0.30, 0.20, 0.10);
    Character cell   (400, 60, 15, 1, 8, 6, 1, 0.60, 0.35, 0.25, 0.20);

    std::cout << "Goku data:\n";
    goku.print();

    std::cout << "Vegeta data:\n";
    vegeta.print();

    int damage = cell.performAttack();
    std::cout << "Vegeta takes " << damage << " damage from Cell:\n";
    vegeta.receiveDamage(damage);
    vegeta.print();

    return 0;
}
