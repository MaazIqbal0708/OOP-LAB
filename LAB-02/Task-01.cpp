// Maaz Iqbal
// 24k-0542

#include <iostream>
#include <string>
using namespace std;

struct LibraryBook {
    string bookTitle;
    string writer;
    int publishYear;
};

int main() {
    int totalBooks;
    cout << "How many books do you want to enter? ";
    cin >> totalBooks;
    cin.ignore(); 

    LibraryBook* bookList = new LibraryBook[totalBooks];
    for (int index = 0; index < totalBooks; index++) {
        cout << "\nEnter details for book " << index + 1 << ":\n";
        cout << "Title: ";
        getline(cin, bookList[index].bookTitle);
        cout << "Author: ";
        getline(cin, bookList[index].writer);
        cout << "Year: ";
        cin >> bookList[index].publishYear;
        cin.ignore();
    }

    int filterYear;
    cout << "\nEnter a year to find books published after that: ";
    cin >> filterYear;

    cout << "\nBooks published after " << filterYear << ":\n";
    bool isFound = false;
    for (int index = 0; index < totalBooks; index++) {
        if (bookList[index].publishYear > filterYear) {
            cout << "Title: " << bookList[index].bookTitle << ", Author: " << bookList[index].writer << ", Year: " << bookList[index].publishYear << endl;
            isFound = true;
        }
    }

    if (!isFound) {
        cout << "Oops! No books found published after " << filterYear << "." << endl;
    }

    delete[] bookList;

    return 0;
}

