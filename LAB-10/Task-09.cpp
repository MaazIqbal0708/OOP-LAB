#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile("large_log.txt");
    
    char buffer[20];
    inFile.read(buffer, 19);
    buffer[19] = '\0';
    cout << inFile.tellg() << endl;
    
    inFile.read(buffer, 19);
    buffer[19] = '\0';
    cout << inFile.tellg() << endl;
    
    string line;
    getline(inFile, line);
    cout << inFile.tellg() << endl;
    
    inFile.close();
    return 0;
}