#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream file("config.txt", ios::in | ios::out);
    
    file.seekp(5);
    file << "XXXXX";
    
    file.seekg(0);
    string content;
    getline(file, content);
    cout << content << endl;
    
    file.close();
    return 0;
}