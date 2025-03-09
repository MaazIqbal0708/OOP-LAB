#include <iostream>
using namespace std;

class person {
protected:
    string name;
    int age;
public:
    person(string name, int age) : name(name),  age(age) {}

    void displaydetails() {
        cout << "\nName: " << name << "\nAge: " << age ;
    }
};

class teacher : public person {
protected:
    string subject;
public:
    teacher(string name, int age, string subject) : person(name, age), subject(subject) {}

    void displaydetails() {
        person::displaydetails();
        cout << "\nSubject: " << subject ;
    }
};

class researcher : public person {
protected:
    string researcharea;
public:
    researcher(string name, int age, string researcharea) : person(name, age), researcharea(researcharea) {}

    void displaydetails() {
        person::displaydetails();
        cout << "\nResearch Area: " << researcharea ;
    }
};

class professor : public teacher, public researcher {
protected:
    int publications;
public:
    professor(string name, int age, string subject, string researcharea, int publications) : 
        teacher(name, age, subject), researcher(name, age, researcharea), publications(publications) {}

    void displaydetails() {
        teacher::displaydetails();
        cout << "\nResearch Area: " << researcharea << "\nNumber of Publications: " << publications << endl;
    }
};

int main() {
    string name, subject, researcharea;
    int age, publications;
    // Enter everything without giving spaces like Name: MaazIqbal.
    cout << "Enter name: "; 
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter name if the subject: ";
    cin >> subject;
    cout << "Enter researchs area: ";
    cin >> researcharea;
    cout << "Enter Number of Publications: ";
    cin >> publications;

    professor p1 (name, age, subject,researcharea, publications);
    p1.displaydetails();
    return 0;
}