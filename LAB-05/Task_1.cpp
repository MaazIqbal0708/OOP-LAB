#include <iostream>
using namespace std;

class Apartment {
private:
    int id;
    string address;
    string* ownerName; 

public:
    Apartment(int aid, string aaddress, string aownerName) {
        id = aid;
        address = aaddress;
        ownerName = new string(aownerName); 
    }

    Apartment(const Apartment& other) {
        id = other.id;
        address = other.address;
        ownerName = other.ownerName; 
    }

    ~Apartment() {
        delete ownerName; 
    }

    void display() const {
        cout << "Apartment ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Owner's Name: " << *ownerName << endl;
    }

    void setOwnerName(const string& newOwnerName) {
        *ownerName = newOwnerName; 
    }
};

int main() {
    Apartment apt1(101, "liatabad", "MAaz");
    cout << "nakli apartment:" << endl;
    apt1.display();

    Apartment apt2 = apt1;
    cout << "\n apartment:" << endl;
    apt2.display();

    apt2.setOwnerName("Zahran");
    cout << "\n apartment after changing owners name:" << endl;
    apt2.display();

    cout << "\n apartment after copying:" << endl;
    apt1.display();

    return 0;
}
