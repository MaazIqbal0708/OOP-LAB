#include <iostream>
using namespace std;

class employee {
protected:
    string name;
    float salary;
public:
    employee(string name,float salary) {
        this->name = name;
        this->salary = salary;
    }
    virtual void displaydetails() {
        cout << "Name:" << name << endl;
        cout << "salary:" << salary << endl;
    }
};

class Manager : public employee {
private:
    float bonus;

public:
    Manager(string n, float s, float b) : employee(n, s), bonus(b) {}

    void displaydetails() override {
        cout << "Name: " << name << ", Salary: " << salary << ", Bonus: " << bonus << endl;
    }
};

int main() {
    string name;
    float salary, bonus;

    cout << "Enter manager's name: ";
    cin >> name;
    cout << "Enter manager's salary: ";
    cin >> salary;
    cout << "Enter manager's bonus: ";
    cin >> bonus;

    Manager manager(name, salary, bonus);
    manager.displaydetails();

    return 0;
}