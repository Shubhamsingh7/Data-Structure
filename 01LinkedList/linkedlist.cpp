#include<iostream>
using namespace std;
template<class T>
class Node{
    public:
        T data;
        Node<T> *next;
        Node<T> *prev;
        Node(T data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};
template<class T>
class LinkedList{
    public:
        Node<T> *head;
        Node<T> *reverseHead;
    public:
        LinkedList(){
            head = NULL;
            reverseHead = NULL;
        }
        void insert(T data, bool isDoublyLL = true){
            Node<T> *currentNode = new Node<T>(data);
            if(head == NULL){
                head = currentNode;
                reverseHead = currentNode;
                return;
            }
            Node<T> *ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = currentNode;
            reverseHead = ptr->next;
            if(isDoublyLL){
                currentNode->prev = ptr;
            }
        }
        void display(){
            cout<<"Forward order :- ";
            if(head == NULL){
                cout<<"List is Empty"<<endl;
                return;
            }
            Node<T> *ptr = head;
            while(ptr != NULL){
                cout<<ptr->data<<" -> ";
                ptr = ptr->next;
            }
            cout<<endl;
        }
        void reverseDisplay(){
            cout<<"Reverse order :- ";
            if(head == NULL){
                cout<<"List is Empty"<<endl;
                return;
            }
            Node<T> *ptr = reverseHead;
            while(ptr != NULL){
                cout<<ptr->data<<" <- ";
                ptr = ptr->prev;
            }
            cout<<endl;;
        }
};
int main(){
    LinkedList<string> *list = new LinkedList<string>();
    list->insert("Shubham");
    list->insert("ram");
    list->insert("lakhan");
    list->insert("seeta");
    list->insert("hanuman");
    list->insert("angad");
    list->insert("vibhisan");
    list->display();
    list->reverseDisplay();
    return 0;
}