#include <iostream>
#include <string>
using namespace std;

class menuItem {
protected:
    string dishName;
    double price;

public:
    menuItem(string name, double p) : dishName(name), price(p) {}
    virtual ~menuItem() {}
    virtual void showDetails() const = 0;
    virtual void prepare() const = 0;
};

class appetizer : public menuItem {
    string dippingSauce;

public:
    appetizer(string name, double p, string sauce) : menuItem(name, p), dippingSauce(sauce) {}

    void showDetails() const override {
        cout << "APPETIZER: " << dishName << "\nPrice: Rs." << price <<
            "and it comes with " << dippingSauce << " dipping sauce" << endl;
    }

    void prepare() const override {
        cout << "Preparing " << dishName << ":\n1. Plate the appetizer\n" << "2. Add " << dippingSauce 
            << " sauce on the side\n" << "3. Placing the herbs\n";
    }
};

class mainCourse : public menuItem {
    string sideDish;

public:
    mainCourse(string name, double p, string side) 
        : menuItem(name, p), sideDish(side) {}

    void showDetails() const override {
        cout << "Main DIsh: " << dishName << " of Price: Rs." << price << "\n& Served with " << sideDish << "\n";
    }

    void prepare() const override {
        cout << "Preparing " << dishName << ":\n1. Cook main food" << "\n2. Prepare " << sideDish 
            << "\n3. Plate together\n" << "4. Add final touches\n";
    }
};

int main() {
    const int menu_size = 4;
    menuItem* menu[menu_size] = {
        new appetizer("Ande Wala Burger", 240.0, "Chatni"),
        new appetizer("Garlic Bread", 300.0, "cheese"),
        new mainCourse("Fried Fish", 1000.0, "mashed potatoes"),
        new mainCourse("Chicken Karahi(2 person)", 850.0, "Taftan bread(3)")
    };

    for (int i = 0; i < menu_size; i++) {
        cout << "\n";
        menu[i]->showDetails();
        cout << "Preparation Steps:\n";
        menu[i]->prepare();
        cout << "------------------------\n";
    }

    for (int i = 0; i < menu_size; i++) {
        delete menu[i];
    }

    return 0;
}