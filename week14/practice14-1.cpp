//Week 14_練習一：二元搜尋樹插入節點
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
        binarySearchTree.preOrder();
        cout << endl;
        ptr = strtok(nullptr, " ");
    }
}