// Maaz Iqbal
// 24k-0542

#include <iostream>
using namespace std;

int main() {
    int arrSize;

    cout << "Enter the size of the array: ";
    cin >> arrSize;

    int* numbers = new int[arrSize];

    cout << "Enter the elements of the array:" << endl;
    for (int index = 0; index < arrSize; index++) {
        cin >> numbers[index];
    }

    cout << "Array elements are:" << endl;
    for (int* numPtr = numbers; numPtr < numbers + arrSize; numPtr++) {
        cout << *numPtr << " ";
    }
    cout << endl;

    int Sum = 0;
    for (int* numPtr = numbers; numPtr < numbers + arrSize; numPtr++) {
        Sum += *numPtr;
    }

    cout << "Sum of the array elements: " << Sum << endl;
    delete[] numbers;

    return 0;
}
