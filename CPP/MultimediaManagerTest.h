#ifndef MULTIMEDIA_MANAGER_TEST_H
#define MULTIMEDIA_MANAGER_TEST_H

#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "MultimediaManager.h"
#include <iostream>
#include <vector>
#include <memory>

class MultimediaManagerTest {
public:
    MultimediaManagerTest(){
        MultimediaManager* manager = new MultimediaManager();
        // Create some multimedia objects
        auto photo1 = manager->createPhoto("Photo1", "D:\\time_money_phrase_219589_938x1668.jpg", 48.858844, 2.294351);
        auto photo2 = manager->createPhoto("Photo2", "D:\\time_money_phrase_219589_938x1668.jpg", 40.748817, -73.985428);
        auto video1 = manager->createVideo("Video1", "D:\\Samara.mp4", 120);
        // display video1
        manager->displayMultimedia("Video1", std::cout);
        // play video1
        manager->playMultimedia("Video1");

    };
};

#endif