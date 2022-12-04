#include "Day03.hpp"

Day03::Day03()
{
    std::ifstream file{"../inputs/day03.in"};
    std::string rucksack;

    if (!file.is_open())
    {
        std::cout << "File could not be opened!\n";
        std::exit(1);
    }

    while (std::getline(file, rucksack))
    {
        rucksacks.push_back(rucksack);
    }
}

int Day03::part1()
{
    int totalScore{0};
    for (const std::string &rucksack : rucksacks)
    {
        std::string firstCompartment = rucksack.substr(0, rucksack.length() / 2);
        std::string secondCompartment = rucksack.substr(rucksack.length() / 2);
        std::vector<std::string> x{firstCompartment, secondCompartment};
        std::vector<char> commonCharacters{getCommonChars(x)};
        for (const char c : commonCharacters)
        {
            totalScore += charToScore(c);
        }
    }
    return totalScore;
}

int Day03::part2()
{
    int totalScore{0};
    for (std::vector<std::string>::const_iterator it = rucksacks.begin(); it != rucksacks.end();)
    {
        std::vector<std::string> rucksackGroup = getRucksackGroup(it);
        std::vector<char> commonCharacters{getCommonChars(rucksackGroup)};
        for (const char c : commonCharacters)
        {
            totalScore += charToScore(c);
        }
    }

    return totalScore;
}

int Day03::charToScore(char c)
{
    if (isupper(c))
    {
        return 27 + c - 65;
    }
    else
    {
        return 1 + c - 97;
    }
}

std::vector<std::string> Day03::getRucksackGroup(std::vector<std::string>::const_iterator &it)
{
    std::vector<std::string> res{};
    for (int i = 0; i < 3 && it != rucksacks.end(); i++)
    {
        res.push_back(*it);
        it++;
    }
    return res;
}

std::vector<char> Day03::getCommonChars(std::vector<std::string> strings)
{
    std::vector<char> res{};
    // ASCII has 128 characters
    // This holds the values of the first string
    std::vector<int> charsInString1(128, 0);
    std::vector<int> charsInString2(128, 0);

    // Mark the position of the character if you encounter it in the first string
    for (auto ch : strings[0])
    {
        charsInString1[ch]++;
    }

    for (int i = 1; i < strings.size(); i++)
    {
        // Increment the position of the char in the i-th string
        for (auto ch : strings[i])
        {
            charsInString2[ch]++;
        }

        // Check if char was already encountered in first string
        for (int i = 0; i < 128; i++)
        {
            charsInString1[i] = std::min(charsInString1[i], charsInString2[i]);
            // Reset value
            charsInString2[i] = 0;
        }
    }

    for (int i = 0; i < 128; i++)
    {
        // If value is greater than 0 that means it was encountered in all strings
        if (charsInString1[i] > 0)
        {
            res.push_back((char)i);
        }
    }
    return res;
}

void Day03::printSolutions()
{
    std::cout << "Part 1: " << part1() << "\n";
    std::cout << "Part 2: " << part2() << "\n";
}
