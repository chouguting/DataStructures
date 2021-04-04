//Week 5_練習三：稀疏矩陣表示法
#include <iostream>
#include <vector>

using namespace std;
typedef struct {
    int xCoord;
    int yCoord;
    int theNumData;
} points;

int main() {
    int width, depth;
    cin >> depth >> width;
    int table[depth][width];
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < width; j++) {
            cin >> table[i][j];
        }
    }

    vector<points> thePointList;
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < width; j++) {
            if (table[i][j] != 0) {
                points thePointThatIsNotZero = {j, i, table[i][j]};
                thePointList.push_back(thePointThatIsNotZero);
            }

        }
    }
    cout << depth << " " << width << " " << thePointList.size() << endl;
    for (int i = 0; i < thePointList.size(); i++) {
        printf("%d %d %d\n",
               thePointList[i].yCoord,
               thePointList[i].xCoord,
               thePointList[i].theNumData);
    }
}
