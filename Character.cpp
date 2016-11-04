#include "Character.hpp"

// Constructor with initial data for the instance
Character::Character(int _HP, int _MP, int _speed, int _character_class,
        int _attack, int _defense, int _magic, double _attack_percent,
        double _defense_percent, double _magic_percent, double _critical_percent)
{
    std::cout << "CONSTRUCTOR FOR CHARACTER" << std::endl;
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

// Method to print the data for this character
void Character::print()
{
    std::cout << "HP: " << current_HP << " / " << HP << std::endl;
    std::cout << "MP: " << current_MP << " / " << MP << std::endl;
    std::cout << "Status: " << status << std::endl;
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
    current_HP -= (base_damage - defense);
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
