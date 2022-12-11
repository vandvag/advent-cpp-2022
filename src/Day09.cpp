//
// Created by Evangelos Vandoros on 10/12/22.
//

#include "Day09.hpp"
Day09::Day09() {

  std::ifstream file("../inputs/day09.in");

  std::string line{};

  while (std::getline(file, line)) {
    std::stringstream lineStream{line};
    char direction{};
    int value{};
    lineStream >> direction >> value;
    commands.push_back(Command(direction, value));
  }

  for (Command &command : commands)
    std::cout << "(" << command.dir << ", " << command.val << ")\n";
}

void Day09::printSolutions() {
  std::cout << "Part 1: " << part1() << "\n";
  std::cout << "Part 2: " << part2() << "\n";
}

int Day09::part1() { return 0; }
int Day09::part2() { return 0; }

std::pair<int, int> Day09::commandToDirection(Command &command) {
  switch (command.dir) {
  case 'U':
    return std::pair<int, int>{0, 1};
  case 'D':
    return std::pair<int, int>{0, -1};
  case 'L':
    return std::pair<int, int>{-1, 0};
  case 'R':
    return std::pair<int, int>{1, 0};
  default:
    return std::pair<int, int>{0, 0};
  }
  return std::pair<int, int>();
}
