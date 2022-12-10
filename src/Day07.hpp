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
class File;
class Directory
{
  private:
    std::string name{};
    Directory parent;
    std::vector<Directory> directories{};
    std::vector<File> files{};

  public:
    Directory(std::string _name);
    Directory() = default;
    std::vector<Directory> getDirectories();
    void addFile(const File &file);
    void addDirectory(const Directory &directory);
    Directory getParent() const;
};
class File
{
  private:
    std::string name{};
    long size{};
    Directory parent{};

  public:
    File(std::string _name, long _size);
    File(std::string _name, long _size, Directory _parentDir);
};
} // namespace day7

class Day07
{
  private:
    day7::Directory root{};
    day7::Directory currentDirectory{};
    long part1();
    long part2();

  public:
    Day07();
    void printSolutions();
};
#endif
