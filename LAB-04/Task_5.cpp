#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    double rentalPrice;
    bool isAvailable;
    int carID;
    double totalRevenue;

public:
    Car() : brand("Unknown"), model("Generic"), rentalPrice(0.0), isAvailable(true), carID(0), totalRevenue(0.0) {}

    Car(string b, string m, double p, bool a, int id) 
        : brand(b), model(m), rentalPrice(p), isAvailable(a), carID(id), totalRevenue(0.0) {}

    Car(const Car& other) 
        : brand(other.brand), model(other.model), rentalPrice(other.rentalPrice), 
          isAvailable(other.isAvailable), carID(other.carID), totalRevenue(other.totalRevenue) {
        cout << "Copy constructor called. Car copied successfully." << endl;
    }

    ~Car() {
        cout << "Car object for " << brand << " " << model << " (ID: " << carID << ") is being destroyed." << endl;
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
        totalRevenue += totalPrice;
        cout << "Car rented successfully for " << days << " days. Total price: " << totalPrice << endl;
    }

    void returnCar() {
        isAvailable = true;
        cout << "Car returned successfully." << endl;
    }

    void displayDetails() const {
        cout << "Car ID: " << carID << ", Brand: " << brand << ", Model: " << model 
             << ", Price: " << rentalPrice << ", Available: " << (isAvailable ? "Yes" : "No") 
             << ", Total Revenue: " << totalRevenue << endl;
    }
};

int main() {
    Car car1("Toyota", "Corolla", 50.0, true, 101);
    cout << "Original Car Details:" << endl;
    car1.displayDetails();

    Car car2 = car1;
    cout << "Copied Car Details:" << endl;
    car2.displayDetails();

    car1.updateDetails("Honda", "Civic", 60.0, false);
    cout << "Original Car Details After Modification:" << endl;
    car1.displayDetails();

    cout << "Copied Car Details After Original Modification:" << endl;
    car2.displayDetails();

    car1.rentCar(7);
    car1.displayDetails();

    car2.rentCar(12);
    car2.displayDetails();

    return 0;
}
