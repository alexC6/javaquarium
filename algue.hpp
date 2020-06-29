#ifndef DEF_ALGUE
#define DEF_ALGUE

#include "vivant.hpp"

class Algue : public Vivant {
    public:
        Algue() = default;
        Algue(const int);

        virtual void eaten();
        virtual void evolution();
};

#endif