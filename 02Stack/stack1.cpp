//stack using array
#include<iostream>
using namespace std;
#define STACK_SIZE 10
template<class T>
class Stack{
    private:
        T *stack;
        int TOP;
        int size;
    public:
        Stack(int size){
            this->size = size;
            stack = new T[size];
            TOP = -1;
        }
        void push(T data){
            if(TOP == (size - 1)){
                cout<<"Stack OverFlow"<<endl;
                return;
            }
            TOP++;
            stack[TOP] = data;
        }
        void peek(){
            if(TOP == -1){
                return;
            }
            cout<<"Top Element :-"<<stack[TOP]<<endl;
        }
        void pop(){
            if(TOP == -1){
                cout<<"Stack Empty"<<endl;
                return;
            }
            TOP--;
        }


};

int main(){
    Stack<char> *stack = new Stack<char>(STACK_SIZE);
    for(int i = 0 ;  i <= 10 ; i++){
        stack->push('a' + i);
    }
    for(int i = 0 ;  i <= 10 ; i++){
        stack->peek();
        stack->pop();
    }
    stack->pop();
    stack->peek();
    return 0;
}