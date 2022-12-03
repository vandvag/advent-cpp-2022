#ifndef DAY03_HPP
#define DAY03_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <limits.h>
#include <algorithm>

class Day03
{
private:
    std::vector<std::string> rucksacks;
    int part1();
    int part2();
    int charToScore(char c);
    std::vector<std::string> getRucksackGroup(std::vector<std::string>::const_iterator &it);
    std::vector<char> getCommonChars(std::vector<std::string> strings);

public:
    Day03();
    void printSolutions();
};
#endif