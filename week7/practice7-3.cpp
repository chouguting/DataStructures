#include <iostream>

using namespace std;
#define STACK_SIZE 100
typedef struct {
    int Y;
    int X;
} point;

class Stack {
    int top;
    point data[STACK_SIZE];
public:
    bool isEmpty() {
        return (top == -1) ? 1 : 0;
    }

    bool isFull() {
        return (top == STACK_SIZE - 1) ? 1 : 0;
    }

    bool push(point pushNumber) {
        if (isFull() == 1)return false;
        data[++top] = pushNumber;
        return true;
    }

    bool pop(point &changeNum) {
        if (isEmpty() == 1)return false;
        changeNum = data[top--];
        return true;
    }

    Stack() {
        top = -1;
    }
};

point direction[4] = {{0,  1},
                      {-1, 0},
                      {0,  -1},
                      {1,  0}};

int main() {
    point current = {8, 8};
    Stack roadRecord;
    char theMatrix[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> theMatrix[i][j];
        }
    }
    theMatrix[current.Y][current.X] = 'S';
    bool success = true;
    while (current.Y != 1 || current.X != 1) {
        bool hasMoved = false;
        for (int i = 0; i < 4; i++) {
            if (theMatrix[current.Y + direction[i].Y][current.X + direction[i].X] == '0') {
                if (theMatrix[current.Y][current.X] == '0') {
                    theMatrix[current.Y][current.X] = 'G';
                }
                roadRecord.push(current);
                current.Y = current.Y + direction[i].Y;
                current.X = current.X + direction[i].X;
                hasMoved = true;
                break;
            }
        }
        if (hasMoved)continue;
        theMatrix[current.Y][current.X] = 'D';
        if (!roadRecord.pop(current)) {
            cout << "NO\n";
            success = false;
            break;
        }
    }
    if (success)cout << "YES\n";
    theMatrix[1][1] = 'X';
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << theMatrix[i][j];
            if (j != 9)cout << " ";
        }
        cout << endl;
    }
}