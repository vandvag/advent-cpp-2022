#ifndef DAY05_HPP
#define DAY05_HPP

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

class Day05
{
  private:
    std::vector<std::vector<int>> commands;
    int part1();
    int part2();

  public:
    Day05();
    void printSolutions();
};
#endif
