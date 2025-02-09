// Maaz Iqbal
// 24k-0542

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollno;
    int marks[3];
};

int main() {
    int numofstudents;

    cout << "Enter the number of students: ";
    cin >> numofstudents;

    Student* students = new Student[numofstudents];

    for (int i = 0; i < numofstudents; i++) {
        cout << "Enter details for student " << i + 1 << endl;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Roll Number: ";
        cin >> students[i].rollno;
        cout << "Enter marks for 3 subjects: ";
        for (int j = 0; j < 3; j++) {
            cin >> students[i].marks[j];
        }
    }

    for (int i = 0; i < numofstudents; i++) {
        int totalMarks = 0;
        for (int j = 0; j < 3; j++) {
            totalMarks += students[i].marks[j];
        }
        float average = totalMarks / 3.0;
        cout << "Student: " << students[i].name << ", Average Marks: " << average << endl;
    }
    delete[] students;

    return 0;
}
