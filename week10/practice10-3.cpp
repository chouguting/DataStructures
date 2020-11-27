#include <iostream>
#include <cstring>

using namespace std;

struct listNode {
    char data[500];
    listNode *nextPtr;
};

class LinkedStack {
public:
    listNode *topPtr;

    LinkedStack() {
        topPtr = nullptr;
    }

    void push(char *theStr) {
        listNode *temp = new listNode;
        strcpy(temp->data, theStr);
        temp->nextPtr = topPtr;
        topPtr = temp;
    }

    void pushUnique(char *newString) {
        listNode *locator = topPtr;
        listNode *prior = nullptr;
        bool firstTime = true;
        while (locator != nullptr) {
            if (locator != topPtr) {
                if (firstTime) {
                    prior = topPtr;
                    firstTime = false;
                } else {
                    prior = prior->nextPtr;
                }

            }
            if (strcmp(locator->data, newString) == 0) {
                break;
            }
            locator = locator->nextPtr;
        }
        if (locator == nullptr) {
            push(newString);
            return;
        }

        listNode *temp;
        if (prior == nullptr) {
            temp = topPtr;
            topPtr = topPtr->nextPtr;
        } else {
            temp = locator;
            prior->nextPtr = locator->nextPtr;
        }
        delete (temp);
    }

    int countLeft() {
        int count = 0;
        for (listNode *i = topPtr; i != nullptr; i = i->nextPtr) {
            count++;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    getchar();
    getchar();
    int piles[n];
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
        getchar();
        getchar();
    }

    for (int i = 0; i < n; i++) {
        LinkedStack linkedStack;
        for (int j = 0; j < piles[i]; j++) {
            char theStr[500];
            fgets(theStr, 500, stdin);
            strtok(theStr, "\r\n");
            linkedStack.pushUnique(theStr);
        }
        cout << linkedStack.countLeft() << endl;
    }
}