//File: rec01
//Author: Kiersten Page
//Purpose: The purpose of this lab is to implement Conway's Game Of Life

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using  namespace std;

void printWorld(const vector<string>& world){
    for(const string& line : world){
        cout << line << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void oneRound(vector<string>& oldWorld){  //will simulate one round of Conway's Game of Life
    vector <string> newWorld = oldWorld;
    for(size_t row = 0; row < oldWorld.size(); ++row ){
        for(size_t cell = 0; cell < oldWorld[row].size(); ++cell){
            int count = 0;
            if(row == 0){    //check to see if current row is top row
                if(cell == 0){  //check to see if current cell is the far-most left cell;
                        if(oldWorld[row][cell + 1] == '*'){ //check to the right
                            count += 1;
                        }
                        if(oldWorld[row + 1][cell + 1] == '*'){ //check lower-right corner
                            count += 1;
                        }
                        if(oldWorld[row + 1][cell] == '*'){ //check below
                            count += 1;
                        }
                }
                else if(cell == (oldWorld[row].size()) - 1){ //check to see if current cell is the far-most right cell
                        if(oldWorld[row][cell - 1] == '*'){ //check to the left
                        count += 1;
                        }
                        if(oldWorld[row + 1][cell - 1] == '*'){ //check lower-left corner
                        count += 1;
                        }
                        if(oldWorld[row + 1][cell] == '*'){ //check below
                        count += 1;
                        }
                }
                else{
                        if(oldWorld[row][cell - 1] == '*'){ //check to the left
                            count += 1;
                        }
                        if(oldWorld[row][cell + 1] == '*'){ //check to the right
                            count += 1;
                        }
                        if(oldWorld[row + 1][cell - 1] == '*'){ //check lower-left corner
                            count += 1;
                        }
                        if(oldWorld[row + 1][cell + 1] == '*'){ //check lower-right corner
                            count += 1;
                        }
                        if(oldWorld[row + 1][cell] == '*'){ //check below
                            count += 1;
                        }
                }
            }
            else if(row == (oldWorld.size()-1)){    //check to see if current row is the last row
                if(cell == 0){  //check to see if current cell is the far-most left cell;
                        if(oldWorld[row][cell + 1] == '*'){ //check to the right
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell + 1] == '*'){ //check upper-right corner
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell] == '*'){ //check above
                            count += 1;
                        }
                }
                else if(cell == (oldWorld[row].size()) - 1){   //check to see if current cell is the far-most right cell
                        if(oldWorld[row][cell - 1] == '*'){ //check to the left
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell - 1] == '*'){ //check upper-left corner
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell] == '*'){ //check above
                            count += 1;
                        }
                }
                else{   //check all other cells in the row
                        if(oldWorld[row][cell - 1] == '*'){ //check to the left
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell - 1] == '*'){ //check upper-left corner
                            count += 1;
                        }
                        if(oldWorld[row][cell + 1] == '*'){ //check to the right
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell + 1] == '*'){ //check upper-right corner
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell] == '*'){ //check above
                            count += 1;
                        }
                }
            }
            else{   //for all other rows
                if(cell == 0){
                        if(oldWorld[row][cell + 1] == '*'){ //check to the right
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell + 1] == '*'){ //check upper-right corner
                            count += 1;
                        }
                        if(oldWorld[row + 1][cell + 1] == '*'){ //check lower-right corner
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell] == '*'){ //check above
                            count += 1;
                        }
                        if(oldWorld[row + 1][cell] == '*'){ //check below
                            count += 1;
                        }
                }
                else if(cell == (oldWorld[row].size()) - 1){
                        if(oldWorld[row][cell - 1] == '*'){ //check to the left
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell - 1] == '*'){ //check upper-left corner
                            count += 1;
                        }
                        if(oldWorld[row + 1][cell - 1] == '*'){ //check lower-left corner
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell] == '*'){ //check above
                            count += 1;
                        }
                        if(oldWorld[row + 1][cell] == '*'){ //check below
                            count += 1;
                        }
                }
                else{
                        if(oldWorld[row][cell - 1] == '*'){ //check to the left
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell - 1] == '*'){ //check upper-left corner
                            count += 1;
                        }
                        if(oldWorld[row + 1][cell - 1] == '*'){ //check lower-left corner
                            count += 1;
                        }
                        if(oldWorld[row][cell + 1] == '*'){ //check to the right
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell + 1] == '*'){ //check upper-right corner
                            count += 1;
                        }
                        if(oldWorld[row + 1][cell + 1] == '*'){ //check lower-right corner
                            count += 1;
                        }
                        if(oldWorld[row - 1][cell] == '*'){ //check above
                            count += 1;
                        }
                        if(oldWorld[row + 1][cell] == '*'){ //check below
                            count += 1;
                        }
                }
            }
            //Check to see if cell will live or die
            if(oldWorld[row][cell] == '-'){
                if(count == 3){
                    newWorld[row][cell] = '*';
                }
            }
            else{
                if(count < 2 || count > 3){
                    newWorld[row][cell] = '-';
                }
            }
        }
    }
    oldWorld = newWorld;
}

int main() {
    vector<string> oldWorld;   //define a world to read lines into
    vector<string>newWorld; //this will be the newWorld after one round of Conway's Game of Life

    ifstream initialWorld("life.txt");
    if (!initialWorld){
        cerr << "Couldn't Open the File.\n";
        exit(1);
    }

    string line;
    while(getline(initialWorld, line)){     //while loop will get the initial file into vector form
        oldWorld.push_back(line);
        newWorld.push_back(line);
    }

    cout << "Initial World" << endl;
    printWorld(oldWorld);   //Print out initial world
    int generations = 10;
    for(int i = 0; i < generations ; ++i){
        oneRound(oldWorld);
        cout << "Generation: " << i + 1 << endl;
        printWorld(oldWorld);
    }


    initialWorld.close();   //close the file

}