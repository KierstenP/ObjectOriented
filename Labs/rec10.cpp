/*Author: Kiersten Page
 *Rec10
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Instrument {
public:
    Instrument(){}; //constructor for instrument class
    virtual void makeSound() const = 0; //all classes must have makesound, marks Instrument as abstract class
    virtual void play() const = 0;
private:
};

void Instrument::makeSound() const {
    cout << "To make a sound...";
}

class Brass : public Instrument{
public:
    Brass(unsigned mps) : mouthpieceSize(mps) {};   //constructor for brass instruments
    void makeSound() const override {
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size " << mouthpieceSize << endl;
    };
private:
    unsigned mouthpieceSize;
};

class String : public Instrument{
public:
    String(unsigned p) : pitch(p) {}; //constructor for string instruments
    void makeSound() const override{
        Instrument::makeSound();
        cout << "bow a string with pitch " << pitch << endl;
    }; //make string class abstract
private:
    unsigned pitch;
};

class Percussion : public Instrument{
public:
    Percussion(){}; //percussion instrument constructor
    void makeSound() const override{
        Instrument::makeSound();
        cout << "hit me!" << endl;
    }; //make percussion class abstract
};
class Trumpet : public Brass{
public:
    Trumpet(unsigned mps) : Brass(mps){};
    void play() const override{
        cout << "Toot" << endl;
    }
};

class Trombone : public Brass{
public:
    Trombone(unsigned mps) : Brass(mps){};
    void play() const override{
        cout << "Blat" << endl;
    }
};

class Violin : public String{
public:
    Violin(unsigned p) : String(p){};
    void play() const override{
        cout << "Screech" << endl;
    }
};

class Cello : public String{
public:
    Cello(unsigned p) : String(p){};
    void play() const override{
        cout << "Squawk" << endl;
    }
};

class Drum : public Percussion{
public:
    Drum(): Percussion(){};
    void play() const override{
        cout << "Boom" << endl;
    }
private:
};

class Cymbal : public Percussion{
public:
    Cymbal(): Percussion(){};
    void play()const override{
        cout << "Crash" << endl;
    }
private:
};

class Musician {
public:
    Musician() : instr(nullptr) {}

    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }

    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }

    void play() const{
        if(instr)instr->play();
        else cerr << "have no instr\n";
    }

private:
    Instrument* instr;
};

class MILL{
public:
    void receiveInstr(Instrument& instr){
        cout << "Testing Instrument" << endl;
        instr.makeSound();
        for(size_t i = 0; i < instruments.size() ; ++i){
            if(instruments[i] == nullptr){ //place instrument at the first available spot
                instruments[i] = &instr;
                return;
            }
        }
        instruments.push_back(&instr);  //add new bin at end of row
    }

    void dailyTestPlay() const {
        for(Instrument* instrumentsPtr : instruments){
            if (instrumentsPtr != nullptr) {
                instrumentsPtr->makeSound();
            }
        }
    }

    Instrument* loanOut(){
        for(size_t i = 0 ; i < instruments.size(); ++i){
            if(instruments[i] != nullptr){
                Instrument* instrumentLoan= instruments[i];
                instruments[i] = nullptr;
                return instrumentLoan;
            }
        }
        return nullptr; //returns nullptr in the case that there are no instruments left in the mill
    }

private:
    vector<Instrument*> instruments; //array to store all of the instrument pointers
};


class Orch{
public:
    void addPlayer(Musician& musician){
        for(size_t i =0; i < musicians.size(); ++i){
            if(musicians[i] == nullptr) {
                musicians[i] = &musician;
                return;
            }
        }
        musicians.push_back(&musician);
    }

    void play(){
        for(Musician* musicianptr : musicians){
            musicianptr->play();
            cout << endl;
        }
    }

private:
    vector<Musician*> musicians;


};
// PART ONE
int main() {

     cout << "Define some instruments ------------------------------------\n";
     Drum drum;
     Cello cello(673);
     Cymbal cymbal;
     Trombone tbone(4);
     Trumpet trpt(12) ;
     Violin violin(567) ;

     //Part One test code

//     // use the debugger to look at the mill
//     cout << "Define the MILL --------------------------------------------\n";
//     MILL mill;
//
//     cout << "Put the instruments into the MILL --------------------------\n";
//     mill.receiveInstr(trpt);
//     mill.receiveInstr(violin);
//     mill.receiveInstr(tbone);
//     mill.receiveInstr(drum);
//     mill.receiveInstr(cello);
//     mill.receiveInstr(cymbal);
//
//     cout << "Daily test -------------------------------------------------\n";
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << "Define some Musicians---------------------------------------\n";
//     Musician harpo;
//     Musician groucho;
//
//     cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
//     //groucho.testPlay();
//     //cout << endl;
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << endl << endl;
//
//     groucho.testPlay();
//     cout << endl;
//     mill.receiveInstr(*groucho.giveBackInstr());
//     harpo.acceptInstr(mill.loanOut());
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     harpo.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//
//     cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
//
//     // fifth
//     mill.receiveInstr(*groucho.giveBackInstr());
//     cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
//     mill.receiveInstr(*harpo.giveBackInstr());
//
//
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//
//     cout << endl;


    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);

    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
}