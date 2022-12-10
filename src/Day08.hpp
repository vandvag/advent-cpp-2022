#ifndef DAY08_HPP
#define DAY08_HPP

#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
#include "Grid.hpp"

class Day08
{
private:
  std::vector<int> treeMap{};
  int numRows{0};
  int numCols{0};
  int part1();
  int part2();
  bool isVisible(int x, int y);
  int calculateScenicScore(int x, int y);
public:
  Day08();
  void printSolutions();
};
#endif
