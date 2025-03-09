#include <iostream>
using namespace std;

class account {
protected:
    int accountnumber;
    float balance;
public:
    account(int accountnumber, float balance) : accountnumber(accountnumber), balance(balance) {}

    void displaydetails() {
        cout << "Account Number: " << accountnumber << endl;
        cout << "Balance: " << balance << "pkr" << endl;
    }
};

class savingaccount : public account {
protected:
    float interestrate;

public:
    savingaccount(int accountnumber, float balance, float interestrate) : 
        account(accountnumber, balance), interestrate(interestrate) {}
    
    void displaydetails() {
        account::displaydetails();
        cout << "Interest Rate: " << interestrate << "%" << endl;
    }
};

class checkingaccount : public account {
protected:
    float overdraftlimit;
public:
    checkingaccount(int accountnumber, float balance, float overdraftlimit) : 
        account(accountnumber, balance), overdraftlimit(overdraftlimit) {}
    void displaydetails() {
        account::displaydetails();
        cout << "Overdraft Limit: " << overdraftlimit << "pkr" << endl;
    }
};

int main() {
    int accountnumber;
    float balance, interestrate, overdraftlimit;

    cout << "Enter saving account number: ";
    cin >> accountnumber;
    cout << "Enter balance: ";
    cin >> balance;
    cout << "Enter interest rate: ";
    cin >> interestrate;
    savingaccount acc1(accountnumber, balance, interestrate);
    acc1.displaydetails();

    cout << "Enter checking account number: ";
    cin >> accountnumber;
    cout << "Enter balance: ";
    cin >> balance;
    cout << "Enter overdraft limit: ";
    cin >> overdraftlimit;
    checkingaccount acc2(accountnumber, balance, overdraftlimit);
    acc2.displaydetails();
    
    return 0;
}