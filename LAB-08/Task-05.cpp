#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int elements[2][2];

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0){
        elements[0][0] = a;
        elements[0][1] = b;
        elements[1][0] = c;
        elements[1][1] = d;
    }

    Matrix2x2 operator+(const Matrix2x2& other) const {
        return Matrix2x2( elements[0][0] + other.elements[0][0],
            elements[0][1] + other.elements[0][1],
            elements[1][0] + other.elements[1][0],
            elements[1][1] + other.elements[1][1] );
    }

    Matrix2x2 operator-(const Matrix2x2& other) const {
        return Matrix2x2(   elements[0][0] - other.elements[0][0],
            elements[0][1] - other.elements[0][1],
            elements[1][0] - other.elements[1][0],
            elements[1][1] - other.elements[1][1] );
    }

    Matrix2x2 operator*(const Matrix2x2& other)const {
        return Matrix2x2( elements[0][0]*other.elements[0][0] + elements[0][1]*other.elements[1][0],
            elements[0][0]*other.elements[0][1] + elements[0][1]*other.elements[1][1],
            elements[1][0]*other.elements[0][0] + elements[1][1]*other.elements[1][0],
            elements[1][0]*other.elements[0][1] + elements[1][1]*other.elements[1][1] );
    }

    friend int determinant(const Matrix2x2& m);
    friend class MatrixHelper;
    friend ostream& operator<<(ostream& os, const Matrix2x2& m);
};

class MatrixHelper {
public:
    static void updateElement(Matrix2x2& m, int row, int col, int value) {
        if (row >= 0 && row < 2 && col >= 0 && col < 2) {
            m.elements[row][col] = value;
            cout << "Updated value at (" << row << "," << col << ") is " << value << endl;
        }
    }
};

int determinant(const Matrix2x2& m) {
    return m.elements[0][0] * m.elements[1][1] - m.elements[0][1] * m.elements[1][0];
}

ostream& operator<<(ostream& os, const Matrix2x2& m) {
    os << "[" << m.elements[0][0] << " " << m.elements[0][1] << "]\n" << "[" << m.elements[1][0] <<
         " " << m.elements[1][1] << "]";
    return os;
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix 1:\tn" << m1 << endl;
    cout << "Matrix 2:\n" << m2 << endl;
    cout << "Sum:\n" << m1 + m2 << endl;
    cout << "Product:\n" << m1 * m2 << endl;
    cout << "Determinant of m1:\n " << determinant(m1) << endl;

    MatrixHelper::updateElement(m1, 0, 1, 5);
    cout << "Updated Matrix 1:\n" << m1 << endl;

    return 0;
}