#include<iostream>
#include<stack>
#include<set>
#include<map>
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

        void DFS(string source){
            cout<<"DFS from "<<source<<"is :- ";
            stack<string>s;
            set<string>visited;
            s.push(source);
            while(!s.empty()){
                string currentItem = s.top();
                s.pop();
                bool isVisited = visited.find(currentItem) == visited.end();
                if(isVisited){
                    cout<<currentItem<<", ";
                    visited.insert(currentItem);
                    for(string value : graph[currentItem]){
                        s.push(value);
                    }
                }

            }
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