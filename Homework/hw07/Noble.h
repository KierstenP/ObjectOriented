/*
Author: Kiersten Page
HW07
*/
#ifndef NOBLE_H
#define NOBLE_H

#include "Protector.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace WarriorCraft {
    class Noble {
    public:
        Noble();
        Noble(const string& aname, double thestrength);
        virtual double getStrength() = 0;
        void setStrength(double stren);
        string getName();
        virtual bool isAlive() = 0;
        virtual void defend();
        void setAlive(bool val);

        virtual void battle(Noble& enemy) = 0;
        virtual void subtractStrength(double num1, double num2) = 0;
    protected:

    private:
        string name;
        double strength;
        bool alive;
    };


    class PersonWithStrengthToFight : public Noble {
    public:
        PersonWithStrengthToFight();
        PersonWithStrengthToFight(const string& aname, double thestrength);
        string getName();
        bool isAlive() override;
        double getStrength() override;
        void battle(Noble& enemy) override;
        void subtractStrength(double num1, double num2) override;
        void battleCry();
    private:
    };

    class Lord : public Noble {
    public:
        Lord(const string& aname);
        void hire(Protector& protector);
        string getName();
        bool isAlive() override;
        double getStrength() override;
        void battle(Noble& enemy) override;
        void subtractStrength(double num1, double num2) override;
        void defend();
        void fire
    private:
        vector<Protector*> army;
    };
}
#endif