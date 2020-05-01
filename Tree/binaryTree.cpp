//binary tree using array reprasentation
#include<iostream>
using namespace std;

template<class T>
class Tree{
    private:
        T *binaryArray;
        int size;
    public:
        Tree(int size){
            binaryArray = new T[size];
            this->size = size;
        }
        void insert(T array[]){
            for(int i = 0 ; i < size ;i++){
                binaryArray[i] = array[i];
            }
        }
        void display(){
            for(int i = 0 ; i < size ;i++){
                cout<<binaryArray[i]<<", ";
            }
        }
        //preOrder Traversal
        void preOrder(int index){
            if(index >= size){
                return;
            }
            cout<<binaryArray[index]<<", ";
            preOrder(2*index + 1);
            preOrder(2*index + 2);
        }
        // inorder traversal
        void inorder(int index){
            if(index >= size)
                return;
            inorder(2*index + 1);
            cout<<binaryArray[index]<<", ";
            inorder(2*index + 2);
        }
        void postorder(int index){
            if(index >= size){
                return;
            }
            postorder(2*index + 1);
            postorder(2*index + 2);
            cout<<binaryArray[index]<<", ";
        }
};


int main(){
    Tree<int> *tree = new Tree<int>(10);
    int array[] {2,8,6,25,3,6,89,12,0,7};
    tree->insert(array);
    cout<<"Tree elements are :- ";
    tree->display();
    cout<<endl;
    cout<<"preOrder Traversal :- ";
    tree->preOrder(0);
    cout<<endl;
    cout<<"Inorder Traversal :- ";
    tree->inorder(0);
    cout<<endl;
    cout<<"post order traversal :- ";
    tree->postorder(0);
    cout<<endl;
    return 0;
}