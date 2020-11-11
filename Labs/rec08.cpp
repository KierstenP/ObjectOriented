/* Author: Kiersten Page
 * rec08 overloading operators
 */


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Rational{
    friend ostream& operator<<(ostream& os, const Rational& number);
    friend istream& operator>>(istream& is, Rational& num);
    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend bool operator<(const Rational& lhs, const Rational& rhs);
public:
    Rational(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator) { simplify(); }

    void simplify() {   //this function serves to ensure that the rational number is in its simplest form
        int check = greatestCommonDivisor(numerator, denominator);
        numerator = numerator / check;
        denominator = denominator / check;
        if (denominator < 0) {  //check if the negative sign is located in the denominator
            numerator = numerator * (-1);   //changes numerator to "negative"
            denominator = denominator * (-1);   //changes denominator to "positive"
        }
    }

    int greatestCommonDivisor(int x, int y) {   //provided code to determine the greatest common divisor
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }

    Rational& operator++() {
        numerator += denominator;
        simplify();
        return *this;
    }

    Rational operator++(int dummy) {
        Rational original(*this);
        numerator += denominator;
        simplify();
        return original;
    }

    Rational &operator+=(const Rational& rhs) {
        int tempRHS = rhs.numerator;
        numerator *= rhs.denominator;       //get a common denominator
        tempRHS *= denominator;
        numerator += tempRHS;
        denominator *= rhs.denominator;
        simplify(); //simplify the changed rational number
        return *this;   //return the number that was acted on
    }

    explicit operator bool() const{
        return (numerator!=0);
    }   // check if numerator is nonzero or not

private:
    int numerator;
    int denominator;

};

ostream& operator<<(ostream& os, const Rational& number){   //output operator
    os << number.numerator << "/" << number.denominator << endl;
    return os;
}

istream& operator>>(istream& is, Rational& number){     //input operator
    char slash;
    is >> number.numerator >> slash >> number.denominator;
    number.simplify();
    return is;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {  //addition operator
    Rational temp = lhs;
    return temp += rhs;
}

bool operator==(const Rational& lhs, const Rational& rhs){      //equivalent operator
    if(lhs.numerator == rhs.numerator){
        if(lhs.denominator == rhs.denominator){
            return true;
        }
    }
    return false;
}

bool operator!=(const Rational& lhs, const Rational& rhs){  //not-equal operator
    if(lhs == rhs){
        return false;
    }
    return true;
}

bool operator<(const Rational& lhs, const Rational& rhs) {  //less-than operator
    int tempLHS = lhs.numerator * rhs.denominator;
    int tempRHS = rhs.numerator * lhs.denominator;
    return (tempLHS < tempRHS);
}

bool operator<=(const Rational& lhs, const Rational& rhs) { //less-than-equal-to operator
    return (lhs == rhs) || (lhs < rhs);
}

bool operator>(const Rational& lhs, const Rational& rhs) {  //greater-than operator
    return (!(lhs<=rhs));
}

bool operator>=(const Rational& lhs, const Rational& rhs) //greater-than-equal-to operator
{ return (!(lhs < rhs)); }

Rational& operator--(Rational& rhs) {
    rhs += Rational(-1);
    return rhs;
}

Rational operator--(Rational& rhs, int notUsed) {
    Rational original(rhs);
    rhs += Rational(-1);
    return original;
}



/*
	testRational.cpp
	CS2124
	Implement the class Rational, so that the following program works.
 */

//#include <iostream>

// If time allows use  separate compilation, otherwise just define the class below
//#include "Rational.h"

//using namespace std;

// If time allows after implementing separate compilation, then wrap the class in a namespace.
//using namespace CS2124;

int main() {
    Rational twoThirds(2,3);
    cout << twoThirds << endl;

    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    const Rational one = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;	// Implement as member
    cout << "a = " << a << endl;

    // Implement as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;

    // How does this manage to work?
    // It does NOT require writing another == operator.
    cout << "1 == one: " << boolalpha << (1 == one) << endl;

    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;

    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;

    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;

    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;

    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing?
    //cout << "a-- -- = " << (a-- --) << endl;
    //cout << "a = " << a << endl;


    // Should report that 1 is true
    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    }

    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    }
}
