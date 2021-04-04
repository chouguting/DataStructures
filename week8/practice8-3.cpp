//Week 8_練習三：後序運算式求值
#include <iostream>
#include <cstring>

#define STACK_SIZE 100
using namespace std;

class Stack {
public:
    int top;
    int data[STACK_SIZE];

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

    int pop() {
        if (isEmpty() == 1)return 0;
        return data[top--];
    }

    Stack() {
        top = -1;
    }
};

int main() {
    Stack dataSet;
    char theStr[500];
    fgets(theStr, 500, stdin);
    strtok(theStr, "\r\n");
    char *p = strtok(theStr, " ");
    int length = strlen(theStr);
    while (p != NULL) {
        if (p[0] == '+') {
            dataSet.push(dataSet.pop() + dataSet.pop());
        } else if (p[0] == '-') {
            int a = dataSet.pop();
            int b = dataSet.pop();
            dataSet.push(b - a);
        } else if (p[0] == '*') {
            dataSet.push(dataSet.pop() * dataSet.pop());
        } else if (p[0] == '/') {
            int a = dataSet.pop();
            int b = dataSet.pop();
            dataSet.push(b / a);
        } else if (p[0] == '%') {
            int a = dataSet.pop();
            int b = dataSet.pop();
            dataSet.push(b % a);
        } else {
            dataSet.push(stoi(p));
        }

        p = strtok(NULL, " ");
    }
    cout << dataSet.pop() << endl;
}