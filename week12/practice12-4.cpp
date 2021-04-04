//Week 12_加分題：用分層方式輸出二元樹
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

void locateNum(int *tree, int findNum, int &seeker) {
    for (int i = 1; i < 1024; i++) {
        if (tree[i] == findNum) {
            seeker = i;
            return;
        }
    }
}

int main() {
    char preOrderStr[500];
    int treeData[1024] = {};
    treeData[0] = 0;
    fgets(preOrderStr, 500, stdin);
    strtok(preOrderStr, "\r\n");

    string line;
    getline(cin, line);
    istringstream is(line);

    vector<int> preOrderNum;
    vector<int> inOrderNum;

    char *ptr = strtok(preOrderStr, " ");
    while (ptr != nullptr) {
        preOrderNum.push_back(stoi(ptr));
        int n;
        is >> n;
        inOrderNum.push_back(n);
        ptr = strtok(nullptr, " ");
    }

    int preIndex = 0;
    int inIndex = 0;
    int seeker = 1;
    while (true) {
        treeData[seeker] = preOrderNum[preIndex];
        if (preOrderNum[preIndex] == inOrderNum[inIndex])break;
        preIndex++;
        seeker *= 2;
        if (seeker > treeData[0])treeData[0] = seeker;
    }
    preIndex++;
    inIndex++;
    while (preIndex < preOrderNum.size()) {
        if (preOrderNum[preIndex] != inOrderNum[inIndex]) {
            locateNum(treeData, inOrderNum[inIndex], seeker);
            seeker = seeker * 2 + 1;
            if (seeker > treeData[0])treeData[0] = seeker;
            treeData[seeker] = preOrderNum[preIndex];
            inIndex++;
            if (inOrderNum[inIndex] == preOrderNum[preIndex])inIndex++;
            preIndex++;
        } else if (preOrderNum[preIndex] == inOrderNum[inIndex]) {
            locateNum(treeData, preOrderNum[preIndex - 1], seeker);
            seeker = seeker * 2;
            if (inIndex + 1 >= inOrderNum.size() || preOrderNum[preIndex - 1] != inOrderNum[inIndex + 1]) {
                seeker = seeker * +1;
            }
            treeData[seeker] = preOrderNum[preIndex];
            inIndex++;
            preIndex++;
        }
        if (seeker > treeData[0])treeData[0] = seeker;
    }
    int layerMax = 0;
    int layer = 0;
    bool justChangedLine = false;
    for (int i = 1; i <= treeData[0]; i++) {
        if (i > layerMax) {
            if (i != 1)cout << endl;
            layer++;
            layerMax = (layerMax + 1) * 2 - 1;
            cout << layer << ":";
            justChangedLine = true;
        }
        if (treeData[i] != 0) {
            if (!justChangedLine)cout << ",";
            cout << treeData[i];
            justChangedLine = false;
        }
    }
    cout << endl;
}