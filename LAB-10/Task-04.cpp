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

            if (Type == "AutonomousCar") {
                size_t colonPos = ExtraData.find(':');
                if (colonPos != string::npos) {
                    string versionStr = ExtraData.substr(colonPos + 1);
                    float softwareVersion = stof(versionStr);
                    cout << "AutonomousCar ID: " << ID << " Software Version: " << softwareVersion << endl;
                }
            }
            else if (Type == "ElectricVehicle") {
                size_t colonPos = ExtraData.find(':');
                if (colonPos != string::npos) {
                    string capacityStr = ExtraData.substr(colonPos + 1);
                    int batteryCapacity = stoi(capacityStr);
                    cout << "ElectricVehicle ID: " << ID << " Battery Capacity: " << batteryCapacity << endl;
                }
            }

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