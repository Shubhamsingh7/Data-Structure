#include<iostream>
using namespace std;
template<class T>
class Node{
    public:
        T data;
        Node<T> *next;
    public:
        Node(T data){
            this->data = data;
            next = NULL;
        }
};
template<class T>
class Queue{
    private:
        Node<T> *front;
        Node<T> *rear;
    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }
        bool isEmpty(){
            return front == NULL;
        }
        void push(T data){
            Node<T> *currentNode = new Node<T>(data);
            if(front == NULL){
                front = currentNode;
                rear = front;
                return;
            }
            rear->next = currentNode;
            rear = currentNode;
        }
        void pop(){
            if(isEmpty()){
                return;
            }
            Node<T> *temp;
            front = front->next;
            temp = NULL;
        }
        void getFirst(){
            if(isEmpty()){
                return;
            }
            cout<<front->data<<endl;
        }
};
int main(){
    
    Queue<char> *q = new Queue<char>();
    for(int i = 0 ; i < 10 ; i++){        
        q->push('a' + i);   
    }
    q->getFirst();
    q->pop();
    q->pop();
    q->getFirst();
    q->pop();
    q->getFirst();
    q->pop();

    q->getFirst();
    q->pop();

    q->getFirst();
    q->getFirst();
    q->getFirst();
    q->pop();

    q->getFirst();
    return 0;
}