// Maaz Iqbal
// 24k-0542

#include <iostream>
using namespace std;

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;


    int** arr = new int*[size];

    for (int i = 0; i < size; i++) {
        arr[i] = new int;
        cout << "Enter the element for index " << i+1 << ": ";
        cin >> *arr[i];
    }


    cout << "Array elements are:" << endl;
    for (int i = 0; i < size; i++) {
        cout << *arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}
