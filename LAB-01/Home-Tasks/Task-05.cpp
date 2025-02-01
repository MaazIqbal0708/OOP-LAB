// Name: Maaz Iqbal
// ROll no: 24k-0542

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int cityAQI[4][28];
    float weeklyAvg[4][4] = {0};
    int highestAQI[4] = {INT_MIN};
    int lowestAQI[4] = {INT_MAX};
    bool criticalDays[4][28] = {false};

    for (int i = 0; i < 4; i++) {
        cout << "Enter AQI values for City " << i + 1 << " over 28 days:\n";
        for (int j = 0; j < 28; j++) {
            cout << "Day " << j + 1 << ": ";
            cin >> cityAQI[i][j];

            if (cityAQI[i][j] > highestAQI[i]) {
                highestAQI[i] = cityAQI[i][j];
            }
            if (cityAQI[i][j] < lowestAQI[i]) {
                lowestAQI[i] = cityAQI[i][j];
            }

            if (cityAQI[i][j] > 150) {
                criticalDays[i][j] = true;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            weeklyAvg[i][0] += cityAQI[i][j];
            weeklyAvg[i][1] += cityAQI[i][7 + j];
            weeklyAvg[i][2] += cityAQI[i][14 + j];
            weeklyAvg[i][3] += cityAQI[i][21 + j];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            weeklyAvg[i][j] /= 7.0;
        }
    }

    cout << "\n--- AQI Report ---\n";

    for (int i = 0; i < 4; i++) {
        cout << "\nCity " << i + 1 << " Weekly Averages:\n";
        for (int j = 0; j < 4; j++) {
            cout << "Week " << j + 1 << ": " << weeklyAvg[i][j] << endl;
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << "\nCritical Pollution Days for City " << i + 1 << " (AQI > 150):\n";
        for (int j = 0; j < 28; j++) {
            if (criticalDays[i][j]) {
                cout << "Day " << j + 1 << " (AQI: " << cityAQI[i][j] << ")\n";
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << "\nCity " << i + 1 << " - Highest AQI: " << highestAQI[i] 
             << ", Lowest AQI: " << lowestAQI[i] << endl;
    }

    return 0;
}
