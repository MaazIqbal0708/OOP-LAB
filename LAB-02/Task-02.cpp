// Maaz Iqbal
// 24K-0542

#include <iostream>
using namespace std;


int main () {
    int rows, col;
    cout << "Enter the rows of matrix you want:" << endl;
    cin >> rows;
    cout << "Enter the columns of matrix you want:" << endl;
    cin >> col;

    int **mat1 = new int*[rows];
    int **mat2 = new int*[col];
    int **sum = new int*[rows];
    int **diff = new int*[col];

    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        mat1[i] = new int[col];
        for (int j = 0; j < col; j++) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < col; i++) {
        mat2[i] = new int[rows];
        for (int j = 0; j < rows; j++) {
            cin >> mat2[i][j];
        }
    }
    
    cout << "Sum of the matrices:" << endl;
    for (int i = 0; i < rows; i++) {
        sum[i] = new int[col];
        for (int j = 0; j < col; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Difference of the matrices:" << endl;
    for (int i = 0; i < rows; i++) {   
        diff[i] = new int[col];
        for (int j = 0; j < col; j++) {
            diff[i][j] = mat1[i][j] - mat2[i][j];
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < rows; i++) {
        delete[] mat1[i];
        delete[] mat2[i];
        delete[] sum[i];
        delete[] diff[i];
    }
    delete[] mat1;
    delete[] mat2;
    delete[] sum;
    delete[] diff;

    return 0;
}