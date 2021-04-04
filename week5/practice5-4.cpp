//Week 5_加分題：河內塔遊戲
#include <iostream>

using namespace std;

void HonaiTower(int numberOfDisc) {
    if (numberOfDisc == 1) {
        cout << 1 << endl;
        return;
    }
    HonaiTower(numberOfDisc - 1);
    cout << numberOfDisc << endl;
    HonaiTower(numberOfDisc - 1);
}

int main() {
    int numberOfDisc;
    cin >> numberOfDisc;
    HonaiTower(numberOfDisc);
}