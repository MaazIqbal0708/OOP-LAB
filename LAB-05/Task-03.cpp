#include <iostream>
using namespace std;

class Worker {
public:
    string workerName;
    string jobTitle;

    Worker(const string& workerName, const string& jobTitle)
        : workerName(workerName), jobTitle(jobTitle) {}
};

class Assignment {
public:
    string taskName;
    string dueDate;
    Worker* team[10]; 
    int teamSize;

    Assignment(string taskName, string dueDate) : taskName(taskName), dueDate(dueDate), teamSize(0) {}

    void assignWorker(Worker* worker) {
        if (teamSize < 10) {
            team[teamSize++] = worker;
        } else {
            cout << "Cannot add more workers to this assignment." << endl;
        }
    }

    void showDetails() const {
        cout << "Task: " << taskName << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Assigned Workers:" << endl;
        for (int i = 0; i < teamSize; ++i) {
            cout << team[i]->workerName << " (" << team[i]->jobTitle << ")" << endl;
        }
    }
};

int main() {
    Worker worker1("Muhammad Burair", "Engineer");
    Worker worker2("Talha Shahid", "Designer");

    Assignment task1("Software Development", "2025-06-01");
    Assignment task2("UI/UX Enhancement", "2026-08-15");

    task1.assignWorker(&worker1);
    task1.assignWorker(&worker2);
    task2.assignWorker(&worker2);

    cout << "Task 1 Details:" << endl;
    task1.showDetails();
    cout << endl;

    cout << "Task 2 Details:" << endl;
    task2.showDetails();

    return 0;
}
