#include "Party.hpp"

Party::Party(int _size, party_t _type)
{
    size = _size;
    type = _type;
    // Using 'new' calls malloc and calls the constructor for the class
    members = new Character*[size];
}

Party::~Party()
{
    // Using 'delete' calls free and calls the destructor for the class
    delete [] members;
}

Character * Party::getMember(int index)
{
    if (index >= 0 && index < size)
        return members[index];
    else
        // Do something
        throw std::runtime_error("Invalid index!");
}

void Party::setMember(int index, Character * _character)
{
    if (index >= 0 && index < size)
        members[index] = _character;
}

/*
void Party::print()
{
    for (int i=0; i<size; i++)
    {
        std::cout << "Member: " << i << std::endl;
        members[i]->print();
    }
}
*/

void Party::print()
{
    // Print all the members of a party horizontally
    for (int line=0; line<PRINT_LINES; line++)
    {
        for (int i=0; i<size; i++)
        {
            std::cout << " | ";
            // The first line is the name of the character
            if (line == 0)
            {
                // Cast the type of character to be able to call the correct methods
                if (type == HERO)
                {
                    static_cast<Hero*>(members[i])->print(line);
                }
                if (type == MONSTER)
                {
                    static_cast<Monster*>(members[i])->print(line);
                }
            }
            // All other lines are generic Character data
            else
            {
                members[i]->print(line);
            }
        }
        std::cout << " |" << std::endl;
    }
}
