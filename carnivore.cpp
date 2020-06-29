#include "carnivore.hpp"

Carnivore::Carnivore(const std::string &pName, sexe_t pSex, const std::string &pSpecies)
    : Poisson(pName, pSex, pSpecies) {}

Carnivore::Carnivore(const std::string &pName, sexe_t pSex, const std::string &pSpecies, int pAge)
    : Poisson(pName, pSex, pSpecies, pAge) {}

void Carnivore::eat() {
    this->PV += 5;
}