#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class FileReader {
private:
    ifstream inputFile;
    string filename;

public:
    FileReader(const string& fname) : filename(fname) {}

    void readFile() {
        inputFile.open(filename);

        if (!inputFile.is_open()) {
            cerr << "Error: Could not open file '" << filename << "'" << endl;
            return;
        }

        string line;

        while (getline(inputFile, line)) {
            if (line.empty() || line[0] == '#') {
                continue;
            }

            istringstream iss(line);
            string Type, ID, Name, YearStr, ExtraData, Certification;
            int Year;

            getline(iss, Type, ',');
            getline(iss, ID, ',');
            getline(iss, Name, ',');
            getline(iss, YearStr, ',');
            getline(iss, ExtraData, ',');
            getline(iss, Certification, ',');

            Year = stoi(YearStr);

            cout << "Type: " << Type << endl;
            cout << "ID: " << ID << endl;
            cout << "Name: " << Name << endl;
            cout << "Year (int): " << Year << endl;
            cout << "ExtraData: " << ExtraData << endl;
            cout << "Certification: " << Certification << endl;
            cout << "---------------------" << endl;
        }

        inputFile.close();
    }
};

int main() {
    FileReader fileReader("vehicles.txt");
    fileReader.readFile();
    return 0;
}