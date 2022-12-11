//
// Created by Evangelos Vandoros on 10/12/22.
//

#include "Day10.hpp"

Day10::Day10() {
  std::ifstream file("../inputs/day10.in");

  std::string line{};
  while (std::getline(file, line)) {
    std::vector<std::string> tokens{Utilities::splitString(line, " ")};
    if (tokens[0] == "addx")
      instructions.emplace_back(tokens[0], std::stoi(tokens[1]));
    else if (tokens[0] == "noop")
      instructions.emplace_back(tokens[0], 0);
  }
}
int Day10::part1() {
  for (const Instruction &instruction : instructions) {
    if (instruction.cmd == "noop") {
      incrementCpuCycle();
    } else if (instruction.cmd == "addx") {
      incrementCpuCycle();
      incrementCpuCycle();
      cpuRegisterValue += instruction.value;
    } else {
      std::cout << "Invalid command\n";
    }
  }

  return std::accumulate(importantSignalStrengths.begin(),
                         importantSignalStrengths.end(), 0);
}

void Day10::incrementCpuCycle() {
  cycleCount++;
  if (cycleCount == importantClockCycle) {
    importantSignalStrengths.push_back(calculateSignalStrength());
    importantClockCycle += 40;
  }
}

int Day10::part2() { return 0; }

void Day10::printSolutions() {
  std::cout << "Part 1: " << part1() << "\n";
  std::cout << "Part 2: " << part2() << "\n";
}

int Day10::calculateSignalStrength() { return cycleCount * cpuRegisterValue; }
