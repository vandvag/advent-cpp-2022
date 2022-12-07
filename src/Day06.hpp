#ifndef DAY06_HPP
#define DAY06_HPP

#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

class Day06
{
  private:
    std::string signal{};
    int part1(const int startOfMessageMarker) const;
    bool is_unique(const std::deque<char> &buffer) const;

  public:
    Day06();
    void printSolutions();
};
#endif
