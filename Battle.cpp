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
    // Call the method to set the battle parameters
    initialize(_hero_party, _enemy_party);
}

// Prepare the parameters for the battle
void Battle::initialize(Party & _hero_party, Party & _enemy_party)
{
    hero_party = _hero_party;
    enemy_party = _enemy_party;

    num_heros = hero_party.getSize();
    num_enemies = enemy_party.getSize();

    state = FIGHTING;
}

void Battle::battleLoop()
{
    int turn = 1;

    while (state == FIGHTING)
    {
        std::cout << "---- TURN # " << turn++ << " ----" << std::endl;
        // Print the current values for the parties
        std::cout << "HEROES:" << std::endl;
        hero_party.print();
        std::cout << "MONSTERS:" << std::endl;
        enemy_party.print();

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

    if (state == HERO_WON)
    {
        std::cout << "The heros have won!! Congratulations!" << std::endl;
    }
    else
    {
        std::cout << "Your heroes have been defeated. Game over!" << std::endl;
    }
}

//// Private methods ////

void Battle::playerAction(int index)
{
    char option = 'x';
    int damage;
    int target;
    // Get a pointer to the hero that will act
    // Cast it to the correct Class pointer
    Hero * the_hero = static_cast<Hero*> (hero_party.getMember(index));

    while (state == FIGHTING && option != 'a' && option != 'd' && option != 'h' && option != 'r')
    {
        // Show the menu
        std::cout << "Select an action for '" << the_hero->getName() << "': \n";
        std::cout << "\ta. Attack\n";
        std::cout << "\td. Defend\n";
        std::cout << "\th. Heal\n";
        std::cout << "\tr. Run\n";
        std::cout << "Your coice: ";
        std::cin >> option;

        switch (option)
        {
            case 'a':
                // Get the damage dealt by the hero
                damage = the_hero->performAttack();
                // Select the enemy to attack
                target = selectEnemyTarget();
                // Apply the damate
                enemy_party.getMember(target)->receiveDamage(damage);
                break;
            case 'd':
                the_hero->defend();
                break;
            case 'h':
                the_hero->healDamage(30);
                break;
            case 'r':
                // Quit the battle, conceding defeat
                std::cout << "Your party runs away. You lost the battle\n";
                state = ENEMY_WON;
                break;
            default:
                std::cout << "Invalid option. Try again ...\n";
        }
    }
}

void Battle::enemyAction(int index)
{
    action_t action;
    int damage;
    int target;
    // Get a pointer to the monster that will act
    // Cast it to the correct Class pointer
    Monster * the_enemy = static_cast<Monster*> (enemy_party.getMember(index));

    // Get the action taken by the monster using its percentages
    action = the_enemy->selectAction();

    switch (action)
    {
        case ATTACK:
            // Get the damage dealt by the hero
            damage = the_enemy->performAttack();
            // Select the enemy to attack
            target = selectHeroTarget();
            // Apply the damate
            hero_party.getMember(target)->receiveDamage(damage);
            break;
        case DEFEND:
            the_enemy->defend();
            break;
        case HEAL:
            the_enemy->healDamage(30);
            break;
        default:
            std::cout << "The enemy does not know what to do and stands still\n";
    }
}

// Ask the user to select an enemy to attack
int Battle::selectEnemyTarget()
{
    int choice = -1;
    Monster * the_enemy = nullptr;

    while (choice < 1 || choice > num_enemies)
    {
        std::cout << "Your opponents are:\n";
        for (int i=0; i<num_enemies; i++)
        {
            // Get the current monster
            the_enemy = static_cast<Monster*> (enemy_party.getMember(i));
            // Print it's identifier name
            std::cout << "\t" << i+1 << ". " << the_enemy->getName() << std::endl;
        }
        std::cout << "Select one: ";
        std::cin >> choice;
    }
    return choice-1;
}

// Randomly select the hero that will be attacked
int Battle::selectHeroTarget()
{
    // Randomly select one of the heroes
    int target = rand() % num_heros;

    return target;
}

// Check if any of the parties has been defeated
void Battle::updateBattleState()
{
    bool alive = false;

    // Check if there are enemies alive
    for (int i=0; i<num_enemies; i++)
    {
        if (enemy_party.getMember(i)->getStatus() != DEAD)
            alive = true;
    }
    // If all enemies have been defeated, the heroes won
    if (!alive)
    {
        state = HERO_WON;
        return;
    }

    alive = false;
    // Check if there are heroes alive
    for (int i=0; i<num_heros; i++)
    {
        if (hero_party.getMember(i)->getStatus() != DEAD)
            alive = true;
    }
    // If all heroes have been defeated, the monsters won
    if (!alive)
    {
        state = ENEMY_WON;
        return;
    }
}

