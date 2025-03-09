#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    double rentalPrice;
    bool isAvailable;

public:
    Car() : brand("Unknown"), model("Generic"), rentalPrice(0.0), isAvailable(true) {}

    Car(string b, string m, double p, bool a) : brand(b), model(m), rentalPrice(p), isAvailable(a) {}

    // Copy Constructor
    Car(const Car& other) {
        brand = other.brand;
        model = other.model;
        rentalPrice = other.rentalPrice;
        isAvailable = other.isAvailable;
        cout << "Copy constructor called. Car copied successfully." << endl;
    }

    // Destructor
    ~Car() {
        cout << "Car object for " << brand << " " << model << " is being destroyed." << endl;
    }

    void updateDetails(const string& newBrand, const string& newModel, double newPrice) {
        brand = newBrand;
        model = newModel;
        rentalPrice = newPrice;
    }

    bool checkAvailability() const {
        return isAvailable;
    }

    void rentCar(int days) {
        if (!isAvailable) {
            cout << "Car is not available for rent." << endl;
            return;
        }

        double totalPrice = rentalPrice * days;
        if (days > 10) {
            totalPrice *= 0.9;
        } else if (days > 5) {
            totalPrice *= 0.95;
        }

        isAvailable = false;
        cout << "Car rented successfully for " << days << " days. Total price: " << totalPrice << endl;
    }

    void returnCar() {
        isAvailable = true;
        cout << "Car returned successfully." << endl;
    }

    void displayDetails() const {
        cout << "Brand: " << brand << ", Model: " << model << ", Price: " << rentalPrice << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

int main() {
    // Create an original car object
    Car car1("Toyota", "Corolla", 50.0, true);
    cout << "Original Car Details:" << endl;
    car1.displayDetails();

    // Use the copy constructor to create a copy of the car
    Car car2 = car1;
    cout << "Copied Car Details:" << endl;
    car2.displayDetails();

    // Modify the original car details
    car1.updateDetails("Honda", "Civic", 60.0, false);
    cout << "Original Car Details After Modification:" << endl;
    car1.displayDetails();

    // Verify that the copied car remains unchanged
    cout << "Copied Car Details After Original Modification:" << endl;
    car2.displayDetails();

    return 0;
}
