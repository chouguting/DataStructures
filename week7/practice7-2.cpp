//Week 7_練習二：環狀佇列
#include <iostream>

using namespace std;

class CircularQueue {
    int *data;
    int maxSize;
    int front;
    int rear;
public:
    CircularQueue(int maxSize) : maxSize(maxSize) {
        data = new int[maxSize];
        front = 0;
        rear = 0;
    }

    bool isFull() {
        return ((rear + 1) % maxSize == front) ? true : false;
    }

    bool isEmpty() {
        return (rear == front) ? true : false;
    }

    bool enqueue(int insertNum) {
        if (isFull())return false;
        rear = (rear + 1) % maxSize;
        data[rear] = insertNum;
        return true;
    }

    bool dequeue(int &dequeuedNum) {
        if (isEmpty())return false;
        front = (front + 1) % maxSize;
        dequeuedNum = data[front];
        return true;
    }
};

int main() {
    int size;
    cin >> size;
    CircularQueue circularQueue(size);
    while (true) {
        int opCode;
        cin >> opCode;
        if (opCode == -1)break;
        if (opCode == 1) {
            int insertNum;
            cin >> insertNum;
            if (!circularQueue.enqueue(insertNum)) {
                cout << "FULL\n";
            }
        } else {
            int dequeuedNum;
            if (!circularQueue.dequeue(dequeuedNum)) {
                cout << "EMPTY\n";
            } else {
                cout << dequeuedNum << "\n";
            }
        }
    }
}