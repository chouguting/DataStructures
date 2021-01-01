#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num1, num2;
    int requiredSize = 0;
    int data[500][500] = {};
    vector<int> theList[500];
    while (cin >> num1 >> num2) {
        if (max(num1, num2) > requiredSize)requiredSize = max(num1, num2);
        theList[num1].push_back(num2);
        theList[num2].push_back(num1);
        data[num1][num2] = data[num2][num1] = 1;
    }
    cout << "Adjacency matrix:" << endl;
    for (int i = 0; i <= requiredSize; i++) {
        for (int j = 0; j <= requiredSize; j++) {
            cout << data[i][j];
            if (j != requiredSize)cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Adjacency list:" << endl;
    for (int i = 0; i <= requiredSize; i++) {
        cout << i << ": ";
        for (int j = 0; j < theList[i].size(); j++) {
            cout << theList[i][j];
            if (j != requiredSize)cout << " -> ";
        }
        cout << "end" << endl;
    }
}