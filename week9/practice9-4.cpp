#include <iostream>
#include <vector>

using namespace std;

class ItemNode {
public:
    char name;
    float value;
    float weight;
    ItemNode *nextPtr;

    ItemNode(char name, float value, float weight) : name(name), value(value), weight(weight) {}

    ItemNode() {}
};

class StoragePlace {
public:
    int maxWeight;
    ItemNode *topPtr;

    StoragePlace(int maxW) {
        maxWeight = maxW;
        topPtr = NULL;
    }

    float getWeight() {
        float weightSum = 0;
        if (topPtr == nullptr)return 0;
        for (ItemNode *i = topPtr; i != nullptr; i = i->nextPtr) {
            weightSum += i->weight;
        }
        return weightSum;
    }

    bool isEmpty() {
        return (topPtr == nullptr) ? true : false;
    }

    bool canFit(ItemNode item) {
        if (getWeight() + item.weight > maxWeight)return false;
        return true;
    }

    bool push(ItemNode item) {
        if (!canFit(item))return false;
        ItemNode *locator = topPtr;
        while (locator != nullptr &&
               (locator->value / locator->weight) > (item.value / item.weight)) {
            if (locator->nextPtr == nullptr ||
                (locator->nextPtr->value / locator->nextPtr->weight) <= (item.value / item.weight)) {
                while (locator->nextPtr != nullptr &&
                       locator->nextPtr->value / locator->nextPtr->weight == item.value / item.weight &&
                       item.weight > locator->nextPtr->weight) {
                    locator = locator->nextPtr;
                }
                break;
            }
            locator = locator->nextPtr;
        }
        ItemNode *temp = new ItemNode;
        *temp = item;
        if (locator == nullptr) {
            temp->nextPtr = nullptr;
            topPtr = temp;
        } else if (locator == topPtr) {
            if (locator->value / locator->weight > item.value / item.weight) {
                temp->nextPtr = topPtr->nextPtr;
                locator->nextPtr = temp;
            } else {
                temp->nextPtr = topPtr;
                topPtr = temp;
            }

        } else {
            temp->nextPtr = locator->nextPtr;
            locator->nextPtr = temp;
        }

        return true;
    }

    ItemNode pop() {
        ItemNode *locator = topPtr;
        while (locator->nextPtr->nextPtr != nullptr) {
            locator = locator->nextPtr;
        }
        ItemNode *temp = locator->nextPtr;
        ItemNode re = *temp;
        delete (temp);
        locator->nextPtr = nullptr;
        return re;
    }

    bool CPsmallestWorthToBeReplaced(ItemNode item) {
        ItemNode *locator = topPtr;
        while (locator->nextPtr != nullptr) {
            locator = locator->nextPtr;
        }
        return ((locator->value / locator->weight) < (item.value / item.weight)) ? true : false;
    }


    void printContent() {
        float valueSum = 0;
        int counter = 0;
        for (ItemNode *i = topPtr; i != nullptr; i = i->nextPtr) {
            counter++;
            valueSum += i->value;
        }
        for (int i = counter; i > 0; i--) {
            ItemNode *id = topPtr;
            for (int j = 1; j < i; j++) {
                id = id->nextPtr;
            }
            cout << id->name;
            if (i != 1)cout << " ";
        }
        cout << endl;
        printf("total weight:%.2f\n", getWeight());
        printf("total value:%.0f\n", valueSum);
    }
};


int main() {
    StoragePlace backPack(20);
    while (true) {
        char name;
        float value, weight;
        cin >> name;
        if (name == '-')break;
        cin >> value >> weight;
        getchar();
        ItemNode itemForNow(name, value, weight);
        if (backPack.push(itemForNow)) {
            continue;
        } else {
            while (!backPack.canFit(itemForNow)) {
                if (!backPack.CPsmallestWorthToBeReplaced(itemForNow)) {
                    break;
                }
                backPack.pop();
            }
            backPack.push(itemForNow);
        }
    }
    backPack.printContent();
}