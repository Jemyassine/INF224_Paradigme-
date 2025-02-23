#include "MultimediaManager.h"
#include <iostream>
//  Create a photo
PhotoPtr MultimediaManager::createPhoto(const std::string& name, const std::string& pathname, double latitude, double longitude) {
    auto photo = PhotoPtr(new Photo(name, pathname, latitude, longitude));
    multimediaTable[name] = photo;
    return photo;
}
// Create a video
VideoPtr MultimediaManager::createVideo(const std::string& name, const std::string& pathname, int duration) {
    auto video = VideoPtr(new Video(name, pathname, duration));
    multimediaTable[name] = video;
    return video;
}
// Create a film
FilmPtr MultimediaManager::createFilm(const std::string& name, const std::string& pathname, int duration, int* chapters, int count) {
    auto film = FilmPtr(new Film(name, pathname, duration, chapters, count));
    multimediaTable[name] = film;
    return film;
}
// Create a group
GroupPtr MultimediaManager::createGroup(const std::string& name) {
    auto group = GroupPtr(new Group(name));
    groupTable[name] = group;
    return group;
}
// Find a multimedia object
MultimediaPtr MultimediaManager::findMultimedia(const std::string& name) const {
    auto it = multimediaTable.find(name);
    if (it != multimediaTable.end()) {
        return it->second;
    } else {
        return nullptr;
    }
}
// Display a multimedia object
void MultimediaManager::displayMultimedia(const std::string& name, std::ostream& os) const {
    MultimediaPtr multimedia = findMultimedia(name);
    if (multimedia != nullptr) {
        multimedia->display(os);
    } else {
        os << "Multimedia object not found: " << name << std::endl;
    }
}
// Display a group
void MultimediaManager::displayGroup(const std::string& name, std::ostream& os) const {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        it->second->display(os);
    } else {
        os << "Group not found: " << name << std::endl;
    }
}

// Play a multimedia object
void MultimediaManager::playMultimedia(const std::string& name) const {
    auto it = multimediaTable.find(name);
    if (it != multimediaTable.end()) {
        it->second->play();
    } else {
        std::cerr << "Multimedia object not found: " << name << std::endl;
    }
}
// Play a group
void MultimediaManager::playGroup(const std::string& name) const {
    auto it = groupTable.find(name);
    if (it != groupTable.end()) {
        it->second->play();
        }
    else {
        std::cerr << "Group not found: " << name << std::endl;
    }
}

// Remove a multimedia object
void MultimediaManager::removeMultimedia(const std::string& name) {
    MultimediaPtr multimedia = findMultimedia(name);
    if (multimedia != nullptr) {
        multimediaTable.erase(name);
    }
}

void MultimediaManager::removeGroup(const std::string& name) {
    groupTable.erase(name);
}

// List all multimedia objects
void MultimediaManager::listAllMultimedias(std::ostream& os) const {
    for (auto const& it : multimediaTable) {
        it.second->display(os);
    }
}
// List all groups
void MultimediaManager::listALLGroups(std::ostream& os) const {
    for (auto const& it : groupTable) {
        it.second->display(os);
    }
}
void MultimediaManager::save(const std::string& filename) const {
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Could not open file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& pair : multimediaTable) {
        ofs << pair.second->getClassName() << '\n';
        pair.second->write(ofs);
    }

    ofs.close();
}

void MultimediaManager::load(const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cerr << "Could not open file for reading: " << filename << std::endl;
        return;
    }

    std::string className;
    while (getline(ifs, className)) {
        MultimediaPtr obj = createObject(className);
        if (obj) {
            obj->read(ifs);
            multimediaTable[obj->getName()] = obj;
        }
    }

    ifs.close();
}
MultimediaPtr MultimediaManager::createObject(const std::string& className) {
    if (className == "Photo") {
        return std::make_shared<Photo>();
    } else if (className == "Video") {
        return std::make_shared<Video>();
    } else if (className == "Film") {
        return std::make_shared<Film>();
    } else {
        return nullptr;
    }
}