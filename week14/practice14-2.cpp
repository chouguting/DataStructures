#include<iostream>
#include <cstring>

using namespace std;

class BinarySearchTree {
private:
    struct node {
        int value;
        node *leftPtr;
        node *rightPtr;
    };
    node *root;

    void addNum(node *&location, int newNum) {
        if (root == nullptr) {
            connect(root, newNum);
            return;
        }
        if (location == nullptr) {
            connect(location, newNum);
            return;
        }
        if (location->value < newNum) {
            addNum(location->rightPtr, newNum);
        } else {
            addNum(location->leftPtr, newNum);
        }
    }

    void connect(node *&location, int newNum, int mode = 0) {
        node *temp = new node;
        temp->leftPtr = nullptr;
        temp->rightPtr = nullptr;
        temp->value = newNum;
        location = temp;
    }

    void preOrder(node *location) {
        if (location == nullptr)return;
        cout << location->value << " ";
        preOrder(location->leftPtr);
        preOrder(location->rightPtr);
    }

    bool search(int findNum, node *&location, node ***lastPlace = nullptr) {
        node *seeker = root;
        *lastPlace = &root;
        while (seeker != nullptr) {
            if (findNum == seeker->value) {
                location = seeker;
                return true;
            }
            if (findNum > seeker->value) {
                *lastPlace = &seeker->rightPtr;
                seeker = seeker->rightPtr;
            } else {
                *lastPlace = &seeker->leftPtr;
                seeker = seeker->leftPtr;
            }
        }
        *lastPlace = nullptr;
        return false;
    }

    node *findMax(node *location) {
        node *result = location;
        while (location->rightPtr != nullptr) {
            location = location->rightPtr;
            result = location;
        }
        return result;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void addNum(int newNum) {
        addNum(root, newNum);
    }

    void preOrder() {
        preOrder(root);
    }


    bool deleteNum(int deleteNum) {
        node *deleteLocation, **lastLoaction;
        if (!search(deleteNum, deleteLocation, &lastLoaction)) {
            return false;
        }
        node *temp = deleteLocation;
        //case1:
        if (deleteLocation->leftPtr == nullptr && deleteLocation->rightPtr == nullptr) {
            *lastLoaction = nullptr;
            delete temp;
        }//case 3:
        else if (deleteLocation->leftPtr != nullptr && deleteLocation->rightPtr != nullptr) {
            node *maxFinder = findMax(deleteLocation->leftPtr);
            int numTemp = maxFinder->value;
            this->deleteNum(numTemp);
            deleteLocation->value = numTemp;
        }
            //case 2:
        else if (deleteLocation->leftPtr != nullptr || deleteLocation->rightPtr != nullptr) {
            if (deleteLocation->rightPtr != nullptr) {
                *lastLoaction = deleteLocation->rightPtr;
            } else {
                *lastLoaction = deleteLocation->leftPtr;
            }
            delete temp;
        }
        return true;
    }
};

int main() {

    BinarySearchTree binarySearchTree;
    char str[500];
    fgets(str, 500, stdin);
    strtok(str, "\r\n");
    char *ptr = strtok(str, " ");
    while (ptr != nullptr) {
        int num = stoi(ptr);
        binarySearchTree.addNum(num);
        ptr = strtok(nullptr, " ");
    }
    cout << "Binary search tree (before):\n";
    binarySearchTree.preOrder();
    cout << endl;

    fgets(str, 500, stdin);
    strtok(str, "\r\n");
    ptr = strtok(str, " ");
    while (ptr != nullptr) {
        int num = stoi(ptr);
        if (!binarySearchTree.deleteNum(num)) {
            cout << "no " << num << endl;
        }
        ptr = strtok(nullptr, " ");
    }
    cout << "Binary search tree (after):\n";
    binarySearchTree.preOrder();
    cout << endl;
}