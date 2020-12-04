#include <iostream>

using namespace std;
int add = 20;

void foo(int *&ptr) {
    ptr = &add;
}

int main() {
    int a = 5;
    int b = 3;
    int *ptr = &a;
    foo(ptr);
    cout << *ptr;
}