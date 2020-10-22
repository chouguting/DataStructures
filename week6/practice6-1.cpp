#include <iostream>

#define MAX_TERM 10000
using namespace std;

typedef struct {
    float coef; //係數
    unsigned int expon; //次數
} polynomial;

void printPoly(polynomial *start, polynomial *end);

void addPoly(
        polynomial *indexA, polynomial *finishA,
        polynomial *indexB, polynomial *finishB,
        polynomial resultReal[], polynomial **end_d) {
    int totalIndex = 0;

    polynomial result[100];
    while (indexA <= finishA && indexB <= finishB) {
        if (indexA->expon > indexB->expon) {
            result[totalIndex] = {indexA->coef, indexA->expon};
            indexA += 1;
        } else if (indexB->expon > indexA->expon) {
            result[totalIndex] = {indexB->coef, indexB->expon};
            indexB += 1;
        } else {
            result[totalIndex] = {indexA->coef + indexB->coef, indexA->expon};
            indexA += 1;
            indexB += 1;
        }
        totalIndex += 1;
    }

    while (indexA <= finishA) {
        result[totalIndex] = {indexA->coef, indexA->expon};
        totalIndex += 1;
        indexA++;
    }

    while (indexB <= finishB) {
        result[totalIndex] = {indexB->coef, indexB->expon};
        totalIndex += 1;
        indexB++;
    }
    for (int i = 0; i < totalIndex; i++) {
        resultReal[i] = result[i];
    }
    *end_d = &resultReal[totalIndex - 1];

}

void multiplyPoly(polynomial *a, polynomial *b, polynomial c[], polynomial *na, polynomial *nb, polynomial **nc) {
    polynomial *i;
    polynomial *j;

    polynomial result[100];
    polynomial *resultEnd = result - 1;

    for (i = a; i <= na; i++) {
        polynomial temp[100];
        int index = 0;
        for (j = b; j <= nb; j++) {
            temp[index].coef = i->coef * j->coef;
            temp[index].expon = i->expon + j->expon;
            index++;
        }
        addPoly(result, resultEnd, temp, &temp[index - 1], result, &resultEnd);

    }
    int index = 0;
    for (polynomial *i = result; i <= resultEnd; i++) {
        c[index++] = *i;
    }
    *nc = &c[index - 1];

}

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
    multiplyPoly(startA, startB, start_d, finishA, finishB, &end_d);
    printPoly(start_d, end_d);
}