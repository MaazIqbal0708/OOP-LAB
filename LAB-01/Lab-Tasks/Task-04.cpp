// Name: Maaz Iqbal
// ROll no: 24k-0542

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int totalParticipants = 5;
    char teamA[totalParticipants][100], teamB[totalParticipants][100];

    cout << "Enter the names of participants for Team A:\n";
    for (int i = 0; i < totalParticipants; i++) {
        cout << "Participant " << i + 1 << ": ";
        cin.getline(teamA[i], 100);
    }

    cout << "\nEnter the names of participants for Team B:\n";
    for (int i = 0; i < totalParticipants; i++) {
        cout << "Participant " << i + 1 << ": ";
        cin.getline(teamB[i], 100);
    }

    cout << "\nParticipants for Team A (in reverse order):\n";
    for (int i = totalParticipants - 1; i >= 0; i--) {
        cout << teamA[i] << endl;
    }

    cout << "\nParticipants for Team B (in reverse order):\n";
    for (int i = totalParticipants - 1; i >= 0; i--) {
        cout << teamB[i] << endl;
    }

    return 0;
}

