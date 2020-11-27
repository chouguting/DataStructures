#include <iostream>

using namespace std;

class LinkedList {
private:
    struct priceNode {
        int price;
        priceNode *nextPtr;
    };

    class listNode {
    public:
        string data;
        listNode *nextPtr;
        priceNode *firstPrice;

        void addPrice(int price) {
            priceNode *temp = new priceNode;
            temp->price = price;
            temp->nextPtr = nullptr;
            if (firstPrice == nullptr) {
                firstPrice = temp;
            } else {
                if (price < firstPrice->price) {
                    temp->nextPtr = firstPrice;
                    firstPrice = temp;
                    return;
                }
                priceNode *locator = firstPrice;
                while (firstPrice != nullptr && locator->nextPtr != nullptr) {
                    if (price < locator->nextPtr->price) {
                        break;
                    }
                    locator = locator->nextPtr;
                }
                temp->nextPtr = locator->nextPtr;
                locator->nextPtr = temp;
            }
        }

        void printPrice() {
            for (priceNode *i = firstPrice; i != nullptr; i = i->nextPtr) {
                cout << i->price << ",";
            }
        }
    };

    listNode *frontPtr;
public:
    LinkedList() {
        frontPtr = nullptr;
    }

    bool add(string itemName, int price) {
        listNode *last = frontPtr;
        listNode *finder = frontPtr;
        while (finder != nullptr) {
            if (finder->data == itemName) {
                break;
            }
            finder = finder->nextPtr;
        }

        while (frontPtr != nullptr && last->nextPtr != nullptr) {
            last = last->nextPtr;
        }

        if (finder == nullptr) {
            listNode *temp = new listNode;
            temp->nextPtr = nullptr;
            temp->data = itemName;
            temp->firstPrice = nullptr;
            if (frontPtr == nullptr) {
                frontPtr = temp;
            } else {
                last->nextPtr = temp;
            }
            temp->addPrice(price);
            return false;
        } else {
            finder->addPrice(price);
        }
        return true;
    }

    void printList() {
        for (listNode *i = frontPtr; i != nullptr; i = i->nextPtr) {
            cout << i->data << ",";
            i->printPrice();
            cout << endl;
        }
    }
};

int main() {
    int times;
    cin >> times;
    LinkedList linkedList;
    for (int t = 0; t < times; t++) {
        string itemName;
        int price;
        cin >> itemName >> price;
        linkedList.add(itemName, price);
    }
    linkedList.printList();
}