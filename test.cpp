#include "aquarium.hpp"

int main() {
    int i;
    Aquarium aquarium;

    for (i = 0; i < 5; i++) {
        aquarium.addAlgae();
    }

    aquarium.addFish("alpha", m, "Carpe");
    aquarium.addFish("beta", m, "Carpe");
    aquarium.addFish("charlie", m, "Carpe");
    aquarium.addFish("delta", f, "Carpe");
    aquarium.addFish("echo", f, "Carpe");
    aquarium.addFish("foxtrot", f, "Carpe");

    for (i = 0; i < 4; i++) {
        aquarium.computeTour();
    }

    return 0;
}