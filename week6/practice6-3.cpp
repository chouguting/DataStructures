//Week 6_練習三：計算A × A^T
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
    //getchar();
    int requiredSize = 0;
    points theMaxtrix[11];
    points theSecondMatrix[11];
    int top = 1;
    for (int time = 0; time < times; time++) {
        int y, x, num;
        scanf("(%d:%d)=%d", &y, &x, &num);
        getchar();
        //getchar();
        //稀疏矩陣表示法中最大的XY值 就是轉換成一班矩陣後至少需要的大小(requiredSize*requiredSize)
        if (max(y, x) > requiredSize)requiredSize = max(y, x);
        //從一開始存入數據
        theMaxtrix[top] = {y, x, num};
        top++;
    }
    //稀疏矩陣表示法中第一格(index 0)是存 長寬及數據個數;
    theMaxtrix[0] = {requiredSize, requiredSize, top};

    //i指向ROW
    for (int i = 1; i <= requiredSize; i++) {
        //j指向COLUMN
        for (int j = 1; j <= requiredSize; j++) {
            //存矩陣的在該點(ROW,COLUMN)的合
            int sum = 0;
            //在我們的兩個稀疏矩陣中找到兩個合適的樹相乘
            for (int firstOp = 1; firstOp <= theMaxtrix[0].theNumData; firstOp++) {
                for (int secondOp = 1; secondOp <= theMaxtrix[0].theNumData; secondOp++) {
                    //如果兩個稀疏矩陣的ROW可以對上i和j
                    if (theMaxtrix[firstOp].yCoord == i && theMaxtrix[secondOp].yCoord == j) {
                        //然後兩個稀疏矩陣的COLUMN又一樣 就成起來並加入SUM
                        if (theMaxtrix[firstOp].xCoord == theMaxtrix[secondOp].xCoord) {
                            sum += theMaxtrix[firstOp].theNumData * theMaxtrix[secondOp].theNumData;
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