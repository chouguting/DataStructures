#include <iostream>

using namespace std;

int main() {
    string a = "hi";
    string b;
    cin >> b;
    if (a == b) {
        cout << "YEEE\n";
    } else {
        cout << "nah!!!\n";
    }
    cout << endl;
    if (!a.compare(a)) {
        cout << "YEEEEEEEAH\n";
    } else {
        cout << "Guh!!!";
    }
}