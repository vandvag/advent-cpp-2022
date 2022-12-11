//
// Created by Evangelos Vandoros on 10/12/22.
//

#ifndef ADVENT_CPP_2022_DAY10_HPP
#define ADVENT_CPP_2022_DAY10_HPP
#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>

struct Instruction
{
    std::string cmd;
    int value;
    Instruction(std::string _cmd, int _val) : cmd(_cmd), value(_val){};
};

class Day10
{
private:
    std::vector<Instruction> instructions;
    std::vector<int> importantSignalStrengths{};
    int importantClockCycle{20};
    int cycleCount{0};
    int cpuRegisterValue{1};
    int part1();
    int part2();
    int calculateSignalStrength();
    void incrementCpuCycle();

public:
    Day10();
    void printSolutions();
};

#endif // ADVENT_CPP_2022_DAY10_HPP
