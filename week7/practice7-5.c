#include <stdio.h>
#include <string.h>

int main() {
    char theStr[500];
    fgets(theStr, 500, stdin);
    strtok(theStr, "\r\n");
    int maxLenIndex = 0;
    int maxSubStrLength = 0;
    int totalLength = strlen(theStr);
    for (int i = 0; i < totalLength; i++) {
        int tempSubStrLength = 0;
        for (int j = 1;; j++) {
            if (i - j >= 0 && i + j < totalLength && theStr[i + j] == theStr[i - j]) {
                tempSubStrLength += 1;
            } else {
                break;
            }
        }
        if (tempSubStrLength > maxSubStrLength) {
            maxSubStrLength = tempSubStrLength;
            maxLenIndex = i;
        }
    }
    for (int i = maxLenIndex - maxSubStrLength; i <= maxLenIndex + maxSubStrLength; i++) {
        printf("%c", theStr[i]);
    }
    printf("\n");
}