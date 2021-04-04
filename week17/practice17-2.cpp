//Week 17_練習二：Prim’s algorithm
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GraphWithWeight {
private:
    struct Edge {
        int vertex1;
        int vertex2;
        int weight;
    };
    vector<Edge> EdgeList;
    int listTop;
public:
    GraphWithWeight() {
        listTop = -1;
    }


    void addData(int vertex1, int vertex2, int weight) {
        if (max(vertex1, vertex2) > listTop)listTop = max(vertex1, vertex2);
        EdgeList.push_back({vertex1, vertex2, weight});
    }

    void sortEdgeList() {
        for (int i = 0; i < EdgeList.size(); i++) {
            int minIndex = i;
            int minWeight = EdgeList[i].weight;
            for (int j = i; j < EdgeList.size(); j++) {
                if (EdgeList[j].weight < minWeight) {
                    minIndex = j;
                    minWeight = EdgeList[j].weight;
                }
            }
            swap(EdgeList[i], EdgeList[minIndex]);
        }
    }

    //Prim's Algorithm
    void minimalCost(int startFrom) {
        vector<int> hasWalked;
        sortEdgeList();
        int connectedCount = 0;
        int costCount = 0;
        hasWalked.push_back(startFrom);
        while (connectedCount < listTop) {
            bool notFound = true;
            for (int i = 0; i < EdgeList.size(); i++) {
                if ((find(hasWalked.begin(), hasWalked.end(), EdgeList[i].vertex1) != hasWalked.end()) ==
                    !(find(hasWalked.begin(), hasWalked.end(), EdgeList[i].vertex2) != hasWalked.end())) {
                    if (find(hasWalked.begin(), hasWalked.end(), EdgeList[i].vertex1) == hasWalked.end() &&
                        find(hasWalked.begin(), hasWalked.end(), EdgeList[i].vertex2) != hasWalked.end()) {
                        hasWalked.push_back(EdgeList[i].vertex1);
                        printf("%d: <%d,%d>\n", connectedCount + 1, EdgeList[i].vertex2, EdgeList[i].vertex1);
                    } else {
                        hasWalked.push_back(EdgeList[i].vertex2);
                        printf("%d: <%d,%d>\n", connectedCount + 1, EdgeList[i].vertex1, EdgeList[i].vertex2);
                    }
                    connectedCount++;
                    costCount += EdgeList[i].weight;
                    notFound = false;
                    break;
                }
            }
            if (notFound)break;
        }
        printf("\nThe cost of minimum spanning tree: %d\n", costCount);
    }
};

int main() {
    GraphWithWeight graphWithWeight;
    int vertex1, vertex2, weight;
    int startFrom;
    cin >> startFrom;
    while (cin >> vertex1 >> vertex2 >> weight) {
        graphWithWeight.addData(vertex1, vertex2, weight);
    }
    graphWithWeight.minimalCost(startFrom);
}