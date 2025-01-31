// Name: Maaz Iqbal
// Roll No: 24k-0542

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const int maxParticipants = 5;
    char firstEvent[maxParticipants][100], secondEvent[maxParticipants][100];
    char participantName[100];
    bool isRegistered = false;

    cout << "Enter the names of participants for the first event:\n";
    for (int i = 0; i < maxParticipants; i++)
    {
        cout << "Enter participant " << i + 1 << ": ";
        cin.getline(firstEvent[i], 100);
    }

    cout << "\nEnter the names of participants for the second event:\n";
    for (int i = 0; i < maxParticipants; i++)
    {
        cout << "Enter participant " << i + 1 << ": ";
        cin.getline(secondEvent[i], 100);
    }

    cout << "\nEnter the name of the participant to search for: ";
    cin.getline(participantName, 100);

    for (int i = 0; i < maxParticipants; i++)
    {
        if (strcmp(firstEvent[i], participantName) == 0)
        {
            isRegistered = true;
            break;
        }
    }

    if (!isRegistered)
    {
        for (int i = 0; i < maxParticipants; i++)
        {
            if (strcmp(secondEvent[i], participantName) == 0)
            {
                isRegistered = true;
                break;
            }
        }
    }

    if (isRegistered)
    {
        cout << participantName << " is registered for one of the events.\n";
    }
    else
    {
        cout << participantName << " is not registered for any event.\n";
    }

    return 0;
}

