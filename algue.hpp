#ifndef DEF_ALGUE
#define DEF_ALGUE

#include "vivant.hpp"

class Algue : public Vivant {
    public:
        Algue() = default;
        Algue(int);

        virtual void eaten() override;
        virtual void evolution() override;
};

#endif