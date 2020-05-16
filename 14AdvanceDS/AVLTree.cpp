#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node<T> left;
        Node<T> right;
        Node<T> parent;

        Node(T data){
            this->data = data;
            left = right = parent =  NULL;
        }

};
template<class T>
class AVLTree{
    private:
        Node<T> root;
        int currentSize;
    public:
        AVLTree(){
            root = NULL;
            currentSize = 0;
        }
    void insert(T data){
        Node<T> node(data);
        if(root == NULL){
            root = node;
            currentSize++;
            return;
        }
        add(root,node);
    }

    private:
        void add(Node<T> node,Node<T> newNode){
            if(newNode.data >= node.data){
                if(node.right == NULL){
                    node.right = newNode;
                    currentSize++;
                    newNode.parent = node;
                }else{
                    add(node.right,newNode);
                }
            }else{
                if(node.left == NULL){
                    node.left = newNode;
                    currentSize++;
                    newNode.parent = node;
                }else{
                    add(node.left,newNode);
                }
            }
        checkBalance(newNode);
        }

        void checkBalance(Node<T> node){
            if(node == NULL){
                return;
            }
            int leftHeight = height(node.left);
            int rightHeight = height(node.right);
            int balanceFactor = leftHeight - rightHeight;
            if(balanceFactor > 1 || balanceFactor < - 1){
                rebalance(node,leftHeight,rightHeight);
            }else{
                checkBalance(node.parent);
            }
        }
        int height(Node<T> node){
            if(node == NULL){
                return 0;
            }
            return 1 + max(height(node.left),height(node.right));
        }
        void rebalance(Node<T> node,int leftHeight,int rightHeight){
            if(leftHeight < rightHeight){
                
            }
        }

};

int main(){

}
