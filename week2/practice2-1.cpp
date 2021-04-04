//Week 2_練習一：選擇排序法
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

int main(){
    int size;
    cin>>size;
    int* arr=new int[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    selectionSort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i];
        if(i!=size-1){
            cout<<" ";
        }else{
            cout<<endl;
        }
    }
    delete[] arr;
    return 0;
}