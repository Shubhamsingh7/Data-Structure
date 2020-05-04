#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<set>

using namespace std;
class Graph{
    private:
        map<string,list<string>> graph;
    public:
        void addEdge(string source,string destination){
            graph[source].push_back(destination);
            graph[destination].push_back(source);
        }

        void BFS(string source){
            cout<<"BFS from "<<source<<" is :- ";
            queue<string>q;
            set<string>visited;

            q.push(source);
            visited.insert(source);

            while(!q.empty()){
                string currentItem = q.front();
                q.pop();
                cout<<currentItem<<", ";
                for(string value : graph[currentItem]){
                    if(visited.find(value) == visited.end()){
                        q.push(value);
                        visited.insert(value);
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
    g->BFS("delhi");
    return 0;
}