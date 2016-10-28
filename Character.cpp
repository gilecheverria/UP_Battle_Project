#include "Character.h"

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
    status = 0;
}

// Method to print the data for this character
void Character::print()
{
    std::cout << "HP: " << current_HP << " / " << HP << std::endl;
    std::cout << "MP: " << current_MP << " / " << MP << std::endl;
}

// Method to decrease the health of the character
//  depends on a base damage received, and the defense stats of the character
void Character::receive_damage(int base_damage)
{
    current_HP -= (base_damage - defense);
}
