#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;

public:
    Vehicle(string b, int s) : brand(b), speed(s) {}

    virtual void displayDetails() {
        cout << "Brand: " << brand << ", Speed: " << speed << endl;
    }
};

class Car : public Vehicle {
protected:
    int seats;

public:
    Car(string b, int s, int st) : Vehicle(b, s), seats(st) {}

    void displayDetails() override {
        cout << "Brand: " << brand << ", Speed: " << speed << ", Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;

public:
    ElectricCar(string b, int s, int st, int bl) : Car(b, s, st), batteryLife(bl) {}

    void displayDetails() override {
        cout << "Brandd " << brand << ", Sped " << speed << ", Seats: " << seats << ", Batttery Life: " << batteryLife << endl;
    }
};

int main() {
    string brand;
    int speed, seats, batteryLife;
    cout << "please enter the details showroom bhai:" << endl;
    cout << "Enter brands: ";
    cin >> brand;
    cout << "Enter speed: ";
    cin >> speed;
    cout << "Enter seats: ";
    cin >> seats;
    cout << "Enter battery lifes: ";
    cin >> batteryLife;

    ElectricCar electricCar(brand, speed, seats, batteryLife);
    electricCar.displayDetails();

    return 0;
}