#ifndef DEF_HERBIVORE
#define DEF_HERBIVORE

#include "algue.hpp"
#include "poisson.hpp"

class Herbivore : public Poisson {
    public:
        Herbivore(const std::string &, const sexe_t &, const std::string &);
        Herbivore(const std::string &, const sexe_t &, const std::string &, const int);

        virtual void eat();
};

#endif