#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct listNode {
    string data;
    int count;
    listNode *nextPtr;
};

class LinkedList {
public:
    listNode *frontPtr;

    LinkedList() {
        frontPtr = nullptr;
    }


    bool add(string newWord, int index) {
        listNode *last = frontPtr;
        listNode *finder = frontPtr;
        bool hasFound = false;
        while (finder != nullptr) {
            string temp = finder->data;
            string temp2 = newWord;
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
            if (temp == temp2) {
                hasFound = true;
                break;
            }
            finder = finder->nextPtr;
        }

        if (finder == nullptr && index != -1) {
            finder = frontPtr;
            for (int i = 1; i < index; i++) {
                if (finder == nullptr)break;
                finder = finder->nextPtr;
            }
            if (finder == nullptr)return false;
        }

        while (frontPtr != nullptr && last->nextPtr != nullptr) {
            last = last->nextPtr;
        }
        listNode *temp = new listNode;
        temp->nextPtr = nullptr;
        temp->data = newWord;
        if (finder == nullptr) {
            temp->count = 1;
            if (frontPtr == nullptr) {
                frontPtr = temp;
            } else {
                last->nextPtr = temp;
            }
            return false;
        } else {
            if (hasFound) {
                finder->count += 1;
            } else {
                temp->count = 1;
                temp->nextPtr = finder->nextPtr;
                finder->nextPtr = temp;
            }

        }
        return true;
    }

    void printList() {
        for (listNode *i = frontPtr; i != nullptr; i = i->nextPtr) {
            cout << i->data << ", " << i->count;
            cout << endl;
        }

    }
};

int main() {
    LinkedList linkedList;
    while (true) {
        bool ended = false;
        char input[500];
        fgets(input, 500, stdin);
        strtok(input, "\r\n");
        char *p = strtok(input, " ");
        while (p != nullptr) {
            string temp(p);
            if (strcmp(input, "#Finish") == 0) {
                ended = true;
                break;
            }
            linkedList.add(temp, -1);
            p = strtok(nullptr, " ");
        }
        if (ended)break;
    }


    while (true) {
        string opCode;
        cin >> opCode;
        if (opCode == "#Exit")break;
        if (opCode == "#Print") {
            linkedList.printList();
        }
        if (opCode == "#Insert") {
            int count;
            string input;
            cin >> count >> input;
            linkedList.add(input, count);
        }
        if (opCode == "#Add") {
            string input;
            cin >> input;
            linkedList.add(input, -1);
        }
    }
}