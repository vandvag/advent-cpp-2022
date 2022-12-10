#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template <typename T>
class Grid {
private:
  std::vector<T> gridMap{};
  int numRows = 0;
  int numCols = 0;

public:
  Grid<T>(std::string inputPath);
  Grid<T>() = default;
  T at(int x, int y);
  T at(int i);

};
