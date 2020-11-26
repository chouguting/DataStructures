#include <iostream>

using namespace std;

using namespace std;


class LinkedPoly {
    struct listNode {
        int coef;
        int expo;
        listNode *nextPtr;
    };
public:
    listNode *frontPtr;

    LinkedPoly() {
        frontPtr = nullptr;
    }

    void add(int coefNum, int expoNum) {
        listNode *temp = new listNode;
        temp->nextPtr = nullptr;
        temp->coef = coefNum;
        temp->expo = expoNum;
        listNode *locator = frontPtr;
        if (frontPtr == nullptr) {
            frontPtr = temp;
            return;
        }
        if (expoNum > frontPtr->expo) {
            temp->nextPtr = frontPtr;
            frontPtr = temp;
            return;
        }
        while (frontPtr != nullptr && locator->nextPtr != nullptr) {
            if (locator->nextPtr != nullptr && locator->nextPtr->expo < expoNum) {
                break;
            }
            locator = locator->nextPtr;
        }
        temp->nextPtr = locator->nextPtr;
        locator->nextPtr = temp;
    }


    void printPoly() {
        for (listNode *i = frontPtr; i != nullptr; i = i->nextPtr) {
            if (i->coef == 0) {
                continue;
            }
            if (i != frontPtr && i->coef >= 0) {
                printf("+");
            }
            printf("%d", i->coef);
            if (i->expo > 0) {
                cout << "x";
            }
            if (i->expo > 1) {
                cout << "^" << i->expo;
            }
        }
        cout << endl;
    }

    LinkedPoly operator+(LinkedPoly B) {
        LinkedPoly ans;
        listNode *aIndex = frontPtr;
        listNode *bIndex = B.frontPtr;
        while (aIndex != nullptr && bIndex != nullptr) {
            if (aIndex->expo > bIndex->expo) {
                ans.add(aIndex->coef, aIndex->expo);
                aIndex = aIndex->nextPtr;
            } else if (aIndex->expo < bIndex->expo) {
                ans.add(bIndex->coef, bIndex->expo);
                bIndex = bIndex->nextPtr;
            } else {
                ans.add(aIndex->coef + bIndex->coef, aIndex->expo);
                aIndex = aIndex->nextPtr;
                bIndex = bIndex->nextPtr;
            }
        }
        while (aIndex != nullptr) {
            ans.add(aIndex->coef, aIndex->expo);
            aIndex = aIndex->nextPtr;
        }
        while (bIndex != nullptr) {
            ans.add(bIndex->coef, bIndex->expo);
            bIndex = bIndex->nextPtr;
        }
        return ans;
    }

    LinkedPoly operator*(LinkedPoly B) {
        LinkedPoly ans;
        LinkedPoly theMiddleTerm[100];
        listNode *bIndex = B.frontPtr;
        int midTermSize = 0;
        while (bIndex != nullptr) {
            for (listNode *aIndex = frontPtr; aIndex != nullptr; aIndex = aIndex->nextPtr) {
                theMiddleTerm[midTermSize].add(aIndex->coef * bIndex->coef, aIndex->expo + bIndex->expo);
            }
            midTermSize++;
            bIndex = bIndex->nextPtr;
        }
        for (int i = 0; i < midTermSize; i++) {
            ans = ans + theMiddleTerm[i];
        }
        return ans;
    }

};


int main() {

    LinkedPoly A;
    LinkedPoly B;
    while (true) {
        int coef, expo;
        cin >> coef;
        if (coef == -1)break;
        cin >> expo;
        A.add(coef, expo);
    }

    while (true) {
        int coef, expo;
        cin >> coef;
        if (coef == -1)break;
        cin >> expo;
        B.add(coef, expo);
    }

    LinkedPoly addResult = A + B;
    addResult.printPoly();

    LinkedPoly multResult = A * B;
    multResult.printPoly();
}