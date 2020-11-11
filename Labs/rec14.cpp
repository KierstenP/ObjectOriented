/* Author: Kiersten Page
 * rec14
 */
//author: Kiersten Page
// recitation 14

#include <iostream>
using namespace std;


//task one
//check if an int will have an even number of ones
int isEven(int integer){
    if(integer == 0){
        return true;
    }
    else{
        if(integer%2 ==0){
            return isEven(integer/2);
        }
        return !isEven(!integer/2);
    }
};

//task two
//return a new list that is the sum of the values in the two lists that are passed in
struct Node{
    int data;
    Node* link;
    Node(int data, Node* link) : data(data), link(link){}
};

Node* listReturn(Node* one, Node* two){
    if((one == nullptr)&&(two == nullptr)){
        return nullptr;
    }
    else if(one == nullptr && two != nullptr){
        return new Node(two->data, listReturn(one, two->link));
    }
    else if(one != nullptr && two == nullptr){
        return new Node(one->data, listReturn(two, one->link));
    }
    else{
        return new Node(one->data + two->data, listReturn(one->link, two->link));
    }
}

//task 3
//return the max of the values in a binary tree
struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
            : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

int max(TNode* root) {
    if (root == nullptr){
        throw invalid_argument("Invalid Root");

    }
    if ((root->left == nullptr) && (root->right != nullptr)){
        int right = max(root->right);
        if (right > root->data){
            return right;
        }
        return root->data;
    }
    if ((root->right == nullptr) && (root->left != nullptr)){
        int left = max(root->left);
        if(left>root->data){
            return left;
        }
        return root->data;
    }

    if ((root->right != nullptr) && (root->left != nullptr)){
        int left = max(root->left);
        int right = max(root->right);
        if ((left > right) && (left > root->data)){
            return left;
        }
        else if ((left < right) && (right > root->data)){
            return right;
        }
        return root->data;
    }

}


//task 4
//checks if a word is a palindrome
bool palindrome(char letter[], int numberOfElements){
    if(numberOfElements<2){return true;}
    return letter[0] == letter[numberOfElements-1] && palindrome(letter+1, (numberOfElements-2));
}


//task 5
//tower of hanoi problem
int towers(int disks, string a,string b, string c){
    int count = 0;
    if(disks>0){
        count = towers(disks-1, a, b, c);
        count++;
        count += towers(disks-1, a, b, c);
    }
    return count;
}

//task 6
void mystery(int n) {
    if (n > 1) {
        cout << 'a';
        mystery(n/2);
        cout << 'b';
        mystery(n/2);
    }
    cout << 'c';
}