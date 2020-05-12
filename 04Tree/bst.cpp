//bst 
#include<iostream>
#include<queue>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node<T> *left;
        Node<T> *right;

        Node(T data){
            this->data = data;
            left = right = NULL;
        }
};

template<class T>
class BST{
    public:
        Node<T> *root;
    public:
        BST(){
            root = NULL;
        }

        void addNode(T data){
            Node<T> *currentNode = new Node<T>(data);
            if(root == NULL){
                root = currentNode;
                return;
            }
            Node<T> *ptr = root;
            while(ptr->left != NULL && ptr->right != NULL){
                if(data >= ptr->data){
                    ptr = ptr->right;
                }else{
                    ptr = ptr->left;
                }
            }
            if(data >= ptr->data){
                    ptr->right = currentNode;
                }else{
                    ptr->left = currentNode;
                }  
        }



        void preOrder(Node<T> * root){
            if(root == NULL){
                return;
            }
            cout<<root->data<<", ";
            preOrder(root->left);
            preOrder(root->right);
        }
        void postOrder(Node<T> *root){
            if(root == NULL){
                return;
            }
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<", ";
        }
        void inOrder(Node<T> *root){
            if(root == NULL){
                return;
            }
            inOrder(root->left);
            cout<<root->data<<", ";
            inOrder(root->right);

        }

        void levelOrderTraversal(Node<T> *root){
            cout<<"Level Order Traversal :- ";
            queue<Node<T>*> q;
            q.push(root);
            while(!q.empty()){
                Node<T> *currentNode = q.front();
                q.pop();
                cout<<currentNode->data<<", ";
                if(currentNode->left != NULL){
                    q.push(currentNode->left);
                }
                if(currentNode->right != NULL){
                    q.push(currentNode->right);
                }
            }

        }
        Node<T>* findGreatest(Node<T> *root){
            if(root->right == NULL){
                return root;
            }
            return findGreatest(root->right);
        }

        void deleteNode(Node<T> *root,int data){
            if(root == NULL){
                return;
            }
            Node<T> *ptr = root;
            while(ptr->data != data){
                if(data >= ptr->data){
                    ptr = ptr->right;
                }else{
                    ptr = ptr->left;
                }
            }
            if(ptr->left == NULL && ptr->right == NULL){
                ptr = NULL;
                
            }else if(ptr->left == NULL || ptr->right == NULL){
                if(ptr->left != NULL){
                    Node<T> *temp = ptr->left;
                    ptr->left = NULL;
                    ptr = temp;
                }else{
                    Node<T> *temp = ptr->right;
                    ptr->right = NULL;
                    ptr = temp;
                }
            }else{
                Node<T> *greatestNode = findGreatest(ptr->left);
                ptr->data = greatestNode->data;
                ptr = greatestNode;
                if(ptr->left == NULL && ptr->right == NULL){
                ptr = NULL;
            }else if(ptr->left == NULL || ptr->right == NULL){
                if(ptr->left != NULL){
                    Node<T> *temp = ptr->left;
                    ptr->left = NULL;
                    ptr = temp;
                }else{
                    Node<T> *temp = ptr->right;
                    ptr->right = NULL;
                    ptr = temp;
                }
            }
            }
        }
};
int main(){
    BST<int> *bst = new BST<int>();
    bst->addNode(5);
    bst->addNode(3);
    bst->addNode(8);
    bst->addNode(1);
    bst->addNode(4);
    bst->addNode(7);
    bst->addNode(10);
    bst->addNode(2);
    bst->addNode(7);
    // cout<<"Preorder traversal is -> ";
    // bst->preOrder(bst->root);
    // cout<<endl;
    // cout<<"PostOrder traversal is -> ";
    // bst->postOrder(bst->root);
    // cout<<endl;
    // cout<<"InOrder traversal is -> ";
    // bst->inOrder(bst->root);
    // cout<<endl;
    bst->levelOrderTraversal(bst->root);
    cout<<endl;
    bst->deleteNode(bst->root,10);
    bst->levelOrderTraversal(bst->root);
    cout<<endl;
    bst->deleteNode(bst->root,1);
    bst->levelOrderTraversal(bst->root);
    cout<<endl;
    bst->deleteNode(bst->root,3);
    bst->levelOrderTraversal(bst->root);
    cout<<endl;

    return 0;
}