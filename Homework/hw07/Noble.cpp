
/*
Author: Kiersten Page
HW07
*/
#include "Noble.h"

namespace WarriorCraft {
    Noble::Noble() {}
    Noble::Noble(const string & aname, double thestrength) : name(aname), strength(thestrength), alive(true) {}
    string Noble::getName() { return name; }
    void Noble::setStrength(double s) { strength = s; }
    double Noble::getStrength() { return strength; }
    bool Noble::isAlive() { return alive; }
    void Noble::setAlive(bool val) { alive = val; }
    void Noble::defend(){}
    void Noble :: subtractStrength(double num1, double num2) {
        if (num2 != 0) {
            strength = strength - (strength * num1 / num2);
        }
        else {
            strength = strength * num2;
        }
    }
    //battle method for the noble class
    void Noble::battle(Noble& opponent) {
        std::cout << getName() << " battles " << opponent.getName() << std::endl;
        if (!this->isAlive()) && (!opponent.isAlive()) {    //both nobles are already dead
            std::cout << "Oh, NO!  They're both dead!  Yuck!\n";
        }
        else if(!this->isAlive() && opponent.isAlive()){    //if you're dead and your opponent is alive
            std:: cout << "He's dead " << opponent.getName() << std::endl;
        }
        else if(this->isAlive() && !opponent.isAlive()){    //if you're alive and your opponent is dead
            std:: cout << "He's dead " << this->getName() << std::endl;
        }
        else if (this->getStrength() == opponent.getStrength()) {   //if you both have the same strength
            std::cout << "Mutual Annihilation: " << opponent.getName() << " and " << this->getName() << " die at each other's hands\n";
            this->subtractStrength(0, 0);
            opponent.subtractStrength(0, 0);
        }
            //If both are alive and have different strength
        else {
            if (this->getStrength() > opponent.getStrength()) {
                this->defend();
                opponent.defend();
                std::cout << this->getName() << " defeats " << opponent.getName() << std::endl;
                this->subtractStrength(opponent.getStrength(), this->getStrength());
                opponent.subtractStrength(0, 0);
                opponent.setAlive(false);
            }
            else {
                defend();
                opponent.defend();
                std::cout << opponent.getName() << " defeats " << getName() << std::endl;
                opponent.subtractStrength(this->getStrength(), opponent.getStrength());
                subtractStrength(0, 0);
                setAlive(false);
            }
        }
    }
    //person with strength to fight class
    PersonWithStrengthToFight::PersonWithStrengthToFight() {}
    PersonWithStrengthToFight::PersonWithStrengthToFight(const string & aname, double thestrength) :
            Noble(aname, thestrength) {}
    string PersonWithStrengthToFight::getName() { return Noble::getName(); }
    double PersonWithStrengthToFight::getStrength() { return Noble::getStrength(); }
    bool PersonWithStrengthToFight::isAlive() { return Noble::isAlive(); }
    void PersonWithStrengthToFight::battle(Noble& opponent) { battleCry() , return Noble::battle(opponent); }
    void PersonWithStrengthToFight::subtractStrength(double num1, double num2) { return Noble::subtractStrength(num1, num2); }
    void PersonWithStrengthToFight::battleCry(){cout << "Insert Scary Battle Cry Here"}

    Lord::Lord(const string & aname) : Noble(aname, 0) {}
    { army.clear(); }
    void Lord::hire(Protector& protector) {
        if (!protector.isEmployed()) {
            army.push_back(&protector);
            protector.hired(*this);
        }
    }
    bool Lord::isAlive() { return Noble::isAlive(); }
    string Lord::getName() { return Noble::getName(); }
    double Lord::getStrength() {
        double armyStrength = 0;
        for (size_t i = 0; i < army.size(); ++i) {
            armyStrength += army[i]->getStrength();
        }
        Noble::setStrength(armyStrength);
        return armyStrength;
    }
    void Lord::battle(Noble& opponent) { return Noble::battle(opponent); }
    void Lord::subtractStrength(double num1, double num2) {
        for (size_t i = 0; i < army.size(); ++i) { army[i]->(num1, num2); }
        if (num1 == 0) { setAlive(false); }
    }
    void Lord::defend() {
        for (size_t i = 0; i < army.size(); ++i) { army[i]->battle(); }
    }
    void Lord::fire(Protector& protectorPerson){
        for(size_t i = 0; i < army.size(); ++i){
            if(army[i] == &protectorPerson){
                protectorPerson.employer == nullptr;
                for(size_t j = i; j < army.size(); ++j)
                army[j] == army[j+1];
                break;
            }
        }
    }
}