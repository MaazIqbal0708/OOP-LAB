// Name: Maaz Iqbal
// Roll No: 24k-0542

#include <iostream>
using namespace std;

void collectNames(char group[][100], const string &groupName, int maxsize) {
    int size;
    cout << "Enter the names of participants for " << groupName << " (Max " << maxsize << " participants):" << endl;
    cin >> size;
    cin.ignore();

    for (int i = 0; i < size; i++) {
        cout << "Enter name " << i + 1 << ": ";
        cin.getline(group[i], 100);
    }
}

void showParticipants(const char group[][100], const string &groupName, int size) {
    cout << "\nParticipants for " << groupName << ":\n";
    for (int i = 0; i < size; i++) {
        if(group[i][0] == '\0') break;
        cout << group[i] << endl;
    }
}

int main() {
    const int maxSize = 5;
    char groupA[maxSize][100], groupB[maxSize][100];

    collectNames(groupA, "Group A", maxSize);
    collectNames(groupB, "Group B", maxSize);

    showParticipants(groupA, "Group A", maxSize);
    showParticipants(groupB, "Group B", maxSize);

    return 0;
}
