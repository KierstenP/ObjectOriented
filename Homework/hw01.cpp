//File: HW01
//Author: Kiersten Page
//Purpose: Decrypt an encrypted text file using Caesar Cypher

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//takes an encrypted character and returns the decrypted character
char decryptCharacter(char& character, int& rotations){
    if(character <= 'z' && character >= 'a'){
        character -= rotations;
        if (character < 'a'){
            character += 26;
        }
        return character;
    }
    else{
        return character;   //return decrypted character
    }
}

//takes an encrypted string and returns the decrypted string
void decryptString(string& encryptedString, int& rotations){
    for(int i = 0; i < encryptedString.size(); ++i){
        encryptedString[i] = decryptCharacter(encryptedString[i], rotations);
    }
}

//reads in an encrypted file and decrypts the file line by line
int main(){
    ifstream encryptedFile("encrypted.txt");        //check to see if the file opens correctly
    if (!encryptedFile) {
        cerr << "Could not open the file.\n";
        exit(1);
    }

    int rotations;
    encryptedFile >> rotations;     //get the number of letter rotations

    vector<string> strings;
    string line;
    getline(encryptedFile, line);   //used to "gobble up" the extra newline character

    while (getline(encryptedFile, line)) {      //read in encrypted strings
        strings.push_back(line);
    }

    for(size_t i = 0; i < strings.size(); ++i){        //decrypt the encrypted strings
        decryptString(strings[i], rotations);
    }

    for (size_t i = strings.size(); i > 0; --i){       //print out the decrypted file
        cout << strings[i-1] << endl;
    }

    encryptedFile.close();
}