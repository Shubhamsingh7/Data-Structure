#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}
void bubble_sort(int arr[],int size){
    if(size == 1)
        return;
    bool sortedFlag = false;
        int pass = 0;
    for(int i = 0 ; i < size - 1 ;i++){
        pass++;
        sortedFlag = false;
        for(int j = 0 ; j < size - 1 - i ; j++){
            if(arr[j] > arr[j+1]){  
                swap(&arr[j],&arr[j+1]);
                sortedFlag = true;
            }
        }
        if(sortedFlag == false){   
            cout<<pass<<endl;
            return;
        }
    }
        cout<<pass<<endl;
}

int main(){

    int arr[] = {5,61,7,12,8,20,29,114,121,32,400,820};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,size);
    for(int i = 0 ;i < size ;i++){
        cout<<arr[i]<<" ";
    }

}