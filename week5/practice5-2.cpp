#include <iostream>

#define MAX_TERM 10000
using namespace std;

typedef struct {
    float coef; //係數
    unsigned int expon; //次數
} polynomial;

void printPoly(polynomial *start, polynomial *end) {
    for (polynomial *i = start; i <= end; i++) {
        if (i->coef == 0) {
            continue;
        }
        if (i != start && i->coef >= 0) {
            printf("+");
        }
        if (i == end) {
            if (i->expon == 0) {
                printf("%.2lf\n", i->coef);
            } else {
                printf("%.2lfx^%d\n", i->coef, i->expon);
            }
        } else {
            printf("%.2lfx", i->coef);
            if (i->expon > 1) {
                printf("^%d", i->expon);
            }
        }
    }
}

int main() {
    polynomial p[MAX_TERM];
    int ATimes, BTimes;
    int totalIndex = 0;
    cin >> ATimes;
    polynomial *startA, *finishA, *startB, *finishB, *start_d, *end_d;
    startA = p;
    for (int times = 0; times < ATimes; times += 1) {
        cin >> p[totalIndex].coef;
        cin >> p[totalIndex].expon;
        totalIndex += 1;
    }
    finishA = p + totalIndex - 1;
    printPoly(startA, finishA);
    startB = p + totalIndex;
    cin >> BTimes;
    for (int times = 0; times < BTimes; times += 1) {
        cin >> p[totalIndex].coef;
        cin >> p[totalIndex].expon;
        totalIndex += 1;
    }
    finishB = p + totalIndex - 1;
    printPoly(startB, finishB);

    start_d = p + totalIndex;


    polynomial *indexA = startA;
    polynomial *indexB = startB;
    //加法
    while (indexA <= finishA && indexB <= finishB) {
        if (indexA->expon > indexB->expon) {
            p[totalIndex] = {indexA->coef, indexA->expon};
            indexA += 1;
        } else if (indexB->expon > indexA->expon) {
            p[totalIndex] = {indexB->coef, indexB->expon};
            indexB += 1;
        } else {
            p[totalIndex] = {indexA->coef + indexB->coef, indexA->expon};
            indexA += 1;
            indexB += 1;
        }
        totalIndex += 1;
    }

    while (indexA <= finishA) {
        p[totalIndex] = {indexA->coef, indexA->expon};
        totalIndex += 1;
        indexA++;
    }

    while (indexB <= finishB) {
        p[totalIndex] = {indexB->coef, indexB->expon};
        totalIndex += 1;
        indexB++;
    }
    end_d = p + totalIndex - 1;
    printPoly(start_d, end_d);
}