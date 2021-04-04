//Week 2_練習二：二元搜尋法
#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selectionSort(int* array,int length){
    for(int i=0;i<length-1;i++){
        int min=array[i];
        int changeIndex=i;
        for(int j=i;j<length;j++){
            if (array[j]<min){
                changeIndex=j;
                min=array[j];
            }
        }
        swap(array+i,array+changeIndex);
    }
}

int binarySearch(int* array,int searchNum,int size){
    int* org=array;
    int* left=array;
    int* right=array+size-1;
    while (right>=left){
        int* middle=left+(right-left)/2;
        if(*middle>searchNum){
            right=middle-1;
        } else if(*middle<searchNum){
            left=middle+1;
        } else{
            return middle-org;
        }
    }
    return -1;
}

int main(){
    int size;
    int searchNum;
    cin>>searchNum;
    cin>>size;
    int* arr=new int[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    selectionSort(arr,size);
    cout<<binarySearch(arr,searchNum,size)<<endl;
    delete[] arr;
    return 0;
}