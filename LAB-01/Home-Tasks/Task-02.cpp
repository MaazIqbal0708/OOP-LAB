// Name: Maaz Iqbal
// ROll no: 24k-0542

#include <iostream>
using namespace std;

int main() {
    int cityAQI[4][7];
    int totalAQI[4] = {0};
    int mostPollutedCity = 0;

    for (int i = 0; i < 4; i++) {
        cout << "Enter AQI readings for City " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "Day " << j + 1 << ": ";
            cin >> cityAQI[i][j];
            totalAQI[i] += cityAQI[i][j];
        }
    }

    cout << "\nAverage AQI for each city:\n";
    for (int i = 0; i < 4; i++) {
        int avgAQI = totalAQI[i] / 7;
        cout << "City " << i + 1 << ": " << avgAQI << endl;

        if (avgAQI > totalAQI[mostPollutedCity] / 7) {
            mostPollutedCity = i;
        }
    }

    cout << "\nCity " << mostPollutedCity + 1 << " has the worst air quality.\n";

    cout << "\nCritical Pollution Days (AQI > 150) for each city:\n";
    for (int i = 0; i < 4; i++) {
        bool foundCritical = false;
        cout << "City " << i + 1 << ": ";
        for (int j = 0; j < 7; j++) {
            if (cityAQI[i][j] > 150) {
                cout << "Day " << j + 1 << " ";
                foundCritical = true;
            }
        }
        if (!foundCritical) {
            cout << "No critical days.";
        }
        cout << endl;
    }

    return 0;
}
