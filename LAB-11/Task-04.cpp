#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class DatabaseError : public exception {
public:
    const char* what() const noexcept override {
        return "A database operation failed";
    }
};

class ConnectionError : public DatabaseError {};
class QueryExecutionError : public DatabaseError {};
class TimeoutError : public QueryExecutionError {};

template <typename T>
class DatabaseHandler {
private:
    bool simulateConnectionIssue(const string& dbName) {
        return dbName == "broken_connection" || dbName.empty();
    }

    bool simulateTimeout(const string& query) {
        return query == "complex_join" || query == "large_scan";
    }

public:
    void establishConnection(const string& dbName) {
        if (simulateConnectionIssue(dbName)) {
            throw ConnectionError();
        }
        cout << "Connected to: " << dbName << endl;
    }

    T execute(const string& query) {
        if (simulateTimeout(query)) {
            throw TimeoutError();
        }
        cout << "Executed: " << query << endl;
        return T();
    }
};

void testDatabaseOperations() {
    DatabaseHandler<string> db;

    try {
        cout << "Trying to connect to broke connection..." << endl;
        db.establishConnection("broken_connection");
    }
    catch (const ConnectionError& e) {
        cerr << "CaughtConnection Error - what(): " << e.what() << endl;
    }

    try {
        cout << "Trying to connect to validdb..." << endl;
        db.establishConnection("valid_db");
        
        cout << "Trying to execute complex_join.." << endl;
        auto result = db.execute("complex_join");
    }
    catch (const TimeoutError& e) {
        cerr << "Caught Timeout Error - what(): " << e.what() << endl;
    }
    catch (const DatabaseError& e) {
        cerr << "Caught DatabaseError - what(): " << e.what() << endl;
    }
}

int main() {
    testDatabaseOperations();
    return 0;
}