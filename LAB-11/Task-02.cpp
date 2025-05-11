#include <iostream>
#include <stdexcept>

using namespace std;

class QueueOverflowError : public exception {};
class QueueUnderflowError : public exception {};

template <typename T>
class FixedQueue {
private:
    T* elements;
    int maxSize;
    int head;
    int tail;
    int currentSize;

    void validateCapacity() const {
        if (maxSize <= 0) {
            throw invalid_argument("Queue capacity must be positive");
        }
    }

public:
    FixedQueue(int capacity) : maxSize(capacity), head(0), tail(-1), currentSize(0) {
        validateCapacity();
        elements = new T[maxSize];
    }

    ~FixedQueue() {
        delete[] elements;
    }

    FixedQueue(const FixedQueue&) = delete;
    FixedQueue& operator=(const FixedQueue&) = delete;

    void push(const T& value) {
        if (full()) {
            throw QueueOverflowError();
        }
        
        tail = (tail + 1) % maxSize;
        elements[tail] = value;
        currentSize++;
    }

    T pop() {
        if (empty()) {
            throw QueueUnderflowError();
        }
        
        T value = elements[head];
        head = (head + 1) % maxSize;
        currentSize--;
        return value;
    }

    bool empty() const {
        return currentSize == 0;
    }

    bool full() const {
        return currentSize == maxSize;
    }

    int size() const {
        return currentSize;
    }

    int capacity() const {
        return maxSize;
    }
};

int main() {
    try {
        FixedQueue<int> q(2);
        q.push(10);
        q.push(20);
        cout << "Trying to push to full queue..." << endl;
        q.push(30);
    }
    catch (const QueueOverflowError& e) {
        cerr << "Caught QueueOverflowError - what(): " << e.what() << endl;
    }

    try {
        FixedQueue<string> q(3);
        cout << "Trying to pop from empty queue..." << endl;
        string val = q.pop();
    }
    catch (const QueueUnderflowError& e) {
        cerr << "Caught QueueUnderflowError - what(): " << e.what() << endl;
    }

    FixedQueue<char> charQueue(3);
    charQueue.push('A');
    charQueue.push('B');
    cout << "Popped: " << charQueue.pop() << endl;
    charQueue.push('C');
    
    return 0;
}