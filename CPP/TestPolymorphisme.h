#ifndef TestPolymorphisme_h
#define TestPolymorphisme_h
#include "Photo.h"
#include "Video.h"
#include <iostream>
#include <vector>
class TestPolymorphisme {
public:
    TestPolymorphisme() {test();}; 
    void test (){
        std::vector<Multimedia*> multimediaList;
        std::string pathname1 = "D:\\time_money_phrase_219589_938x1668.jpg";
        std::string pathname2 = "D:\\Samara.mp4";

    // Ajout d'objets de type Photo et Video
        multimediaList.push_back(new Photo("time_money",pathname1, 48.8566, 2.3522));
        multimediaList.push_back(new Video("Samara", pathname2, 120));

    // Boucle pour afficher et jouer chaque élément
        for (auto & it : multimediaList) {
            it->display(std::cout);
            it->play();
            std::cout << std::endl;
        };

    // Libération de la mémoire
        for (auto & it : multimediaList) {
            delete it;  // Appelle le destructeur virtuel correctement
        };
    // la prpriété cracteristique de polymorphisme est que le type de l'objet est déterminé à l'exécution et non à la compilation
    // les elements de la liste multimediaList sont de type Multimedia* mais ils peuvent pointer vers des objets de type Photo ou Video
    // par rapport au java le polymorphisme en C++ est plus puissant car il peut être utilisé avec des pointeurs et des références
    
    }
};
#endif
