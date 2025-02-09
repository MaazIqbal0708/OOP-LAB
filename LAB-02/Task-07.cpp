// Maaz Iqbal
// 24k-0542

#include <iostream>
using namespace std;

int main() {
    int rows1, col1, rows2, col2;

    cout << "Enter the dimensions of the first matrix (rows x cols): ";
    cin >> rows1 >> col1;
    cout << "Enter the dimensions of the second matrix (rows x cols): ";
    cin >> rows2 >> col2;


    if (col1 != rows2) {
        cout << "Matrix multiplication is not possible. Number of columns of matrix 1 must be equal to number of rows of matrix 2." << endl;
        return 1;
    }

 
    int** mat1 = new int*[rows1];
    for (int i = 0; i < rows1; i++) {
        mat1[i] = new int[col1];
    }
    int** mat2 = new int*[rows2];
    for (int i = 0; i < rows2; i++) {
        mat2[i] = new int[col2];
    }
    int** result = new int*[rows1];
    for (int i = 0; i < rows1; i++) {
        result[i] = new int[col2];
    }

    cout << "Enter elements of matrix 1:" << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter elements of matrix 2:" << endl;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < col2; j++) {
            cin >> mat2[i][j];
        }
    }
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    cout << "Resultant matrix after multiplication:" << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows1; i++) {
        delete[] mat1[i];
    }
    delete[] mat1;
    for (int i = 0; i < rows2; i++) {
        delete[] mat2[i];
    }
    delete[] mat2;
    for (int i = 0; i < rows1; i++) {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}
