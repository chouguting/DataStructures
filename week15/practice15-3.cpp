//Week 15_練習三：網路連通性
#include "stdio.h"
int main() {
    int size;
    scanf("%d", &size);
    int data[size];
    for (int i = 0; i < size; i++)data[i] = -1;
    for (int i = 0; i < size; i++) {
        int inputNum;
        for (int j = 0; j < size; j++) {
            scanf("%d", &inputNum);
            if (j > i && inputNum == 1) {
                data[j] = i;
            }
        }
    }
    int pass = 1;
    for (int i = 1; i < size; i++) {
        if (data[i] == -1)pass = 0;
    }
    (pass) ? printf("1\n") : printf("-1\n");
}