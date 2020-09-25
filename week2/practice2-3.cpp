#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insertionSort(int* array,int length){
    int* arr2=new int[length];
    int currentSize=0;
    arr2[0]=array[0];
    currentSize++;
    for(int i=1;i<length;i++){
        int insertPlace=0;
        int x=0;
        while(array[i]>arr2[insertPlace]){
            if(insertPlace>=currentSize){
                break;
            }
            insertPlace++;
        }
        //insertPlace-=1;
        for(int j=currentSize-1;j>=insertPlace;j--){
            if(j<length-1){
                swap(&arr2[j+1],&arr2[j]);
            }
        }
        arr2[insertPlace]=array[i];
        currentSize++;

        if(i<=2){
            for(int j=0;j<currentSize;j++){
                cout<<arr2[j];
                if(j!=currentSize-1){
                    cout<<" ";
                }else{
                    cout<<endl;
                }
            }
        }

    }
    for(int i=0;i<length;i++){
        array[i]=arr2[i];
    }
    delete[] arr2;

}

int main(){
    int size;
    cin>>size;
    int* arr=new int[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    insertionSort(arr,size);

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