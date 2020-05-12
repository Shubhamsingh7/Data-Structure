//merge sort
#include<iostream>
using namespace std;

void merge(int arr[],int left,int right){
    int size = (right - left + 1);     
    int *temp = new int[size];

    int mid = (left + right)/2;
    int i = left;
    int j = mid + 1;
    int k = 0;   // temp index from 0 as its a new array whose size may be less then left or right

    while((i <= mid) && ( j <= right)){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int i = left ; i <= right ;i++){
        arr[i] = temp[i - left];        //subtract left from i to make temp index point from 0 index
    }
    delete temp;
}
// time O(nlogn) | space O(n)
void merge_sort(int arr[],int left,int right){
    if(left >= right){             // check if array can't be further divided
        return;
    }
    int mid = (left + right)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);
    merge(arr,left,right);
}


int main(){
    int arr[] {6,9,2,4,3,96,25,14,96,2,15,78,35,12,52};
    int size = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,size-1);
    for(int i = 0 ; i < size ;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}