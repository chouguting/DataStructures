#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    bool first = true;
    for (int i = a; i <= b; i++) {
        string word = to_string(i);
        string wordReversed = word;
        reverse(wordReversed.begin(), wordReversed.end());
        if (word == wordReversed) {
            if (!first) {
                cout << " ";
            }
            first = false;
            cout << i;
        }
    }
    cout << " " << endl;
}