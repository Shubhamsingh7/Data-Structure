//stack using linked list
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
class Stack{
    private:
        Node<T> *TOP;
    public:
        Stack(){
            TOP = NULL;
        }
        void push(T data){
            Node<T> *currentNode = new Node<T>(data);
            if(TOP == NULL){
                TOP = currentNode;

                return;
            }
            currentNode->next = TOP;
            TOP = currentNode;
        }
        void pop(){
            if(TOP == NULL){
                cout<<"Stack Empty"<<endl;
                return;
            }
            Node<T> *ptr = TOP;
            TOP = TOP->next;
            delete ptr;
        }
        void peek(){
            if(TOP == NULL){
                cout<<"Stack Empty"<<endl;
                return;
            }
            cout<<TOP->data<<endl;
        }
};
int main(){
    Stack<int> *stack = new Stack<int>();
    stack->peek();
    for(int i = 0 ; i < 100 ; i++){
        stack->push(i);
    }
    for(int i = 0 ; i < 25 ; i++){
        stack->peek();
        stack->pop();
    }
    stack->peek();
    stack->peek();
    stack->peek();
    stack->peek();
    stack->peek();
    return 0;
}