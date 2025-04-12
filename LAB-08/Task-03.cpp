#include <iostream>
#include <cmath>
using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double a = 0.0, double b = 0.0) : x(a), y(b) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(const double scal) const {
        return Vector2D(x * scal, y * scal);
    }

    friend double dotProduct(const Vector2D& v1, const Vector2D& v2);
    friend ostream& operator<<(ostream& os, const Vector2D& v);
};

double dotProduct(const Vector2D& v1, const Vector2D& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

ostream& operator<<(ostream& os,const  Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")" << endl;
    return os;
}

int main() {
    Vector2D v1(5.0, -4.0);
    Vector2D v2(-3.0, 2.0);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v1 + v2 = " << v1 + v2 << endl;
    cout << "v1 - v2 = " << v1 - v2 << endl;
    cout << "v1 * 6.75 = " << v1 * 6.75 << endl;
    cout << "Dot product: " << dotProduct(v1, v2) << endl;

    return 0;
}