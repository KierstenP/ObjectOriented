/* Author: kiersten page
 * rec09
 *
 */

#include <iostream>
#include <vector>
using namespace std;
/*purpose of protected is to allow a derived class direct access to that member while still keeping
 * the field private from all other code
 */

class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numberOfPages(numPages){};
    virtual void displayNumPages()  const = 0;
    //marked the display method as virtual for the cases of base class pointers to derived objects
protected:
private:
    unsigned numberOfPages; //make sure to move data members and methods as far up as possible
    //because numberOfPages is a member variable of all of the derived classes and they all have the same
    //base class, we can just keep numberOfPages in the printedmaterial class rather than keeo the member
    //variable in each derived class.
};

void PrintedMaterial::displayNumPages() const {
    cout << numberOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages){};  //calls the constructor from the direct base class
    void displayNumPages()const {
        cout << "Type: Magazine, Number of Pages: ";
        PrintedMaterial::displayNumPages();
    }
protected:
private:

};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages){}; //calls the constructor from the direct base class
protected:
private:

};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndex) : Book(numPages), numberOfIndexPages(numIndex){};
    void displayNumPages() const {  //create a new display method in order to account for derived classes specific members
        //cout << numOfIndexPages << endl << numOfPages << endl; numOfPages is marked private in the base class
        cout << "Type: Textbook, " <<  "Number of Pages: ";
        PrintedMaterial::displayNumPages(); //call the base classes method to display its private member variables
        cout << "Number of Index Pages: " << numberOfIndexPages << endl;
    }
protected:
private:
    unsigned numberOfIndexPages;

};

class Novel : public Book {
public:
    Novel(unsigned numPages) : Book(numPages){};
    void displayNumPages() const {
        cout << "Type: Novel, Number of Pages:";
        PrintedMaterial::displayNumPages();
    }
protected:
private:

};


// tester/modeler code
int main()
{
    TextBook t(5430, 23);
    Novel n(213);
    Magazine m(6);

    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();

    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
    cout << "Now with the virtual mechanism involved\n";
    PrintedMaterial* pmPtr;
    pmPtr = &t; // like putting t into a vector but
    // we are actually putting the address of t
    // into a vector pointers of pointers to
    // PrintedMaterials. We'll "say" we are putting
    // t into the vector
    // (that is, pointers to the Base class)
    pmPtr->displayNumPages();

    // Storing generic objects in a vector
    cout << "\n\nNow we'll use a container. Yea!!!\n\n";
    vector< PrintedMaterial* > allThemPrinties;
    allThemPrinties.push_back(&t);
    allThemPrinties.push_back(&n);
    allThemPrinties.push_back(&m);
    for( size_t ndx=0; ndx < allThemPrinties.size(); ++ ndx )
    {
        allThemPrinties[ndx]->displayNumPages();
        cout << endl;
    }

}