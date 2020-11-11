// rec13_test.cpp
/* Author: Kiersten Page
 * rec13
 */

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

//Function definitions

//task 9
void iteratorListPrint(const list<int>& list1){
//    list<int>::iterator l;
    list<int>::const_iterator l;
    for (l = list1.begin(); (l != list1.end()); ++l){
        cout << *l << " ";
    }
    cout << endl;
}

//task 10
void rangedForListPrint(const list<int>& list1){
    for(const int& num : list1){
        cout << num << " ";
    }
    cout << endl;
}

//task 11
void printEveryOtherItem(const list<int>& list1){
    for (auto iter = list1.begin(); iter != list1.end(); ++++iter){ //double increment for every other item
        cout << *iter<< " ";
    }
    cout << endl;
}

//task 12
list<int>::const_iterator findItem(const list<int>& list1, int targetItem){
    for (list<int>::const_iterator iter = list1.begin(); iter != list1.end(); iter++){
        if(*iter == targetItem){
            return iter;
        }
    }
    return list1.end();
}

//task 13
auto findItemAuto(const list<int>& list1, int targetItem){
    for (auto iter = list1.begin(); iter != list1.end(); iter++){
        if(*iter == targetItem){
            return iter;
        }
    }
    return list1.end();
}

//task 15
bool isEven(const int& num) {
    return (num % 2 == 0);
//    if(num % 2 == 0){ // even case
//        return true;
//    }
//    else return false;  //odd case
//}
}

//task 16
struct isEvenFunctor{
    int operator()(const int num) const
    {
        return !(num % 2);
    }
};

//task 19
list<int>::iterator ourFind(list<int>::iterator start, list<int>::iterator end, int find) {
    for (list<int>::iterator p = start; p != end; ++p) {
        if (*p == find) {
            return p;
        }
    }
    cout << "Could not find the given value." << endl;
    return end;
}

//task 20
template <typename myTemplate, typename myT2>
myTemplate ourFind(myTemplate start, myTemplate end, myT2 target) {
    cout << "Using the template version now" << endl;
    for (myTemplate p = start; p != end; ++p) {
        if (*p == target) {
            return p;
        }
    }
    cout << "Could not find the given value." << endl;
    return end;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> vecInts = {3, 7, 24, 12, 29, 50, 34, 87};  //initialize vector with various values
    for(const int& num : vecInts){  //print out using the ranged for
        cout << num << " ";
    }
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> listInts(vecInts.begin(), vecInts.end()); //initialize the list to include items from the vector
    for (int i : listInts){ //print out the list
        cout << i << " ";
    }
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(vecInts.begin(), vecInts.end());   //sort the vector
    cout << "Vector" << endl;
    for(const int& num : vecInts){  //print out the vector
        cout << num << " ";
    }
    cout << "List" << endl;
    for(const int& num : listInts){ //print out the list
        cout << num << " ";
    }
    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for(size_t i = 0; i < vecInts.size(); i += 2){  //loop to print every other element in the vector
        cout << vecInts[i] << " ";
    }
    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    cout << "Commented Out";
//    for(size_t i = 0; i < listInts.size(); i += 2){  //loop to print every other element in the list
//        cout << listInts[i] << " ";
//    }
    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    vector<int>::iterator v;
    for (v = vecInts.begin(); v < vecInts.end(); v = v + 2){
        cout << *v << " ";
    }
    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    list<int>::iterator l;
    for (l = listInts.begin(); (l != listInts.end()) && (l != --listInts.end()); ++++l){
        cout << *l << " ";
    }
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    listInts.sort();    //sort the list using its sort method
    for(const int& num : listInts){  //print out the list to prove that the sort method works
        cout << num << " ";
    }
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    iteratorListPrint(listInts);
    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    rangedForListPrint(listInts);
    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    printEveryOtherItem(listInts);
    cout << "=======\n";


    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    //pass case
    cout << "Find 3" << endl;
    list<int>::const_iterator iter1;
    iter1 = findItem(listInts, 3);
    if (iter1 == listInts.end()){
        cout << "test failed";
    }
    else{
        cout << *iter1 << endl;
    }
    //fail case
    cout << "Find 4" << endl;
    list<int>::const_iterator iter2;
    iter2 = findItem(listInts, 4);
    if (iter2 == listInts.end()){
        cout << "Test failed" << endl;
    }
    else{
        cout << *iter2 << endl;
    }
    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    //pass case
    cout << "Find 3" << endl;
    list<int>::const_iterator iter3;
    iter3 = findItem(listInts, 3);
    if (iter3 == listInts.end()){
        cout << "test failed";
    }
    else{
        cout << *iter3 << endl;
    }
    //fail case
    cout << "Find 4" << endl;
    list<int>::const_iterator iter4;
    iter4 = findItem(listInts, 4);
    if (iter4 == listInts.end()){
        cout << "Test failed" << endl;
    }
    else{
        cout << *iter4 << endl;
    }
    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    //pass case
    cout << "Find 3" << endl;
    if(find(listInts.begin(), listInts.end(), 3) != listInts.end()){
        cout << *find(listInts.begin(), listInts.end(), 3);
    }
    else{
        cout << "Test failed." << endl;
    }

    cout << endl;
    //fail case
    cout << "Find 4" << endl;
    if(find(listInts.begin(), listInts.end(), 4) != listInts.end()){
        cout << *find(listInts.begin(), listInts.end(), 4);
    }
    else{
        cout << "Test failed." << endl;
    }
    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    //find the first even number in the list
    cout << "Find 3" << endl;
    if(find_if(listInts.begin(), listInts.end(), isEven) != listInts.end())
        cout << *find_if(listInts.begin(), listInts.end(), isEven) << endl; //Exists
    else
        cout << "No even numbers Found";
    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";
//    struct isEvenFunctor{
//        int operator()(const int num) const
//        {
//            return !(num % 2);
//        }
//    };

    auto p6 = find_if(listInts.begin(), listInts.end(), isEven);
    if(p6 != listInts.end()) {
        cout << *p6 << endl;
    }
    else {
        cout << "Nothing Found";
    }

    cout << "=======\n";

    // 17. Lambda
    cout << "Task 17:\n";
    [] { cout << "Hello Lambda!" << endl; }();

    [] (int a, int b) { cout << a + b << endl; } (4, 5);

    int result = [] (int a, int b) { return a + b; } (4, 5);
    cout << "the result is: " << result << endl;

    int result2 = [] (int a, int b) -> int { return a + b; } (4, 5);    //including the return type
    cout << "the result is: " << result2 << endl;

    auto p7 = find_if(listInts.begin(), listInts.end(), [](int num) -> bool{return num%2==0;});
    if(p7 != listInts.end()) {
        cout << *p7 << endl;
    }
    else {
        cout << "Nothing Found";
    }

    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int arr[8]; //there are eight total items in the vector
    copy(vecInts.begin(), vecInts.end(), arr);  //copy items into the array from the vector
    for (int i : arr) { //print the contents
        cout << i << " ";
    }
    cout << endl;
    //pass case
    auto f = find(arr, arr+sizeof(arr) , 12);
    if(f != arr+sizeof(arr)){
        cout << *f << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    auto f2 = find(arr, arr+sizeof(arr), 4);
    if(f2 != arr+sizeof(arr)){
        cout << *f2 << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    //pass case
//    if(f2 != arr+sizeof(arr)){
//        cout << *f2 << endl;
//    }
//    else{
//        cout << "Not found" << endl;
//    }
    iter1 = ourFind(listInts.begin(), listInts.end(), 3);
    if(iter1 != listInts.end()){
        cout << *iter1 << endl;
    }
    else{
        cout << "Not found" << endl;
    }


    //fail case
    iter2 = ourFind(listInts.begin(), listInts.end(), 4);
    if(iter2 != listInts.end()){
        cout << *iter2 << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    cout << "=======\n";

    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    //vector
    //pass case
    auto f3 = ourFind(vecInts.begin(), vecInts.end(), 3);
    if(f3 != vecInts.end()){
        cout << *f3 << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    //fail case
    f3 = ourFind(vecInts.begin(), vecInts.end(), 4);
    if(f3 != vecInts.end()){
        cout << *f3 << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    cout << "=======\n";

    //list
    //pass case
    iter1 = ourFind(listInts.begin(), listInts.end(), 3);
    iter1 = ourFind(listInts.begin(), listInts.end(), 3);
    if(iter1 != listInts.end()){
        cout << *iter1 << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    //fail case
    iter1 = ourFind(listInts.begin(), listInts.end(), 4);
    iter1 = ourFind(listInts.begin(), listInts.end(), 3);
    if(iter1 != listInts.end()){
        cout << *iter1 << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    cout << "=======\n";
    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    vector<string> words;
    string word;
    ifstream ifs("pooh-nopunc.txt");
    if (!ifs) {
        cerr << "file could not be opened\n";
        exit(1);
    }
    while (ifs >> word) {
        auto fi = find(words.begin(), words.end(), word);
        if (fi == words.end()) {
            words.push_back(word);
        }
    }
    cout << "Size: " << words.size() << endl << "Distinct Words:" << endl;
    for (const string& word : words) { cout << word << endl; }
    ifs.close(); //close the file


    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    set<string> words2;
    string word2;
    ifstream ifs2("pooh-nopunc.txt");
    if (!ifs2) {
        cerr << "Could not open the file\n";
        exit(1);
    }
    while (ifs2 >> word) { words2.insert(word2); }
    cout << "The set's size: " << words2.size() << "\nThe set's contents: ";
    for (string s : words2) { cout << s << " "; }
    ifs2.close();
    cout << "=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    map<string, vector<int>> words3;
    string word3;
    int position = 0;
    ifstream ifs3("pooh-nopunc.txt");
    if (!ifs3) {
        cerr << "Could not open the file\n";
        exit(1);
    }
    while (ifs3 >> word3) {
        words3[word3].push_back(position);
        position += 1;
    }
    for (const auto& item : words3) {
        cout << "\nWord: " << item.first << "\nPosition(s): ";
        for (int i : item.second) {
            cout << i << " ";
        }
    }
    ifs3.close();
    cout << "=======\n";
}