#include "algue.hpp"

Algue::Algue(const int pAge) : Vivant(pAge) {}

void Algue::eaten() {
    this->PV -= 2;
}

void Algue::evolution() {
    this->PV++;
    this->age++;
}