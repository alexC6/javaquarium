#ifndef DEF_POISSON
#define DEF_POISSON

#include <iostream>

#include "vivant.hpp"

typedef enum {
    f, m
} sexe_t;

class Poisson : public Vivant {
    protected:
        std::string name;
        sexe_t sexe;
        std::string species;

    public:
        Poisson(const std::string &, const sexe_t &, const std::string &);
        Poisson(const std::string &, const sexe_t &, const std::string &, const int);

        virtual ~Poisson() = default;

        bool operator!=(const Poisson &);
        bool operator==(const Poisson &);

        std::string getName();
        std::string getSexe();
        std::string getSpecies();

        void setName(const std::string &);
        void setSexe(const sexe_t &);
        void setSpecies(const std::string &);

        virtual void eat() = 0;
        virtual void eaten();
        void evolution();
};

#endif