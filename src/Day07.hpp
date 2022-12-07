#ifndef DAY07_HPP
#define DAY07_HPP

#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

#include "Utils.hpp"

namespace day7
{
class Directory
{
  private:
    std::string name{};

  public:
    Directory(std::string _name);
    Directory() = default;
};
class File
{
  private:
    std::string name{};
    long size{};
    Directory parentDir{};

  public:
    File(std::string _name, long _size);
    File(std::string _name, long _size, Directory _parentDir);
};
} // namespace day7

class Day07
{
  private:
    day7::Directory root{std::string{"/"}};
    int part1();
    int part2();

  public:
    Day07();
    void printSolutions();
};
#endif
