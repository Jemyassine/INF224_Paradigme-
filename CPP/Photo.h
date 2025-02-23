#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo : public Multimedia {
private:
    double latitude;
    double longitude;

public:
    Photo() : Multimedia(), latitude(0), longitude(0) {}
    Photo(const std::string& name, const std::string& pathname, double latitude, double longitude);
    virtual ~Photo();

    void display(std::ostream& os) const override;
    void play() const override;

    // Serialization
    void write(std::ofstream& ofs) const override;
    void read(std::ifstream& ifs) override;

    // Factory method
    std::string getClassName() const override { return "Photo"; }
};

#endif