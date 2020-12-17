#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findStructure(vector<int> &tempList, int theNum, int data[], int size) {
    for (int i = 0; i < size; i++) {
        if (data[i] == theNum) {
            tempList.push_back(i);
            findStructure(tempList, i, data, size);
        }
    }
}

void printResult(int data[], int size) {
    for (int i = 0; i < size; i++) {
        if (data[i] != -1)continue;
        vector<int> tempList;
        findStructure(tempList, i, data, size);
        tempList.push_back(i);
        sort(tempList.begin(), tempList.end());
        cout << " {";
        for (int j = 0; j < tempList.size(); j++) {
            if (j != 0)cout << ",";
            cout << tempList[j];
        }
        cout << "}";
    }
    cout << endl;
}

void unionSets(int data[], int dest, int orgin) {
    if (dest > orgin)swap(dest, orgin);
    if (data[orgin] != -1) {
        unionSets(data, dest, data[orgin]);
    } else {
        data[orgin] = dest;
    }
}

int find(int data[], int num) {
    while (data[num] != -1) {
        num = data[num];
    }
    return num;
}

int main() {
    int size;
    cin >> size;
    int data[size];
    for (int i = 0; i < size; i++) {
        data[i] = -1;
    }
    while (true) {
        int num1, num2;
        if (scanf("Union(%d,%d)", &num1, &num2)) {
            printf("Union(%d,%d):", num1, num2);
            unionSets(data, num1, num2);
            printResult(data, size);
        } else if (scanf("Find(%d), Find(%d)", &num1, &num2)) {
            printf("Find(%d), Find(%d): ", num1, num2);
            if (find(data, num1) == find(data, num2)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else if (scanf("%d", &num1) && num1 == -1) {
            break;
        }
    }
}