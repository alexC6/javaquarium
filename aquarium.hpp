#ifndef DEF_AQUARIUM
#define DEF_AQUARIUM

#include <vector>

#include "carnivore.hpp"
#include "herbivore.hpp"

class Aquarium {
    size_t algaeNbr;
    std::vector<Algue> algaeList;
    std::vector<Poisson *> fishList;

    public:
        Aquarium();

        ~Aquarium();

        size_t getAlgaeNbr();
        std::vector<Poisson *> getFishes();

        void addAlgae();
        void addFish(const std::string &, const sexe_t &, const std::string &);
        void addFish(const std::string &, const sexe_t &, const std::string &, const int);

        void computeTour();
        void displayContent();
};

#endif