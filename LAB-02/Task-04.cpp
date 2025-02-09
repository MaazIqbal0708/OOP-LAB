// Maaz Iqbal
// 24k-0542

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore();

    string *arr = new string[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, arr[i]);
    }

    sort(arr, arr + n);

    cout << "Sorted strings: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}
