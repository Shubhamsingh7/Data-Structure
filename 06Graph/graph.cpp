//using adjancy list
#include<iostream>
#include<list>

using namespace std;

class Graph{
    private:
        int V;
        list<int> *adj;
        
    public:
        Graph(int V){
            this->V = V;
            adj = new list<int>[V];
        }

        void addEdge(int u,int v,bool isBidirectional = false){
            adj[u].push_back(v);
            if(isBidirectional){
                adj[v].push_back(u);
            }
        }

        void display(){
            for(int i = 0 ; i < V ;i++){
                cout<<i<<" -> ";
                for(int value : adj[i]){
                    cout<<value<<", ";
                }
                cout<<endl;
            }
        }
        
};
int main(){
    Graph *g = new Graph(5);
    g->addEdge(0,1);
    g->addEdge(0,4);
    g->addEdge(1,2);
    g->addEdge(1,3);
    g->addEdge(3,0);
    g->addEdge(2,4,true);
    g->display();
    return 0;
}