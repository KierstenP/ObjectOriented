#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>
using  namespace std;

struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

// listAddHead: adds a data item to the beginning of a [possibly empty] list
void listAddHead(Node*& headPtr, int entry) {
    headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like.
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listAddHead(result, vals[index-1]);
    }
    return result;
}

/*Task One: Splice a singly linked list of ints into another list of ints given a pointer to the
 * node that you will insert after. After implementing the function, test the code by printing both lists
 * before the splice, and print the original list after the splice.
 */

void splice(Node*& addList, Node*& spliceList){
    Node* last =  spliceList->next; //element after the add list
    if(last == nullptr){
        spliceList->next = addList; //just adds the list to the end if you're inserting at the last element
    }
    else{
        spliceList->next = addList;
        while(addList != nullptr){
            if(addList->next == nullptr){   //checks to see if current element is last element
                addList->next = last; //if so, sets next element of the added list to where the splice list left off
                break; //break the loop
            }
            else{
                addList = addList -> next;
            }
        }
    }
}

void printList(Node* list){
    while(list != nullptr){  //check to see if list was created successfully or not
        cout << list -> data << " ";
        list = list -> next;
    }
    cout << endl;
}

/* Task Two: look to see if a list is a sublist of another list.
 */
//
Node* isSublist(Node* lookingForList, Node* lookingInList){
    for (Node *orig = lookingInList; orig != nullptr; orig = orig->next) {
        if (orig->data == lookingForList->data) {
            Node *temp1 = orig->next;
            Node *temp2 = lookingForList->next;
            while (temp1 != nullptr && temp2 != nullptr) {
                if (temp1->data == temp2->data) {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                } else {
                    break;
                }
            }
            if (temp2 == nullptr) {
                return orig;
            }
        }
    }
    return nullptr;
}


void printIsSublist(Node* lookingForList, Node* lookingInList){ //function to print out whether or not a list is a sublist
    cout << "Attempt match: ";
    printList(lookingForList);
    Node* result = isSublist(lookingForList, lookingInList);
    if(result == nullptr){
        cout << "Failed to match" << endl;
        cout << endl;
    }
    else{
        printList(result);
        cout << endl;
    }
}

int main() {
    //task one test code
    cout << "Part One: " << endl << endl;
    Node* l1 = listBuild({5, 7, 9, 1}); //initialize first list
    Node* l2 = listBuild({6, 3, 2}); //initialize second list
    cout << "L1: ";
    printList(l1); //print list one before changing
    cout << "L2: ";
    printList(l2); //print list two before changing
    cout << "Target: ";
    printList(l1->next);
    cout << "Splicing L2 at target in L1" << endl;
    splice(l2, (l1->next));   //slice the two lists together at a certain position
    cout << "L1: ";
    printList(l1); //print the list post slicing
    cout << "L2: ";
    printList(l2);
    cout << "=====================" << endl;

    //task two test code
    cout << endl;
    cout << "Part Two:" << endl << endl;
    Node* targetList = listBuild({1, 2, 3, 2, 3, 2, 4, 5, 6});
    cout << endl << "Target: ";
    printList(targetList);  //go through and check if lists match within the target list
    Node* l3 = listBuild({1});
    printIsSublist(l3, targetList);
    Node* l4 = listBuild({3, 9});
    printIsSublist(l4, targetList);
    Node* l5 = listBuild({2, 3});
    printIsSublist(l5, targetList);
    Node* l6 = listBuild({2, 4, 5, 6});
    printIsSublist(l6, targetList);
    Node* l7 = listBuild({2, 3, 2, 4});
    printIsSublist(l7, targetList);
    Node* l8 = listBuild({5, 6, 7});
    printIsSublist(l8, targetList);



}