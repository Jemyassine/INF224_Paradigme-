#include "Group.h"
#include <iostream>

// Constructor
Group::Group(const std::string& name) : name(name) {}

// Destructor
Group::~Group() {
    std::cout << "Group " << name << " is being destroyed." << std::endl;
}

// Accessor to get the name of the group
std::string Group::getName() const {
    return name;
}

// Method to display the attributes of all objects in the list
void Group::display(std::ostream& os) const {
    os << "Group: " << name << std::endl;
    for (auto  multimedia : *this) {
        multimedia->display(os);
    }
}
// Method to play the content of all objects in the list
void Group::play() const {
    for (auto multimedia : *this) {
        multimedia->play();
    }
}