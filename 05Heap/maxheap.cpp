#include<iostream>
using namespace std;
class MaxHeap{
    private:
        int *array;
        int current;
        int capacity;
    public:
        MaxHeap(int capacity){
            this->capacity = capacity;
            array = new int[capacity];
            current = -1;
        }

        void insert(int data){
            if(current >= capacity){
                return;
            }
            if(current == -1){
                array[0] = data;
                current++;
                return;
            }
            array[++current] = data;
            int index = current;
            int parent = (index/2);
            while(parent != 0){
                if(data > array[parent]){
                    int temp = array[parent];
                    array[parent] = array[index];
                    array[index] = temp;
                    index = parent;
                    parent = (parent/2);
                }else{
                    return;
                }
            }
            if(data > array[parent]){
                    int temp = array[parent];
                    array[parent] = array[index];
                    array[index] = temp;
                }

        }


        void display(){
            cout<<"Level order traversal of max heap :- ";
            for(int i = 0 ; i < current ;i++){
                cout<<array[i]<<", ";
            }
            cout<<endl;
        }

        void deleteMax(){
            if(current == -1){
                return;
            }
            if(current == 0){
                current--;
                return;
            }
            array[0] = array[current];
            current--;
            int index = 0;
            while(index <= current){
                if((2*index + 1) > current && (2*index + 2) > current){
                    return;
                }
                int greatestIndex = (array[2*index + 1] > array[2*index + 2]) ? (2*index + 1) : (2*index + 2);
                if(array[index] < array[greatestIndex]){
                    int temp = array[index];
                    array[index] = array[greatestIndex];
                    array[greatestIndex] = temp;
                    index = greatestIndex;
                }else{
                    return;
                }
            }
        }


        
        void get(){
            if(current == -1){
                return;
            }
            cout<<"Maximum element is :- "<<array[0]<<endl;
        }
};
int main(){
    MaxHeap *heap = new MaxHeap(10);
    heap->insert(40);
    heap->insert(12);
    heap->get();
    heap->insert(60);
    heap->insert(20);
    heap->get();
    heap->insert(25);
    heap->insert(10);
    heap->insert(18);
    heap->get();
    heap->insert(100);
    heap->insert(5);
    heap->get();
    heap->display();
    heap->deleteMax();
    heap->deleteMax();
    heap->insert(30);

    heap->insert(102);

    heap->get();

    // heap->deleteMax();
    heap->display();


}