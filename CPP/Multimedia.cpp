#include "Multimedia.h"
using namespace std;

Multimedia::Multimedia( string name, string pathname)
    : name(name), pathname(pathname) {}
string Multimedia::getName() const {
    return name;
}
Multimedia::~Multimedia() {
    // Définition vide pour le destructeur virtuel pur
}
string Multimedia::getPathname() const {
    return pathname;
}
void Multimedia::setName(const string& name) {
    this->name = name;
}
void Multimedia::setPathname(const string& name) {
    this->pathname = name;
}
void Multimedia::write(ofstream& ofs) const {
    ofs << name << '\n' << pathname << '\n';
}

void Multimedia::read(ifstream& ifs) {
    getline(ifs, name);
    getline(ifs, pathname);
}