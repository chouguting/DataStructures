#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int tableSize, targetSize;
    cin >> tableSize >> targetSize;
    getchar();
    char table[tableSize][tableSize];
    for (int i = 0; i < tableSize; i++) {
        string tempStr;
        cin >> tempStr;
        getchar();
        for (int j = 0; j < tableSize; j++) {
            table[i][j] = tempStr[j];
        }
    }
    for (int i = 0; i < targetSize; i++) {
        string wantToFind;
        cin >> wantToFind;
        getchar();
        bool hasFoundTheWord = false;
        for (int i = 0; i < tableSize; i++) {
            string tempStrHorizontalWay = "";
            for (int j = 0; j < tableSize; j++) {
                tempStrHorizontalWay += table[i][j];
                string tempStrVerticalWay = "";
                for (int k = 0; k < tableSize; k++) {
                    tempStrVerticalWay += table[k][j];
                }
                tempStrVerticalWay = tempStrVerticalWay + tempStrVerticalWay + tempStrVerticalWay;
                if (tempStrVerticalWay.find(wantToFind) != -1) {
                    hasFoundTheWord = true;
                }
                reverse(tempStrVerticalWay.begin(), tempStrVerticalWay.end());
                if (tempStrVerticalWay.find(wantToFind) != -1) {
                    hasFoundTheWord = true;
                }
            }
            tempStrHorizontalWay = tempStrHorizontalWay + tempStrHorizontalWay + tempStrHorizontalWay;
            if (tempStrHorizontalWay.find(wantToFind) != -1) {
                hasFoundTheWord = true;
            }
            reverse(tempStrHorizontalWay.begin(), tempStrHorizontalWay.end());
            if (tempStrHorizontalWay.find(wantToFind) != -1) {
                hasFoundTheWord = true;
            }
        }
        (hasFoundTheWord) ? cout << "Yes\n" : cout << "No\n";
    }
}