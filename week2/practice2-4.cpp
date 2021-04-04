//Week 2_加分題：交集法
#include <iostream>
using namespace std;
int fibonacciSeq(int length){
    if(length==1){
        return 0;
    }else if(length==2){
        return 1;
    }
    return fibonacciSeq(length-1)+fibonacciSeq(length-2);
}
int main(){
    int i;
    cin>>i;
    cout<<fibonacciSeq(i+1)<<endl;
    return 0;
}