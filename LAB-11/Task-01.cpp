#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

class DimensionMismatchException : public exception {
private:
    string errorMsg;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        ostringstream oss;
        oss << "Matrix dimensions mismatch (" << r1 << "x" << c1 
            << " cannot add with " << r2 << "x" << c2 << ")";
        errorMsg = oss.str();
    }
    
    const char* what() const noexcept override {
        return errorMsg.c_str();
    }
};

template <typename T>
class Matrix {
private:
    T** matrixData;
    int rowCount;
    int colCount;
    
    void initMatrix() {
        matrixData = new T*[rowCount];
        for (int i = 0; i < rowCount; i++) {
            matrixData[i] = new T[colCount]{};
        }
    }
    
    void clearMatrix() {
        for (int i = 0; i < rowCount; i++) {
            delete[] matrixData[i];
        }
        delete[] matrixData;
    }
    
public:
    Matrix(int rows, int cols) : rowCount(rows), colCount(cols) {
        if (rows <= 0 || cols <= 0) {
            throw invalid_argument("Matrix dimensions must be POsitive");
        }
        initMatrix();
    }
    
    Matrix(const Matrix& src) : rowCount(src.rowCount), colCount(src.colCount) {
        initMatrix();
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                matrixData[i][j] = src.matrixData[i][j];
            }
        }
    }
    
    ~Matrix() {
        clearMatrix();
    }
    
    Matrix& operator=(const Matrix& rhs) {
        if (this != &rhs) {
            clearMatrix();
            rowCount = rhs.rowCount;
            colCount = rhs.colCount;
            initMatrix();
            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    matrixData[i][j] = rhs.matrixData[i][j];
                }
            }
        }
        return *this;
    }
    
    int rows() const { return rowCount; }
    int cols() const { return colCount; }
    
    T& at(int row, int col) {
        if (row < 0 || row >= rowCount || col < 0 || col >= colCount) {
            throw out_of_range("Matrix index out of bounds");
        }
        return matrixData[row][col];
    }
    
    const T& at(int row, int col) const {
        if (row < 0 || row >= rowCount || col < 0 || col >= colCount) {
            throw out_of_range("Matrix index outof bounds.");
        }
        return matrixData[row][col];
    }
    
    Matrix operator+(const Matrix& other) const {
        if (rowCount != other.rowCount || colCount != other.colCount) {
            throw DimensionMismatchException(rowCount, colCount, 
                                          other.rowCount, other.colCount);
        }
        
        Matrix result(rowCount, colCount);
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                result.matrixData[i][j] = matrixData[i][j] + other.matrixData[i][j];
            }
        }
        return result;
    }
    
    void display() const {
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                cout << matrixData[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    try {
        Matrix<int> mat1(2, 2);
        mat1.at(0, 0) = 5;
        mat1.at(0, 1) = 10;
        mat1.at(1, 0) = 8;
        mat1.at(1, 1) = 9;
        
        Matrix<int> mat2(2, 2);
        mat2.at(0, 0) = 1;
        mat2.at(0, 1) = 2;
        mat2.at(1, 0) = 3;
        mat2.at(1, 1) = 4;
        
        cout << "Matrix 1:" << endl;
        mat1.display();
        
        cout << "\nMatrix 2:" << endl;
        mat2.display();
        
        Matrix<int> sum = mat1 + mat2;
        cout << "\nSum:" << endl;
        sum.display();
        
        Matrix<int> mat3(3, 3);
        cout << "\nAttmpting invalid addition..." << endl;
        Matrix<int> invalidSum = mat1 + mat3;
    }
    catch (const DimensionMismatchException& e) {
        cerr << "Matrix error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    
    return 0;
}