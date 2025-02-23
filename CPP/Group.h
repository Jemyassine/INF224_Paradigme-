#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <memory>
#include <string>
#include "Multimedia.h"
#ifdef version_etape_9
using MultimediaPtr = std::shared_ptr<Multimedia>;

class Group : public std::list<MultimediaPtr> {
#else
class Group : public std::list<Multimedia*> {
#endif
private:
    std::string name;

public:
    // Constructor
    Group(const std::string& name);

    //desctructor
    virtual ~Group();

    // Accessor to get the name of the group
    std::string getName() const;

    // Method to display the attributes of all objects in the list
    void display(std::ostream& os) const;
    // Method to play the content of all objects in the list
    void play() const;
};

#endif