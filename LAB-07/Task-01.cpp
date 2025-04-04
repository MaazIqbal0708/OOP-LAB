#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    string deviceName;
    bool status; 
    string location;
public:
    Device(int id, string name, string loca) : deviceID(id), deviceName(name), status(false), location(loca) {}

    void virtual turnON() {
        status = true;
        cout << "Device Name:" << deviceName << " at Loaction:" << location << " is turned On." << endl;
    }

    void virtual turnOFF() {
        status = false;
        cout << "Device Name:" << deviceName << " at Loaction:" << location << " is turned Off." << endl;
    }

    void virtual getstatus() {
        cout << "Status:" << (status? "ON" : "OFF") << endl;
    }

    void virtual displayinfo() {
        cout << "Device Name: " << deviceName  << " | Device ID: " << deviceID << " | Location: " << location << " | Status: " << ((status = true)? "ON" : "OFF") << endl;
    }
};

class Light: public Device {
private:
    int brightnessLevel;
    string colorMode;
public:
    Light(int id, string name, string loca, int brightness, string color) : Device(id,name,loca), brightnessLevel(brightness), colorMode(color) {} 

    void displayinfo() override  {
        cout << "Device Name: " << deviceName  << " | Device ID: " << deviceID << " | Location: " << location << " | Status: " << 
        ((status = true)? "ON" : "OFF") << " | Brightness Level: " << brightnessLevel << " Color Mode: " << colorMode << endl;
    }
};

class Thermostat: public Device {
private:
    float temperature;
    string mode;
public:
    Thermostat(int id, string name, string loca, float temp, string mod) : Device(id,name,loca), temperature(temp), mode(mod) {}

    // void displayinfo() override {
    //     cout << "Device Name: " << deviceName  << " | Device ID: " << deviceID << " | Location: " << location << " | Status: " << 
    //     ((status = true)? "ON" : "OFF") << " | Temperature: " << temperature << " | Mode:" << mode << endl;
    // }

    void getstatus() override {
        cout << "Current temperature of the device " << deviceName << " is " << temperature << " degree Celsius." << endl;
    }
};

class securityCamera: public Device {
private:
    string resolution;
    bool recordingStatus;
public:
    securityCamera(int id, string name, string loca, string res) : Device(id,name,loca), resolution(res), recordingStatus(false) {}

    void turnON() override {
        recordingStatus = true;
        status = true;
        cout << "Device Name:" << deviceName << " at Loaction:" << location << " is turned On and started recording." << endl;
    }
};

class smartPlug: public Device {
private:
    int powerConsumption;
    int timerSettings;
public:
    smartPlug(int id, string name, string loca, int power, int timer) : Device(id,name,loca), powerConsumption(power), timerSettings(timer) {}

    void turnOFF() override {
        status = false;
        cout << "Device name:" << deviceName << " at location " << location << " is turned Off | Power Usage: " << powerConsumption << "W" << endl;
    }
};

int main () {
    Thermostat t1(123, "ABC", "Malir", 30, "Heating");
    t1.getstatus();

    Light light(1, "Bedroom Light", "Bedroom", 75, "Warm White");
    Thermostat thermostat(2, "Living Room Thermostat", "Living Room", 22.5, "Cooling");
    securityCamera camera(3, "Front Door Camera", "Front Door", "1080p");
    smartPlug plug(4, "Kitchen Plug", "Kitchen", 1500, 30);
    
    light.turnON();
    light.displayinfo();
    
    thermostat.turnON();
    thermostat.displayinfo();
    
    camera.turnON();
    
    plug.turnON();
    plug.turnOFF();

    return 0;
}