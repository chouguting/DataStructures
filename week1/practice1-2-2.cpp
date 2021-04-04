//Week 1_練習二：質因數分解
#include <iostream>

using namespace std;
#define  Yayun main

int Yayun() {
    long long num;
    cin >> num;
    long long i = 2;
    while (true) {
        int expoCounter = 0;
        while (num % i == 0) {
            expoCounter++;
            num /= i;
        }
        if (expoCounter > 0) {
            cout << i;
            if (expoCounter > 1)cout << "^" << expoCounter;
            if (num != 1)cout << " * ";
        }
        if (num == 1)break;
        i++;
    }
    cout << endl;
}