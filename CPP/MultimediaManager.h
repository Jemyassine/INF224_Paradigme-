#ifndef MULTIMEDIA_MANAGER_H
#define MULTIMEDIA_MANAGER_H
#define version_etape_9
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include <map>
#include <iostream>
#include <memory>
#include <string>

using MultimediaPtr = std::shared_ptr<Multimedia>;
using PhotoPtr = std::shared_ptr<Photo>;
using VideoPtr = std::shared_ptr<Video>;
using FilmPtr = std::shared_ptr<Film>;
using GroupPtr = std::shared_ptr<Group>;

using multimediaTable = std::map<std::string, MultimediaPtr>;
using groupTable = std::map<std::string, GroupPtr>;




class MultimediaManager {
private:
    multimediaTable multimediaTable;
    groupTable groupTable;

public:
    //constructor
    MultimediaManager() {};
    // destructor
    ~MultimediaManager(){};
    
    // Methods to create and add objects to the tables
    PhotoPtr createPhoto(const std::string& name, const std::string& pathname, double latitude, double longitude);
    VideoPtr createVideo(const std::string& name, const std::string& pathname, int duration);
    FilmPtr createFilm(const std::string& name, const std::string& pathname, int duration, int* chapters, int count);
    GroupPtr createGroup (const std::string& name);

    // Methods to find and display objects or groups
    MultimediaPtr findMultimedia(const std::string& name) const;
    void displayMultimedia(const std::string& name, std::ostream& os) const;
    void displayGroup(const std::string& name, std::ostream& os) const;

    // Method to play a multimedia object
    void playMultimedia(const std::string& name) const;
    void playGroup(const std::string& name) const;

    // Methods to remove objects or groups
    void removeMultimedia(const std::string& name);
    void removeGroup(const std::string& name);
    // Method to list all multimedia objects
    void listAllMultimedias(std::ostream& os) const;
    // Method to list all groups
    void listALLGroups(std::ostream& os) const;

    // Serialization
    void save(const std::string& filename) const;
    void load(const std::string& filename);

    // Factory method
    static MultimediaPtr createObject(const std::string& className);
};

#endif