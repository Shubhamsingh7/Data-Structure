#include<iostream>
#include<map>
#include<set>
using namespace std;

class TrieNode{
    public:
        char data;
        bool isTerminating;
        map<char,set<TrieNode>> list;
    public:
        TrieNode(){

        }
        TrieNode(char data){
            this->data = data;
            isTerminating = true;
            set<TrieNode> s;
            list[data] = s;
        }

};
class Trie{
    private:
        TrieNode root;
    public:
        Trie(){
            root.data = ' ';
            root.isTerminating = false;
            set<TrieNode>s;
            root.list[' '] = s;
        }
        void addchar(char data){
            TrieNode node(data);
            bool isFirstChar = root.list[' '].find(data) == root.list[' '].end();
            if(isFirstChar){
                root.list[' '].insert(node);
                return;
            }
            TrieNode ptr = root;
            while(ptr.isTerminating != true){
                
            }
        }
};
int main(){

}