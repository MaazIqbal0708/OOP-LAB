#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    double price;

public:
    Car(string m, double pr) : model(m), price(pr) {}

    friend class inventoryManager;
    friend void comparePrice(const Car& c1, const Car& c2);
};

class inventoryManager {
public:
    static void updatePrice(Car& car, double newprice) {
        car.price = newprice;
        cout << "Updated price for " << car.model << " to pkr" << newprice << endl;
    }

    static void displayCar(const Car& car) {
        cout << "Model: " << car.model << "\tPrice: pkr" << car.price << endl;
    }
};

void comparePrice(const Car& c1, const Car& c2) {
    if (c1.price > c2.price) {
        cout << c1.model << " is more expensive than " << c2.model << endl;
    } else if (c1.price < c2.price) {
        cout << c2.model << " is more expensive than " << c1.model << endl;
    } else {
        cout << "Both cars have the same price" << endl;
    }
}

int main() {
    Car car1("Toyota Camry", 250000.0);
    Car car2("Honda Accord", 270000.0);

    inventoryManager::displayCar(car1);
    inventoryManager::displayCar(car2);
    inventoryManager::updatePrice(car1, 260000.0);
    comparePrice(car1, car2);

    return 0;
}