#include<iostream>
using namespace std;

void buildTree(int *arr,int *tree,int index,int start,int end){
    if(start > end){
        return;
    }
    if(start == end){
        tree[index] = arr[start];
        return;
    }
    int mid = (start + end)/2;

    buildTree(arr,tree,2*index + 1,start,mid);
    buildTree(arr,tree,2*index+2,mid+1,end);
    int left = tree[2*index+1];
    int right = tree[2*index+2];
    tree[index] = min(left,right);
    return;
}

// update node

void updateNode(int *tree,int *arr,int index,int start,int end,int updateIndex,int element){
    if((updateIndex > end) || (updateIndex < start)){
        return;
    }
    if(start == end){
        tree[index] = element;
        return;
    }
    int mid = (start + end)/2;
    updateNode(tree,arr,2*index+1,start,mid,updateIndex,element);
    updateNode(tree,arr,2*index+2,mid+1,end,updateIndex,element);
    tree[index] = min(tree[2*index+1],tree[2*index+2]);
    return;
}

// update range

void updateRange(int *tree,int *arr,int index,int start,int end,int ustart,int uend,int element){
    //Zero overlap
    if((start > uend) || (end < ustart)){
        return;
    }
    if(start == end){
        tree[index] += element;
        return;
    }

    int mid = (start + end)/2;
    updateRange(tree,arr,2*index+1,start,mid,ustart,uend,element);
    updateRange(tree,arr,2*index+2,mid+1,end,ustart,uend,element);
    tree[index] = min(tree[2*index+1],tree[2*index+2]);
    return;
}


int query(int *tree,int index,int start,int end,int qstart,int qend){
    //Zero overlap
    if((start > qend) || (end < qstart)){
        return INT_MAX;
    }
    // Full overlap
    if(start >= qstart && end <= qend){
        return tree[index];
    }
    int mid = (start + end)/2;
    int left = query(tree,2*index+1,start,mid,qstart,qend);
    int right = query(tree,2*index+2,mid+1,end,qstart,qend);
    return min(left,right);

}

int main(){
    int arr[] = {10,8,9,8,24,45,2,5,7,63};
    int length = sizeof(arr)/sizeof(arr[0]);
    int *tree = new int[4*length];
    int index = 0;
    int start = 0;
    int end = (length - 1);
    buildTree(arr,tree,index,start,end);
        cout<<query(tree,index,start,end,start,end)<<endl;
        cout<<query(tree,index,start,end,4,end)<<endl;
        cout<<query(tree,index,start,end,1,3)<<endl;
        updateNode(tree,arr,index,start,end,5,-10);
        cout<<query(tree,index,start,end,start,end)<<endl;
        updateRange(tree,arr,start,start,end,start,5,100);
        cout<<query(tree,index,start,end,start,end)<<endl;

        
    
    return 0;
}