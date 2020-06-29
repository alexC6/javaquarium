#ifndef DEF_VIVANT
#define DEF_VIVANT

class Vivant {
    protected:
        int PV, age;

    public:
        Vivant();
        Vivant(int);

        virtual ~Vivant() = default;

        int getPV();
        int getAge();

        void setPV(int);

        bool dead();
        virtual void eaten() = 0;
        virtual void evolution() = 0;
};

#endif