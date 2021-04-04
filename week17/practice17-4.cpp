//Week 17_加分題：計算 dist^k [u]
#include <iostream>
#include <vector>

#define MatrixMaxSize 10
using namespace std;

class GraphWithLength {
private:
    int adjacencyMatrix[MatrixMaxSize][MatrixMaxSize];
    int matrixSize;
public:
    GraphWithLength() {
        matrixSize = -1;
        for (int i = 0; i < MatrixMaxSize; i++) {
            for (int j = 0; j < MatrixMaxSize; j++) {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addData(int vertexFrom, int vertexTo, int Length) {
        if (max(vertexTo, vertexFrom) > matrixSize)matrixSize = max(vertexTo, vertexFrom);
        adjacencyMatrix[vertexFrom][vertexTo] = Length;
    }

    void BellmanFord(int startFrom) {
        int dist[matrixSize + 1];
        int lastDist[matrixSize + 1];
        for (int i = 0; i < matrixSize + 1; i++) {
            lastDist[i] = 9999;
            dist[i] = 9999;
        }
        dist[startFrom] = lastDist[startFrom] = 0;
        for (int i = 0; i < matrixSize + 1; i++) {
            if (adjacencyMatrix[i][startFrom] != 0) {
                lastDist[i] = adjacencyMatrix[i][startFrom];
            }
        }
        for (int i = 0; i < matrixSize; i++) {
            for (int j = 0; j < matrixSize + 1; j++) {
                for (int k = 0; k < matrixSize + 1; k++) {
                    if (adjacencyMatrix[k][j] != 0 && lastDist[k] != 9999) {
                        if (lastDist[k] + adjacencyMatrix[k][j] < dist[j]) {
                            dist[j] = min(lastDist[j], lastDist[k] + adjacencyMatrix[k][j]);
                        }
                    }
                }
            }
            for (int i = 0; i < matrixSize + 1; i++) {
                if (i != 0)cout << " ";
                if (dist[i] == 9999) {
                    cout << "i";
                } else {
                    cout << dist[i];
                }
                lastDist[i] = dist[i];
            }
            cout << endl;
        }
    }

};

int main() {
    GraphWithLength graphWithLength;
    int vertexFrom, vertexTo, length;
    while (cin >> vertexFrom >> vertexTo >> length) {
        graphWithLength.addData(vertexFrom, vertexTo, length);
    }
    graphWithLength.BellmanFord(0);
}