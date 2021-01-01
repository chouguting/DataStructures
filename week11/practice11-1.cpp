#include <iostream>
#include <cstring>

using namespace std;

class LinkedList {
    struct listNode {
        int data;
        listNode *nextPtr;
    };
    listNode *frontPtr;
public:
    LinkedList() {
        frontPtr = nullptr;
    }

    void invert() {
        listNode *lead = frontPtr;
        listNode *middle, *trail;
        middle = nullptr;
        while (lead != nullptr) {
            trail = middle;
            middle = lead;
            lead = lead->nextPtr;
            middle->nextPtr = trail;
        }
        frontPtr = middle;
    }

    void add(int newNum) {
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
            cout << i->data;
            if (i->nextPtr != nullptr)cout << " ";
        }
        cout << endl;
    }
};

int main() {
    int input;
    LinkedList linkedList;
    char inputs[100];
    fgets(inputs, 100, stdin);
    strtok(inputs, "\r\n");
    char *p = strtok(inputs, " ");
    while (p != nullptr) {
        input = stoi(p);
        linkedList.add(input);
        p = strtok(nullptr, " ");
    }
    linkedList.invert();
    linkedList.printList();
}