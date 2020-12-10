#include <iostream>
#include <cstring>

using namespace std;

class BinaryTree {
private:
    struct node {
        string value;
        int level;
        node *leftPtr;
        node *rightPtr;
    };
    node *root;

    void addValue(node *&location, string locationData, string data1 = "", string data2 = "") {
        if (root == nullptr) {
            connect(root, locationData, 0);
            if (data1 != "")decideToConnect(root, data1, root->level);
            if (data2 != "")decideToConnect(root, data2, root->level);
            return;
        }
        if (location == nullptr)return;
        if (location->value == locationData) {
            if (data1 != "")decideToConnect(location, data1, location->level);
            if (data2 != "")decideToConnect(location, data2, location->level);
        }
        addValue(location->leftPtr, locationData, data1, data2);
        addValue(location->rightPtr, locationData, data1, data2);
    }


    void decideToConnect(node *&location, string newData, int lastLevel) {
        if ((newData[newData.size() - 1] - '0') % 2 == 1) {
            connect(location->leftPtr, newData, lastLevel);
        } else {
            connect(location->rightPtr, newData, lastLevel);
        }
    }

    void connect(node *&location, string newData, int lastLevel) {
        node *temp = new node;
        temp->leftPtr = nullptr;
        temp->rightPtr = nullptr;
        temp->value = newData;
        temp->level = lastLevel + 1;
        location = temp;
    }

    void preOrder(node *location) {
        if (location == nullptr)return;
        cout << location->value << " ";
        preOrder(location->leftPtr);
        preOrder(location->rightPtr);
    }

    void inOrder(node *location) {
        if (location == nullptr)return;
        inOrder(location->leftPtr);
        cout << location->value << " ";
        inOrder(location->rightPtr);
    }

    void postOrder(node *location) {
        if (location == nullptr)return;
        postOrder(location->leftPtr);
        postOrder(location->rightPtr);
        cout << location->value << " ";
    }

    void maxDepth(node *location, int &maxLevel) {
        if (location == nullptr)return;
        if (location->level > maxLevel) {
            maxLevel = location->level;
        }
        maxDepth(location->leftPtr, maxLevel);
        maxDepth(location->rightPtr, maxLevel);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void addValue(string newValue, string data1 = "", string data2 = "") {
        addValue(root, newValue, data1, data2);
    }

    void preOrder() {
        cout << "Preorder: ";
        preOrder(root);
        cout << endl;
    }

    void inOrder() {
        cout << "Inorder: ";
        inOrder(root);
        cout << endl;
    }

    void postOrder() {
        cout << "Postorder: ";
        postOrder(root);
        cout << endl;
    }

    int balanceCoef() {
        int leftMaxDepth = 0, rightMaxDepth = 0;
        maxDepth(root->leftPtr, leftMaxDepth);
        maxDepth(root->rightPtr, rightMaxDepth);
        return abs(leftMaxDepth - rightMaxDepth);
    }
};

int main() {
    string inputData[3];
    BinaryTree binaryTree;
    while (true) {
        bool leave = false;
        char input[500];
        fgets(input, 500, stdin);
        strtok(input, "\r\n");
        char *p = strtok(input, " ");
        int i = 0;
        while (p != nullptr) {
            if (strcmp(p, "0") == 0) {
                leave = true;
                break;
            }
            inputData[i] = p;
            i++;
            p = strtok(nullptr, " ");
        }
        if (leave == true)break;
        if (i == 2) {
            binaryTree.addValue(inputData[0], inputData[1]);
        } else {
            binaryTree.addValue(inputData[0], inputData[1], inputData[2]);
        }
    }
    binaryTree.preOrder();
    binaryTree.inOrder();
    binaryTree.postOrder();
    cout << "The balance factor is " << binaryTree.balanceCoef() << endl;
}