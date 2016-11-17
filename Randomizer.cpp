#include "Randomizer.hpp"

void Randomizer::init()
{
    // Initialize the random seed
    srand(time(NULL));
}

int Randomizer::randomRange(int start, int end)
{
    return rand() % (end - start + 1) + start;
}
