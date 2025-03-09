#include <iostream>
using namespace std;

class device {
protected:
    int deviceid;
    bool status;

public:
    device(int deviceid, bool status) : deviceid(deviceid), status(status) {}

    void displayDetails() {
        cout << "Device ID: " << deviceid << endl;
        cout << "Status: " << (status ? "Active" : "Not active") << endl;
    }
};

class smartphone : public device {
protected:
    float screensize;

public:
    smartphone(int deviceid, bool status, float screensize) : 
        device(deviceid, status), screensize(screensize) {}

    void displayDetails() {
        device::displayDetails();
        cout << "Screen Size: " << screensize << " inches" << endl;
    }
};

class smartwatch : public device {
protected:
    bool heartratemonitor;

public:
    smartwatch(int deviceid, bool status, bool heartratemonitor) :
        device(deviceid, status), heartratemonitor(heartratemonitor) {}

    void displayDetails() {
        device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartratemonitor ? "Yes" : "No") << endl;
    }
};

class smartwearable : public smartphone, public smartwatch {
private:
    int stepcounter;

public:
    smartwearable(int deviceid, bool status, float screensize, bool heartratemonitor, int stepcounter)
        : smartphone(deviceid, status, screensize), smartwatch(deviceid, status, heartratemonitor),
            stepcounter(stepcounter) {}

    void displayDetails() {
        smartphone::displayDetails();
        // cout << "Screen Size: " << screensize << " inches" << endl;
        cout << "Heart Rate Monitor: " << (heartratemonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepcounter << " steps" << endl;
    }
};

int main() {
    int deviceid,stepcounter;
    bool status,heartratemonitor;
    float screensize;
    int statusinput, heartratemonitorinput;

    cout << "Enter device ID: ";
    cin >> deviceid;

    cout << "Enter device status (1 for true/0 for false): ";
    cin >> statusinput;
    status = statusinput;

    cout << "Enter screen size for this smartwearable (inches): ";
    cin >> screensize;

    cout << "Enter heart rate monitor status (1 for true/0 for false): ";
    cin >> heartratemonitorinput;
    heartratemonitor = heartratemonitorinput;

    cout << "Enter step counter for this smartwearable: ";
    cin >> stepcounter;
    
    smartwearable smartwear1(deviceid, status, screensize, heartratemonitor, stepcounter);
    smartwear1.displayDetails();

    return 0;
}
