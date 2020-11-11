// HW02
// Author: Kiersten Page
// Purpose: Modelling a game of medieval times where warriors can battle one another


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Warrior{
    string name;
    int strength;
};
void createWarrior(string& name, int& strength, vector<Warrior>& warriors){ //will create and add a warrior to the vector
    Warrior warrior;
    warrior.name = name;
    warrior.strength = strength;
    warriors.push_back(warrior);
}
void status(vector<Warrior> warriors){      //function to list each warrior and their status
    cout << "There are: " << warriors.size() << " warriors" << endl;
    for(Warrior& warrior : warriors){
        cout << "Warrior: " << warrior.name << ", strength: " << warrior.strength << endl;
    }
}
bool findWarriors(string& warriorOne, string& warriorTwo, vector<Warrior>& warriors){   //check to see if warriors exist
    bool checkOne = false;
    bool checkTwo = false;
    for(Warrior& warrior : warriors){
        if(warrior.name == warriorOne){
            checkOne = true;
        }
        else if(warrior.name == warriorTwo){
            checkTwo = true;
        }
    }
    if(checkOne == true && checkTwo == true){
        return true;
    }
    else{
        return false;
    }
}
void battle(string& warriorOne, string& warriorTwo, vector<Warrior>& warriors){ //function to simulate battle
    if(findWarriors(warriorOne, warriorTwo, warriors)){     //check to see if the warriors exist
        cout << warriorOne << " battles " << warriorTwo << endl;
        for(Warrior& warrior1 : warriors){
            if(warrior1.name == warriorOne){
                for(Warrior& warrior2 : warriors){
                    if(warrior2.name == warriorTwo){
                        if(warrior1.strength == 0 && warrior2.strength == 0){
                            cout << "Oh, NO! They're both dead! Yuck!" << endl;
                        }
                        else if(warrior2.strength == 0){

                            cout << "He's dead, " << warrior1.name << endl;
                        }
                        else if(warrior1.strength == 0){
                            cout << "He's dead, " << warrior2.name << endl;
                        }
                        else if(warrior1.strength == warrior2.strength){ //warriors have the same strength
                            warrior1.strength = 0;
                            warrior2.strength = 0;
                            cout << "Mutual Annihilation: " << warrior1.name << " and " << warrior2.name;
                            cout << " die at each other's hands" << endl;

                        }
                        else if(warrior1.strength > warrior2.strength){
                            warrior1.strength -= warrior2.strength;
                            warrior2.strength = 0;
                            cout << warrior1.name << " defeats " << warrior2.name << endl;
                        }
                        else if(warrior2.strength > warrior1.strength){
                            warrior2.strength -= warrior1.strength;
                            warrior1.strength = 0;
                            cout << warrior2.name << " defeats " << warrior1.name << endl;
                        }
                    }
                }
            }
        }
    }
    else{
        cout << "Warrior(s) has/have not yet been seen" << endl;
    }
}
int main(){
    vector<Warrior> warriors;       //creates a space to store warriors in
    ifstream commands("warriors.txt");      //check to make sure the file opens correctly
    if(!commands){
        cerr << "Couldn't open the file.\n";
        exit(1);
    }
    string command;
    while(commands >> command){
        if(command == "Warrior"){
            string name;
            int strength;
            commands >> name;
            commands >> strength;
            createWarrior(name, strength, warriors);
        }
        else if(command == "Status"){
            status(warriors);
        }
        else if(command == "Battle"){
            string warriorOne;
            string warriorTwo;
            commands >> warriorOne;
            commands >> warriorTwo;
            battle(warriorOne, warriorTwo, warriors);
        }
    }
    commands.close();
}