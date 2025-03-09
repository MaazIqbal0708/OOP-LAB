#include <iostream>
#include <string>

using namespace std;

const int MAX_DAYS = 365;

class FitnessTracker {
private:
    string userName;
    int dailyStepGoal;
    int stepsTaken[MAX_DAYS];
    double caloriesBurned[MAX_DAYS];
    int dayCount;

public:
    FitnessTracker(string name, int goal) : userName(name), dailyStepGoal(goal), dayCount(0) {}

    void logSteps(int steps, double calories) {
        if (dayCount >= MAX_DAYS) {
            cout << "Cannot log more days!" << endl;
            return;
        }
        stepsTaken[dayCount] = steps;
        caloriesBurned[dayCount] = calories;
        dayCount++;
    }

    void displayProgress() {
        for (int i = 0; i < dayCount; ++i) {
            cout << "Day " << i + 1 << ": Steps = " << stepsTaken[i] << ", Calories Burned = " << caloriesBurned[i] << endl;
        }
    }

    void checkGoal() {
        if (dayCount == 0) {
            cout << "No data available!" << endl;
            return;
        }
        int lastDay = dayCount - 1;
        if (stepsTaken[lastDay] >= dailyStepGoal) {
            cout << "Goal met for the day!" << endl;
        } else {
            cout << "Goal not met for the day." << endl;
        }
    }
};

int main() {
    FitnessTracker laibaTracker("Laiba", 10000);
    laibaTracker.logSteps(12000, 300);
    laibaTracker.logSteps(8000, 200);
    laibaTracker.displayProgress();
    laibaTracker.checkGoal();
    return 0;
}
