//Author: Kiersten Page
//Purpose: Expand warrior class using classes
//hw3

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Warrior{
public:
    Warrior(const string& name, const string& weapon,  int strength): name(name), weapon(weapon, strength){}
    friend ostream& operator << (ostream& os, const Warrior& warrior);
    friend void battle(vector<Warrior>& warriors, const string& warriorOne, const string& warriorTwo);
private:
    string name;
    class Weapon{
    public:
        Weapon(const string& name, int& strength) : name(name), strength(strength){}
        int getStrength()const {
            return strength;
        }
        string getName()const {
            return name;
        }
        void changeStrength(int amount){
            strength -= amount;
        }
    private:
        string name;
        int strength;
    };
    Weapon weapon;
};

void battle(vector<Warrior>& warriors, const string& warriorOne, const string& warriorTwo){
    for(Warrior& warrior1 : warriors){
        if(warrior1.name == warriorOne){
            for(Warrior& warrior2 : warriors){
                if(warrior2.name == warriorTwo){
                    cout << warrior1.name << " battles " << warrior2.name << endl;
                    if(warrior1.weapon.getStrength() == 0 && warrior2.weapon.getStrength() == 0){
                        cout << "Oh, NO! They're both dead! Yuck!" << endl;
                    }
                    else if(warrior1.weapon.getStrength() == 0){
                        cout << "He's dead " << warrior2.name << endl;
                    }
                    else if(warrior2.weapon.getStrength() == 0){
                        cout << "He's dead " << warrior1.name << endl;
                    }
                    else if(warrior1.weapon.getStrength() == warrior2.weapon.getStrength()){
                        cout << "Mutual Annihilation: " << warrior1.name << " and " << warrior2.name;
                        cout << " die at each other's hands" << endl;
                        warrior1.weapon.changeStrength(warrior1.weapon.getStrength());
                        warrior2.weapon.changeStrength(warrior2.weapon.getStrength());
                    }
                    else if(warrior1.weapon.getStrength() < warrior2.weapon.getStrength()){
                        cout << warrior2.name << " defeats " << warrior1.name << endl;
                        warrior1.weapon.changeStrength(warrior1.weapon.getStrength());
                        warrior2.weapon.changeStrength(warrior1.weapon.getStrength());
                    }
                    else if(warrior2.weapon.getStrength() < warrior1.weapon.getStrength()){
                        cout << warrior1.name << " defeats " << warrior2.name << endl;
                        warrior1.weapon.changeStrength(warrior2.weapon.getStrength());
                        warrior2.weapon.changeStrength(warrior2.weapon.getStrength());
                    }
                }
            }
        }
    }
}

ostream& operator << (ostream& os, const Warrior& warrior){
    cout << "Warrior: " << warrior.name << ", weapon: " << warrior.weapon.getName();
    cout << ", " << warrior.weapon.getStrength() << endl;
    return os;
}

void status(const vector<Warrior>& warriors){
    cout << "There are " << warriors.size() << " warriors" << endl;
    for(const Warrior& warrior: warriors){
        cout << warrior;
    }
}

int main() {
    vector<Warrior> warriors;
    ifstream warriorFile("warriors.txt");
    if(!warriorFile){
        cerr << "Could not open the file" << endl;
        exit(1);
    }
    string command, warrior1Name, weaponName, warrior2Name;
    int strength;

    while(warriorFile >> command){
        if(command == "Warrior"){
            warriorFile >> warrior1Name >> weaponName >> strength;
            warriors.emplace_back(warrior1Name, weaponName, strength);
        }
        else if(command == "Status"){
            status(warriors);
        }
        else if(command == "Battle"){
            warriorFile >> warrior1Name >> warrior2Name;
            battle(warriors, warrior1Name, warrior2Name);
        }
    }
    warriorFile.close();
}