//Week 7_練習一：刮號對稱性
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char theStr[500];
    while (true) {
        int top = -1;
        fgets(theStr, 500, stdin);
        strtok(theStr, "\r\n");
        if (strcmp(theStr, "end") == 0) {
            break;
        }
        bool isValid = true;
        for (int i = 0; i < strlen(theStr); i++) {
            if (theStr[i] == '(') {
                top += 1;
            } else if (theStr[i] == ')') {
                top -= 1;
            }
            if (top < -1)isValid = false;
        }
        if (top != -1)isValid = false;
        if (isValid) {
            cout << "1" << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    //cout<<"程式結束"<<endl;
}