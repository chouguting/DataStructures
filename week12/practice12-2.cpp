#include <iostream>
#include <cstring>

using namespace std;

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
    int counter = 0;
    int dividend = treeData[0];
    while (dividend > 0) {
        dividend = dividend / 2;
        counter++;
    }
    cout << counter << endl;
}