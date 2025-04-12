#include <iostream>
#include <string>
using namespace std;

class account{
private:
    string accNumber;
    double balance;

public:
    account(string accNum, double bal) : accNumber(accNum), balance(bal) {}

    friend class manager;
    friend void transferFunds(account& from, account& to, double amount);
};

class manager {
public:
    static void displayAccount(account& acc) {
        cout << "Account Number: " << acc.accNumber << "\tBalance: " << acc.balance << "pkr." << endl;
    }

    static void deposit(account& acc, double amount) {
        acc.balance += amount;
        cout << "Deposited amount: " << amount << "to this acount: " << acc.accNumber << endl;
    }

    static void withdraw(account& acc, double amount) {
        if (acc.balance >= amount) {
            acc.balance -= amount;
            cout << "Withdrwan amount: " << amount << "from this account" << acc.accNumber << endl;
        } else {
            cout << "Insufficient balance in account " << acc.accNumber << endl;
        }
    }
};

void transferFunds(account& account1, account& account2, double amount) {
    if (account1.balance >= amount) {
        account1.balance -= amount;
        account2.balance += amount;
        cout << "Transferred amount" << amount << "pkr from " << account1.accNumber << " to " 
            << account2.accNumber << endl;
    } else {
        cout << "Transfer failed: Insufficient balance in source account" << endl;
    }
}

int main() {
    account acc1("acc089", 100000.0);
    account acc2("acc134", 237000.0);

    manager::displayAccount(acc1);
    manager::deposit(acc1, 1000.0);
    manager::withdraw(acc2, 5870.0);
    transferFunds(acc1, acc2, 58000.0);

    manager::displayAccount(acc1);
    manager::displayAccount(acc2);

    return 0;
}