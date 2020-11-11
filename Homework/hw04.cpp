/*
Author: Kiersten Page
Purpose: Nobles have armies of warriors and battle other nobles
HW04
*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Warrior{
public:
    Warrior(const string& name, const int& strength) : name(name), strength(strength){}
    string getName() const {       //returns the name of the warrior
        return name;
    }
    int getStrength() const{    //returns the strength of the warrior
        return strength;
    }
    void changeStrength(const int& decrement){  //changes the strength of the warrior
        if(decrement == 0){
            strength = 0;   //reduces the warrior's strength to 0
        }
        else{
            strength = (strength * decrement);  //changes warrior's strength depending on the ratio given
        }

    }
    bool getEmploymentStatus(){ //returns whether or not the warrior is already employed
        return hired;
    }
    bool changeEmploymentStatus(bool hired){    //changes the warriors employment status
        hired = hired;
    }

private:
    string name;    //name of the warrior
    int strength;   //strength of the warrior
    bool hired; //bool to keep track of whether or not the warrior has been hired already
};


class Noble{
public:
    Noble(const string& name) : name(name), alive(true){}    //initializes a noble to be alive (with his given name)
    bool hire(Warrior& warrior){    //hires a warrior
        if(!alive){ //noble can't hire someone if he's already dead
            return false;
        }
        else {
            if (warrior.getEmploymentStatus()) {  //if warrior has already been hired, then the noble cannot hire the warrior
                return false;
            } else {
                warrior.changeEmploymentStatus(true);   //keep track of when a warrior is hired
                Warrior* wp;
                wp = &warrior;
                strength += warrior.getStrength(); //adds warriors strength to army
                army.push_back(wp);    //pushes warrior pointer into the army
                return true; //indicate whether or not hire was successful
            }
        }
    }

    void display(){ //displays warriors in the nobles army
        cout << name << " has an army of " << army.size() << endl;
        for(size_t i = 0; i < army.size(); ++i){
            cout << "       " << army[i]->getName() << ": " << army[i] ->getStrength() << endl;
        }
    }

    bool fire(Warrior& warrior){    //fires a warrior from the nobles army
        if(!alive){ //if the noble is dead, he can't fire a warrior
            return false;
        }
        else {
            for (size_t i = 0; i < army.size(); ++i) {
                if (army[i] == &warrior) {
                    strength -= warrior.getStrength(); //when a warrior is fired, their strength is removed from the army's strength
                    warrior.changeEmploymentStatus(false);
                    cout << warrior.getName() << ", you're fired! -- " << name << endl;
                    army[i] = army[army.size() - 1];
                    army.pop_back();

                    return true;
                }
            }
            return false;   //returns false when the method fails
        }
    }

    void battle(Noble& otherNoble){ //two nobles battle one another
        cout << name << " battles " << otherNoble.name << endl; //announces who is battling who
        if(!alive && !otherNoble.alive){    //case where both nobles try to battle one another, but they're both dead
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        else if(strength == otherNoble.strength){   //if both nobles' armies have the same strength
            cout << "Mutual Annihilation: " << name << " and " << otherNoble.name;
            cout << " die at each other's hands." << endl;
            strength = 0;
            otherNoble.strength = 0;
            for(size_t i = 0; i < army.size(); ++i){
                army[i]->changeStrength(0);
            }
            for(size_t i = 0; i < otherNoble.army.size(); ++i){
                otherNoble.army[i]->changeStrength(0);
            }
            //sets both nobles' alive states to false (dead)
            alive = false;
            otherNoble.alive = false;
        }
        else if(strength == 0 && otherNoble.strength != 0){
            cout << "He's dead " << otherNoble.name << endl;    //if 'this' noble is already dead
        }
        else if(otherNoble.strength == 0 && strength != 0){
            cout << "He's dead " << name << endl;   //if other noble is already dead
        }
        else if(strength > otherNoble.strength){
            cout << name << " defeats " << otherNoble.name << endl; //'this' noble is stronger than the other noble
            int ratio;
            ratio = (otherNoble.strength/strength); //ratio used to decrease 'this' nobles strength
            for(size_t i = 0; i < army.size(); ++i){
                army[i]->changeStrength(ratio); //changes individual warriors strength by ratio
            }
            for(size_t i = 0; i < otherNoble.army.size(); ++i){
                otherNoble.army[i]->changeStrength(0);  //reduces other nobles' warriors' strengths to 0
            }
            strength -= otherNoble.strength;    //reduces nobles total strength
            otherNoble.strength = 0; //reduces other nobles strength to 0
            otherNoble.alive = false; //indicates that the other noble is dead
        }
        else if(strength < otherNoble.strength){    //does the same as above, but this time, the other noble defeats 'this' noble
            cout << otherNoble.name << " defeats " << name << endl;
            int ratio;
            for(size_t i = 0; i < army.size(); ++i){
                otherNoble.army[i]->changeStrength(ratio);
            }
            for(size_t i = 0; i < otherNoble.army.size(); ++i){
                army[i]->changeStrength(0);
            }
            otherNoble.strength -= strength;
            strength = 0;
            alive = false;
        }
    }
private:
    string name;    //noble's name
    vector<Warrior*> army;      //vector of warrior pointers to represent the noble's army
    int strength;   //keeps track of the strength of the noble's army
    bool alive; //keeps track of whether or not the noble is alive
};


int main() {
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);

    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();

    art.fire(cheetah);
    art.display();

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
}