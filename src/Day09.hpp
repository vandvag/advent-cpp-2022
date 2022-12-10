//
// Created by Evangelos Vandoros on 10/12/22.
//

#ifndef ADVENT_CPP_2022_DAY09_HPP
#define ADVENT_CPP_2022_DAY09_HPP
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

struct Command {
  char dir;
  int val;
  Command(char _dir, int _val) : dir(_dir), val(_val){};
};

class Day09 {
private:
  std::vector<Command> commands;
  std::pair<int, int> headPosition{0, 0};
  std::pair<int, int> tailPosition{0, 0};
  int part1();
  int part2();

public:
  Day09();
  void printSolutions();
};

#endif // ADVENT_CPP_2022_DAY09_HPP
