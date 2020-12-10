#include<iostream>

using namespace std;

class binarySearchTree {
private:
    struct node {
        int value;
        int level;
        node *leftPtr;
        node *rightPtr;
    };
    node *root;

    void addNum(node *location, int newNum) {
        if (root == nullptr) {
            node *temp = new node;
            temp->leftPtr = nullptr;
            temp->rightPtr = nullptr;
            temp->level = 1;
            root = temp;
            return;
        }

    }

    void connect(node *location, node *addNode) {

    }

public:
    binarySearchTree() {
        root = nullptr;
    }

    void addNum(int newNum) {
        addNum(root, newNum);
    }
};