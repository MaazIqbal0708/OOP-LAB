#include <iostream>
#include <cmath>
using namespace std;

class complex {
private:
    double real;
    double imag;

public:
    complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    complex operator+(complex& other){
        return complex(this->real + other.real, this->imag + other.imag);
    }

    complex operator-(complex& other) {
        return complex(this->real - other.real, this->imag - other.imag);
    }

    complex operator*(complex& other) {
        return complex(this->real * other.real - this->imag * other.imag,
            this->real * other.imag + this->imag * other.real );
    }

    complex operator/(complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        return complex((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator
        );
    }

    friend double magnitude(complex& c);

    friend ostream& operator<<(ostream& os,const complex& c);
};

ostream& operator<<(ostream& os,const complex& c) {
    os << "(" << c.real;
    if (c.imag >= 0) {
        os << " + " << c.imag << "i)";
    } else {
        os << " - " << -c.imag << "i)";
    }
    return os;
}

double magnitude(complex& c) {
    return sqrt((c.real * c.real) + (c.imag * c.imag));
}

int main() {
    complex c1(1, 2);
    complex c2(3, -4);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;
    cout << "c1 * c2 = " << c1 * c2 << endl;
    cout << "c1 / c2 = " << c1 / c2 << endl;
    cout << "Magnitude of c1: " << magnitude(c1) << endl;
    cout << "Magnitude of c2: " << magnitude(c2) << endl;

    return 0;
}