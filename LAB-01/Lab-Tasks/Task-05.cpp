// Name: Maaz Iqbal
// Roll No: 24k-0542

#include <iostream>
using namespace std;

int main() {
    int team1count, team2count;

    cout << "Enter the number of members in Team One: ";
    cin >> team1count;

    cout << "Enter the number of members in Team Two: ";
    cin >> team2count;

    cout << "\nTeam Participation Chart:\n";

    cout << "Team One: ";
    for (int i = 0; i < team1count; i++) {
        cout << "*";
    }
    cout << endl;

    cout << "Team Two: ";
    for (int i = 0; i < team2count; i++) {
        cout << "*";
    }
    
    return 0;
}
