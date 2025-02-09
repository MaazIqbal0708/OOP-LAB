// Maaz Iqbal
// 24k-0542

#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    cout << "Enter dimensions of the 3D array (x y z): ";
    cin >> x >> y >> z;

    int*** arr = new int**[x];
    for (int i = 0; i < x; i++) {
        arr[i] = new int*[y];
        for (int j = 0; j < y; j++) {
            arr[i][j] = new int[z];
        }
    }

    cout << "Enter values for the 3D array:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Enter value for [" << i << "][" << j << "][" << k << "]: ";
                cin >> arr[i][j][k];
            }
        }
    }

    cout << "3D Array values:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
