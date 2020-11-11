#include "Warrior.h"
#include "Noble.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace WarriorCraft {
    Warrior::Warrior(const std::string& warriorName, int warrior_strength) : name(warriorName), strength(warrior_strength) {}
    void Warrior::reduceStrength(int strengthOne, int strengthTwo) {
        if (strengthTwo != 0) { strength = strength - (strength * strengthOne / strengthTwo); }
        else { strength = strength * strengthTwo; }
    }
    bool Warrior::runaway() {
        if (noble == nullptr) { return false; }
        for (size_t i = 0; i < (noble->warriors.size()); ++i) {
            if (noble->warriors[i] == this) {
                noble->warriors[i] = noble->warriors[i+1];
            }
        }
        noble->warriors.pop_back();
        cout << name << " flees in terror, abandoning his lord, " << noble->getName() << endl;
        noble = nullptr;
        return true; }
    string Warrior::getName() const { return name; }
    int Warrior::getStrength() const { return strength; }
}