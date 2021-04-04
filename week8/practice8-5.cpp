//Week 8_加分題：還是要中序
#include <iostream>
#include <cstring>

#define STACK_SIZE 100
using namespace std;
enum Type {
    preOrder, inOrder, postOrder
};

class Stack {
public:
    int top;
    string data[STACK_SIZE];

    bool isEmpty() {
        return (top == -1) ? 1 : 0;
    }

    bool isFull() {
        return (top == STACK_SIZE - 1) ? 1 : 0;
    }

    bool push(string pushNumber) {
        if (isFull() == 1)return false;
        data[++top] = pushNumber;
        return true;
    }

    void addParentheses(int index) {
        data[index] = "(" + data[index] + ")";
    }

    string pop() {
        if (isEmpty() == 1)return 0;
        return data[top--];
    }

    Stack() {
        top = -1;
    }
};

int main() {
    for (int time = 0; time < 3; time++) {
        Type type;
        Stack dataSet;
        char theStr[500];
        fgets(theStr, 500, stdin);
        strtok(theStr, "\r\n");
        int length = strlen(theStr);
        if (theStr[0] < '0' || theStr[0] > '9') {
            type = preOrder;
        } else if (theStr[length - 1] < '0' || theStr[length - 1] > '9') {
            type = postOrder;
        } else {
            type = inOrder;
            cout << "same\n";
        }

        if (type == preOrder) {
            for (int i = strlen(theStr) - 1; i >= 0; i--) {
                if (theStr[i] >= '0' && theStr[i] <= '9') {
                    dataSet.push(to_string(theStr[i] - '0'));
                } else {
                    string a = dataSet.pop();
                    string b = dataSet.pop();
                    dataSet.push(a + theStr[i] + b);
                    if (i != 0) {
                        dataSet.addParentheses(dataSet.top);
                    }
                }
            }
            cout << dataSet.pop() << endl;
        }

        if (type == postOrder) {
            for (int i = 0; i < strlen(theStr); i++) {
                if (theStr[i] >= '0' && theStr[i] <= '9') {
                    dataSet.push(to_string(theStr[i] - '0'));
                } else {
                    dataSet.push(dataSet.pop() + theStr[i] + dataSet.pop());
                    if (i != strlen(theStr) - 1) {
                        dataSet.addParentheses(dataSet.top);
                    }
                }
            }
            cout << dataSet.pop() << endl;
        }
    }
}