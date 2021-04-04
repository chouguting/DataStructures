//Week 16_加分題：計算圖形的 low 與 dfn 值
#include <iostream>
#include <vector>

using namespace std;

class AdjacentLists {
private:
    vector<int> theList[500];
    int listTop;

    void DFNAndLOW(vector<int> *location, vector<int> *lastLocation, bool hasVisited[], int dfnList[], int lowList[],
                   int &index) {
        dfnList[location - theList] = lowList[location - theList] = index++;
        hasVisited[location - theList] = true;
        for (int i = 0; i < location->size(); i++) {
            if (!hasVisited[(*location)[i]]) {
                DFNAndLOW(&theList[(*location)[i]], location, hasVisited, dfnList, lowList, index);
                if (lowList[(*location)[i]] < lowList[location - theList]) {
                    lowList[location - theList] = lowList[(*location)[i]];
                }
            } else if (lastLocation != &theList[(*location)[i]]) {
                if (lowList[(*location)[i]] < dfnList[location - theList]) {
                    lowList[location - theList] = lowList[(*location)[i]];
                }
            }
        }
    }

public:
    AdjacentLists() {
        listTop = -1;
    }

    void addData(int num1, int num2) {
        if (max(num1, num2) > listTop)listTop = max(num1, num2);
        theList[num1].push_back(num2);
        theList[num2].push_back(num1);
    }

    void DFNAndLOW() {
        bool hasVisited[500] = {};
        int dfnList[listTop + 1];
        int lowList[listTop + 1];
        int index = 0;
        DFNAndLOW(&theList[3], nullptr, hasVisited, dfnList, lowList, index);
        cout << "   ";
        for (int i = 0; i <= listTop; i++) {
            cout << " " << i;
        }
        cout << "\ndfn";
        for (int i = 0; i <= listTop; i++) {
            cout << " " << dfnList[i];
        }
        cout << "\nlow";
        for (int i = 0; i <= listTop; i++) {
            cout << " " << lowList[i];
        }
        cout << endl;
    }
};

int main() {
    AdjacentLists adjacentLists;
    int num1, num2;
    while (cin >> num1 >> num2) {
        adjacentLists.addData(num1, num2);
    }
    adjacentLists.DFNAndLOW();
}