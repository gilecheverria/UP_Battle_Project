/*
   Class to control the flow of a battle in the game

   Gilberto Echeverria
   gilecheverria@yahoo.com
   08/11/2016
*/

#include "Battle.hpp"

// Constructor
Battle::Battle(Party & _hero_party, Party & _enemy_party)
{
    hero_party = _hero_party;
    enemy_party = _enemy_party;
}

void Battle::initialize(Party & _hero_party, Party & _enemy_party);
{
    hero_party = _hero_party;
    enemy_party = _enemy_party;
}

void Battle::battleLoop()
{
    int num_heros = hero_party.getSize();
    int num_enemies = enemy_party.getSize();

    while (state = FIGHTING)
    {
        // Select the actions for the heroes
        for (int i=0; i<num_heros; i++)
        {
            playerAction(i);
        }
        // Select the actions for the enemies
        for (int i=0; i<num_enemies; i++)
        {
            enemyAction(i);
        }
    }
}

//// Private methods ////
void Battle::playerAction(int index)
{
    char option = 'a';

    while (option != 'a' && option != 'd' && option != 'h')
    {
        // Show the menu
        std::cout << "Select an action:\n";
        std::cout << "\ta. Attack\n";
        std::cout << "\td. Defend\n";
        std::cout << "\th. Heal\n";
        std::cout << "Your coice: ";
        std::cin >> option;

        switch (option)
        {
            case 'a':
                // Get the damage dealt by the hero
                int damage = hero_party.getMember(index).performAttack();
                // Select the enemy to attack
                int target = selectEnemyTarget();
                // Apply the damate
                enemy_party.getMember(target).receiveDamage(damage);
                break;
            case 'd':
                hero_party.getMember(index).defend();
                break;
            case 'h':
                hero_party.getMember(index).heal();
                break;
            default:
                std::cout << "Invalid option. Try again ...\n";
        }
    }
}

void Battle::enemyAction(int index)
{

}

int Battle::selectEnemyTarget()
{
    int num_enemies = enemy_party.getSize();
    int choice = -1;

    while (choice < 0 && choice >= num_enemies)
    {
        std::cout << "Your opponents are:\n";
        for (int i=0; i<num_enemies; i++)
        {
            std::cout << i << ". " << std::endl;
        }
        std::cout << "Select one: ";
        std::cin >> choice;
    }
    return choice;
}
