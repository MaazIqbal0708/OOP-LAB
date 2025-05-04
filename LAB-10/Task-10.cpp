#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream file("data_records.txt", ios::in | ios::out | ios::ate);
    
    file << "Record 5" << endl;
    streampos endPos = file.tellp();
    
    file.seekg(0);
    string line;
    while(getline(file, line)) {
        cout << line << endl;
    }
    
    cout << "End position: " << endPos << endl;
    file.close();
    return 0;
}