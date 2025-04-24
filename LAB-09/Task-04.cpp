#include <iostream>
#include <string>
using namespace std;

class WeatherSensor {
public:
    WeatherSensor() {}
    virtual ~WeatherSensor() {}
    virtual void readData() = 0;
    virtual void displayReport() const = 0;
};

class Thermometer : public WeatherSensor {
    double temperature;
public:
    void readData() override {
        temperature = 25.5;
    }
    void displayReport() const override {
        cout << "Thermometer Reading: " << temperature << "°C\n";
    }
};

class Barometer : public WeatherSensor {
    double pressure;
public:
    void readData() override {
        pressure = 1013.25;
    }
    void displayReport() const override {
        cout << "Barometer Reading: " << pressure << " hPa\n";
    }
};

int main() {
    const int num_sensors = 2;
    WeatherSensor* sensors[num_sensors] = {
        new Thermometer(),
        new Barometer()
    };

    for (int i = 0; i < num_sensors; i++) {
        sensors[i]->readData();
        sensors[i]->displayReport();
    }

    for (int i = 0; i < num_sensors; i++) {
        delete sensors[i];
    }

    return 0;
}