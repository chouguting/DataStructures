//Week 10_練習二：圓桌報數遊戲
#include <iostream>

using namespace std;
struct listNode {
    int data;
    listNode *nextPtr;
};

class LinkedRoundTable {
public:
    listNode *firstPtr;
    listNode *lastPtr;

    LinkedRoundTable() {
        firstPtr = nullptr;
        lastPtr = nullptr;
    }

    void addToN(int n) {
        for (int i = 1; i <= n; i++) {
            listNode *temp = new listNode;
            temp->data = i;
            temp->nextPtr = nullptr;
            if (firstPtr == nullptr) {
                firstPtr = temp;
            } else {
                lastPtr->nextPtr = temp;
            }
            lastPtr = temp;
        }
    }

    void playUntilLastOne(int startWith, int step) {
        listNode *indexer = firstPtr;
        for (int i = 1; i < startWith; i++) {
            indexer = indexer->nextPtr;
        }
        while (firstPtr != lastPtr) {
            listNode *prior;
            listNode *theOne;
            for (int i = 0; i < step;) {
                if (i == step - 2)prior = indexer;
                if (i == step - 1)theOne = indexer;
                if (indexer->nextPtr == nullptr) {
                    indexer = firstPtr;
                } else {
                    indexer = indexer->nextPtr;
                }
                i++;
            }
            cout << popThatOne(theOne, &prior) << " ";
        }
        cout << firstPtr->data << endl;
    }

    int popThatOne(listNode *theOne, listNode **prior) {
        listNode *temp;
        if ((*prior)->nextPtr == nullptr) {
            temp = firstPtr;
            firstPtr = firstPtr->nextPtr;
        } else if (theOne->nextPtr == nullptr) {
            temp = theOne;
            lastPtr = *prior;
            lastPtr->nextPtr = nullptr;
        } else {
            temp = theOne;
            (*prior)->nextPtr = theOne->nextPtr;
        }
        int a = temp->data;
        delete (temp);
        return a;
    }

    void printList() {
        for (listNode *i = firstPtr; i != nullptr; i = i->nextPtr) {
            cout << i->data << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    LinkedRoundTable linkedRoundTable;
    linkedRoundTable.addToN(n);
    //linkedRoundTable.printList();
    linkedRoundTable.playUntilLastOne(a, b);
}
