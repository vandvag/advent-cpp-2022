//
// Created by Evangelos Vandoros on 10/12/22.
//

#ifndef ADVENT_CPP_2022_FILESYSTEM_HPP
#define ADVENT_CPP_2022_FILESYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>

class Item {
protected:
    std::string name{};
    long size{};
    Item *parent{nullptr};

public:
    const std::string &getName() const;
    Item *getParent() const;
    long getSize() const;
    void setSize(long newSize);
    virtual ~Item() = default;
    void setParent(Item *_parent);
};

class Directory : public Item {
protected:
    std::vector<Item *> children{};

public:
    Directory(std::string _name);
    friend std::ostream &operator<<(std::ostream &os, Directory &dir);
    void addChild(Item *child);
};

class File : public Item {
public:
    friend std::ostream &operator<<(std::ostream &os, File &file);
};


#endif//ADVENT_CPP_2022_FILESYSTEM_HPP
