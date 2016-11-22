#include "Game.hpp"

Game::Game()
{
    // Create the Party objects for the opposing teams
    the_heros = new Party(hero_party_size, HERO);
    the_monsters = new Party(monster_party_size);
    // Create the Battle object
    the_battle = new Battle(*the_heros, *the_monsters);

    // Load the data in the files
    num_heroes = FileIOTemplate<Hero>::readData(hero_database, MAX_HEROS, "heros.bin");
    num_monsters = FileIOTemplate<Monster>::readData(monster_database, MAX_MONSTERS, "monsters.bin");
}

Game::~Game()
{
    delete the_heros;
    delete the_monsters;
    delete the_battle;
}

void Game::gameMenu()
{
    std::string option = "a";

    while (option != "q")
    {
        std::cout << "\n<<< Main Game Menu >>>\n";
        std::cout << "\tv. View the arrays of heros and monsters\n";
        std::cout << "\tah. Add a new Hero\n";
        std::cout << "\tam. Add a new Monster\n";
        std::cout << "\tph. Create a party of heros\n";
        std::cout << "\tpm. Create a party of monsters\n";
        std::cout << "\tb. Battle with the existing parties\n";
        std::cout << "\tq. Quit the program\n";
        std::cout << "Select an option: ";
        std::cin >> option;

        if (option == "v")
        {
            printHeroArray();
            printMonsterArray();
        }
        else if (option == "ah")
        {
            createHero();
        }
        else if (option == "am")
        {
            createMonster();
        }
        else if (option == "ph")
        {
            createHeroParty();
        }
        else if (option == "pm")
        {
            createMonsterParty();
        }
        else if (option == "b")
        {
            the_battle->battleLoop();
        }
        else if (option == "q")
        {
            std::cout << "Thanks for playing! See you next time ..." << std::endl;
        }
        else
        {
            std::cout << "Incorrect option. Try again ..." << std::endl;
        }
    }
}

void Game::printHeroArray()
{
    std::cout << "\nThe heros:\n";
    for (int i=0; i<num_heroes; i++)
    {
        std::cout << "INDEX #" << i << std::endl;
        hero_database[i].print();
    }
}

void Game::printMonsterArray()
{
    std::cout << "\nThe monsters:\n";
    for (int i=0; i<num_monsters; i++)
    {
        std::cout << "INDEX #" << i << std::endl;
        monster_database[i].print();
    }
}

void Game::createHero()
{
    FileIOTemplate<Hero>::writeNewData(hero_database[num_heroes++], "heros.bin");
}

void Game::createMonster()
{
    FileIOTemplate<Monster>::writeNewData(monster_database[num_monsters++], "monsters.bin");
}

void Game::createHeroParty()
{
    int index;

    for (int i=0; i<hero_party_size; i++)
    {
        std::cout << "Enter index of hero (from the database): ";
        std::cin >> index;

        the_heros->setMember(i, &hero_database[index]);
    }
}

void Game::createMonsterParty()
{
    int index;

    for (int i=0; i<monster_party_size; i++)
    {
        std::cout << "Enter index of the monster (from the database): ";
        std::cin >> index;

        //the_monsters->setMember(i, &monster_database[index]);
        the_monsters->setMember(i, new Monster(monster_database[index]));
    }
}
