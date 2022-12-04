#include "Day04.hpp"

Day04::Day04()
{
    std::regex regexPattern("^([\\d]+)-([\\d]+),([\\d]+)-([\\d]+)$");
    std::ifstream file{"../inputs/day04.in"};
    std::string line{};
    if (!file.is_open())
    {
        std::cout << "File couldn't be opened";
        std::exit(1);
    }

    while (getline(file, line))
    {
        std::smatch matches{};
        std::regex_search(line, matches, regexPattern);
        std::vector<int> elfPair{};
        for (int i = 1; i < matches.size(); i++)
        {
            elfPair.push_back(std::stoi(matches[i]));
        }
        elfPairs.push_back(elfPair);
    }
}

int Day04::part1()
{
    int count{0};
    for (const std::vector<int> &elfPair : elfPairs)
    {
        if (((elfPair[0] <= elfPair[2]) && (elfPair[1] >= elfPair[3])) || ((elfPair[0] >= elfPair[2]) && (elfPair[1] <= elfPair[3])))
            count++;
    }
    return count;
}

int Day04::part2()
{
    int count{0};
    for (const std::vector<int> &elfPair : elfPairs)
    {
        if (!((elfPair[1] < elfPair[2]) || (elfPair[3] < elfPair[0])))
            count++;
    }
    return count;
}

void Day04::printSolutions()
{
    std::cout << "Part 1: " << part1() << "\n";
    std::cout << "Part 2: " << part2() << "\n";
}