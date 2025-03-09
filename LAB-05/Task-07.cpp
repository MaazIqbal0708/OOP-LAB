#include <iostream>
using namespace std;

class Product {
public:
    int productId;
    string productName;
    int stock;

    Product(int id, string name, int qty) : productId(id), productName(name), stock(qty) {}

    void displayInfo() {
        cout << "Product ID: " << productId << ", Name: " << productName << ", Stock: " << stock << endl;
    }
};

class Warehouse {
private:
    Product* inventory[100]; // Maximum capacity of 100 products
    int itemCount;

public:
    Warehouse() : itemCount(0) {}

    void addProduct(int id, string name, int qty) {
        if (itemCount < 100) {
            inventory[itemCount++] = new Product(id, name, qty);
        }
    }

    void sortByProductName() {
        for (int i = 0; i < itemCount - 1; ++i) {
            for (int j = i + 1; j < itemCount; ++j) {
                if (inventory[i]->productName > inventory[j]->productName) {
                    Product* temp = inventory[i];
                    inventory[i] = inventory[j];
                    inventory[j] = temp;
                }
            }
        }
    }

    void findProductById(int id) {
        for (int i = 0; i < itemCount; ++i) {
            if (inventory[i]->productId == id) {
                inventory[i]->displayInfo();
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    void showInventory() {
        for (int i = 0; i < itemCount; ++i) {
            inventory[i]->displayInfo();
        }
    }

    ~Warehouse() {
        for (int i = 0; i < itemCount; ++i) {
            delete inventory[i];
        }
    }
};

int main() {
    Warehouse storage;
    storage.addProduct(3, "Office Chair", 30);
    storage.addProduct(1, "Water Bottles", 60);
    storage.addProduct(2, "Logitech Keyboards", 25);

    cout << "Inventory before sorting:" << endl;
    storage.showInventory();

    storage.sortByProductName();
    cout << "\nInventory after sorting by name:" << endl;
    storage.showInventory();

    cout << "\nSearching for product with ID 2:" << endl;
    storage.findProductById(2);

    return 0;
}