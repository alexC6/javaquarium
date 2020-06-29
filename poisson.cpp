#include "poisson.hpp"

Poisson::Poisson(const std::string &pName, const sexe_t &pSexe, const std::string &pSpecies)
    : name(pName), sexe(pSexe), species(pSpecies) {}

Poisson::Poisson(const std::string &pName, const sexe_t &pSexe, const std::string &pSpecies, const int pAge)
    : Vivant(pAge), name(pName), sexe(pSexe), species(pSpecies) {}

bool Poisson::operator!=(const Poisson &other) {
    return (this->species != other.species);
}

bool Poisson::operator==(const Poisson &other) {
    return (this->species == other.species);
}

std::string Poisson::getName() {
    return this->name;
}

std::string Poisson::getSexe() {
    if (this->sexe == f) {
        return "female";
    } else {
        return "male";
    }
}

std::string Poisson::getSpecies() {
    return this->species;
}

void Poisson::setName(const std::string &newName) {
    this->name = newName;
}

void Poisson::setSexe(const sexe_t &newSexe) {
    this->sexe = newSexe;
}

void Poisson::setSpecies(const std::string &newSpecies) {
    this->species = newSpecies;
}

void Poisson::eaten() {
    this->PV -= 4;
}

void Poisson::evolution() {
    this->PV--;
    this->age++;
}