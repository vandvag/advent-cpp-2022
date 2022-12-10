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
        std::vector<std::string> tokens{Utilities::splitString(line, " ")};
        // chanes current directory
        if (tokens[1] == "cd")
        {
            // At the beginning we will cd to the root always
            // So create the root
            if (tokens[2] == "/")
            {
                root = day7::Directory(tokens[2]);
                continue;
            }
            if (tokens[2] == "..")
            {
                currentDirectory = currentDirectory.
            }
        }
        // we read a directory
        if (tokens[0] == "dir")
        {
            std::cout << "This line is a directory"
                      << "\n";
            std::cout << line << "\n";
        }
    }
}

long Day07::part1()
{
    return -1;
}

long Day07::part2()
{
    return -1;
}

void Day07::printSolutions()
{
    std::cout << "Part 1: " << part1() << "\n";
    std::cout << "Part 2: " << part2() << "\n";
}

day7::Directory::Directory(std::string _name)
{
    name = _name;
}

day7::Directory day7::Directory::getParent() const
{
    return parent;
}

day7::File::File(std::string _name, long _size) : name(_name), size(_size){};
day7::File::File(std::string _name, long _size, Directory _parentDir) : name(_name), size(_size), parent(_parentDir){};
