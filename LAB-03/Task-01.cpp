#include <iostream>
#include <string>

using namespace std;

const int MAX_TRANSACTIONS = 100;

class Wallet {
private:
    string ownerName;
    double totalBalance;
    string transactionHistory[MAX_TRANSACTIONS];
    int transactionCount;

public:
    Wallet(string name) : ownerName(name), totalBalance(0), transactionCount(0) {}

    void addMoney(double amount) {
        if (transactionCount >= MAX_TRANSACTIONS) {
            cout << "Transaction history is full!" << endl;
            return;
        }
        totalBalance += amount;
        transactionHistory[transactionCount++] = "Added: $" + to_string(amount);
    }

    void spendMoney(double amount) {
        if (amount > totalBalance) {
            cout << "Insufficient balance!" << endl;
            return;
        }
        if (transactionCount >= MAX_TRANSACTIONS) {
            cout << "Transaction history is full!" << endl;
            return;
        }
        totalBalance -= amount;
        transactionHistory[transactionCount++] = "Spent: $" + to_string(amount);
        if (totalBalance < 50) {
            cout << "Low cash warning! Current balance: $" << totalBalance << endl;
        }
    }

    void displayTransactionHistory() {
        for (int i = 0; i < transactionCount; ++i) {
            cout << transactionHistory[i] << endl;
        }
    }
};

int main() {
    Wallet saadWallet("Saad");
    saadWallet.addMoney(200);
    saadWallet.spendMoney(50);
    saadWallet.displayTransactionHistory();
    return 0;
}
