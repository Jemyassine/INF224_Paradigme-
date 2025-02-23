#include "Video.h"
#include <iostream>
#include <cstdlib>  // Pour la fonction system()

Video::Video(const std::string& name, const std::string& pathname, int duration)
    : Multimedia(name, pathname), duration(duration) {}

Video::~Video() {
    std::cout << "Video " << getName() << " is being destroyed." << std::endl;
}

int Video::getDuration() const {
    return duration;
}

void Video::setDuration(int duration) {
    this->duration = duration;
}

void Video::display(std::ostream& os) const {
    os << "Vidéo: " << getName() << "\n"
       << "Chemin: " << getPathname() << "\n"
       << "Durée: " << duration << " secondes" << std::endl;
}

void Video::play() const {
#ifdef _WIN32
    std::string command = "start " + getPathname() + " &";  // Commande pour lire la vidéo
#elif __linux__
    std::string command = "mpv " + getPathname() + " &";  // Commande pour lire la vidéo
#else
    std::cerr << "Unsupported platform" << std::endl;
    return;
#endif    
    system(command.c_str());  // Lancement de l'application externe
}

void Video::write(std::ofstream& ofs) const {
    Multimedia::write(ofs);
    ofs << duration << '\n';
}

void Video::read(std::ifstream& ifs) {
    Multimedia::read(ifs);
    ifs >> duration;
    ifs.ignore();  // Ignore le caractère de fin de ligne après la durée
}

