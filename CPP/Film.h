#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video {
private:
    int* chapterDurations;
    int chapterCount;

public:
    Film() : Video::Video(), chapterDurations(nullptr), chapterCount(0){};
    // Constructor
    Film(const std::string& name, const std::string& pathname, int duration, int* chapters = nullptr, int count = 0);

    // Destructor
    virtual ~Film();

    // Modifier to set chapter durations
    void setChapters(int* chapters, int count);

    // Accessor to get chapter durations
    const int* getChapters() const;

    // Accessor to get chapter count
    const int getChapterCount() const;

    // Accessor to get the duration of a specific chapter
    const int getChapterDuration(int index) const;

    // Method to display chapter durations
    void displayChapters() const;

    // Overriding the display method from Video class
    void display(std::ostream& os) const override;
    
    // Copy constructor
    Film(const Film& other);

    // Copy assignment operator
    Film& operator=(const Film& other);

    // Serialization
    void write(std::ofstream& ofs) const override;
    void read(std::ifstream& ifs) override;

    // Factory method
    std::string getClassName() const override { return "Film"; }
};

#endif