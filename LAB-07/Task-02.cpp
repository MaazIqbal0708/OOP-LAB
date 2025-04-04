#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string productID;
    string productName;
    float price;
    int stockQuantity;
public:
    Product(string id, string name, float p, int stock) 
        : productID(id), productName(name), price(p), stockQuantity(stock) {}
    
    virtual void applyDiscount(float percent) {
        price *= (1 - percent/100);
    }
    
    virtual float calculateTotalPrice(int quantity) {
        return price * quantity;
    }
    
    virtual void displayProductInfo() {
        cout << "ID: " << productID << "\nName: " << productName 
             << "\nPrice: Rs." << price << "\nStock: " << stockQuantity << endl;
    }
    
    float operator+(Product& p) { //operator overloadinng
        return this->price + p.price;
    }
    
    friend ostream& operator<<(ostream& os, Product& p);
};

ostream& operator<<(ostream& os, Product& p) {
    p.displayProductInfo();
    return os;
}

class Electronics : public Product {
    int warrantyPeriod;
    string brand;
public:
    Electronics(string id, string name, float p, int stock, int warranty, string b) 
        : Product(id, name, p, stock), warrantyPeriod(warranty), brand(b) {}
    
    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Brand: " << brand << "\nWarranty: " << warrantyPeriod << " months" << endl;
    }
};

class Clothing : public Product {
    string size;
    string color;
    string fabricMaterial;
public:
    Clothing(string id, string name, float p, int stock, string s, string c, string fabric) 
        : Product(id, name, p, stock), size(s), color(c), fabricMaterial(fabric) {}
    
    void applyDiscount(float percent) override {
        if (color == "Summer" || color == "Winter") {
            price *= (1 - (percent + 10)/100);
        } else {
            price *= (1 - percent/100);
        }
    }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;
public:
    FoodItem(string id, string name, float p, int stock, string exp, int cal) 
        : Product(id, name, p, stock), expirationDate(exp), calories(cal) {}
    
    float calculateTotalPrice(int quantity) override {
        if (quantity > 5) {
            return price * quantity * 0.9;
        }
        return price * quantity;
    }
};

class Book : public Product {
    string author;
    string genre;
public:
    Book(string id, string name, float p, int stock, string a, string g) 
        : Product(id, name, p, stock), author(a), genre(g) {}
    
    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Author: " << author << "\nGenre: " << genre << endl;
    }
};

int main() {
    Electronics phone("A001", "Iphone 14", 230000, 10, 20, "Apple");
    Clothing shirt("B001", "Shirrt", 16000, 25, "S", "Black", "Cotton and Linen Mix");
    FoodItem peanutbutter("C001", "Peanut Butter", 1500, 100, "12-12-2025", 10000);
    Book book("D001", "Peer-e-Kaamil", 1500, 5, "Umera Ahmed", "Romance and Spiritual");

    cout << book << endl;
    cout << phone << endl;

    cout << shirt << endl;
    shirt.applyDiscount(15);
    cout << "Shirt after discount: Rs." << shirt.calculateTotalPrice(1) << endl;
    
    cout << peanutbutter << endl;
    cout << "6 Jars of Peanut Buter cost: Rs." << peanutbutter.calculateTotalPrice(6) << endl;
    
    cout << "Combined price of Phone and Shirt: Rs." << (phone + shirt) << endl;
    
    return 0;
}
