// Name: Maaz Iqbal
// Roll No: 24k-0542

#include <iostream>
using namespace std;

int main() {
    int cityAQI[4][28];
    float avgMonthlyAQI[4] = {0};
    float avgFirstWeek[4] = {0};
    float avgLastWeek[4] = {0};

    for (int i = 0; i < 4; i++) {
        cout << "Enter AQI values for City " << i + 1 << " over 28 days:\n";
        for (int day = 0; day < 28; day++) {
            cout << "Day " << day + 1 << ": ";
            cin >> cityAQI[i][day];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int day = 0; day < 28; day++) {
            avgMonthlyAQI[i] += cityAQI[i][day];
        }
        avgMonthlyAQI[i] /= 28;
    }

    for (int i = 0; i < 4; i++) {
        for (int day = 0; day < 7; day++) {
            avgFirstWeek[i] += cityAQI[i][day];
        }
        avgFirstWeek[i] /= 7;

        for (int day = 21; day < 28; day++) {
            avgLastWeek[i] += cityAQI[i][day];
        }
        avgLastWeek[i] /= 7;
    }

    cout << "\nMonthly Average AQI for each city:\n";
    for (int i = 0; i < 4; i++) {
        cout << "City " << i + 1 << ": " << avgMonthlyAQI[i] << endl;
    }

    int improvedCity = 0;
    float highestImprovement = avgFirstWeek[0] - avgLastWeek[0];

    for (int i = 1; i < 4; i++) {
        float improvement = avgFirstWeek[i] - avgLastWeek[i];
        if (improvement > highestImprovement) {
            highestImprovement = improvement;
            improvedCity = i;
        }
    }

    cout << "\nCity with the most improved air quality: City " << improvedCity + 1 << endl;

    return 0;
}