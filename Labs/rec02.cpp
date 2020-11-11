//Author: Kiersten Page
//rec02
//Purpose: Take in a file from the user consisting of various chemical names and their formulas, and to sort/display
//them


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Chemical{
    vector<string> names;
    int cAtoms;
    int hAtoms;
};

void openFile(ifstream& chemicalFile);
void fillVector(ifstream& chemicalFile, vector<Chemical>& chemicals);
void insertInfo(vector<Chemical>& chemicals, const string& name, const int& c, const int& h);
size_t location(vector<Chemical> chemicals, const int& c, const int& h);
void sortVector(vector<Chemical>& chemicals);
void displayVector(const vector<Chemical>& chemicals);


int main() {
    vector<Chemical> chemicals; //vector to store chemicals in
    ifstream chemicalFile;
    openFile(chemicalFile);
    fillVector(chemicalFile, chemicals);
    sortVector(chemicals);
    displayVector(chemicals);
}

void openFile(ifstream& chemicalFile){
    string fileName;
    cout << "What is the name of the file you wish to open?" << endl;
    cin >> fileName;
    chemicalFile.open(fileName);
    while(!chemicalFile){
        chemicalFile.clear();
        cerr << "The file was not able to be opened. Please input another file name." << endl;
        cin >> fileName;
        chemicalFile.open(fileName);
    }
}

void fillVector(ifstream& chemicalFile, vector<Chemical>& chemicals){
    string name;
    int c, h;
    char dummyC, dummyH;

    chemicalFile >> name >> dummyC >> c >> dummyH >> h;     //read in first initial chemical
    insertInfo(chemicals, name, c, h);

    while(chemicalFile >> name >> dummyC >> c >> dummyH >> h){
        insertInfo(chemicals, name, c, h);
    }
    chemicalFile.close();
}

void insertInfo(vector<Chemical>& chemicals, const string& name, const int& c, const int& h){
    size_t position;
    position = location(chemicals, c, h);
    if(position == chemicals.size()){
        Chemical newChemical;
        newChemical.names.push_back(name);
        newChemical.cAtoms = c;
        newChemical.hAtoms = h;
        chemicals.push_back(newChemical);
    }
    else{
        chemicals[position].names.push_back(name);
    }
}

size_t location(vector<Chemical> chemicals, const int& c, const int& h){
    for(size_t i =0; i < chemicals.size(); ++i){
        if(chemicals[i].hAtoms == h && chemicals[i].cAtoms == c ){
            return(i);
        }
    }
    return(chemicals.size());
}

void sortVector(vector<Chemical>& chemicals){
    for(size_t i = 0; i < chemicals.size(); ++i){
        bool done;
        done = true;
        Chemical temp;
        for(size_t j = 0; j < (chemicals.size() - 1 - i); ++j){
            if(chemicals[j].cAtoms > chemicals[j + 1].cAtoms){
                temp = chemicals[j];
                chemicals[j] = chemicals[j + 1];
                chemicals[j + 1] = temp;
                done = false;
            }
            else if(chemicals[j].cAtoms == chemicals[j + 1].cAtoms) {
                if (chemicals[j].hAtoms > chemicals[j + 1].hAtoms) {
                    temp = chemicals[j];
                    chemicals[j] = chemicals[j + 1];
                    chemicals[j + 1] = temp;
                    done = false;
                }
            }
            if(done){break;}
        }
    }
}

void displayVector(const vector<Chemical>& chemicals){
    for(Chemical chemical : chemicals){
        cout << "C" << chemical.cAtoms << "H" << chemical.hAtoms << " ";
        for(const string& name : chemical.names){
            cout << name << " ";
        }
        cout << endl;
    }
}