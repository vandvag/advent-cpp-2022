#include "Day03.hpp"

Day03::Day03()
{
    std::ifstream file{"../ipnuts/day03.in"};
    std::string rucksack;

    if (!file.is_open())
    {
        std::cout << "File could not be opened!";
        std::exit(1);
    }

    while (std::getline(file, rucksack))
    {
        std::string firstCompartment = rucksack.substr(0, rucksack.length() / 2);
        std::string secondCompartment = rucksack.substr(rucksack.length() / 2);
        std::cout << firstCompartment << "\n";
        std::cout << secondCompartment << "\n";
    }
}