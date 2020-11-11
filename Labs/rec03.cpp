//Author: Kiersten Page
//Purpose: Simulate a banking experience in a tutorial style lab
//rec03

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//accounts.txt

//Part one
struct accountStruct{
    string name;
    int number;

};

//Part two
class AccountClass{
public:
    //2c
    friend ostream& operator <<(ostream& os, const AccountClass& account);
    AccountClass(const string name, const int number) : name(name), number(number){};
    string accessName() const {
        return name;
    };
    int accessNumber() const {
        return number;
    };

    int getBalance() const{
        return balance;
    }
    //3d
    void deposit(int ammount){
        balance += ammount;
        Transaction transaction;

        transaction.newTransaction("Deposit", ammount);
        transactions.push_back(transaction);
    }

    void withdrawal(int ammount){
            balance -= ammount;
            Transaction transaction;
            transaction.newTransaction("Withdrawal", ammount);
            transactions.push_back(transaction);

    }



private:
    string name;
    int number;

    //part 3-4
    class Transaction{

    private:
        //3a
        string type;
        int ammount;
    public:
        friend ostream& operator <<(ostream& os, const AccountClass& account);

        void newTransaction(string t, int a){
            type = t;
            ammount = a;
        }

        string getType() const {
            return type;
        }

        int getAmmount() const {
            return ammount;
        }
    };
    //3b
    vector<Transaction> transactions;
    int balance;

};

//2b
ostream& operator <<(ostream& os, const AccountClass& account){
    //os << "Name: " << account.accessName() << " Number: " << account.accessNumber() << endl;
    //2c
    os << "Name: " <<  account.name << " Number: " << account.number << endl;
    if(account.transactions.size() != 0) {
        os << "Transaction History:" << endl;
        for (AccountClass::Transaction transaction : account.transactions) {
            cout << "Type: " << transaction.getType() << " Ammount: " << transaction.getAmmount() << endl;
        }
    }
    return os;
}

int main() {
    //1a
    cout << "1a" << endl;
    ifstream accountFile("accounts.txt");
    if (!accountFile) {
        cerr << "Couldn't Open the File";
        exit(1);
    }
    vector<accountStruct> accounts;
    string name;
    int number;
    while (accountFile >> name >> number) {
        accountStruct account1;
        account1.name = name;
        account1.number = number;
        accounts.push_back(account1);
    }
    accountFile.close();
    for (const accountStruct &account : accounts) {
        cout << "Name: " << account.name << ", Number: " << account.number << endl;
    }
    cout << endl;
    //1b
    cout << "1b" << endl;
    accounts.clear();
    accountFile.open("accounts.txt");
    if (!accountFile) {
        cerr << "Couldn't Open the File";
        exit(1);
    }
    while (accountFile >> name >> number) {
        accountStruct account1{name, number};
        accounts.push_back(account1);
    }
    accountFile.close();
    for (const accountStruct &account : accounts) {
        cout << "Name: " << account.name << ", Number: " << account.number << endl;
    }
    cout << endl;

    //2a
    cout << "2a" << endl;
    accountFile.open("accounts.txt");
    if (!accountFile) {
        cerr << "Couldn't Open the File";
        exit(1);
    }
    vector<AccountClass> accounts2;
    while (accountFile >> name >> number) {
        AccountClass account(name, number);
        accounts2.push_back(account);
    }
    accountFile.close();
    for (const AccountClass &account : accounts2) {
        cout << "Name: " << account.accessName() << ", Number: " << account.accessNumber() << endl;
    }
    accounts2.clear();
    cout << endl;

    //2b - 2c
    cout << "2b-2c" << endl;
    accountFile.open("accounts.txt");
    if (!accountFile) {
        cerr << "Couldn't Open the File";
        exit(1);
    }
    while (accountFile >> name >> number) {
        AccountClass account(name, number);
        accounts2.push_back(account);
    }
    accountFile.close();
    for (AccountClass &account : accounts2) {
        cout << account;
    }
    accounts2.clear();
    cout << endl;

    //2d
    cout << "2d" << endl;
    accountFile.open("accounts.txt");
    if (!accountFile) {
        cerr << "Couldn't Open the File";
        exit(1);
    }
    while (accountFile >> name >> number) {
        accounts2.push_back(AccountClass(name, number));
    }
    accountFile.close();
    for (AccountClass &account : accounts2) {
        cout << account;
    }
    accounts2.clear();
    cout << endl;

    //2e
    cout << "2e" << endl;
    accountFile.open("accounts.txt");
    if (!accountFile) {
        cerr << "Couldn't Open the File";
        exit(1);
    }
    while (accountFile >> name >> number) {
        accounts2.emplace_back(AccountClass(name, number));
    }
    accountFile.close();
    for (AccountClass &account : accounts2) {
        cout << account;
    }
    accounts2.clear();
    cout << endl;
    //3e
    cout << "3e" << endl;
    ifstream bankingFile("banking.txt");
    if (!bankingFile) {
        cerr << "Couldn't open the file" << endl;
        exit(1);
    }
    string type;
    while (bankingFile >> type) {
        if (type == "Account") {
            bankingFile >> name >> number;
            accounts2.emplace_back(AccountClass(name, number));
        }
        else if (type == "Deposit") {
            int ammount;
            bankingFile >> number >> ammount;
            for (size_t i = 0; i < accounts2.size(); i++) {
                if (accounts2[i].accessNumber() == number) {
                    accounts2[i].deposit(ammount);
                    break;
                }
            }
        }
        else if(type == "Withdraw"){
            int ammount;
            bankingFile >> number >> ammount;
            for (size_t i = 0; i < accounts2.size(); i++){
                if (accounts2[i].accessNumber() == number){
                    if (accounts2[i].getBalance() < ammount){
                        cerr << "Insufficient Funds" << endl;

                    }
                    else {
                        accounts2[i].withdrawal(ammount);
                    }
                    break;
                }
            }
        }
    }
    bankingFile.close();
    for (AccountClass &account : accounts2) {
        cout << account;
    }
}