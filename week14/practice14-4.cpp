//Week 14_加分題：二元搜尋樹找 successor
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void preOrder(int data[], int index, vector<int> &list) {
    if (data[index] == 0)return;
    list.push_back(data[index]);
    preOrder(data, index * 2, list);
    preOrder(data, index * 2 + 1, list);
}

void inOrder(int data[], int index, vector<int> &list) {
    if (data[index] == 0)return;
    inOrder(data, index * 2, list);
    list.push_back(data[index]);
    inOrder(data, index * 2 + 1, list);
}

void postOrder(int data[], int index, vector<int> &list) {
    if (data[index] == 0)return;
    postOrder(data, index * 2, list);
    postOrder(data, index * 2 + 1, list);
    list.push_back(data[index]);
}

void successor(int data[], int target) {
    string inStr, preStr, postStr;
    vector<int> inList, preList, postList;
    inOrder(data, 1, inList);
    preOrder(data, 1, preList);
    postOrder(data, 1, postList);
    for (int i = 0; i < inList.size(); i++) {
        if (inList[i - 1] == target) {
            cout << inList[i] << " ";
            break;
        }
    }
    for (int i = 0; i < preList.size(); i++) {
        if (preList[i - 1] == target) {
            cout << preList[i] << " ";
            break;
        }
    }
    for (int i = 0; i < postList.size(); i++) {
        if (postList[i - 1] == target) {
            cout << postList[i];
            break;
        }
    }
}

int main() {
    int treeData[1024] = {};
    char theStr[500];
    fgets(theStr, 500, stdin);
    strtok(theStr, "\r\n");
    char *p = strtok(theStr, " ");
    treeData[1] = stoi(p);
    treeData[0] = 1;
    p = strtok(nullptr, " ");
    while (p != nullptr) {
        int addNum = stoi(p);
        int seeker = 1;
        while (treeData[seeker] != 0) {
            if (addNum < treeData[seeker]) {
                seeker *= 2;
            } else {
                seeker = seeker * 2 + 1;
            }
        }
        treeData[seeker] = addNum;
        if (seeker > treeData[0])treeData[0] = seeker;
        p = strtok(nullptr, " ");
    }
    int findNum;
    cin >> findNum;
    successor(treeData, findNum);
    cout << endl;
}