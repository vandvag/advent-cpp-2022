#ifndef DAY04_HPP
#define DAY04_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

class Day04
{
private:
    std::vector<std::vector<int>> elfPairs{};
    int part1();
    int part2();

public:
    Day04();
    void printSolutions();
};
#endif