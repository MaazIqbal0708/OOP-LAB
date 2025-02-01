// Name: Maaz Iqbal
// ROll no: 24k-0542    

#include <iostream>
using namespace std;

int main() {
    int cityAQI[4][7];

    for (int i = 0; i < 4; i++) {
        cout << "Enter AQI readings for City " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "Day " << j + 1 << ": ";
            cin >> cityAQI[i][j];
        }
    }

    cout << "\nAQI Levels for each city over the week (Each '*' represents 50 AQI):\n";
    for (int i = 0; i < 4; i++) {
        cout << "City " << i + 1 << ": ";
        for (int j = 0; j < 7; j++) {
            int stars = cityAQI[i][j] / 50;
            for (int k = 0; k < stars; k++) {
                cout << "*";
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
