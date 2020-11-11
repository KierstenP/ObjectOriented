/*
  Recitation 06
  CS2124
 
  Focus: Dynamic arrays and copy control


  Author: Kiersten Page
  rec06
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
    friend ostream& operator<<(ostream& os, const Position& rhs) {
        os << '[' << rhs.title << ',' << rhs.salary << ']';
        return os;
    }
public:
    Position(const string& aTitle, double aSalary)
            : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
private:
    string title;
    double salary;
}; // class Position

class Entry {
    friend ostream& operator<<(ostream& os, const Entry& entry) {
        os << entry.name << ' ' << entry.room
           << ' ' << entry.phone << ", " << *entry.pos;
        return os;
    }
public:
    Entry(const string& name, unsigned room, unsigned phone, Position& position)
            : name(name), room(room), phone(phone), pos(&position) {
    }
    const string& getName() const { return name; }
    unsigned getPhone() const { return phone; }
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory {
    // Overload output operator
    friend ostream& operator<<(ostream& os, const Directory& directory) {
        for (size_t i = 0; i < directory.size; ++i) {
            os << *directory.entries[i];
            os << endl;
        }
        return os;
    }
public:
    // Of course the first function you need to write for this (or
    // any) class is...
    // ???
    // ...
    // We'll get you started with the add method, but obviously you
    // have a lot of work to do here.

    //Initializer
    Directory() {
        ++capacity;
        entries = new Entry*[capacity];
    }

    //Copy Constructor
    Directory(const Directory& copy) {
        cout << "Calling the copy constructor" << endl;
        size = copy.size;
        capacity = copy.capacity;
        entries = new Entry*[capacity];
        for (size_t index = 0; index < size; ++index) {
            Entry* new_entry = new Entry(*copy.entries[index]);
            entries[index] = new_entry;
        }
    }

    //Destructor
    ~Directory() {
        cout << "Calling the destructor" << endl;
        for (size_t i = 0; i < size; ++i) {
            delete entries[i];
        }
        delete[] entries;
    }

    //Assignment Operator
    Directory& operator=(const Directory& other) {
        cout << "Calling the assignment operator" << endl;
        //prevent self assignment
        if (this != &other) {
            //free up
            for (size_t i = 0; i < size; ++i) {
                delete entries[i];
            }
            delete[] entries;
            size = other.size;
            capacity = other.capacity;
            entries = new Entry*[capacity];
            for (size_t index = 0; index < size; ++index) {
                Entry* new_entry = new Entry(*other.entries[index]);
                entries[index] = new_entry;
            }
        }
        //return yourself
        return *this;
    }


    //add method
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (size == capacity)	{   //if directory has reached max size
            // something is missing!!!  Add it!

            capacity *= 2; //double capacity

            Entry** nextArray = new Entry*[capacity];
            for (size_t i = 0; i < size; ++i) {
                nextArray[i] = entries[i];
            }
            delete[] entries;
            entries = nextArray;

        } // if
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } // add

    //overloading the [] operator so that you can look up someones number by passing in their name
    unsigned operator[] (string name) const {
        for (size_t i = 0; i < size; ++i) {
            if (name == entries[i]->getName()) {    //if input name matchies one, then the number will be returned
                return (entries[i]->getPhone());
            }
        }
        cerr << "This person is not in the directory." << endl; //else an error message will be printed
    }

private:
    Entry** entries;
    size_t size;
    size_t capacity;
}; // class Directory

void doNothing(Directory dir) { cout << dir << endl; }

int main() {

    // Note that the Postion objects are NOT on the heap.
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);

    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;

    Directory d2 = d;	// What function is being used??
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << d << endl;

    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";

    Directory d3;
    d3 = d2;

    // Should display 1592
    cout << d2["Carmack"] << endl;

} // main