#include <iostream>

using namespace std;

class Item {
public:
    char name;
    float value;
    float weight;

    Item(char name, float value, float weight) : name(name), value(value), weight(weight) {}

    Item() {}
};

class StoragePlace {
public:
    Item data[10];
    int top = -1;
    int maxWeight;

    StoragePlace(int maxW) {
        stackInitial();
        maxWeight = maxW;
    }

    int stackInitial() {
        return 1;
    }

    float getWeight() {
        float weightSum = 0;
        for (int i = 0; i <= top; i++) {
            weightSum += data[i].weight;
        }
        return weightSum;
    }

    bool isEmpty() {
        return (top == -1) ? true : false;
    }

    bool push(Item item) {
        if (getWeight() + item.weight > maxWeight) {
            return false;
        } else {
            data[++top] = item;
            return true;
        }
    }

    Item pop() {
        if (!isEmpty()) {
            top--;
        }
        return data[top + 1];
    }

    bool topOneWorthToBeReplaced(Item item) {
        if (data[top].value < item.value && (getWeight() - data[top].weight + item.weight) <= 20) {
            return true;
        }
        return false;
    }


    void printContent() {
        int i;
        float valueSum = 0;
        for (i = 0; i <= top; i++) {
            printf("%c %.1f %.1f\n", data[i].name, data[i].value, data[i].weight);
            valueSum += data[i].value;
        }
        printf("weight:%.1f\n", getWeight());
        printf("value:%.1f\n", valueSum);

    }
};


int main() {
    StoragePlace backPack(20);
    for (int i = 0; i < 5; i++) {
        char name;
        float value, weight;
        StoragePlace floor(1000);
        cin >> name >> value >> weight;
        getchar();
        Item itemForNow(name, value, weight);
        if (backPack.push(itemForNow)) {
            continue;
        } else {
            while (!backPack.topOneWorthToBeReplaced(itemForNow)) {
                if (backPack.isEmpty())break;
                floor.push(backPack.pop());
            }
            if (backPack.topOneWorthToBeReplaced(itemForNow)) {
                backPack.pop();
                backPack.push(itemForNow);
            }
            int takeIndex = 0;
            while (takeIndex <= floor.top && backPack.push(floor.data[takeIndex])) {
                takeIndex++;
            }

        }
    }
    backPack.printContent();
}