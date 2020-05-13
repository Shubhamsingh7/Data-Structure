//using map

#include<iostream>
#include<map>
#include<list>
using namespace std;
template<class T>
class Graph{
    private:
        map<T,list<T>>graph;
    public:
        void addEdge(T u ,T v){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        void display(){
            for(pair<T,list<T>> value : graph){
                cout<<value.first<<" -> ";
                for(T value : value.second){
                    cout<<value<<", ";
                }
                cout<<endl;
            }
        }
};
int main(){
    // Graph<int> *g = new Graph<int>();
    // g->addEdge(0,1);
    // g->addEdge(0,4);
    // g->addEdge(1,2);
    // g->addEdge(1,3);
    // g->addEdge(3,0);
    // g->addEdge(2,4);
    Graph<string> *g = new Graph<string>();
    g->addEdge("delhi","lucknow");
    g->addEdge("delhi","chandigardh");
    g->addEdge("kolkata","mumbai");
    g->addEdge("delhi","jaipur");
    g->addEdge("beguluru","kolkata");
    g->display();
    
    return 0;
}