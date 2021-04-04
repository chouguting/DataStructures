//Week 6_加分題：翻轉吧陣列
#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;
    getchar();
    int theMatrix[size][size];
    int theMatrix2[size][size];
    int dataNum = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            theMatrix[i][j] = dataNum;
            dataNum++;
        }
    }
    string operation;
    cin >> operation;
    for (int i = 0; i < operation.length(); i++) {
        char opCode = operation[i];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                theMatrix2[i][j] = theMatrix[i][j];
            }
        }
        if (opCode == 'H') {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    theMatrix[i][j] = theMatrix2[i][abs(size - 1 - j)];
                }
            }
        } else if (opCode == 'V') {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    theMatrix[abs(size - 1 - i)][j] = theMatrix2[i][j];
                }
            }
        } else if (opCode == 'D') {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    theMatrix[i][j] = theMatrix2[j][i];
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d", theMatrix[i][j]);
            if (j != size - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

}