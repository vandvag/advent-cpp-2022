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
}
