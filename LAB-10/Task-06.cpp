#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem itemToSave;
    itemToSave.itemID = 1001;
    strcpy(itemToSave.itemName, "WidgetX");

    ofstream outFile("inventory.dat", ios::binary);
    if (!outFile) {
        cerr << "Error creating file" << endl;
        return 1;
    }
    outFile.write(reinterpret_cast<char*>(&itemToSave), sizeof(InventoryItem));
    outFile.close();

    InventoryItem itemToLoad;
    ifstream inFile("inventory.dat", ios::binary);
    if (!inFile) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    inFile.read(reinterpret_cast<char*>(&itemToLoad), sizeof(InventoryItem));
    inFile.close();

    cout << "Loaded Item ID: " << itemToLoad.itemID << endl;
    cout << "Loaded Item Name: " << itemToLoad.itemName << endl;

    return 0;
}