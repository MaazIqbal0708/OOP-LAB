// Maaz Iqbal
// 24k-0542

#include <iostream>
#include <string>
using namespace std;

struct Product {
    int proID;
    string name;
    int quantity;
    float price;
};

int main() {
    int numProducts;

    cout << "Enter the number of products: ";
    cin >> numProducts;

    Product* products = new Product[numProducts];

    for (int i = 0; i < numProducts; i++) {
        cout << "Enter details for product " << i + 1 << endl;
        cout << "Product ID: ";
        cin >> products[i].proID;
        cout << "Product Name: ";
        cin.ignore();  
        getline(cin, products[i].name);
        cout << "Quantity: ";
        cin >> products[i].quantity;
        cout << "Price: ";
        cin >> products[i].price;
    }

    float totalValue = 0;
    for (int i = 0; i < numProducts; i++) {
        totalValue += products[i].quantity * products[i].price;
    }

    cout << "Total value of the inventory: " << totalValue << endl;

    delete[] products;
    return 0;
}
