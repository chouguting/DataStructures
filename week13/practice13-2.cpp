//Week 13_練習二：Min Heap 插入節點
#include <iostream>
#include <cstring>

using namespace std;

void insert(int treeData[], int addNum) {
    treeData[0]++;
    treeData[treeData[0]] = addNum;
    int seeker = treeData[0];
    while (seeker / 2 > 0) {
        if (treeData[seeker] < treeData[seeker / 2]) {
            swap(treeData[seeker], treeData[seeker / 2]);
        } else {
            break;
        }
        seeker /= 2;
    }
}

void deleteNum(int treeData[], int deleteNum) {
    int seeker = 1;
    while (seeker <= treeData[0]) {
        if (treeData[seeker] == deleteNum)break;
        seeker++;
    }
    swap(treeData[seeker], treeData[treeData[0]]);
    treeData[treeData[0]] = 0;
    treeData[0]--;
    while (seeker * 2 <= treeData[0]) {
        if (treeData[seeker] < treeData[seeker * 2] && treeData[seeker] < treeData[seeker * 2 + 1]) {
            break;
        }
        if (treeData[seeker * 2] < treeData[seeker * 2 + 1]) {
            swap(treeData[seeker * 2], treeData[seeker]);
            seeker = seeker * 2;
        } else {
            swap(treeData[seeker * 2 + 1], treeData[seeker]);
            seeker = seeker * 2 + 1;
        }
    }
}

void printTree(int treeData[], int maxIndex) {
    for (int i = 1; i <= maxIndex; i++) {
        printf("[%d]%d", i, treeData[i]);
        if (i < maxIndex)cout << " ";
    }
    cout << endl;
}


int main() {
    int treeData[1024] = {};
    char theStr[500];
    fgets(theStr, 500, stdin);
    strtok(theStr, "\r\n");
    char *p = strtok(theStr, " ");
    treeData[1] = stoi(p);
    treeData[0] = 1;
    printTree(treeData, treeData[0]);
    p = strtok(nullptr, " ");
    while (p != nullptr) {
        int addNum = stoi(p);
        insert(treeData, addNum);
        printTree(treeData, treeData[0]);
        p = strtok(nullptr, " ");
    }
}