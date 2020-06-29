#include "herbivore.hpp"

Herbivore::Herbivore(const std::string &pName, const sexe_t &pSex, const std::string &pSpecies)
    : Poisson(pName, pSex, pSpecies) {}

Herbivore::Herbivore(const std::string &pName, const sexe_t &pSex, const std::string &pSpecies, const int pAge)
    : Poisson(pName, pSex, pSpecies, pAge) {}

void Herbivore::eat() {
    this->PV += 3;
}