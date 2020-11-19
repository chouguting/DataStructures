#include <iostream>
#include <cstring>

using namespace std;

struct listNode {
    int data;
    listNode *nextPtr;
};

class LinkedStack {
public:
    listNode *topPtr;

    LinkedStack() {
        topPtr = nullptr;
    }

    void push(int newNum) {
        listNode *temp = new listNode;
        temp->data = newNum;
        temp->nextPtr = topPtr;
        topPtr = temp;
    }

    bool pop(int *popedNum) {
        if (isEmpty())return false;
        listNode *temp = topPtr;
        *popedNum = topPtr->data;
        topPtr = topPtr->nextPtr;
        delete (temp);
        return true;
    }

    bool isEmpty() {
        if (topPtr == nullptr)return true;
        return false;
    }

    void printList() {
        for (listNode *i = topPtr; i != nullptr; i = i->nextPtr) {
            cout << i->data << endl;
        }
    }
};

class LinkedQueue {
public:
    listNode *frontPtr;
    listNode *rearPtr;

    LinkedQueue() {
        frontPtr = NULL;
        rearPtr = NULL;
    }

    bool isEmpty() {
        if (frontPtr == NULL)return true;
        return false;
    }

    void addQ(int newNum) {
        listNode *temp = new listNode;
        temp->data = newNum;
        temp->nextPtr = NULL;
        if (frontPtr == NULL) {
            frontPtr = temp;
        } else {
            rearPtr->nextPtr = temp;
        }
        rearPtr = temp;
    }

    bool deleteQ(int *deletedNum) {
        if (isEmpty())return false;
        listNode *temp = frontPtr;
        *deletedNum = temp->data;
        frontPtr = frontPtr->nextPtr;
        delete (temp);
        return true;
    }

    void printList() {
        for (listNode *i = frontPtr; i != nullptr; i = i->nextPtr) {
            cout << i->data << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Stack:" << endl;
    LinkedStack linkedStack;
    linkedStack.push(5);
    linkedStack.push(4);
    linkedStack.push(-1);
    linkedStack.printList();
    int a;
    linkedStack.pop(&a);
    cout << "popped:" << a << endl;
    linkedStack.printList();

    cout << endl << "Queue:" << endl;
    LinkedQueue linkedQueue;
    linkedQueue.addQ(6);
    linkedQueue.addQ(4);
    linkedQueue.addQ(2);
    linkedQueue.addQ(5);
    linkedQueue.printList();

    linkedQueue.deleteQ(&a);
    cout << "popped:" << a << endl;
    linkedQueue.printList();

}