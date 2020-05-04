// O(n) time  | O(1) space
#include<iostream>
using namespace std;

void swap(int arr[],int left,int right){
    arr[left] = arr[left] ^ arr[right];
    arr[right] = arr[left] ^ arr[right];
    arr[left] = arr[left] ^ arr[right];
}

int partition(int arr[],int left,int right,int pivot){
    
    while(left <= right){
        while(arr[left] < pivot){
            left++;
        }
        while(arr[right] > pivot){
            right--;
        }
        if(left <= right){
            swap(arr,left,right);
            left++;
            right--;
        }
    }
    return left - 1;
}

void quick_sort(int arr[],int left,int right){
    
    if(left >= right){
        return;
    }
    int pivot = arr[(left + right)/2];
    int partitionIndex = partition(arr,left,right,pivot);
    quick_sort(arr,left,partitionIndex - 1);
    quick_sort(arr,partitionIndex+1,right);

}

int main(){
    int arr[] {5,9,3,15,85,45,69,25,85,16,365,482,294};
    int size = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,size-1);
    for(int i = 0 ; i < size ;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}