#include "Day07.hpp"

Day07::Day07()
{
    std::ifstream file{"../inputs/day07.in"};

    if (!file.is_open())
    {
        std::cout << "File could not be opened"
                  << "\n";
        std::exit(1);
    }

    std::string line;
    while (std::getline(file, line))
    {
    }
}

int Day07::part1()
{
    return -1;
}

int Day07::part2()
{
    return -1;
}

day7::Directory::Directory(std::string _name)
{
    name = _name;
}

day7::File::File(std::string _name, long _size) : name(_name), size(_size){};
day7::File::File(std::string _name, long _size, Directory _parentDir)
    : name(_name), size(_size), parentDir(_parentDir){};
