
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool isPrimeNumber(long long n){
    if(n==1)
        return false;
    for(long long i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    }
    return true;
}
int main() {
    long num;
    cin>>num;
    vector<int> result;
    long tempNum=num;
    if((num==1||isPrimeNumber(num))){
        cout<<num<<endl;
        return 0;
    }
    for(int i=0;!isPrimeNumber(tempNum);i++){
        for(int j=2;j<=num;j++){
                if (tempNum % j == 0) {
                    tempNum /= j;
                    result.push_back(j) ;
                    break;
                }

        }
    }
    int lastNum = -1;
    int counter=1;
    bool flag=false;

    for(int i=0;i<result.size();i++){
        if(i>0&&result[i]==result[i-1]){
            counter+=1;
            flag= false;
        } else{
            if(counter>1){
                cout<<"^"<<counter<<" * ";
                counter=1;
            }

            cout<<result[i];
            if(i!=result.size()-1&&counter==1&&result[i]!=result[i+1]){
                cout<<" * ";
            }


            flag=false;
        }
    }
    int a=(int)result[result.size()-1];
    if(tempNum==a){
        counter++;
        cout<<"^"<<counter;
    }else{
        if(counter>1){
            cout<<"^"<<counter<<" * ";
        }else{
            cout<<" * ";
        }
        cout<<tempNum;
    }
    cout<<"\n";


}
