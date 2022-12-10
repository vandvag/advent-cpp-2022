#include "Grid.hpp"

template <typename T>
T Grid<T>::at(int x, int y) {
  int idx = x * numCols + y;
  return gridMap.at(idx);
}

template <typename T>
T Grid<T>::at(int i) { return gridMap.at(i); }

template <typename T>
Grid<T>::Grid(std::string inputPath) {
  std::ifstream file{inputPath};

  if (!file.is_open()) {
    std::cout << "File couldn't be opened\n";
    std::exit(1);
  }

  std::string line{};
  while(std::getline(file, line)) {
    for (const char ch : line)
      gridMap.push_back(int(ch - '0'));
    numRows++;
  }
  numCols = line.size();
}
