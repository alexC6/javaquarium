#include "vivant.hpp"

Vivant::Vivant() : PV(10), age(0) {}

Vivant::Vivant(const int pAge) : PV(10), age(pAge) {}

int Vivant::getPV() {
    return this->PV;
}

void Vivant::setPV(int newPV) {
    this->PV = newPV;
}

bool Vivant::dead() {
    return ((this->PV <= 0) || (this->age > 20));
}