#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    char *input = new char[500];
    fgets(input, 1000, stdin);
    strtok(input, "\r\n");
    int Times = atoi(input);

    for (int time = 0; time < Times; time += 1) {
        char *theStr = (char *) malloc(sizeof(char) * 1000);
        fgets(theStr, 1000, stdin);
        strtok(theStr, "\r\n");
        char *thePointer = theStr;
        char *endPtr = theStr + strlen(theStr);
        while (thePointer < endPtr) {
            if (*thePointer == 'a' && thePointer < endPtr - 1) {
                char *tempPtr = thePointer + 1;
                string tempString(tempPtr);
                reverse(tempString.begin(), tempString.end());
                *(thePointer + 1) = '\0';
                strcat(theStr, tempString.c_str());
            }
            if (*thePointer == 'b' && thePointer < endPtr - 1) {
                char *tempStr = new char[1000];
                strcpy(tempStr, thePointer + 1);
                strcat(theStr, tempStr);
                endPtr = theStr + strlen(theStr);
            }
            if (*thePointer == 'c' && thePointer < endPtr) {
                char *tempStr = new char[1000];
                strcpy(tempStr, thePointer + 3);
                *(thePointer + 1) = '\0';
                if (thePointer >= endPtr - 3) {
                    break;
                }
                strcat(thePointer, tempStr);
                endPtr = theStr + strlen(theStr);
            }
            thePointer += 1;
        }
        cout << theStr << endl;
    }
}