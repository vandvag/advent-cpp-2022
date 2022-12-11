//
// Created by Evangelos Vandoros on 10/12/22.
//

#include "FileSystem.hpp"
const std::string &Item::getName() const {
    return name;
}
Item *Item::getParent() const {
    return parent;
}

long Item::getSize() const {
    return size;
}
void Item::setParent(Item *_parent) {
    parent = _parent;
}

void Item::setSize(const long newSize)  {
    size = newSize;
}

std::ostream &operator<<(std::ostream &os, Directory &dir) {
    os << dir.name << " (directory): " << dir.size << "\n";
    return os;
}

std::ostream &operator<<(std::ostream &os, File &file) {
    os << file.name << " (directory): " << file.size << "\n";
    return os;
}

void Directory::addChild(Item *_child) {
    // If there is an item with the same name, don't add it
    for (const Item *child: children) {
        if (child->getName() == _child->getName()) {
            std::cout << "Name already exists\n";
            return;
        }
    }
    // Update the child's parent
    _child->setParent(this);
    // Add it to the vector of children
    children.push_back(_child);
    Item *temp = _child;
    // Update size of parent recursively
    if (_child->getSize() > 0) {
        while (temp->getParent()) {
            // add the current size to the parent
            temp->getParent()->setSize(_child->getSize() + temp->getParent()->getSize());
            temp = temp->getParent();
        }
    }
    delete temp;
}
