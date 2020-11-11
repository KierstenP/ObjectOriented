#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;



class List{
    friend ostream& operator << (ostream& os, const List& list);
private:
    struct Node {
        Node(int data = 0, Node* next = nullptr, Node* prior = nullptr) : data(data), next(next), prior(prior){}
        int data;
        Node* next;
        Node* prior;

    };

    Node* header = new Node();  //sentinel creation in order to make coding easier later on
    Node* trailer = new Node();
    int listSize = 0;

public:
    void push_back(int data){
        if(header -> next == nullptr){
            header -> next = new Node(data, trailer, header);
            trailer -> prior = header -> next;
        }
        else{
            Node* temp = trailer -> prior;
            temp -> next = new Node(data, trailer, header);
            trailer -> prior = temp -> next;
        }
        ++listSize;
    }

    void pop_back() {
        if(listSize != 0){
            Node* newLastNode = trailer -> prior -> prior;
            delete (trailer -> prior);
            newLastNode -> next = trailer;
            trailer -> prior = newLastNode;
            --listSize;
        }
    }
    int& front()  {
        return header -> next -> data;
    }

    const int front() const {
        int temp = header -> next -> data;
        return temp;    //const form must return a constant reference to the data item
    }

    int& back(){
        return trailer -> prior -> data;
    }
    const int back() const {
        int temp = trailer -> prior -> data;
        return temp;    //const form must return a constant reference to the data item
    }

    int size() const {
        int temp = listSize;    //return copy so as to not risk changing the size
        return temp;
    }


    int push_front(int data){
        if(header -> next == nullptr){
            header -> next = new Node(data, trailer, header);
            trailer -> prior = header -> next;
        }
        else{
            Node* temp = header -> next;
            header -> next = new Node(data, temp, header);
            temp -> prior = header -> next;
        }
        ++listSize;
    }

    void pop_front(){
        if(listSize != 0){
            Node* temp = header -> next -> next;
            delete (header -> next);
            header -> next = temp ;
            temp -> prior = header;
            --listSize;
        }
    }

    void clear(){
        for (int i = listSize; i != 0; --i) {
            this -> pop_back();
        }
    }

    int operator[](size_t index) const {
        Node* temp = header;
        for(size_t i = 0; i < listSize; ++i){
            temp = temp->next;
            if(index == i){
                return temp->data;
            }
        }
        return 0;
    }
    int& operator[](size_t index){
        Node* temp = header;
        for(size_t i = 0; i < listSize; ++i){
            temp = temp->next;
            if(index == i){
                return temp->data;
            }
        }
        return header->data;
    }
};

ostream& operator << (ostream& os, const List& list){
    if (list.listSize == 0){
        os << "List is empty" << endl;
    }
    else {
        cout << "{ ";
        int count = 0;
        List::Node* tempNode = list.header -> next;
        while(count != list.listSize) {
            os << tempNode -> data << " ";
            tempNode = tempNode -> next;
            ++count;
        }
        os << "}" << endl;
    }
    return os;
}

// Task 1
void printListInfo(const List& myList) {
    cout << "size: " << myList.size()
         << ", front: " << myList.front()
         << ", back(): " << myList.back()
         << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList){
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList){
    theList.front() = 17;
    theList.back() = 42;
}

//// Task 4
//void printListSlow(const List& myList) {
//    for (size_t i = 0; i < myList.size(); ++i) {
//        cout << myList[i] << ' ';
//    }
//    cout << endl;
//}
//
//// Task 8
//void doNothing(List aList) {
//    cout << "In doNothing\n";
//    printListInfo(aList);
//    cout << endl;
//    cout << "Leaving doNothing\n";
//}

int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";

    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }

    cout << "===================\n";

//    // Task 2
//    cout << "\n------Task Two------\n";
//    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
//    for (int i = 0; i < 10; ++i) {
//        cout << "myList2.push_front(" << i*i << ");\n";
//        myList.push_front(i*i);
//        printListInfo(myList);
//    }
//    cout << "===================\n";
//    cout << "Remove the items with pop_front\n";
//    while (myList.size()) {
//        printListInfo(myList);
//        myList.pop_front();
//    }
//    cout << "===================\n";
//
//    // Task 3
//    cout << "\n------Task Three------\n";
//    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
//    for (int i = 0; i < 10; ++i) {
//        myList.push_back(i*i);
//    }
//    printListInfo(myList);
//    cout << "Now clear\n";
//    myList.clear();
//    cout << "Size: " << myList.size() << ", list: " << myList << endl;
//    cout << "===================\n";
//
//    // Task 4
//    cout << "\n------Task Four------\n";
//    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
//    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
//    cout << "Display elements with op[]\n";
//    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
//    cout << endl;
//    cout << "Add one to each element with op[]\n";
//    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
//    cout << "And print it out again with op[]\n";
//    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
//    cout << endl;
//    cout << "Now calling a function, printListSlow, to do the same thing\n";
//    printListSlow(myList);
//    cout << "Finally, for this task, using the index operator to modify\n"
//         << "the data in the third item in the list\n"
//         << "and then using printListSlow to display it again\n";
//    myList[2] = 42;
//    printListSlow(myList);
//
//
//    // Task 5
//    cout << "\n------Task Five------\n";
//    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
//    myList.clear();
//    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
//    printListInfo(myList);
//    cout << "Now display the elements in a ranged for\n";
//    for (int x : myList) cout << x << ' ';
//    cout << endl;
//    cout << "And again using the iterator type directly:\n";
//    // Note you can choose to nest the iterator class or not, your choice.
//    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
//    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
//        cout << *iter << ' ';
//    }
//    cout << endl;
//    cout << "WOW!!! (I thought it was cool.)\n";
//
//    // Task 6
//    cout << "\n------Task Six------\n";
//    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
//    myList.clear();
//    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
//    printListInfo(myList);
//    cout << "Filling an empty list with insert at begin(): "
//         << "i*i for i from 0 to 9\n";
//    myList.clear();
//    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
//    printListInfo(myList);
//    // ***Need test for insert other than begin/end***
//    cout << "===================\n";
//
//    // Task 7
//    cout << "\n------Task Seven------\n";
//    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
//    myList.clear();
//    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
//    cout << "Erasing the elements in the list, starting from the beginning\n";
//    while (myList.size()) {
//        printListInfo(myList);
//        myList.erase(myList.begin());
//    }
//    // ***Need test for erase other than begin/end***
//    cout << "===================\n";
//
//    // Task 8
//    cout << "\n------Task Eight------\n";
//    cout << "Copy control\n";
//    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
//    myList.clear();
//    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
//    printListInfo(myList);
//    cout << "Calling doNothing(myList)\n";
//    doNothing(myList);
//    cout << "Back from doNothing(myList)\n";
//    printListInfo(myList);
//
//    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
//    List listTwo;
//    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
//    printListInfo(listTwo);
//    cout << "listTwo = myList\n";
//    listTwo = myList;
//    cout << "myList: ";
//    printListInfo(myList);
//    cout << "listTwo: ";
//    printListInfo(listTwo);
//    cout << "===================\n";
}