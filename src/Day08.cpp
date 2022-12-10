#include "Day08.hpp"

Day08::Day08() {
  std::ifstream file("../inputs/day08.in");

  if (!file.is_open()) {
    std::cout << "File is not open\n";
    std::exit(1);
  }

  std::string line{};
  while(std::getline(file, line)) {
    for (const char ch: line)
      treeMap.push_back(int(ch - '0'));
    numRows++;
  }
  numCols = line.size();
}

bool Day08::isVisible(int x, int y) {
  int currVal = treeMap.at(x * numCols + y);
  bool visibleFromTop{true};
  bool visibleFromBottom{true};
  bool visibleFromLeft{true};
  bool visibleFromRight{true};
  // Check if visible from the top
  for (int i = 0; i < x; i++) {
    int temp {treeMap.at(i * numCols + y)};
    if (temp >= currVal) {
      visibleFromTop = false;
      break;
    }
  }
  // Check if visible from the bottom
  for (int i = x + 1; i < numRows; i++) {
    int temp {treeMap.at(i * numCols + y)};
    if (temp >= currVal) {
      visibleFromBottom = false;
      break;
    }
  }
  // Check if visible from the left
  for (int i = 0; i < y; i++) {
    int temp {treeMap.at(x * numCols + i)};
    if (temp >= currVal) {
      visibleFromLeft = false;
      break;
    }
  }
  // Check if visible from the top
  for (int i = y + 1; i < numCols; i++) {
    int temp {treeMap.at(x* numCols + i)};
    if (temp >= currVal) {
      visibleFromRight = false;
      break;
    }
  }
  return visibleFromTop || visibleFromBottom || visibleFromLeft || visibleFromRight;
}

int Day08::part1() {
  int visibleTrees{2 * (numRows + numCols - 2)};
  for (int i = 1; i < numRows - 1; i++) {
    for (int j = 1; j < numCols - 1; j++) {
      if (isVisible(i,j))
        visibleTrees++;
    }
  }
  return visibleTrees;
}

int Day08::part2() {
  int highestScenicScore{0};
  for (int i = 1; i < numRows; i++) {
    for (int j = 1; j < numCols; j++) {
      int currentScenicScore {calculateScenicScore(i,j)};
      if(currentScenicScore > highestScenicScore)
        highestScenicScore = currentScenicScore;
    }
  }
  return highestScenicScore;
}

void Day08::printSolutions() {
  std::cout << "Part 1: " << part1() << "\n";
  std::cout << "Part 2: " << part2() << "\n";
}
int Day08::calculateScenicScore(int x, int y) {
  int scoreFromLeft{0};
  int scoreFromTop{0};
  int scoreFromRight{0};
  int scoreFromBottom{0};
  int currentVal = treeMap.at(x * numCols + y);
  // Top score
  int i{x-1};
  while (i >=0) {
    scoreFromTop++;
    int temp = treeMap.at(i * numCols + y);
    if (temp >= currentVal)
      break;
    i--;
  }
  // Bottom score
  i = x + 1;
  while (i < numRows) {
    scoreFromBottom++;
    int temp = treeMap.at(i * numCols + y);
    if (temp >= currentVal)
      break;
    i++;
  }
  // Left score
  i=y-1;
  while (i >= 0) {
    scoreFromLeft++;
    int temp = treeMap.at(x * numCols + i);
    if (temp >= currentVal)
      break;
    i--;
  }
  // Right score
  i = y + 1;
  while (i < numRows) {
    scoreFromRight++;
    int temp = treeMap.at(x * numCols + i);
    if (temp >= currentVal)
      break;
    i++;
  }
  return scoreFromBottom * scoreFromLeft * scoreFromRight * scoreFromTop;
}
