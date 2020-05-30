#include<iostream>
using namespace std;

//update the index and all the index dependent on that
void update(int *arr,int size,int index,int data){
    index+=1;

    while(index <= size){
        arr[index] += data;
        index = index + (index & (-index));   //take 2's complement AND with number then add with number
    }
}

int sum(int arr[],int index){
    index+=1;
    int sum = 0;
    while(index > 0){
        sum += arr[index];
        index = index - (index & (-index));      // take 2's complement of number then AND with number then subtract with number
    }
    return sum;
}

int rangeSum(int arr[],int i,int j){
    return sum(arr,j) - sum(arr,i-1);
}

int main(){
    int arr[] = {3,8,4,9,10,45,2,96,74,16,86,42,38,64,59,-4,192};
    int size = sizeof(arr)/sizeof(arr[0]);
    int arr1[size];
    for(int i = 0 ; i < size ; i++){
        arr1[i] = 0;
    }
    for(int i = 0 ; i < size ; i++){
        update(arr1,size,i,arr[i]);
    }
    int n,i,j;
    cin>>n;
    while(n-- > 0){
        cin>>i>>j;
        cout<<"sum from "<<i<<" to "<<j<<" = "<<rangeSum(arr1,i,j)<<endl;
    }

    return 0;
}