#include "Monster.hpp"

// Initialize static array with the names of the monster types
std::string Monster::text_names[NUM_TYPES] = { "Goblin", "Troll", "Giant", "Dragon" };

Monster::Monster(monster_t _type)
{
    // Set the type of the monster
    type = _type;

    action_percent[ATTACK] = 50;
    action_percent[DEFEND] = 40;
    action_percent[HEAL] = 10;
}

action_t Monster::selectAction()
{
    int selection = Randomizer::randomRange(1, 100);
    int accum = 0;

    // Loop over the possible actions
    for (int i=0; i<NUM_ACTIONS; i++)
    {
        // Compute the accumulated percentages
        accum += action_percent[i];
        if (selection <= accum)
        {
            // Cast the integer into an action_t variable
            return (action_t)i;
        }
    }
    // A default action
    // if the percents are correctly filled this should never happen
    return ATTACK;
}

// Fill the data for a monster with input from the user
void Monster::inputData()
{
    // Ask for a correct monster type
    type = (monster_t)validateMonsterType();

    action_percent[ATTACK] = 50;
    action_percent[DEFEND] = 40;
    action_percent[HEAL] = 10;

    // Call the input data method from the parent class
    Character::inputData();
}

void Monster::print()
{
    std::cout << "=== Type: " << getName() << " ===" << std::endl;
    // Call the 'print' method of the parent class
    Character::print();
}

void Monster::print(int line)
{
    if (line == 0)
        std::cout << "== " << std::setw(9) << getName() << " ==";
    else
        Character::print(line);
}

// Return the text name that corresponds to the monster type
std::string Monster::getName()
{
    //std::string text_names[] = { "Goblin", "Troll", "Giant", "Dragon" };

    return text_names[type];
}

// Ask the user for the monster type and check it is correct
int Monster::validateMonsterType()
{
    int the_type;
    bool valid = false;

    while (!valid)
    {
        std::cout << "Monster types:\n";
        for (int i=0; i<NUM_TYPES; i++)
        {
            std::cout << "\t" << i << ". " << text_names[i] << "\n";
        }
        std::cout << "Select type: ";
        std::cin >> the_type;

        // Check that the type entered is valid
        if (the_type >= 0 and the_type < NUM_TYPES)
            valid = true;
        else
            std::cout << "Incorrect type. Try again ...\n";
    }
    return the_type;
}
