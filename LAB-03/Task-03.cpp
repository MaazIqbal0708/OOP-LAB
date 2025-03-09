#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 1000;

class Library {
private:
    string bookList[MAX_BOOKS];
    bool borrowedBooks[MAX_BOOKS];
    int bookCount;

public:
    Library() : bookCount(0) {
        for (int i = 0; i < MAX_BOOKS; ++i) {
            borrowedBooks[i] = false;
        }
    }

    void addBook(string bookName) {
        if (bookCount >= MAX_BOOKS) {
            cout << "Cannot add more books!" << endl;
            return;
        }
        bookList[bookCount++] = bookName;
    }

    void lendBook(string bookName) {
        for (int i = 0; i < bookCount; ++i) {
            if (bookList[i] == bookName && !borrowedBooks[i]) {
                borrowedBooks[i] = true;
                cout << "Book lent: " << bookName << endl;
                return;
            }
        }
        cout << "Book not available!" << endl;
    }

    void returnBook(string bookName) {
        for (int i = 0; i < bookCount; ++i) {
            if (bookList[i] == bookName && borrowedBooks[i]) {
                borrowedBooks[i] = false;
                cout << "Book returned: " << bookName << endl;
                return;
            }
        }
        cout << "Book not found or already returned!" << endl;
    }

    void displayAvailableBooks() {
        cout << "Available Books:" << endl;
        for (int i = 0; i < bookCount; ++i) {
            if (!borrowedBooks[i]) {
                cout << bookList[i] << endl;
            }
        }
    }
};

int main() {
    Library peshawarLibrary;
    peshawarLibrary.addBook("C++ Programming");
    peshawarLibrary.addBook("Data Structures");
    peshawarLibrary.lendBook("C++ Programming");
    peshawarLibrary.displayAvailableBooks();
    peshawarLibrary.returnBook("C++ Programming");
    peshawarLibrary.displayAvailableBooks();
    return 0;
}
