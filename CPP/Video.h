#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia {
private:
    int duration;  // Durée en secondes

public:
    Video() : Multimedia(), duration(0) {} // Constructeur par défaut
    Video(const std::string& name, const std::string& pathname, int duration); // Constructeur
    virtual ~Video(); // Destructeur

    int getDuration() const;// Accesseur
    void setDuration(int duration);// Modificateur 

    void display(std::ostream& os) const override; // Méthode d'affichage
    void play() const override; // Méthode de lecture

    // Serialization
    void write(std::ofstream& ofs) const override;
    void read(std::ifstream& ifs) override;

    // Factory method
    std::string getClassName() const override { return "Video"; }
};

#endif
