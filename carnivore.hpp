#ifndef DEF_CARNIVORE
#define DEF_CARNIVORE

#include "poisson.hpp"

class Carnivore : public Poisson {
    public:
        Carnivore(const std::string &, const sexe_t &, const std::string &);
        Carnivore(const std::string &, const sexe_t &, const std::string &, const int);

        virtual void eat();
};

#endif