#include "Hero.hpp"

Hero::Hero(std::string _name, int _HP, int _MP, int _speed, int _character_class,
        int _attack, int _defense, int _magic, double _attack_percent,
        double _defense_percent, double _magic_percent, double _critical_percent) :
    Character(_HP, _MP, _speed, _character_class, _attack, _defense, _magic,
            _attack_percent, _defense_percent, _magic_percent, _critical_percent)
{
    std::cout << "CONSTRUCTOR FOR HERO" << std::endl;

    name = _name;
    experience = 0;
    gold = 0;
}
