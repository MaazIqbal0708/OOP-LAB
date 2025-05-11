#include <iostream>
#include <stdexcept>

using namespace std;

class AbsoluteZeroViolation : public exception {};

template <typename T>
T celsiusToFahrenheit(T celsiusTemp) {
    const T absoluteZero = -273.15;
    
    if (celsiusTemp < absoluteZero) {
        throw AbsoluteZeroViolation();
    }
    
    return (celsiusTemp * 9) / 5 + 32;
}

void testConversion(double temp) {
    try {
        cout << "Converting " << temp << "°C to Fahrenheit..." << endl;
        double fahrenheit = celsiusToFahrenheit(temp);
        cout << "Converted: " << fahrenheit << "°F" << endl;
    }
    catch (const AbsoluteZeroViolation& e) {
        cerr << "Caught AbsoluteZeroViolation - what(): " << e.what() << endl;
    }
}

int main() {
    testConversion(-311.0);

    testConversion(0.0);
    testConversion(25.0);
    testConversion(100.0);
    
    testConversion(-273.15);

    return 0;
}