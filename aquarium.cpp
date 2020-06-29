#include "aquarium.hpp"

Aquarium::Aquarium() : algaeNbr(0), algaeList(0), fishList(0) {}

Aquarium::~Aquarium() {
    if (!(this->fishList.empty())) {
        std::vector<Poisson *>::iterator it = this->fishList.begin();

        for (; it != this->fishList.end(); it++) {
            delete *it;
        }
    }
}

size_t Aquarium::getAlgaeNbr() {
    return this->algaeNbr;
}

std::vector<Poisson *> Aquarium::getFishes() {
    return this->fishList;
}

void Aquarium::addAlgae() {
    this->algaeNbr++;
    this->algaeList.push_back(Algue());
}

void Aquarium::addFish(const std::string &pName, sexe_t pSex, const std::string &pSpecies) {
    if (pSpecies == "Mérou" || pSpecies == "Thon" || pSpecies == "Poisson clown") {
        this->fishList.push_back(new Carnivore(pName, pSex, pSpecies));
    } else if (pSpecies == "Bar" || pSpecies == "Sole" || pSpecies == "Carpe") {
        this->fishList.push_back(new Herbivore(pName, pSex, pSpecies));
    }
}

void Aquarium::addFish(const std::string &pName, sexe_t pSex, const std::string &pSpecies, int pAge) {
    if (pSpecies == "Mérou" || pSpecies == "Thon" || pSpecies == "Poisson clown") {
        this->fishList.push_back(new Carnivore(pName, pSex, pSpecies, pAge));
    } else if (pSpecies == "Bar" || pSpecies == "Sole" || pSpecies == "Carpe") {
        this->fishList.push_back(new Herbivore(pName, pSex, pSpecies, pAge));
    }
}

void Aquarium::computeTour() {
    if (this->fishList.empty()) {
        std::cerr << "Aquarium vide" << std::endl;
        return;
    }

    srand(static_cast<unsigned int>(time(NULL)));
    
    size_t index, fishListSize = this->fishList.size(), algaeListSize = this->algaeList.size();
    std::string carnClassName = typeid(Carnivore).name();

    for (index = 0; index < algaeListSize; index++) {
        Algue &curAlgae = this->algaeList[index];
        curAlgae.evolution();

        if (curAlgae.dead()) {
            this->algaeList.erase(this->algaeList.begin() + index);
            algaeListSize--;
        } else if (curAlgae.getPV() >= 10) {
            curAlgae.setPV(static_cast<int>(curAlgae.getPV() / 2));
            this->addAlgae();
            this->algaeList.back().setPV(curAlgae.getPV());
        }
    }

    for (index = 0; index < fishListSize; index++) {
        auto curFish = this->fishList[index];

        curFish->evolution();

        if (curFish->dead()) {
            delete curFish;
            this->fishList.erase(this->fishList.begin() + index);
            fishListSize--;
        } else if (curFish->getPV() <= 5) {
            if (typeid(*(curFish)).name() == carnClassName) {
                size_t toEaten = rand() % fishListSize;
                auto otherFish = this->fishList[toEaten];

                if ((toEaten != index) && (curFish != otherFish)) {
                    curFish->eat();
                    otherFish->eaten();

                    if (otherFish->dead()) {
                        delete otherFish;
                        this->fishList.erase(this->fishList.begin() + toEaten);
                    }
                }
            } else {
                if (algaeListSize != 0) {
                    size_t toEaten = rand() % algaeListSize;

                    curFish->eat();
                    this->algaeList[toEaten].eaten();

                    if (this->algaeList[toEaten].dead()) {
                        this->algaeNbr--;
                        algaeListSize--;
                        this->algaeList.erase(this->algaeList.begin() + toEaten);
                    }
                }
            }
        } else {
            size_t toMeet = rand() % fishListSize;
            auto otherFish = this->fishList[toMeet];

            if ((*curFish == *otherFish) && ((curFish->getSex() != otherFish->getSex()) || (curFish->getSex(1) == "herma"))) {
                size_t babySex = toMeet % 2;

                this->addFish(
                    radioAlphabet[(toMeet + index) % 26],
                    static_cast<sexe_t>(babySex),
                    curFish->getSpecies()
                );
            }
        }
    }

    this->displayContent();
}

void Aquarium::displayContent() {
    std::cout << "Nombre d'algue : " << getAlgaeNbr() << std::endl;

    size_t index, fishListSize = this->fishList.size(), algaeListSize = this->algaeList.size();

    std::cout << "Poissons : " << std::endl;

    for (index = 0; index < fishListSize; index++) {
        std::cout << "\t" << this->fishList[index]->getName() << ", ";
        std::cout << this->fishList[index]->getSpecies() << ", ";
        std::cout << this->fishList[index]->getPV() << std::endl;
    }

    std::cout << "Algues : " << std::endl;

    for (index = 0; index < algaeListSize; index++) {
        std::cout << "\t" << "Algue " << index+1 << " : " << this->algaeList[index].getPV() << std::endl;
    }

    std::cout << std::endl;
}