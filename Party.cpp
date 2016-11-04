#include "Party.hpp"

Party::Party(int _size)
{
    size = _size;
    // Using 'new' calls malloc and calls the constructor for the class
    members = new Character[size];
    //members = malloc (sizeof(Character) * size);
}

Party::~Party()
{
    // Using 'delete' calls free and calls the destructor for the class
    delete [] members;
    //free(members);
}

Character Party::getMember(int i)
{
    if (i > 0 && i < size)
        return members[i];
    else
        // Do something
        throw std::runtime_error("Invalid index!");
}

void Party::setMember(int i, Character _character)
{
    if (i > 0 && i < size)
        members[i] = _character;
}
