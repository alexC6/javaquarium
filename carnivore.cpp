#include "carnivore.hpp"

Carnivore::Carnivore(const std::string &pName, const sexe_t &pSex, const std::string &pSpecies)
    : Poisson(pName, pSex, pSpecies) {}

Carnivore::Carnivore(const std::string &pName, const sexe_t &pSex, const std::string &pSpecies, const int pAge)
    : Poisson(pName, pSex, pSpecies, pAge) {}

void Carnivore::eat() {
    this->PV += 5;
}