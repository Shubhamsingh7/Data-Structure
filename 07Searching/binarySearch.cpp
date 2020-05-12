//binary search
#include<bits/stdc++.h>
using namespace std;
int binary_search(int arr[],int n,int data){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = (left + right)/2;
        if(arr[mid] == data){
            return mid;
        }
        if(arr[mid] > data){
            right = mid -1;
        }else{
            left = left + 1;
        }
    }
    return -1;
}

int helper(int arr[],int left,int right,int data){
    int mid = (left+right)/2;
    if(left > right){
        return -1;
    }
    if(arr[mid] == data){
        return mid;
    }
    if(arr[mid] > data){
        return helper(arr,left,mid-1,data);
    }else{
        return helper(arr,mid+1,right,data);
    }
}

int binary_search_recursiv(int arr[],int n,int data){
    int left = 0;
    int right = n-1;
    return helper(arr,left,right,data);
}

int main(){
    int arr[] {1,4,7,9,16,17,47,69,78,95,125,423,864,3245};
    int size = sizeof(arr)/sizeof(arr[0]);
    // cout<<binary_search(arr,size,37);
    cout<<binary_search_recursiv(arr,size,17);
    return 0;
}