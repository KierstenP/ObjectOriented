//Author: Kiersten Page
//Purpose: Task based lab on pointers
//rec04

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class PlainOldClass {
public:
    PlainOldClass() : x(-72) {}
    int getX() const { return x; }
    void setX( int val )  { x = val; }
private:
    int x;
};

class PlainOldClassV2 {
public:
    PlainOldClassV2() : x(-72) {}
    int getX() const { return x; }
    //void setX( int x )  { x = x; } // HMMMM???
    //int getX( const PlainOldClass* const this = &poc ) const { return x; }
    //void setX( PlainOldClass* const this = &poc, int x )  { x = x; } // Still HMMMM???
    void setX( int x )  { this->x = x; } // No confusion!
    //this is kind of a class pointer thats initialized for each reference of a class
private:
    int x;
};

class Colour {
public:
    Colour(const string& name, unsigned r, unsigned g, unsigned b)
            : name(name), r(r), g(g), b(b) {}
    void display() const {
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
    }
private:
    string name;      // what we call this colour
    unsigned r, g, b; // red/green/blue values for displaying
};

class Person {
public:
    Person(const string& name) : name(name) {}
    void movesInWith(Person& newRoomate) {
        if (this->roomie == &newRoomate) {
            cout << "You already live with this person" << endl;
        }
        else if(&newRoomate == this){
            cout << "You can't move in with yourself" << endl;
        }
        else if (this->roomie != nullptr) {
            cout << "This person already has a roommate" << endl;
        }
        else if(newRoomate.roomie != nullptr){
            cout << "The new roommate already has a roommate" << endl;
        }
        else{
            roomie = &newRoomate;        // now I have a new roomie
            newRoomate.roomie = this;    // and now they do too
        }
    }

    const string& getName() const { return name; }
    // Don't need to use getName() below, just there for you to use in debugging.
    const string& getRoomiesName() const { return roomie->getName(); }
private:
    Person* roomie;
    string name;
};

class SpeakerSystem {
public:
    void vibrateSpeakerCones(unsigned signal) const {

        cout << "Playing: " << signal << "Hz sound..." << endl;
        cout << "Buzz, buzzy, buzzer, bzap!!!\n";
    }
};

class Amplifier {
public:
    void attachSpeakers(const SpeakerSystem &spkrs) {
        if (attachedSpeakers){
            cout << "already have speakers attached!\n";}
        else{
            attachedSpeakers = &spkrs;}
    }

    void detachSpeakers() {
        // should there be an "error" message if not attached?
        if(attachedSpeakers){
            attachedSpeakers = nullptr;
        }
        else{
            cerr << "Speakers were not attached to begin with. " << endl;
            exit(1);
        }
    }
    void playMusic() const {
        if (attachedSpeakers)
            attachedSpeakers->vibrateSpeakerCones(440);
        else
            cout << "No speakers attached\n";
    }

private:
    //SpeakerSystem* attachedSpeakers = nullptr;
    const SpeakerSystem* attachedSpeakers = nullptr;
};
int main() {
    //task one
    cout << "Task 1" << endl;

    int x;
    x = 10;
    cout << "x = " << x << endl;    //prints out 'x = 10'

    cout << endl;

    //task 8
    cout << "Task 8" << endl;

    int* p;
    p = &x; //takes the address of x and copies it into p (copy right hand side into left)
    cout << "p = " << p << endl;
    cout << endl;
    //task 9
    //&x = 0x7ffeec8dca1c
    //p = 0x7ffeec8dca1c; //using the value from my watch window
    //error message: "assigning to 'int *' from incompatible type 'long'
    //task10
    cout << "Task 10" << endl;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl;

    cout << endl;

    //task11
    cout << "Task 11" << endl;

    *p = -2763;
    cout << "p points to where " << *p << " is      stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "x now contains " << x << endl;

    cout << endl;

    //task12
    cout << "Task 12" << endl;

    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;

    cout << endl;

    //task13
    cout << "Task 13" << endl;

    int* q;
    q = p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl;

    cout << endl;

    //task14
    double d(33.44);
    double* pD(&d);
    *pD = *p;
    *pD = 73.2343;
    *p  = *pD;
    *q  = *p;
    //pD  = p;    //compilation error: assigning to 'double *' from incompatible type 'int *'
    //p   = pD;   //compilation error: assigning to 'int *' from incompatible type 'double *'
    //pointers are different types, therefore you cannot assign p to pD and vice-versa

    //task15
    int joe = 24;
    const int sal = 19;
    int*  pI;
    pI = &joe;
    *pI = 234;  //changes value *p and joe hold
    //pI = &sal; ~sal is a const int, but pI is not a const int pointer
    *pI = 7623; //changes value *p and joe hold
    const int* pcI; //defines a const int pointer
    pcI = &joe; //sets value of constant int pointer pcI to the address of joe
    //*pcI = 234; //pcI is const so it cannot be changed
    pcI = &sal; //can change the address it holds
    //*pcI = 7623; //pcI is const so it cannot be changed

    //int* const cpI; //needs to be initialized to something because it cant be changed after initialization
    int* const cpI(&joe);
    //int* const cpI(&sal); //can't re-initialize, cpI is set to the address of joe forever
    //cpI = &joe; //can't assign
    *cpI = 234; //can change the value that cpI holds, just cant change the address
    //cpI = &sal; //can't change the address it points to
    *cpI = 7623; //can change what it holds
    //const int* const cpcI; //needs to be initialize
    const int* const cpcI(&joe);
    //const int* const cpcI(&sal); // can't redefine
    //cpcI = &joe;  // *cpcI = 234; //for the last three, you cannot change the address nor what the pointer holds
    //cpcI = &sal;
    //*cpcI = 7623;

    //task 16
    cout << "Task 16" << endl;

    struct Complex {
        double real;
        double img;
    };
    Complex c = {11.23,45.67};
    Complex* pC(&c);
    //cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
    //cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl; //dereference and then call the method/member variable

    cout << endl;

    //task 17
    cout << "Task 17" << endl;



    PlainOldClass poc;
    PlainOldClass* ppoc( &poc );
    cout << ppoc->getX() << endl;
    ppoc->setX( 2837 );
    cout << ppoc->getX() << endl;

    cout << endl;

    //task 18
    cout << "Task 18" << endl;



    cout << endl;

    //task 19
    cout << "Task 19" << endl;

    int* pDyn = new int(3); // p points to an int initialized to 3 on the heap
    *pDyn = 17;

    cout << endl;

    //task 20
    cout << "Task 20" << endl;

    cout << pDyn << endl;
    delete pDyn;
    pDyn = nullptr; //task 21
    cout << pDyn << endl;
    //cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";
    //cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";

    cout << endl;

    //task 21
    double* pDouble = nullptr;

    //task 22
    //cout << "Can we dereference nullptr?  " << *pDyn << endl;
    //cout << "Can we dereference nullptr?  " << *pDouble << endl;

    //task 23
    //this can never be nullptr

    //task 24
    double* pTest = new double(12);
    delete pTest;
    pTest = nullptr;
    delete pTest; // safe

    //task 25

    short* pShrt = new short(5);
    delete pShrt;
    //delete pShrt;   //does not work because you can't delete a pointer that has already been deleted

    //task 26

    long jumper = 12238743;
    //delete jumper; delete can only be used with the heap
    //long* ptrTolong = &jumper;
    //delete ptrTolong;
    Complex cmplx;
    //delete cmplx; delete can only be used with the heap

    //task 27
    cout << "Task 27" << endl;
    vector<Complex*> complV; // can hold pointers to Complex objects
    Complex* tmpPCmplx;      // space for a Complex pointer
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        tmpPCmplx = new Complex; // create a new Complex object on the heap
        tmpPCmplx->real = ndx;   // set real and img to be the
        tmpPCmplx->img  = ndx;   // value of the current ndx
        complV.push_back(tmpPCmplx); // store the ADDRESS of the object in a vector or pointer to Complex
    }
    // display the objects using the pointers stored in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        cout << complV[ ndx ]->real << endl;
        cout << complV[ ndx ]->img  << endl;
    }
    // release the heap space pointed at by the pointers in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        delete complV[ndx];
    }
    // clear the vector
    complV.clear();

    //need to go through vector and delete objects prior to clearing the vector
    cout << endl;

    //task 28
    cout << "Task 28" << endl;

    vector<Colour*> colours;    //vector of colour pointers
    string inputName;
    unsigned inputR, inputG, inputB;
    // fill vector with Colours from the file
    // this could be from an actual file but here we are using the keyboard instead of a file
    // (so we don't have to create an actual file)
    // Do you remember the keystroke combination to indicate "end of file" at the keyboard?
    // somehow the while's test has to fail - from keyboard input
    while (cin >> inputName >> inputR >> inputG >> inputB) {
        colours.push_back(new Colour(inputName, inputR, inputG, inputB));
    }

    // display all the Colours in the vector:
    for (size_t ndx = 0; ndx < colours.size(); ++ndx) {
        colours[ndx]->display();
        cout << endl;
    }
    //release heap space
    for (size_t ndx = 0; colours.size(); ++ndx) {
        delete colours[ndx];

    }
    //clear the vector
    colours.clear();

    cout << endl;


    //task 29
    //if (ptrVar);




    SpeakerSystem s;
    Amplifier a;
    a.attachSpeakers(s);
    a.playMusic();

    cout << endl;

    //task 30



// write code to model two people in this world
    Person joeBob("Joe Bob"), billyJane("Billy Jane");

// now model these two becoming roommates
    joeBob.movesInWith(billyJane);

// did this work out?
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
}