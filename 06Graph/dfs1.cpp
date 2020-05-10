#include<iostream>
#include<map>
#include<set>
#include<list>
using namespace std;

class Graph{
    private:
        map<string,list<string>> graph;
    public:
        void addEdge(string source,string destination){
            graph[source].push_back(destination);
            graph[destination].push_back(source);
        }

        void dfsUtil(string vertex,set<string>& visited){
            cout<<vertex<<", ";
            visited.insert(vertex);
            for(string children : graph[vertex]){
                bool isVisited = visited.find(children) ==  visited.end();
                if(isVisited){
                    dfsUtil(children,visited);
                }
            }
        }

        void DFS(string source){
            cout<<"DFS :- ";
            set<string> visited;
            dfsUtil(source,visited);
        }
    

};
int main(){
    Graph *g = new Graph();
    g->addEdge("delhi","lucknow");
    g->addEdge("delhi","chandigardh");
    g->addEdge("kolkata","mumbai");
    g->addEdge("delhi","jaipur");
    g->addEdge("lucknow","kolkata");
    g->addEdge("chandigardh","amritsir");
    g->addEdge("jammu","amritsir");
    g->addEdge("jammu","srinagar");
    g->addEdge("jammu","laddak");
    g->addEdge("chandigardh","jammu");
    g->addEdge("laddak","srinagar");
    g->addEdge("kolkata","gowahati");
    g->addEdge("sikkim","gowahati");
    g->addEdge("beguluru","kolkata");
    g->addEdge("beguluru","chennai");
    g->addEdge("beguluru","mumbai");
    g->addEdge("jaipur","mumbai");
    g->addEdge("jaipur","bhopal");
    g->addEdge("delhi","bhopal");
    g->DFS("sikkim");
    return 0;
}