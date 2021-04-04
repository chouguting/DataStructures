//Week 10_練習一：建立鏈結與在不同位置插入數值
#include <iostream>

using namespace std;

struct listNode {
    int data;
    listNode *nextPtr;
};

class LinkedList {
public:
    listNode *frontPtr;

    LinkedList() {
        frontPtr = nullptr;
    }

    void addFromFront(int newNum) {
        listNode *temp = new listNode;
        temp->data = newNum;
        temp->nextPtr = frontPtr;
        frontPtr = temp;
    }

    void addFromMiddle(int newNum, int index) {
        listNode *temp = new listNode;
        int i = 0;
        listNode *locator = frontPtr;
        while (i < index - 1) {
            locator = frontPtr->nextPtr;
            i++;
        }
        temp->data = newNum;
        temp->nextPtr = locator->nextPtr;
        locator->nextPtr = temp;
    }

    void addFromRear(int newNum) {
        listNode *locator = frontPtr;
        while (frontPtr != nullptr && locator->nextPtr != nullptr) {
            locator = locator->nextPtr;
        }
        listNode *temp = new listNode;
        temp->nextPtr = nullptr;
        temp->data = newNum;
        if (frontPtr == nullptr) {
            frontPtr = temp;
        } else {
            locator->nextPtr = temp;
        }

    }

    void printList() {
        for (listNode *i = frontPtr; i != nullptr; i = i->nextPtr) {
            cout << i->data << " ";
            if (i->nextPtr != nullptr)cout << " ";
        }
        cout << endl;
    }
};

int main() {
    int times;
    cin >> times;
    for (int t = 0; t < times; t++) {
        LinkedList linkedList;
        while (true) {
            char opCode;
            cin >> opCode;
            if (opCode == 'f') {
                int inputNum;
                cin >> inputNum;
                getchar();
                linkedList.addFromFront(inputNum);
            } else if (opCode == 'a') {
                int inputNum;
                cin >> inputNum;
                getchar();
                linkedList.addFromRear(inputNum);
            } else if (opCode == 'i') {
                int inputNum, index;
                cin >> inputNum >> index;
                getchar();
                linkedList.addFromMiddle(inputNum, index);
            } else if (opCode == 'q') {
                break;
            }
            cout << "Created Linked list is:  ";
            linkedList.printList();
        }
        if (t != times - 1)cout << endl;
    }
}