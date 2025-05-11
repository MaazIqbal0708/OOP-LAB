#include <iostream>
#include <stdexcept>

using namespace std;

class InvalidQuantityException : public exception {};
class ExceedsCapacityException : public exception {};

template <typename T>
class InventoryManager {
private:
    T currentQuantity;
    T maximumCapacity;

    void validateQuantity(T quantity) const {
        if (quantity < 0) {
            throw InvalidQuantityException();
        }
        if (quantity > maximumCapacity) {
            throw ExceedsCapacityException();
        }
    }

public:
    InventoryManager(T capacity) : maximumCapacity(capacity), currentQuantity(0) {
        if (capacity <= 0) {
            throw invalid_argument(" Capacity must be positive");
        }
    }

    void updateStock(T newQuantity) {
        validateQuantity(newQuantity);
        currentQuantity = newQuantity;
    }

    void addStock(T amount) {
        validateQuantity(currentQuantity + amount);
        currentQuantity += amount;
    }

    void removeStock(T amount) {
        validateQuantity(currentQuantity - amount);
        currentQuantity -= amount;
    }

    T getCurrentStock() const {
        return currentQuantity;
    }

    T getCapacity() const {
        return maximumCapacity;
    }
};

void testInventoryOperations() {
    try {
        InventoryManager<int> warehouse(200);

        warehouse.updateStock(50);
        cout << "Stock updated to: " << warehouse.getCurrentStock() << endl;
        
        warehouse.addStock(30);
        cout << "After adding: " << warehouse.getCurrentStock() << endl;

        try {
            cout << "Attempting to set negative stock..." << endl;
            warehouse.updateStock(-10);
        }
        catch (const InvalidQuantityException& e) {
            cerr << "Error: " << e.what() << " (Ne gative value)" << endl;
        }

        try {
            cout << "Attempting to exceed Capacity (250/200)..." << endl;
            warehouse.addStock(200);
        }
        catch (const ExceedsCapacityException& e) {
            cerr << "Error: " << e.what() << " (Exceeds Caapacity)" << endl;
        }

        cout << "Final stock level: " << warehouse.getCurrentStock() << "/" 
             << warehouse.getCapacity() << endl;
    }
    catch (const exception& e) {
        cerr << "Initialization errocr: " << e.what() << endl;
    }
}

int main() {
    testInventoryOperations();
    return 0;
}