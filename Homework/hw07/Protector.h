/*
Author: Kiersten Page
HW07
*/
#ifndef PROTECTOR_H
#define PROTECTOR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace WarriorCraft {
    class Noble;

    class Protector {
    public:
        Protector(const string& aname, double theStrength);
        virtual double getStrength() = 0;
        virtual void battle() {};
        virtual void hired(Noble& employer) = 0;
        string getName();
        virtual void fired(){};
        virtual void subtractStrength(double num1, double num2) = 0;
        virtual bool isEmployed() = 0;
    private:
        string name;
        double strength;
        Noble* employer;
    };

    class Wizard : public Protector{
    public:
        Wizard(const string& aname, double thestrength);
        double getStrength() override;
        void hired(Noble& employer) override;
        void battle();
        void subtractStrength(double num1, double num2) override;
        bool isEmployed() override;
    private:
    };

    class Warrior : public Protector {
    public:
        Warrior(const string& aname, double thestrength);
        double getStrength() override;
        void hired(Noble& employer) = 0;
        void battleDeclaration();
        void battle() = 0;
        bool isEmployed() = 0;
        void battleDeclaration();
    private:
        string name;
        double strength;
    };

    class Swordsman : public Warriors {
    public:
        Swordsman(const string& aname, double thestrength);
        double getStrength() override;
        void hired(Noble& employer) override;
        void battle();
        void subtractStrength(double num1, double num2) override;
        bool isEmployed() override;
    private:
    };

    class Archer : public Warriors {
    public:
        Archer(const string& aname, double thestrength);
        double getStrength() override;
        void hired(Noble& employer) override;
        void subtractStrength(double num1, double num2) override;
        void battle();
        bool isEmployed() override;
    };

}
#endif