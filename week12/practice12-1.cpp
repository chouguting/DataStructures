//Week 12_練習一：二元樹的陣列表示法
#include <iostream>

using namespace std;

int main() {
    int nodeCount;
    cin >> nodeCount;
    int data[1024] = {};
    int num, left, right;
    cin >> num >> left >> right;
    data[1] = num;
    data[2] = left;
    data[3] = right;
    data[0] = 3; //存TOP
    while (true) {
        cin >> num;
        if (num == -1)break;
        cin >> left >> right;
        int seeker = 1;
        for (; seeker < data[0]; seeker++) {
            if (data[seeker] == num)break;
        }
        seeker *= 2;
        data[seeker] = left;
        seeker += 1;
        data[seeker] = right;
        data[0] = seeker;
    }
    while (data[data[0]] == 0)data[0] -= 1;
    for (int i = 1; i <= data[0]; i++) {
        if (i != 1)cout << " ";
        cout << data[i];
    }
    cout << endl;
}