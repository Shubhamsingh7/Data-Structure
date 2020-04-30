#include<iostream>
using namespace std;
template<class T>
class Queue{
    private:
        int capacity;
        int size;
        T *queue;
        int rear;
        int front;
    public:
        Queue(int capacity){
            this->capacity = capacity;
            size = 0;
            queue = new T[capacity];
            rear = 0;
            front = 0;  
        }
        bool isEmpty(){
            return size == 0;
        }
        bool isFull(){
            return capacity == size;
        }
        void pop(){
            if(isEmpty()){
                return;
            }
            size = size - 1;
            front = (front + 1) % capacity;
        }
        void getFirst(){
            if(isEmpty()){
                return;
            }else{
                cout<<queue[front]<<endl;
            }
        }
        void push(T data){
            if(isFull())
                return;
            queue[rear] = data;
            size = size + 1;
            rear = (rear + 1) % capacity;
        }

};
int main(){
    Queue<char> *q = new Queue<char>(10);
    for(int i = 0 ; i < 19 ; i++){        
        q->push('a' + i);   
    }
    q->getFirst();
    q->pop();
    q->pop();
    q->pop();
    q->pop();
    q->getFirst();
    return 0;
}