#ifndef DAY05_HPP
#define DAY05_HPP

#include <ctype.h>
#include <fstream>
#include <iostream>
#include <queue>
#include <regex>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Day05
{
  private:
    std::vector<std::vector<int>> commands{};
    std::vector<std::stack<char>> stacks{};
    void part1(std::vector<std::stack<char>> stacks);
    void part2(std::vector<std::stack<char>> stacks);
    void getStacksFromStrings(std::vector<std::string> &boxStacksAsStrings);

  public:
    Day05();
    void printSolutions();
};
#endif
