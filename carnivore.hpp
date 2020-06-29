#ifndef DEF_CARNIVORE
#define DEF_CARNIVORE

#include "poisson.hpp"

class Carnivore : public Poisson {
    public:
        Carnivore(const std::string &, sexe_t, const std::string &);
        Carnivore(const std::string &, sexe_t, const std::string &, int);

        virtual void eat() override;
};

#endif