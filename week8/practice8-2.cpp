//Week 8_練習二：經典的鐵軌問題
#include <iostream>

#define STACK_SIZE 100
using namespace std;

class Stack {
    int top;
    int data[STACK_SIZE];
public:
    bool isEmpty() {
        return (top == -1) ? 1 : 0;
    }

    bool isFull() {
        return (top == STACK_SIZE - 1) ? 1 : 0;
    }

    bool push(int pushNumber) {
        if (isFull() == 1)return false;
        data[++top] = pushNumber;
        return true;
    }
    bool pop(int &changeNum) {
        if (isEmpty() == 1)return false;
        changeNum = data[top--];
        return true;
    }
    bool pop() {
        if (isEmpty() == 1)return false;
        top--;
        return true;
    }
    Stack() {
        top = -1;
    }
};

int main() {
    int size;
    cin >> size;
    while (true) {
        int highestNum = 0;
        Stack middleStation;
        bool exit = false;
        bool isValid = true;
        for (int i = 0; i < size; i++) {
            int num;
            cin >> num;
            if (num == -1) {
                exit = true;
                break;
            }
            if (num > highestNum) {
                for (int j = highestNum + 1; j <= num; j++) {
                    middleStation.push(j);
                }
                highestNum = num;
                middleStation.pop();
            } else {
                int tempNum = -1;
                bool foundTheNum = false;
                while (middleStation.pop(tempNum)) {
                    if (tempNum == num) {
                        foundTheNum = true;
                        break;
                    }
                }
                if (!foundTheNum) {
                    isValid = false;
                }
            }
        }
        if (exit)break;
        (isValid) ? cout << "YES\n" : cout << "NO\n";
    }
}