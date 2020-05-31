#include<iostream>
#include<map>
using namespace std;

class TrieNode{
    public:
        bool isTerminating;
        map<char,TrieNode*>child;
        TrieNode(){
            isTerminating = false;
        }
};

class Trie{
    private:
        TrieNode *root;
    public:
        Trie(){
            root = new TrieNode();
        }

        void insert(string str){
            TrieNode *ptr = root;
            for(char ch:str){
                if(!ptr->child.count(ch)){
                    ptr->child[ch] = new TrieNode();
                }
                ptr = ptr->child[ch];
            }
            ptr->isTerminating = true;
        }

        bool search(string str){
            TrieNode *ptr = root;
            for(char ch:str){
                if(!ptr->child.count(ch)){
                    return false;
                }
                ptr = ptr->child[ch];
            }
            return ptr->isTerminating;
        }
};



int main(){
    Trie *t = new Trie();
    int n,i;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        t->insert(s);
    }
    cin>>i;
    while(i--){
        string s;
        cin>>s;
        if(t->search(s)){
            cout<<"string "<<s<<" is present"<<endl;
        }else{
            cout<<"string "<<s<<" is not present"<<endl;

        }
    }
    return 0;
}