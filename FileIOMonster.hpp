#include <cstdio>
#include <cstdlib>
#include "Monster.hpp"

// Use a template to be able to write files of different types of data
class FileIOMonster {

    private:
        static FILE * openAndCheck(std::string file_name, std::string mode);

    public:
        static void writeNewData(Monster & the_monster, std::string file_name);
        static void readData(Monster & the_monster, monster_t type, std::string file_name);
};

FILE * FileIOMonster::openAndCheck(std::string file_name, std::string mode)
{
    FILE * file_ptr = nullptr;

    // Open the file. Convert C++ strings to C arrays of characters for the parameters
    file_ptr = fopen(file_name.c_str(), mode.c_str());
    if (file_ptr == nullptr)
    {
        std::cout << "Error: Unable to open file '" << file_name << "'!\n";
        exit(1);
    }
    return file_ptr;
}

void FileIOMonster::writeNewData(Monster & the_monster, std::string file_name)
{
    FILE * file_ptr = nullptr;

    the_monster.inputData();
    file_ptr = openAndCheck(file_name, "ab");
    fwrite(&the_monster, sizeof (Monster), 1, file_ptr);
    fclose(file_ptr);
}

void FileIOMonster::readData(Monster & the_monster, monster_t type, std::string file_name)
{
    FILE * file_ptr = nullptr;
    file_ptr = openAndCheck(file_name, "ab");
    // Loop over the file looking for the monster of the type specified
    while (fread(&the_monster, sizeof (Monster), 1, file_ptr) == 1)
    {
        // Stop the search when the type has been found
        if (the_monster.getType() == type)
            break;
    }
    fclose(file_ptr);
}
