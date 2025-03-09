#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    double rentalPrice;
    bool isAvailable;
    double totalRevenue;

public:
    Car() : brand("Unknown"), model("Generic"), rentalPrice(0.0), isAvailable(true), totalRevenue(0.0) {}

    Car(string b, string m, double p, bool a) : brand(b), model(m), rentalPrice(p), isAvailable(a), totalRevenue(0.0) {}

    // Copy Constructor
    Car(const Car& other) {
        brand = other.brand;
        model = other.model;
        rentalPrice = other.rentalPrice;
        isAvailable = other.isAvailable;
        totalRevenue = other.totalRevenue;
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

        this->totalRevenue += totalPrice; // Update total revenue using this pointer
        isAvailable = false;
        cout << "Car rented successfully for " << days << " days. Total price: " << totalPrice << endl;
    }

    void returnCar() {
        isAvailable = true;
        cout << "Car returned successfully." << endl;
    }

    void displayDetails() const {
        cout << "Brand: " << brand << ", Model: " << model << ", Price: " << rentalPrice << ", Available: " << (isAvailable ? "Yes" : "No") << ", Total Revenue: " << totalRevenue << endl;
    }
};

int main() {
    // Create an original car object
    Car car1("Toyota", "Corolla", 50.0, true);
    cout << "Original Car Details:" << endl;
    car1.displayDetails();

    // Rent the car for 7 days
    car1.rentCar(7);
    car1.displayDetails();

    // Return the car
    car1.returnCar();
    car1.displayDetails();

    // Rent the car again for 12 days
    car1.rentCar(12);
    car1.displayDetails();

    // Create a copy of the car using the copy constructor
    Car car2 = car1;
    cout << "Copied Car Details:" << endl;
    car2.displayDetails();

    return 0;
}
