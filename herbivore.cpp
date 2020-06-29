#include "herbivore.hpp"

Herbivore::Herbivore(const std::string &pName, const sexe_t &pSexe, const std::string &pSpecies)
    : Poisson(pName, pSexe, pSpecies) {}

Herbivore::Herbivore(const std::string &pName, const sexe_t &pSexe, const std::string &pSpecies, const int pAge)
    : Poisson(pName, pSexe, pSpecies, pAge) {}

void Herbivore::eat() {
    this->PV += 3;
}