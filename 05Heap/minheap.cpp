// using heapyfy
#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}

void heapyfyIterative(int arr[],int i,int heapSize){
    if(i >= heapSize){
        return;
    }
    while( i < heapSize){
        int left = (2*i + 1);
        int right = (2*i + 2);

        bool isInternal = left < heapSize;
        int smallestIndex = i;
        if(isInternal && arr[left] < arr[i]){
            smallestIndex = left;
        }
        isInternal = right < heapSize;
        if(isInternal && arr[right] < arr[smallestIndex]){
            smallestIndex = right;
        }
        if(smallestIndex != i){
            swap(arr,i,smallestIndex);
            i = smallestIndex;
        }else{
            return;
        }
    }
}

void heapify(int arr[],int i,int heapSize){
    int left = (2*i + 1);
    int right = (2*i + 2);

    bool isInternal = left < heapSize;
    int smallestIndex = i;
    if(isInternal && arr[left] < arr[i]){
        smallestIndex = left;
    }
    isInternal = right < heapSize;
    if(isInternal && arr[right] < arr[smallestIndex]){
        smallestIndex = right;
    }
    if(smallestIndex != i){
        swap(arr,i,smallestIndex);
        heapify(arr,smallestIndex,heapSize);
    }
}

void buildMinHeap(int arr[],int size){
    int heapsize = size;
    int lastInternalNode = (size/2) - 1;
    for(int i = lastInternalNode ; i >=0 ; i--){
        heapyfyIterative(arr,i,heapsize);
    }
}

int main(){
    int arr[] = {8,6,18,2,157,5,13,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    buildMinHeap(arr,size);
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}