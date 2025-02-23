#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <fstream>
#include <string>
#include <iostream>

class Multimedia{
private:
    std::string name;
    std::string pathname;
public:
    Multimedia(){};
    Multimedia( std::string name, std::string pathname);
    virtual ~Multimedia();
    std::string getName() const;
    std::string getPathname() const;
    void setName(const std::string& name);
    void setPathname(const std::string& pathname);
    virtual void display(std::ostream& os) const = 0 ;
    virtual void play() const = 0; 
    // Serialization
    virtual void write(std::ofstream& ofs) const;
    virtual void read(std::ifstream& ifs);
    
    // Factory method
    virtual std::string getClassName() const = 0;       
};
#endif