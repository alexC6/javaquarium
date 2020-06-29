#ifndef DEF_AQUARIUM
#define DEF_AQUARIUM

#include <vector>

#include "carnivore.hpp"
#include "herbivore.hpp"

const std::string radioAlphabet[] = {
    "alpha", "beta", "charlie", "delta", "echo", "foxtrot",
    "golf", "hotel", "india", "juliet", "kilo", "lima",
    "mike", "november", "oscar", "papa", "quebec", "romeo",
    "sierra", "tango", "uniform", "victor", "whiskey", "xray",
    "yankee", "zulu"
};

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
        void addFish(const std::string &, sexe_t, const std::string &);
        void addFish(const std::string &, sexe_t, const std::string &, int);

        void computeTour();
        void displayContent();
};

#endif