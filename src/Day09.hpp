//
// Created by Evangelos Vandoros on 10/12/22.
//

#ifndef ADVENT_CPP_2022_DAY09_HPP
#define ADVENT_CPP_2022_DAY09_HPP
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
struct Command {
  char dir;
  int val;
  Command(char _dir, int _val) : dir(_dir), val(_val){};
};

class Day09 {
private:
  std::vector<Command> commands;

public:
  Day09();
};

#endif // ADVENT_CPP_2022_DAY09_HPP
