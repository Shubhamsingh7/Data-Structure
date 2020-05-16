#include<iostream>
using namespace std;

//AVL Node class
template<class T>
class Node{
    public:
        T data;
        Node<T> *left;
        Node<T> *right;
        Node<T> *parent;

        Node(T data){
            this->data = data;
            left = right = parent =  NULL;
        }

};
//AVl tree class
template<class T>
class AVLTree{
    public:
        Node<T> *root;
        int currentSize;
    public:
        AVLTree(){
            root = NULL;
            currentSize = 0;
        }
    
        //insert data in AVL tree
        void insert(T data){ 
            Node<T> *node = new Node<int>(data);
            if(root == NULL){
                root = node;
                currentSize++;
                return;
            }
            add(root,node);
        }

    void preorder(Node<T> *node){
        if(node == NULL)
            return;
        cout<<node->data<<", ";
        preorder(node->left);
        preorder(node->right);
    }

    private:
        // add node recursively to the currect position
        void add(Node<T> *node,Node<T> *newNode){
            if(newNode->data >= node->data){
                if(node->right == NULL){
                    node->right = newNode;
                    currentSize++;
                    newNode->parent = node;
                }else{
                    add(node->right,newNode);
                }
            }else{
                if(node->left == NULL){
                    node->left = newNode;
                    currentSize++;
                    newNode->parent = node;
                }else{
                    add(node->left,newNode);
                }
            }
        checkBalance(newNode);
        }
        // check the height balence of current node
        void checkBalance(Node<T> *node){
            if(node == NULL){
                return;
            }
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            int balanceFactor = leftHeight - rightHeight;
            if(balanceFactor > 1 || balanceFactor < - 1){
                rebalance(node,leftHeight,rightHeight);
                checkBalance(node->parent);
            }else{
                checkBalance(node->parent);
            }
        }
        

        // return height of current node
        int height(Node<T> *node){
            if(node == NULL){
                return 0;
            }
            return 1 + max(height(node->left),height(node->right));
        }

        //rebalence the current node
        void rebalance(Node<T> *node,int leftHeight,int rightHeight){
            if(leftHeight > rightHeight){
                if(height(node->left->left) > height(node->left->right)){
                    node = rightRotation(node);
                }else{
                    node = leftRightRotation(node);
                }
            }else{
                if(height(node->right->right) > height(node->right->left)){
                    node = leftRotation(node);
                }else{
                    node = rightLeftRotation(node);
                }
            }
            if(node->parent == NULL){
                root = node;
            }
        }

        //left rotation
        Node<T>* leftRotation(Node<T> *node){
            Node<T> *temp = node->right;
            node->right = temp->left;
            temp->left = node;
            return temp;
        }

        // right rotation
        Node<T>* rightRotation(Node<T> *node){
            Node<T> *temp = node->left;
            node->left = temp->right;
            temp->right = node;
            return temp;
        }

        // left right rotation
        Node<T>* leftRightRotation(Node<T> *node){
            node->left = leftRotation(node->left);
            return rightRotation(node);
        }

        //right left rotation
        Node<T>* rightLeftRotation(Node<T> *node){
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }




};

int main(){

    AVLTree<int> tree;
    for(int i = 0 ; i <= 100 ; i++){
        tree.insert(i);
    }
        tree.insert(10);
        tree.insert(8);
        tree.insert(7);
        tree.insert(6);
        tree.insert(16);
        tree.insert(98);
        tree.preorder(tree.root);
        cout<<tree.currentSize<<endl;

}
