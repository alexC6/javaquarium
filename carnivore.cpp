#include "carnivore.hpp"

Carnivore::Carnivore(const std::string &pName, const sexe_t &pSexe, const std::string &pSpecies)
    : Poisson(pName, pSexe, pSpecies) {}

Carnivore::Carnivore(const std::string &pName, const sexe_t &pSexe, const std::string &pSpecies, const int pAge)
    : Poisson(pName, pSexe, pSpecies, pAge) {}

void Carnivore::eat() {
    this->PV += 5;
}