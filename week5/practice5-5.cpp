//Week 5_加分題：爬樓梯
#include <iostream>

using namespace std;

int stairCounter(int stairCount) {
    if (stairCount == 1) {
        return 1;
    }
    if (stairCount == 2) {
        return 2;
    }
    return stairCounter(stairCount - 1) + stairCounter(stairCount - 2);
}

int main() {
    int stairs;
    cin >> stairs;
    cout << stairCounter(stairs) << endl;
}