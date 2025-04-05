#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;
public:
    Person(string n, int a, string contact, string addr) 
        : name(n), age(a), contactNumber(contact), address(addr) {}
    
    virtual void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age 
             << "\nContact: " << contactNumber << "\nAddress: " << address << endl;
    }
    
    virtual void updateInfo(string n, int a, string contact, string addr) {
        name = n;
        age = a;
        contactNumber = contact;
        address = addr;
    }
};

class Patient : public Person {
    string patientID;
    string medicalHistory;
    string doctorAssigned;
public:
    Patient(string id, string n, int a, string contact, string addr, string history, string doctor) 
        : Person(n, a, contact, addr), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}
    
    void displayInfo() override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << "\nMedical History: " << medicalHistory 
             << "\nDoctor: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
    string specialization;
    float consultationFee;
    string patientList[10];
    int patientCount;
public:
    Doctor(string n, int a, string contact, string addr, string spec, float fee) 
        : Person(n, a, contact, addr), specialization(spec), consultationFee(fee), patientCount(0) {}
    
    void displayInfo() override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << "\nFee: Rs." << consultationFee << endl;
        cout << "Patients: ";
        for (int i = 0; i < patientCount; i++) {
            cout << patientList[i] << ", ";
        }
        cout << endl;
    }
    
    void addPatient(string patientName) {
        if (patientCount < 10) {
            patientList[patientCount++] = patientName;
        }
    }
};

class Nurse : public Person {
    string assignedWard;
    string shiftTimings;
public:
    Nurse(string n, int a, string contact, string addr, string ward, string shift) 
        : Person(n, a, contact, addr), assignedWard(ward), shiftTimings(shift) {}
    
    void displayInfo() override {
        Person::displayInfo();
        cout << "Ward: " << assignedWard << "\nShift: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
    string department;
    float salary;
public:
    Administrator(string n, int a, string contact, string addr, string dept, float sal) 
        : Person(n, a, contact, addr), department(dept), salary(sal) {}
    
    void updateInfo(string n, int a, string contact, string addr) override {
        Person::updateInfo(n, a, contact, addr);
        cout << "Administrative record updated for " << name << endl;
    }
    
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: Rs." << salary << endl;
    }
};

int main() {
    Patient Iqbal("A100", "Maaz Iqbal", 20, "03001111111", "123 Mustafabad Street,Malir City", "Hypertension", "Dr.Arif");
    Doctor Arif("Dr.Arif Mateen", 48, "03001212121", "456 Street DHA Phase II", "Neurology", 2500);
    Nurse Daniel("Daniel Radcliffe", 33, "03001231231", "789 Street, North Karachi", "Pediatrics", "Day Shift");
    Administrator Ad("Sana Ali", 29, "03001234568", "323 Sweets Street, District Baldia", "Finance", 95000);

    Arif.addPatient("Zahran");
    
    Iqbal.displayInfo();
    cout << endl;
    
    Arif.displayInfo();
    cout << endl;
    
    Daniel.displayInfo();
    cout << endl;
    
    Ad.displayInfo();
    Ad.updateInfo("Sania Zeesham", 28, "03001122334", "654 Ahmadia Street, District Orangi");
    Ad.displayInfo();
    
    return 0;
}