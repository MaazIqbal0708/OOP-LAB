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

    void updateDetails(const string& newBrand, const string& newModel, double newPrice) {
        brand = newBrand;
        model = newModel;
        rentalPrice = newPrice;
    }

    bool checkAvailability() const {
        return isAvailable;
    }

    void rentCar() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Car rented successfully." << endl;
        } else {
            cout << "Car is not available for rent." << endl;
        }
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
    Car car1;
    car1.displayDetails();

    car1.updateDetails("Toyota", "Corolla", 50.0);
    car1.displayDetails();

    car1.rentCar();
    car1.displayDetails();

    car1.rentCar();
    car1.returnCar();
    car1.displayDetails();

    return 0;
}
