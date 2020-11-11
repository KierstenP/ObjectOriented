#include "Noble.h"
#include "Warrior.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace WarriorCraft {
    ostream& operator<<(ostream& os, const Noble& rhs) {
        os << rhs.getName() << " has an army of " << rhs.warriors.size() << "\n";
        for (Warrior* warrior : rhs.warriors) {
            os << "\t" << warrior->getName() << ": " << warrior->getStrength() << "\n";
        }
        return os;
    }
    Noble::Noble(const std::string& nobleName) : name(nobleName) {}
    bool Noble::hire(Warrior& warrior) {
        if (!dead) {
            if (warrior.noble == nullptr) {
                Warrior* warriorPointer = &warrior;
                warriors.push_back(warriorPointer);
                warrior.noble = this;
                return true; }
        }
        return false; }
    bool Noble::battle(Noble& otherNoble) {
        cout << name << " battles " << otherNoble.name << endl;
        if ((dead) && (otherNoble.dead)) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
            return false;
        }
        else if (otherNoble.dead) {
            cout << "He's dead " << name << endl;
            return false;
        }
        else if (dead){
            cout << "You're dead!" << endl;
            return false;
        }
        int currentStrength = 0;
        int otherStrength = 0;
        for (size_t index = 0;index < warriors.size(); ++index) {
            currentStrength += warriors[index]->getStrength();
        }
        for (size_t index = 0;index < otherNoble.warriors.size(); ++index) {
            otherStrength += otherNoble.warriors[index]->getStrength();
        }
        if (currentStrength == otherStrength) {
            cout << "Mutual Annihalation: " << name << " and " << otherNoble.name << " die at each other's hands" << endl;
            dead = true;
            otherNoble.dead = true;
            reduceStrength(0,0);
        }
        else if(currentStrength > otherStrength) {
            cout << name << " defeats " << otherNoble.name << endl;
            otherNoble.dead = true;
            reduceStrength(otherStrength, currentStrength);
            otherNoble.reduceStrength(0,0);
        }
        else {
            cout << otherNoble.name << " defeats " << name << endl;
            dead = true;
            reduceStrength(currentStrength, otherStrength);
            reduceStrength(0,0);
        }
        return true;
    }
    void Noble::reduceStrength(int strengthOne, int strengthTwo) {
        for (size_t i = 0; i < warriors.size(); ++i) {
            warriors[i]->reduceStrength(strengthOne, strengthTwo);
        }
        if (strengthOne == 0) { dead = true; }
    }
    bool Noble::fire(Warrior& warriorName) {
        for (size_t i = 0; i < warriors.size(); ++i) {
            if (warriors[i] == (&warriorName)) {
                warriors[i] = warriors[i+1];
            }
        }
        warriors.pop_back();
        cout << warriorName.name << ", you're fired! " << name << endl;
        return true;
    }
    string Noble::getName() const { return name; }
}