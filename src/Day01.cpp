#include "Day01.hpp"

Day01::Day01()
{
    std::string filePath{"../inputs/day01.in"};
    std::ifstream file(filePath);
    std::string line{};
    if (!file.is_open())
    {
        std::exit(1);
    }
    int calorieSum{0};
    while (std::getline(file, line))
    {
        if (line[0] == '\n')
        {
            calorieSums.push_back(calorieSum);
            calorieSum = 0;
        }
        calorieSum += std::stoi(line);
    }
    file.close();
    std::sort(calorieSums.begin(), calorieSums.end(), [](int a, int b)
              { return (a > b); });
}

int Day01::solvePart1()
{
    return calorieSums[0];
}

int Day01::solvePart2()
{
    return calorieSums[0] + calorieSums[1] + calorieSums[2];
}

void Day01::printSolutions()
{
    std::cout << "Part 1: " << solvePart1() << "\n";
    std::cout << "Part 2: " << solvePart2() << "\n";
}