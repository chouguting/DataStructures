//Week 2_練習三：插入排序法
#include <iostream>

using namespace std;

int insertionSort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        int location = 0;
        int findNum = array[i];
        for (int j = 0; j <= i; j++) {
            if (findNum < array[0]) {
                location = 0;
                break;
            }
            if (i > 0 && findNum > array[i - 1]) {
                location = i;
                break;
            }
            if (array[j] < findNum && array[j + 1] > findNum) {
                location = j + 1;
                break;
            }

        }
        int temp = array[i];
        for (int j = i; j > location; j--) {
            array[j] = array[j - 1];
        }
        array[location] = temp;

        for (int k = 0; k < size; k++) {
            cout << array[k];
        }
        cout << endl;
    }
}

int main() {

    int size;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)cin >> array[i];
    insertionSort(array, size);

}