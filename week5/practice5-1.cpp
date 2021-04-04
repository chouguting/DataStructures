//Week 5_練習一：非連續子序列之兩數最大和
#include<iostream>
#include<vector>

using namespace std;

int main() {
    int times;
    cin >> times;
    vector<int> theList;
    for (int time = 0; time < times; time += 1) {
        int input;
        cin >> input;
        theList.push_back(input);
    }
    int maxSum = 0;
    for (int i = 0; i < theList.size(); i++) {
        int currentSum = theList[i];
        for (int j = 0; j < theList.size(); j++) {
            if (i - j <= 1 && i - j >= -1) {
                continue;
            }
            if (currentSum < theList[i] + theList[j]) {
                currentSum = theList[i] + theList[j];
            }
        }
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    cout << maxSum << endl;
    return 0;

}