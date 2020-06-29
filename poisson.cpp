#include "poisson.hpp"

Poisson::Poisson(const std::string &pName, sexe_t pSex, const std::string &pSpecies)
    : name(pName), sex(pSex), species(pSpecies) {}

Poisson::Poisson(const std::string &pName, sexe_t pSex, const std::string &pSpecies, int pAge)
    : Vivant(pAge), name(pName), sex(pSex), species(pSpecies) {}

bool Poisson::operator!=(const Poisson &other) {
    return (this->species != other.species);
}

bool Poisson::operator==(const Poisson &other) {
    return (this->species == other.species);
}

std::string Poisson::getName() {
    return this->name;
}

std::string Poisson::getSex(int otherFish) {
    std::string fishSpecies = this->species;

    if (((fishSpecies == "Sole") || (fishSpecies == "Poisson clown")) && (otherFish)) {
        return "herma";
    } else {
        if (this->sex == f) {
            return "female";
        } else {
            return "male";
        }
    }
}

std::string Poisson::getSpecies() {
    return this->species;
}

void Poisson::setName(const std::string &newName) {
    this->name = newName;
}

void Poisson::setSex(sexe_t newSex) {
    this->sex = newSex;
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

    if (this->age > 10) {
        if (this->sex == f) {
            this->sex = m;
        } else {
            this->sex = f;
        }
    }
}