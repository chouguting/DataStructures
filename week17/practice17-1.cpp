#include <iostream>
#include <vector>

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

    void Union(int relation[], int target, int origin) {
        if (target > origin)swap(target, origin);
        if (relation[origin] != -1) {
            Union(relation, target, relation[origin]);
        } else {
            relation[origin] = target;
        }
    }

    int Find(int relation[], int target) {
        if (relation[target] == -1)return target;
        Find(relation, relation[target]);
    }

    //Kruskal's Algorithm
    void printMinimalCost() {
        int relation[listTop + 1];
        for (int i = 0; i <= listTop; i++)relation[i] = -1;
        sortEdgeList();
        int connectedCount = 0;
        int Indexer = 0;
        int costCount = 0;
        while (connectedCount < listTop) {
            if (Find(relation, EdgeList[Indexer].vertex1) == Find(relation, EdgeList[Indexer].vertex2)) {
                Indexer++;
                continue;
            } else {
                m
                cout << connectedCount + 1 << ": ";
                printf("<%d,%d>\n", EdgeList[Indexer].vertex1, EdgeList[Indexer].vertex2);
                Union(relation, EdgeList[Indexer].vertex1, EdgeList[Indexer].vertex2);
                costCount += EdgeList[Indexer].weight;
                Indexer++;
                connectedCount++;
            }
        }
        printf("\nThe cost of minimum spanning tree: %d\n", costCount);
    }
};

int main() {
    GraphWithWeight graphWithWeight;
    int vertex1, vertex2, weight;
    while (cin >> vertex1 >> vertex2 >> weight) {
        graphWithWeight.addData(vertex1, vertex2, weight);
    }
    graphWithWeight.printMinimalCost();
}