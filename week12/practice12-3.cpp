//Week 12_練習三：算式樹
#include <iostream>
#include <cstring>

using namespace std;

class ExpressionTree {
    struct Node {
        char value[500];
        Node *leftPtr;
        Node *rightPtr;
    };
    Node *TreePtr;

    void replaceWith(Node *ptr, char *target, int value) {
        if (ptr == nullptr)return;
        if (strcmp(ptr->value, target) == 0) {
            char buf[12];
            snprintf(buf, 12, "%d", value);
            strcpy(ptr->value, buf);
        }
        replaceWith(ptr->rightPtr, target, value);
        replaceWith(ptr->leftPtr, target, value);
    }

    int calculate(Node *ptr) {
        if (ptr->value[0] >= '0' && ptr->value[0] <= '9') {
            return stoi(ptr->value);
        }
        if (strcmp(ptr->value, "+") == 0) {
            return calculate(ptr->leftPtr) + calculate(ptr->rightPtr);
        } else if (strcmp(ptr->value, "-") == 0) {
            return calculate(ptr->leftPtr) - calculate(ptr->rightPtr);
        } else if (strcmp(ptr->value, "*") == 0) {
            return calculate(ptr->leftPtr) * calculate(ptr->rightPtr);
        } else if (strcmp(ptr->value, "/") == 0) {
            return calculate(ptr->leftPtr) / calculate(ptr->rightPtr);
        }
    }

public:
    ExpressionTree() {
        TreePtr = nullptr;
    }

    ExpressionTree(char *theStr) {
        char temp5[500];
        strcpy(temp5, theStr);
        constructTree(temp5, TreePtr);
    }

    void constructTree(char *theStr, Node *&theNode) {
        if (strchr(theStr, '(') == nullptr) {
            theNode = new Node;
            strcpy(theNode->value, theStr);
            theNode->leftPtr = nullptr;
            theNode->rightPtr = nullptr;
            return;
        }
        theStr[strlen(theStr) - 2] = '\0';
        theStr += 2;
        char *ptr = strtok(theStr, " ");
        theNode = new Node;
        strcpy(theNode->value, ptr);
        ptr = strtok(nullptr, " ");

        char *forBack;
        if (strcmp(ptr, "(") == 0) {
            char tmp[50];
            strcpy(tmp, "(");
            int counter = 0;
            while (counter != -1) {
                ptr = strtok(nullptr, " ");
                if (strcmp(ptr, "(") == 0)counter++;
                if (strcmp(ptr, ")") == 0)counter--;
                strcat(tmp, " ");
                strcat(tmp, ptr);

            }
            forBack = ptr + 2;
            constructTree(tmp, theNode->leftPtr);
            ptr = strtok(forBack, " ");
        } else {
            constructTree(ptr, theNode->leftPtr);
            ptr = strtok(nullptr, " ");
        }

        if (strcmp(ptr, "(") == 0) {
            int counter = 0;
            char tmp[50];
            strcpy(tmp, "(");
            while (counter != -1) {
                ptr = strtok(nullptr, " ");
                if (strcmp(ptr, "(") == 0)counter++;
                if (strcmp(ptr, ")") == 0)counter--;
                strcat(tmp, " ");
                strcat(tmp, ptr);
            }
            constructTree(tmp, theNode->rightPtr);
            /*ptr = strtok(nullptr, ")");
            strcat(ptr, " )");
            char tmp[50];
            strcpy(tmp, ptr);
            strcpy(ptr, "( ");
            strcat(ptr, tmp);*/
        } else {
            constructTree(ptr, theNode->rightPtr);
        }
    }

    void replaceWith(char *target, int value) {
        replaceWith(TreePtr, target, value);
    }

    int calculate() {
        return calculate(TreePtr);
    }
};

int main() {
    char input[500];
    fgets(input, 500, stdin);
    strtok(input, "\r\n");
    ExpressionTree expressionTree(input);
    /*while (fgets(input, 500, stdin)) {
        char *p = strtok(input, " ");
        expressionTree.replaceWith(p, input[4] - '0');
    }*/
    expressionTree.replaceWith("x", 5);
    cout << expressionTree.calculate();
    cout << endl;
}