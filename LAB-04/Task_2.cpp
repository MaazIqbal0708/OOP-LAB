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
    Car car1("Toyota", "Corolla", 50.0, true);
    car1.displayDetails();

    car1.rentCar(6);
    car1.displayDetails();

    car1.returnCar();
    car1.displayDetails();

    car1.rentCar(12);
    car1.displayDetails();

    return 0;
}
