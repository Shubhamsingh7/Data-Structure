//bellmen ford algorithm
#include<iostream>
#include<map>
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


        void bellmenFord(T source){
            map<T,int>distance;
            int vertexNum = 0;
            // mark distance of all node infinity
            for(pair<T,list<pair<T,int>>> node : graph){
            distance[node.first] = INT_MAX;
            vertexNum++;
            }

            // mark source node distance 0
            distance[source] = 0;

            for(int i = 0 ; i < (vertexNum -1) ; i++){
            bool distanceUpdated = false;

                for(pair<T,list<pair<T,int>>> currentPair : graph){
                    for(pair<T,int> currentNode : currentPair.second){
                        T currentSource = currentPair.first;
                        T currentDestination = currentNode.first;
                        int edgeWeight = currentNode.second;
                        //check for integer overflow
                        if(distance[currentSource] != INT_MAX){
                            int newDistance = distance[currentSource] + edgeWeight;
                            newDistance = abs(newDistance);
                            if(newDistance < distance[currentDestination]){
                                distance[currentDestination] = newDistance;
                                distanceUpdated = true;
                            }
                        }
                        
                    }
                }
                // break out of loop if no change in distance for 2 consecutve iteration
                if(!distanceUpdated){
                    break;
                }
            }

            // print distance
            for(pair<T,int> node : distance){
                cout<<"distance from "<<source<<" to "<<node.first<<" is "<<node.second<<endl;
            }
            

        }


};
int main(){
    
    Graph<string> g;
    
    g.addEdge("delhi","lucknow",5);
    g.addEdge("delhi","chandigardh",-4);
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
    g.bellmenFord("delhi");

    // Graph<int>g;
    // g.addEdge(1,2,6);
    // g.addEdge(1,3,5);
    // g.addEdge(1,4,5);
    // g.addEdge(2,5,-1);
    // g.addEdge(3,2,-2);
    // g.addEdge(4,3,-2);
    // g.addEdge(4,6,-1);
    // g.addEdge(3,5,1);
    // g.addEdge(5,7,3);
    // g.addEdge(6,7,3);
    // g.bellmenFord(1);
};