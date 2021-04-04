//Week 8_練習一：中序轉後序
#include <iostream>
#include <cstring>

using namespace std;
#define JAVA for
typedef struct {
    char c;
    int isp;
    int icp;
} ipTable;

class Stack {
    int top;
    ipTable data[100];
public:
    bool isEmpty() {
        return (top == -1) ? 1 : 0;
    }

    bool isFull() {
        return (top == 100 - 1) ? 1 : 0;
    }

    bool canAdd(ipTable pushNumber) {
        if (isEmpty())return true;
        if (data[top].isp >= pushNumber.icp)return false;
        return true;
    }

    bool add(ipTable pushNumber) {
        while (!canAdd(pushNumber)) {
            char ch;
            pop(ch);
            cout << " " << ch;
        }
        push(pushNumber);
        return true;
    }

    bool push(ipTable pushNumber) {
        if (isFull() == 1)return false;
        data[++top] = pushNumber;
        return true;
    }

    bool pop(char &popedNum) {
        if (isEmpty() == 1)return false;
        popedNum = data[top--].c;
        return true;
    }

    Stack() {
        top = -1;
    }
};

int main() {
    int times;
    cin >> times;
    getchar();
    //getchar();
    JAVA (int time = 0; time < times; time++) {
        Stack theStack;
        char theStr[500];
        fgets(theStr, 500, stdin);
        strtok(theStr, "\r\n");
        bool hasPrint = false;
        JAVA (int i = 0; i < strlen(theStr); i++) {
            char temp = 'c';
            if (theStr[i] >= '0' && theStr[i] <= '9') {
                if (hasPrint)cout << " ";
                hasPrint = true;
                cout << theStr[i];
            }
            switch (theStr[i]) {
                case '(':
                    theStack.add({'(', 0, 20});
                    break;
                case ')':
                    while (true) {
                        theStack.pop(temp);
                        if (temp == '(')break;
                        if (i != 0)cout << " ";
                        cout << temp;
                    }
                    break;
                case '+':
                    theStack.add({'+', 12, 12});
                    break;
                case '-':
                    theStack.add({'-', 12, 12});
                    break;
                case '*':
                    theStack.add({'*', 13, 13});
                    break;
                case '/':
                    theStack.add({'/', 13, 13});
                    break;
                case '%':
                    theStack.add({'%', 13, 13});
                    break;
            };
        }
        char temp;
        while (theStack.pop(temp)) {
            if (temp != '(' && temp != ')')cout << " ";
            cout << temp;
        }
        cout << endl;
    }
}