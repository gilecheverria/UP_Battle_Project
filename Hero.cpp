#include "Hero.hpp"

Hero::Hero(char * _name, int _HP, int _MP, int _speed, int _character_class,
//Hero::Hero(std::string _name, int _HP, int _MP, int _speed, int _character_class,
        int _attack, int _defense, int _magic, double _attack_percent,
        double _defense_percent, double _magic_percent, double _critical_percent) :
    // Call the constructor for the character class with the required parameters
    Character(_HP, _MP, _speed, _character_class, _attack, _defense, _magic,
            _attack_percent, _defense_percent, _magic_percent, _critical_percent)
{
    //name = _name;
    experience = 0;
    gold = 0;
}

void Hero::print()
{
    std::cout << "=== Name: " << name << " ===" << std::endl;
    // Call the 'print' method of the parent class
    Character::print();
}

void Hero::print(int line)
{
    if (line == 0)
        std::cout << "== " << std::setw(NAME_LENGTH) << name << " ==";
    else
        Character::print(line);
}

void Hero::inputData()
{
    std::cout << "== Hero creation module ==\n";

    std::cout << "Enter the name: ";
    std::cin >> name;

    Character::inputData();
}
