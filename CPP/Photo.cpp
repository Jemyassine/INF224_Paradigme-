#include "Photo.h"
#include <iostream>
#include <cstdlib>

Photo::Photo(const std::string& name, const std::string& pathname, double latitude, double longitude)
    : Multimedia(name, pathname), latitude(latitude), longitude(longitude) {}

Photo::~Photo() {
    std::cout << "Photo " << getName() << " is being destroyed." << std::endl;
}

void Photo::display(std::ostream& os) const {
    os << "Photo: " << getName() << "\n"
       << "Chemin: " << getPathname() << "\n"
       << "Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
}

void Photo::play() const {
#ifdef _WIN32
    std::string command = "start " + getPathname() + " &";
#elif __linux__
    std::string command = "imagej " + getPathname() + " &";
#else
    std::cerr << "Unsupported platform" << std::endl;
    return;
#endif
    system(command.c_str());
}

void Photo::write(std::ofstream& ofs) const {
    Multimedia::write(ofs);
    ofs << latitude << '\n' << longitude << '\n';
}

void Photo::read(std::ifstream& ifs) {
    Multimedia::read(ifs);
    ifs >> latitude >> longitude;
    ifs.ignore(); // Ignore the newline character after longitude
}