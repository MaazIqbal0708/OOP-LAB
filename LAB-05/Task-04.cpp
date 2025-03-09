#include <iostream>
using namespace std;

class AlarmSystem {
private:
    string securityLevel;

public:
    AlarmSystem(string level) : securityLevel(level) {
        cout << "Alarm System initialized with security level: " << securityLevel << endl;
    }

    string getSecurityLevel() const {
        return securityLevel;
    }
};

class SmartHome {
private:
    string homeName;
    AlarmSystem alarmSystem;

public:
    SmartHome(string name, string securityLevel)
        : homeName(name), alarmSystem(securityLevel) {
        cout << "Smart Home '" << homeName << "' has been set up." << endl;
    }

    void showInfo() const {
        cout << "Home Name: " << homeName << endl;
        cout << "Alarm System Security Level: " << alarmSystem.getSecurityLevel() << endl;
    }
};

int main() {
    SmartHome home("Tech-house", "High");
    home.showInfo();

    return 0;
}
