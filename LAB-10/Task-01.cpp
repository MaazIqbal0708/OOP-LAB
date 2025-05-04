#include <iostream>
#include <fstream>
#include <string>

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
        int lineNumber = 0;

        while (getline(inputFile, line)) {
            lineNumber++;

            if (line.empty() || line[0] == '#') {
                continue;
            }

            cout << "Line " << lineNumber << ": " << line << endl;
        }

        inputFile.close();
    }
};

int main() {
    FileReader fileReader("vehicles.txt");
    fileReader.readFile();
    return 0;
}