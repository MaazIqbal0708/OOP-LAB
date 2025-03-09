#include <iostream>
using namespace std;

class Student {
private:
    int rollNumber;
    string fullName;
    int* testScores;
    int scoreCount;  
public:
    Student(int rollNumber, const string& fullName, const int* scores, int scoreCount) {
        this->rollNumber = rollNumber;
        this->fullName = fullName;
        this->scoreCount = scoreCount;
        testScores = new int[scoreCount]; 
        for (int i = 0; i < scoreCount; ++i) {
            testScores[i] = scores[i];
        }
    }

    Student(const Student& source) {
        rollNumber = source.rollNumber;
        fullName = source.fullName;
        scoreCount = source.scoreCount;
        testScores = new int[scoreCount]; 
        for (int i = 0; i < scoreCount; ++i) {
            testScores[i] = source.testScores[i];
        }
    }

    void showDetails() const {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Full Name: " << fullName << endl;
        cout << "Test Scores: ";
        for (int i = 0; i < scoreCount; ++i) {
            cout << testScores[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int marks1[] = {90, 87, 69};
    Student student1(762, "Zahran", marks1, 3);
    student1.showDetails();

    Student student2 = student1;
    student2.showDetails();

    int marks2[] = {78, 82, 70};
    Student student3(542, "Maaz", marks2, 3);
    student2 = student3; 
    student2.showDetails();

    student1.showDetails();

    return 0;
}
