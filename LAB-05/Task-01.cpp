#include <iostream>
using namespace std;

class Flat {
private:
    int flatNumber;
    string location;
    string* residentName; 

public:
    Flat(int fNumber, string fLocation, string fResidentName) {
        flatNumber = fNumber;
        location = fLocation;
        residentName = new string(fResidentName); 
    }

    Flat(const Flat& source) {
        flatNumber = source.flatNumber;
        location = source.location;
        residentName = source.residentName; 
    }

    ~Flat() {
        delete residentName; 
    }

    void showDetails() const {
        cout << "Flat Number: " << flatNumber << endl;
        cout << "Location: " << location << endl;
        cout << "Resident's Name: " << *residentName << endl;
    }

    void updateResident(const string& newResident) {
        *residentName = newResident; 
    }
};

int main() {
    Flat flat1(301, "Gulshan", "Ahsan");
    cout << "Original Flat Info:" << endl;
    flat1.showDetails();

    Flat flat2 = flat1;
    cout << "\nCopied Flat Info:" << endl;
    flat2.showDetails();

    flat2.updateResident("Hamza");
    cout << "\nAfter Updating Resident's Name:" << endl;
    flat2.showDetails();

    cout << "\nOriginal Flat After Modification in Copy:" << endl;
    flat1.showDetails();

    return 0;
}
