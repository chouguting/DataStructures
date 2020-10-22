#include <iostream>

using namespace std;
typedef struct {
    int yCoord;
    int xCoord;
    int theNumData;
} points;

void transposeSparseMatrix(points theData[], points theResult[]) {
    theResult[0] = theData[0];
    int count[theData[0].xCoord] = {};
    for (int i = 1; i <= theData[0].theNumData; i++) {
        count[theData[i].xCoord]++;
    }
    int placeToPut[theData[0].xCoord];
    placeToPut[0] = 1;
    for (int i = 1; i < theData[0].xCoord; i++) {
        placeToPut[i] = placeToPut[i - 1] + count[i - 1];
    }
    for (int i = 1; i <= theData[0].theNumData; i++) {
        int theIndex = placeToPut[theData[i].xCoord];
        theResult[theIndex] = theData[i];
        int temp = theResult[theIndex].xCoord;
        theResult[theIndex].xCoord = theResult[theIndex].yCoord;
        theResult[theIndex].yCoord = temp;
        placeToPut[theData[i].xCoord]++;
    }
}

int main() {
    int width, depth, numbersOfPoints;
    cin >> depth >> width >> numbersOfPoints;
    points thePointList[numbersOfPoints + 1];
    thePointList[0] = {depth, width, numbersOfPoints};
    points transposedPointList[numbersOfPoints + 1];
    for (int i = 1; i <= numbersOfPoints; i++) {
        cin >> thePointList[i].yCoord >> thePointList[i].xCoord >> thePointList[i].theNumData;
    }

    cout << depth << " " << width << " " << numbersOfPoints << endl;
    transposeSparseMatrix(thePointList, transposedPointList);
    for (int i = 1; i <= numbersOfPoints; i++) {
        cout << transposedPointList[i].yCoord << " " << transposedPointList[i].xCoord << " "
             << transposedPointList[i].theNumData << endl;
    }
}