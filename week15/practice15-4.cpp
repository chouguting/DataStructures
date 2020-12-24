#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int data[26];
    for (int i = 0; i < 26; i++) {
        data[i] = -1;
    }
    char input1, input2;
    char temp[100];
    while (fgets(temp, 100, stdin)) {
        input1 = temp[0];
        input2 = temp[2];
        if (data[input1 - 'a'] == -1 && data[input2 - 'a'] == -1) {
            data[min(input1 - 'a', input2 - 'a')] = max(input1 - 'a', input2 - 'a');
        } else {
            if (data[input1 - 'a'] == -1) {
                data[input1 - 'a'] = input2 - 'a';
            } else {
                data[input2 - 'a'] = input1 - 'a';
            }
        }
    }
    int hasPassed[26] = {};
    int seeker;
    char resultStart;
    for (int i = 0; i < 26; i++) {
        if (data[i] != -1) {
            resultStart = char(i + 'a');
            seeker = data[i];
            hasPassed[i] = 1;
            break;
        }
    }
    while (data[seeker] != -1) {
        hasPassed[seeker] = 1;
        seeker = data[seeker];
    }
    bool noResult = false;
    for (int i = 0; i < 26; i++) {
        if (data[i] != -1 && hasPassed[i] == 0) {
            noResult = true;
        }
    }
    if (noResult) {
        cout << "null" << endl;
    } else {
        cout << resultStart << " " << char(seeker + 'a') << endl;
    }
}