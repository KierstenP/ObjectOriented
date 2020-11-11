/*
Author: Kiersten Page
HW07
*/
#include "Protector.h"
#include "Noble.h"

namespace WarriorCraft {

    //protector definition
    Protector::Protector(const string& aName, double theStrength)       //constructor
            : name(aName), strength(theStrength), employer(nullptr) {}
    double Protector::getStrength() {
        return strength;    //returns strength of the protector
    }
    void Protector::hired(Noble& leader) {employer = &leader;}  //hires a protector
    void Protector::fired(){employer == nullptr};
    bool Protector::isEmployed() { return !(employer == nullptr); } //checks to see if a protector is already employed
    string Protector::getName() { return name; }    //returns the name of the protector
    void Protector::subtractStrength(double num1, double num2) {    //lessens the strength of the protector as a result of battle
        if (num2 != 0) { strength = strength - (strength * num1 / num2); }
        else { strength = strength * num2; }
    }
    //wizard derived class of protector class
    Wizard::Wizard(const string& aname, double thestrength) : Protector(aname, thestrength) {}
    double Wizard::getStrength() { return Protector::getStrength(); }
    void Wizard::hired(Noble& leader) { Protector::hired(leader); }
    void Wizard::battle() { cout << "Poof \n"; }
    void Wizard::subtractStrength(double num1, double num2) { Protector::subtractStrength(num1, num2); }
    bool Wizard::isEmployed() { return Protector::isEmployed(); }
    //warrior derived class of protector class
    Warriors::Warriors(const string& aname, double thestrength) : Protector(aname, thestrength) {}
    double Warriors::getStrength() { return Protector::getStrength() }
    void Warrior::fired(){Protector::fired()};
    void Warrior::battleDeclaration() { cout << getName() << " says: Take that in the name of my lord, " << getLeaderName() << endl; }
    //swordsman derived class of protector class
    Swordsman::Swordsman(const string& aname, double thestrength) : Warriors(aname, thestrength) {}
    double Swordsman::getStrength() { return Protector::getStrength(); }
    void Swordsman::battle() { cout << "Clang! " }
    void Swordsman::hired(Noble& leader) { Protector::hired(leader); }
    void Swordsman::subtractStrength(double num1, double num2) { Protector::subtractStrength(num1, num2); }
    bool Swordsman::isEmployed() { return Protector::isEmployed(); }
    //archer derived class of protector class
    Archer::Archer(const string& aname, double thestrength) : Warriors(aname, thestrength) {}
    double Archer::getStrength() {return Protector::getStrength(); }
    void Archer::battle() { cout << "Twang! "; }
    void Archer::hired(Noble& leader) { Protector::hired(leader); }
    void Archer::subtractStrength(double num1, double num2) { Protector::subtractStrength(num1, num2); }
    bool Archer::isEmployed() { return Protector::isEmployed(); }

}