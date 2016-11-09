#include "Monster.hpp"

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
    int selection = rand() % 100 + 1;
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
