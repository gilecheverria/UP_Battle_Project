#include "Character.hpp"

// Constructor with initial data for the instance
Character::Character(int _HP, int _MP, int _speed, int _character_class,
        int _attack, int _defense, int _magic, double _attack_percent,
        double _defense_percent, double _magic_percent, double _critical_percent)
{
    HP = _HP;
    current_HP = _HP;
    MP = _MP;
    current_MP = _MP;
    speed = _speed;
    character_class = _character_class;
    attack = _attack;
    defense = _defense;
    magic = _magic;
    attack_percent = _attack_percent;
    defense_percent = _defense_percent;
    magic_percent = _magic_percent;
    critical_percent = _critical_percent;

    level = 1;
    status = NORMAL;
}

// Fill the statistics for the character with user input
void Character::inputData()
{
    // Get the max Hit Points
    HP = validatePositiveInt("max HP");
    current_HP = HP;
    // Get the max Magic Points
    MP = validatePositiveInt("max MP");
    current_MP = MP;
    // Get the speed
    speed = validatePositiveInt("speed");
    //character_class = _character_class;
    attack = validatePositiveInt("attack");
    defense = validatePositiveInt("defense");
    magic = validatePositiveInt("magic");
    attack_percent = validatePercent("attack percent");
    defense_percent = validatePercent("defense percent");
    magic_percent = validatePercent("magic percent");
    critical_percent = validatePercent("critical percent");
}

// Method to keep asking for a positive integer value
// Receives the prompt string to show the user
int Character::validatePositiveInt(std::string value_name)
{
    int value = 0;
    while (value < 1)
    {
        std::cout << "Enter " << value_name << " (integer) : ";
        std::cin >> value;

        if (value < 1)
            std::cout << "Can't be a negative value. Try again\n";
    }
    return value; 
}

// Method to keep asking for a percent value in the range of 0 to 1
// Receives the prompt string to show the user
float Character::validatePercent(std::string value_name)
{
    float value = -1;
    while (value < 0 || value > 1)
    {
        std::cout << "Enter " << value_name << " (float) : ";
        std::cin >> value;

        if (value < 1)
            std::cout << "Can't only be decimal number between 0 and 1. Try again\n";
    }
    return value; 
}

// Method to print the data for this character
void Character::print()
{
    std::cout << "HP: " << current_HP << " / " << HP << std::endl;
    std::cout << "MP: " << current_MP << " / " << MP << std::endl;
    std::cout << "Status: " << status << std::endl;
}

// Print character stats line by line
void Character::print(int line)
{
    switch (line)
    {
        case 1:
            std::cout << "HP: " << std::setw(4) << current_HP << " / " << std::setw(4) << HP;
            break;
        case 2:
            std::cout << "MP: " << std::setw(4) << current_MP << " / " << std::setw(4) << MP;
            break;
        case 3:
            std::cout << "Status: " << std::setw(7) << status;
            break;
        default:
            // Don't do anything
            break;
    }
}

// Compute the amount of damage produced by this character
int Character::performAttack()
{
    int damage = 0;
    if (status != DEAD)
    {
        damage = attack * level;
    }
    return damage;
}

// Method to decrease the health of the character
//  depends on a base damage received, and the defense stats of the character
void Character::receiveDamage(int base_damage)
{
    // Do not allow negative damage. The std::max function will return
    //  the highest value from 0 or the damage minus the defense
    current_HP -= std::max( (base_damage - defense), 0 );
    if (current_HP <= 0)
    {
        current_HP = 0;
        status = DEAD;
    }
}

// Method to regain HP
void Character::healDamage(int base_recovery)
{
    // Only a live character can be healed
    if (status != DEAD)
    {
        current_HP += base_recovery;
        // Limit the recovery to the maximum HP of the character
        if (current_HP > HP)
            current_HP = HP;
    }
}

void Character::defend()
{

}
