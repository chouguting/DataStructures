//Week 3_加分題：魔方陣
#include <iostream>

using namespace std;

int main() {
    int cubeSize;
    cin >> cubeSize;
    int table[cubeSize][cubeSize];
    for (int i = 0; i < cubeSize; i++) {
        for (int j = 0; j < cubeSize; j++) {
            table[i][j] = -1;
        }
    }
    int indexX = 0, indexY = cubeSize / 2;
    for (int i = 1; i <= cubeSize * cubeSize; i += 1) {
        table[indexX][indexY] = i;
        int indexYTemp = (indexY + 1) % cubeSize;
        int indexXTemp = ((indexX - 1) + cubeSize) % cubeSize;
        if (table[indexXTemp][indexYTemp] == -1) {
            indexX = indexXTemp;
            indexY = indexYTemp;
        } else {
            indexX = (indexX + 1) % cubeSize;
        }
    }
    for (int i = 0; i < cubeSize; i++) {
        for (int j = 0; j < cubeSize; j++) {
            cout << table[i][j];
            (j == cubeSize - 1) ? cout << "\n" : cout << " ";
        }
    }
    return 0;
}