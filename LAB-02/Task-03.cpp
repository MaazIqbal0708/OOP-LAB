// Maaz Iqbal
// 24k-0542

#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string empName;
    int workHours;
    double payRate;
};

int main() {
    int Employees;
    cout << "Enter number of employees: ";
    cin >> Employees;

    Employee *staff = new Employee[Employees];

    for (int index = 0; index < Employees; index++) {
        cout << "Employee " << index + 1 << " details:" << endl;
        cout << "Name: ";
        cin >> staff[index].empName;
        cout << "Hours worked: ";
        cin >> staff[index].workHours;
        cout << "Hourly rate: ";
        cin >> staff[index].payRate;
    }

    for (int index = 0; index < Employees; index++) {
        double Salary = staff[index].workHours * staff[index].payRate;
        cout << staff[index].empName << "'s salary: " << Salary << endl;
    }

    delete[] staff;

    return 0;
}
