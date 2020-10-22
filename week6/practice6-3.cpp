#include <iostream>
#include <algorithm>

using namespace std;
typedef struct {
    int yCoord;
    int xCoord;
    int theNumData;
} points;


int main() {
    int times;
    scanf("%d", &times);
    getchar();
    getchar();
    int requiredSize = 0;
    points theMaxtrix[11];
    points theSecondMatrix[11];
    int top = 1;
    for (int time = 0; time < times; time++) {
        int y, x, num;
        scanf("(%d:%d)=%d", &y, &x, &num);
        getchar();
        getchar();
        if (max(y, x) > requiredSize)requiredSize = max(y, x);
        theMaxtrix[top] = {y, x, num};
        theSecondMatrix[top] = {y, x, num};
        top++;
    }
    theMaxtrix[0] = {requiredSize, requiredSize, top};
    theSecondMatrix[0] = {requiredSize, requiredSize, top};
    for (int i = 1; i <= requiredSize; i++) {
        for (int j = 1; j <= requiredSize; j++) {
            int sum = 0;
            for (int firstOp = 1; firstOp <= theMaxtrix[0].theNumData; firstOp++) {
                for (int secondOp = 1; secondOp <= theMaxtrix[0].theNumData; secondOp++) {
                    if (theMaxtrix[firstOp].yCoord == i && theMaxtrix[secondOp].yCoord == j) {
                        if (i == j) {
                            if (theMaxtrix[firstOp].xCoord == theMaxtrix[secondOp].xCoord) {
                                sum += theMaxtrix[firstOp].theNumData * theMaxtrix[secondOp].theNumData;
                            }
                        } else {
                            if (theMaxtrix[firstOp].xCoord == theMaxtrix[secondOp].xCoord) {
                                sum += theMaxtrix[firstOp].theNumData * theMaxtrix[secondOp].theNumData;
                            }
                        }
                    }

                }
            }
            printf("%d", sum);
            if (j != requiredSize)printf(" ");
        }
        printf("\n");
    }
}