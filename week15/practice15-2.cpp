//Week 15_練習二：DFS 與 BFS
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void DFS(vector<int> theList[], int size) {
    stack<int> theStack;
    int hasWalked[size + 1] = {};
    int walker = 0;
    bool first = true;
    while (true) {
        if (!hasWalked[walker]) {
            if (!first)cout << " ";
            first = false;
            cout << walker;
            hasWalked[walker] = 1;
        }
        int i;
        for (i = 0; i < theList[walker].size(); i++) {
            if (!hasWalked[theList[walker][i]]) {
                break;
            }
        }
        if (i == theList[walker].size()) {
            walker = theStack.top();
            theStack.pop();
            if (theStack.empty())break;

        } else {
            i = theList[walker][i];
            theStack.push(walker);
            walker = i;
        }
    }
    cout << endl;
}

void BFS(vector<int> theList[], int size) {
    queue<int> theQueue;
    int hasWalked[size + 1] = {};
    theQueue.push(0);
    int walker = 0;
    bool first = true;
    while (true) {
        hasWalked[walker] = 1;
        if (!first)cout << " ";
        first = false;
        cout << walker;
        int i;
        for (i = 0; i < theList[walker].size(); i++) {
            if (!hasWalked[theList[walker][i]]) {
                hasWalked[theList[walker][i]] = 1;
                theQueue.push(theList[walker][i]);
            }
        }
        theQueue.pop();
        if (theQueue.empty())break;
        walker = theQueue.front();
    }
    cout << endl;
}

int main() {
    int num1, num2;
    int requiredSize = 0;
    vector<int> theList[500];
    while (cin >> num1 >> num2) {
        if (max(num1, num2) > requiredSize)requiredSize = max(num1, num2);
        theList[num1].push_back(num2);
        theList[num2].push_back(num1);
    }
    cout << "Depth First Search:" << endl;
    DFS(theList, requiredSize);
    cout << endl;
    cout << "Breadth First Search:" << endl;
    BFS(theList, requiredSize);
}