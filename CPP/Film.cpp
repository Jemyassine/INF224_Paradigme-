#include <iostream>
#include "Film.h"

// Constructor
Film::Film(const std::string& name, const std::string& pathname, int duration, int* chapters, int count)
    : Video(name, pathname, duration), chapterDurations(nullptr), chapterCount(count) {
    if (count > 0 && chapters != nullptr) {
        chapterDurations = new int[count];
        for (int i = 0; i < count; ++i) {
            chapterDurations[i] = chapters[i];
        }
    }
}

// Copy constructor
Film::Film(const Film& other) : Video(other), chapterDurations(nullptr), chapterCount(other.chapterCount) {
    if (other.chapterCount > 0 && other.chapterDurations != nullptr) {
        chapterDurations = new int[other.chapterCount];
        for (int i = 0; i < other.chapterCount; ++i) {
            chapterDurations[i] = other.chapterDurations[i];
        }
    }
}

// Copy assignment operator
Film& Film::operator=(const Film& other) {
    if (this != &other) {
        Video::operator=(other); // Call base class assignment operator
        delete[] this->chapterDurations;
        chapterCount = other.chapterCount;
        if (other.chapterCount > 0 && other.chapterDurations != nullptr) {
            chapterDurations = new int[other.chapterCount];
            for (int i = 0; i < other.chapterCount; ++i) {
                chapterDurations[i] = other.chapterDurations[i];
            }
        } else {
            chapterDurations = nullptr;
        }
    }
    return *this;
}

// Destructor
Film::~Film() {
    delete[] chapterDurations;
}

// Modifier to set chapter durations
void Film::setChapters(int* chapters, int count) {
    delete[] chapterDurations;
    chapterCount = count;
    if (count > 0 && chapters != nullptr) {
        chapterDurations = new int[count];
        for (int i = 0; i < count; ++i) {
            chapterDurations[i] = chapters[i];
        }
    } else {
        chapterDurations = nullptr;
    }
}

// Accessor to get chapter durations
const int* Film::getChapters() const {
    return chapterDurations;
}

// Accessor to get chapter count
const int Film::getChapterCount() const {
    return chapterCount;
}
const int Film::getChapterDuration(int index) const {
    if (index >= 0 && index < chapterCount) {
        return chapterDurations[index];
    }
    return -1;
}

// Method to display chapter durations
void Film::displayChapters() const {
    std::cout << "Chapters durations: ";
    for (int i = 0; i < chapterCount; ++i) {
        std::cout << chapterDurations[i] << " ";
    }
    std::cout << std::endl;
}

// Overriding the display method from Video class
void Film::display(std::ostream &os) const {
    Video::display(os);
    Film::displayChapters();
}

// Serialization
void Film::write(std::ofstream& ofs) const {
    Video::write(ofs);
    ofs << chapterCount << '\n';
    for (int i = 0; i < chapterCount; ++i) {
        ofs << chapterDurations[i] << '\n';
    }
}

void Film::read(std::ifstream& ifs) {
    Video::read(ifs);
    ifs >> chapterCount;
    ifs.ignore(); // Ignore the newline character after chapterCount
    chapterDurations = new int[chapterCount];
    for (int i = 0; i < chapterCount; ++i) {
        ifs >> chapterDurations[i];
        ifs.ignore(); // Ignore the newline character after each chapter
    }
}