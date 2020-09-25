#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int size;
    cin >> size;
    getchar();
    vector<int> black;
    vector<int> white;
    vector<int> variable;

    string sentence;
    getline(std::cin, sentence);
    istringstream iss(sentence);
    vector<int> numbers;
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }


    int index = 1;
    int j = 0;
    while (index <= size) {
        if (j < numbers.size()) {
            for (int k = 0; k < numbers[j]; k++) {
                black.push_back(index);
                index++;
            }
        }
        white.push_back(index);
        j++;
        if (j >= numbers.size()) {
            variable.push_back(index);
        }
        index++;
    }

    int canBeMoved = variable.size();

    vector<int> result = black;

    int r = 0;
    int plus = 1;

    while (true) {
        vector<int> tempBlack;
        int flag = 0;
        index = 1;
        j = 0;
        while (index <= size) {

            if (j < numbers.size()) {
                if (j == r) {
                    index += plus;
                }
                for (int k = 0; k < numbers[j]; k++) {
                    tempBlack.push_back(index);
                    index++;
                }
            }

            j++;
            index++;
        }
        for (int s = 0; s < result.size();) {
            if (find(tempBlack.begin(), tempBlack.end(), result[s]) == tempBlack.end()) {
                result.erase(remove(result.begin(), result.end(), result[s]), result.end());
                continue;
            }
            s++;
        }
        if (tempBlack == black && plus >= variable.size()) {
            break;
        }g
        r++;
        plus++;
    }

    index = 0;
    for (int i = 0; i < size; i++) {
        if (i == result[index] - 1) {
            cout << "1";
            if (index < result.size() - 1) {
                index++;
            }
        } else {
            cout << "0";
        }
        if (i != size - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    return 0;
}