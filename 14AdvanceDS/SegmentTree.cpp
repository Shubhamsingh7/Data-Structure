// minimum range query
#include<iostream>
using namespace std;

//O(n) time
void buildSegmentTree(int arr[],int tree[],int index,int start,int end){

    if(start > end){
        return;
    }
    if(start == end){
        tree[index] = arr[start];
        return;
    }
    int mid = (start + end)/2;
    int indexLeft = 2 * index + 1;
    int indexRight = 2 * index + 2;

    buildSegmentTree(arr,tree,indexLeft,start,mid);
    buildSegmentTree(arr,tree,indexRight,mid+1,end);
    tree[index] = min(tree[indexLeft],tree[indexRight]);
    return;
}

//Query  O(log n)
int query(int tree[],int index,int start,int end,int qStart,int qEnd){
    // no overlap
    if(qStart > end || qEnd < start){
        return INT_MAX;
    }
    // full overlap
    if(qStart <= start && qEnd >= end){ 
        return tree[index];
    }

    // partial overlap
    int mid = (start + end)/2;
    int indexLeft = 2 * index + 1;
    int indexRight = 2 * index + 2;

    int leftMin = query(tree,indexLeft,start,mid,qStart,qEnd);
    int rightMin = query(tree,indexRight,mid + 1,end,qStart,qEnd);
    return min(leftMin,rightMin);

}


// update Node
void updateNode(int tree[],int index,int start,int end,int val){
    // full overlap
    if(start == end){
        tree[index] = val;
        return;
    }
    // no overlap
    if(start > end){ 
        return;
    }

    // partial overlap
    
    int mid = (start + end)/2;
    int indexLeft = 2 * index + 1;
    int indexRight = 2 * index + 2;

    updateNode(tree,indexLeft,start,mid,val);
    updateNode(tree,indexRight,mid + 1,end,val);
    return;

}



int main(){
    int arr[] {3,7,2,7,5,6,3,1};
    int length = sizeof(arr)/sizeof(int);
    int tree[4*length];
    int index = 0;
    int start = 0;
    int end = length-1;
    buildSegmentTree(arr,tree,index,start,end);
    
    cout<<query(tree,0,0,length-1,3,6);
    return 0;
}