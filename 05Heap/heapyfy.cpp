//min heap
#include<iostream>
using namespace std;
class Heap{
    private:
        int *arr;
        int capacity;
        int size;


        void heapify(int i){
            if(i>=capacity){
                return;
            }
            int left = (2*i + 1);
            int right = (2*i + 2);
            int smallestIndex = i;
            if((left <= size) && arr[left] < arr[i]){
                smallestIndex = left;
            }
            if((right <= size) && arr[right] < arr[smallestIndex]){
                smallestIndex = right;
            }
            if(smallestIndex != i){
                swap(i,smallestIndex);
                heapify(smallestIndex);
            }else{
                return;
            }
        }

        void swap(int i,int j){
            arr[i] = arr[i] ^ arr[j];
            arr[j] = arr[i] ^ arr[j];
            arr[i] = arr[i] ^ arr[j];
        }
        
    public:
        Heap(int capacity){
            this->capacity = capacity;
            arr = new int[capacity];
            size = -1;
        }

        void insert(int data){
            if(size >= capacity){
                return;
            }
            size++;
            arr[size] = data;
            int parentIndex = size;
            while( parentIndex != 0){
                heapify(parentIndex);
                parentIndex = parentIndex/2;
            }
            heapify(0);
        } 

        void display(){
            
            for(int i = 0 ; i <= size ;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        void extractMin(){
            if(size == -1){
                return;
            }
            cout<<arr[0]<<endl;
            arr[0] = arr[size];
            size--;
            heapify(0); 
        }    

};

int main(){
    Heap *heap = new Heap(10);
    heap->insert(5);
    heap->insert(15);
    heap->insert(8);
    heap->insert(9);
    heap->extractMin();
    heap->extractMin();

    heap->display();
    heap->insert(16);
    heap->insert(3);
    heap->insert(37);
    heap->extractMin();

    heap->display();
    heap->extractMin();
    heap->display();




    return 0;
}