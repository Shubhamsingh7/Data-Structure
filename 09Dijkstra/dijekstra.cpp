//Dijectra algorithm

#include<iostream>
#include<map>
#include<set>
#include<list>
using namespace std;
template<class T>
class Graph{
    private:
        map<T,list<pair<T,int>>>graph;
    public:
        void addEdge(T source, T destination,int weight){
            graph[source].push_back({destination,weight});
            graph[destination].push_back({source,weight});

        }
    void dijkstra(T source){
        map<T,int>nodeDistance;
        for(pair<T,list<pair<T,int>>> node : graph){
            nodeDistance[node.first] = INT_MAX;
        }

        nodeDistance[source] = 0;

        set<pair<int,T>> unvisited;
        unvisited.insert({0,source});

        while(!unvisited.empty()){
            pair<int,T> leastDistancePair = *(unvisited.begin());
            int currentNodeDistance = leastDistancePair.first;
            T currentNode = leastDistancePair.second;
            unvisited.erase(unvisited.begin());
            for(pair<T,int> currentChildren : graph[currentNode]){
                int newDistance = currentNodeDistance + currentChildren.second;
                if(newDistance < nodeDistance[currentChildren.first]){
                    nodeDistance[currentChildren.first] = newDistance;
                    if(unvisited.find({currentChildren.second,currentChildren.first}) != unvisited.end()){
                        unvisited.erase({currentChildren.second,currentChildren.first});
                    
                    }
                    unvisited.insert({newDistance,currentChildren.first});
                }
            }
        }

        for(pair<T,int> node : nodeDistance){
            cout<<"distance from "<<source<<" to "<<node.first<<" is "<<node.second<<endl;
        }

        
    }
};
int main(){

    // Graph<int> g;
    // g.addEdge(1,2,1);
    // g.addEdge(2,3,8);
    // g.addEdge(1,3,4);
    // g.addEdge(1,4,7);
    // g.addEdge(3,4,2);
    // g.dijkstra(1);
    
    Graph<string> g;
    g.addEdge("delhi","lucknow",5);
    g.addEdge("delhi","chandigardh",4);
    g.addEdge("kolkata","mumbai",2);
    g.addEdge("delhi","jaipur",4);
    g.addEdge("lucknow","kolkata",7);
    g.addEdge("chandigardh","amritsir",2);
    g.addEdge("jammu","amritsir",4);
    g.addEdge("jammu","srinagar",4);
    g.addEdge("jammu","laddak",5);
    g.addEdge("chandigardh","jammu",8);
    g.addEdge("laddak","srinagar",12);
    g.addEdge("kolkata","gowahati",7);
    g.addEdge("sikkim","gowahati",5);
    g.addEdge("beguluru","kolkata",6);
    g.addEdge("beguluru","chennai",4);
    g.addEdge("beguluru","mumbai",4);
    g.addEdge("jaipur","mumbai",5);
    g.addEdge("jaipur","bhopal",3);
    g.addEdge("delhi","bhopal",3);
    g.dijkstra("delhi");


}