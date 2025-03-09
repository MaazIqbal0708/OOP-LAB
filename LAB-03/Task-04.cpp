#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    double fuelCapacity;
    double currentFuelLevel;

public:
    Car(string b, string m, double capacity) : brand(b), model(m), fuelCapacity(capacity), currentFuelLevel(capacity) {}

    void drive(double distance) {
        double fuelUsed = distance / 10; 
        if (fuelUsed > currentFuelLevel) {
            cout << "Not enough fuel to drive!" << endl;
            return;
        }
        currentFuelLevel -= fuelUsed;
        cout << "Drove " << distance << " km. Fuel remaining: " << currentFuelLevel << " liters." << endl;
        if (currentFuelLevel < 5) {
            cout << "Low fuel warning!" << endl;
        }
    }

    void refuel(double amount) {
        if (currentFuelLevel + amount > fuelCapacity) {
            currentFuelLevel = fuelCapacity;
            cout << "Tank is now full." << endl;
        } else {
            currentFuelLevel += amount;
            cout << "Refueled " << amount << " liters. Current fuel: " << currentFuelLevel << " liters." << endl;
        }
    }

    void checkFuelStatus() {
        cout << "Current fuel level: " << currentFuelLevel << " liters." << endl;
    }
};

int main() {
    Car zoyaCar("Toyota", "Corolla", 50);
    zoyaCar.drive(100);
    zoyaCar.refuel(20);
    zoyaCar.checkFuelStatus();
    return 0;
}
