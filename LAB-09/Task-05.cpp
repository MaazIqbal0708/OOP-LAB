#include <iostream>
#include <string>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string num, double w) : trackingNumber(num), weight(w) {}
    virtual ~Shipment() {}

    virtual string estimateDeliveryTime() const = 0;
    virtual void showDetails() const = 0;
};

class AirFreight : public Shipment {
    string departingAirport;
    string destinationAirport;

public:
    AirFreight(string num, double w, string depart, string dest)
        : Shipment(num, w), departingAirport(depart), destinationAirport(dest) {}

    string estimateDeliveryTime() const override {
        if (weight < 50) { return "1 business day";
        } else if (weight < 200) { return "2 business days";
        } else { return "3 business days";
        }
    }

    void showDetails() const override {
        cout << "=== AIR FREIGHT SHIPMENT ===" << endl;
        cout << "Tracking #: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Route: " << departingAirport << " ==> " << destinationAirport << endl;
        cout << "Estimated delivery: " << estimateDeliveryTime() << endl;
    }
};

class GroundShipment : public Shipment {
    string originCity;
    string destinationCity;
    double distance;

public:
    GroundShipment(string trackingNum, double w, string origin, string dest, double dist)
        : Shipment(trackingNum, w), originCity(origin), destinationCity(dest), distance(dist) {}

    string estimateDeliveryTime() const override {
        int days = static_cast<int>(distance / 500) + 1;
        return to_string(days) + " business days";
    }

    void showDetails() const override {
        cout << "=== GROUND SHIPMENT ===" << endl;
        cout << "Tracking #: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Route: " << originCity << " ==> " << destinationCity << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Estimated delivery: " << estimateDeliveryTime() << endl;
    }
};

int main() {
    const int num_shipments = 3;
    Shipment* shipments[num_shipments] = {
        new AirFreight("AIR123", 45.67, "KHI", "ISL"),
        new GroundShipment("GR456", 122.0, "Kaula Lampur", "Langkawi", 1200),
        new AirFreight("AIR789", 210.3, "LHR", "UK(Umer-Kot)")
    };

    cout << "===== LOGISTICS MANAGEMENT SYSTEM =====" << endl;
    for (int i = 0; i < num_shipments; i++) {
        shipments[i]->showDetails();
        cout << "------------------------" << endl;
    }

    for (int i = 0; i < num_shipments; i++) {
        delete shipments[i];
    }

    return 0;
}