#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(const string& name, const string& id) : name(name), id(id) {}
    virtual ~Patient() {}
    virtual void displayTreatment() const = 0;
    virtual double calculateCost() const = 0;
    string getName() const { return name; }
    string getId() const { return id; }
};

class InPatient : public Patient {
private:
    int daysAdmitted;
    double dailyRate;
    string procedures[4];
    int procedureCount;

public:
    InPatient(const string& name, const string& id, int days, double rate) 
        : Patient(name, id), daysAdmitted(days), dailyRate(rate), procedureCount(4) {
        procedures[0] = "Medical Examinations";
        procedures[1] = "Daily Monitoring";
        procedures[2] = "Lab Tests";
        procedures[3] = "Medication";
    }

    void displayTreatment() const override {
        cout << "InPatient Treatment Details:" << endl;
        cout << "Patient: " << name << " with ID: " << id << endl;
        cout << "Days Admitted: " << daysAdmitted << endl;
        cout << "Procedures:" << endl;
        for (int i = 0; i < procedureCount; i++) {
            cout << "o " << procedures[i] << endl;
        }
    }

    double calculateCost() const override {
        return daysAdmitted * dailyRate + (procedureCount * 150);
    }
};

class OutPatient : public Patient {
private:
    string procedures[3];
    int procedureCount;

public:
    OutPatient(const string& name, const string& id) 
        : Patient(name, id), procedureCount(3) {
        procedures[0] = "Consultation";
        procedures[1] = "Diagnostic Tests";
        procedures[2] = "Prescription";
    }

    void displayTreatment() const override {
        cout << "OutPatient Treatment Details:" << endl;
        cout << "Patient: " << name << " with ID: " << id << endl;
        cout << "Procedures:" << endl;
        for (int i = 0; i < procedureCount; i++) {
            cout << "o " << procedures[i] << endl;
        }
    }

    double calculateCost() const override {
        return procedureCount * 200;
    }
};

int main() {
    Patient* patient1 = new InPatient("Burair", "AB123", 5, 300.0);
    Patient* patient2 = new OutPatient("Zahran Ali", "CD456");

    Patient* patients[2] = {patient1, patient2};

    for (int i = 0; i < 2; i++) {
        patients[i]->displayTreatment();
        cout << "Total Cost: Rs." << patients[i]->calculateCost() << endl;
        cout << "   ------------------    " << endl;
    }

    delete patient1;
    delete patient2;

    return 0;
}