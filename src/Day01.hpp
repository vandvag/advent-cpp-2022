#ifndef DAY01_HPP
#define DAY01_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

class Day01
{
private:
    std::vector<int> calorieSums{};

public:
    Day01();
    int solvePart1();
    int solvePart2();
    void printSolutions();
};
#endif