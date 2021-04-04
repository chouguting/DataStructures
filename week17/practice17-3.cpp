#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GraphWithLength {
private:
    int adjacencyMatrix[500][500];
    vector<int> adjacencyList[500];
    int MatrixSize;

public:
    GraphWithLength() {
        MatrixSize = -1;
    }

    void addData(int fromVertex, int toVertex, int weight) {
        if (max(fromVertex, toVertex) > MatrixSize)MatrixSize = max(fromVertex, toVertex);
        adjacencyMatrix[fromVertex][toVertex] = weight;
        adjacencyList[fromVertex].push_back(toVertex);
    }

    int getMin(int data[], int hasWalked[], int size) {
        int minN = 9999999;
        int minIndex = 0;
        for (int i = 0; i < size; i++) {
            if (hasWalked[i] == 0) {
                if (data[i] < minN) {
                    minN = data[i];
                    minIndex = i;
                }

            }
        }
        return minIndex;
    }

    void printMinDistance(int startFrom) {
        int DistanceTable[MatrixSize + 1];
        int hasWalked[MatrixSize + 1] = {};
        for (int i = 0; i < MatrixSize + 1; i++) {
            DistanceTable[i] = 999999;
        }
        int indexer = startFrom;
        DistanceTable[startFrom] = 0;
        for (int i = 0; i < MatrixSize; i++) {
            for (int i = 0; i < adjacencyList[indexer].size(); i++) {
                DistanceTable[adjacencyList[indexer][i]] = min(
                        adjacencyMatrix[indexer][adjacencyList[indexer][i]] + DistanceTable[indexer],
                        DistanceTable[adjacencyList[indexer][i]]);
            }
            hasWalked[indexer] = 1;
            indexer = getMin(DistanceTable, hasWalked, MatrixSize + 1);
        }

        for (int i = 0; i < MatrixSize + 1; i++) {
            cout << i << ": " << DistanceTable[i] << endl;
        }
    }

};


int main() {
    GraphWithLength graphWithWeight;
    int vertex1, vertex2, weight;
    int startFrom;
    cin >> startFrom;
    while (cin >> vertex1 >> vertex2 >> weight) {
        graphWithWeight.addData(vertex1, vertex2, weight);
    }
    graphWithWeight.printMinDistance(startFrom);
}