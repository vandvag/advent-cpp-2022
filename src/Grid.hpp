#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Grid
{
private:
    std::vector<T> gridMap{};
    int numRows = 0;
    int numCols = 0;
};