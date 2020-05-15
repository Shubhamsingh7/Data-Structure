//Toplogical sorting
#include<iostream>
#include<list>
#include<map>
#include<stack>
#include<set>

using namespace std;
template<class T>
class Graph{
    private:
        map<T,list<T>>graph;
    private:
        void topolgical_util(T vertex,set<T> &visited,stack<T> &s){
            for(T neighbour : graph[vertex]){
                bool isVisited = visited.find(neighbour) != visited.end();
                if(!isVisited){
                topolgical_util(neighbour,visited,s);
                }
            }
            visited.insert(vertex);
            s.push(vertex);
        }
    public:
        void addEdge(T source,T destination){
            graph[source].push_back(destination);
        }

        void topological_sorting(T source){
            cout<<"Topological sorting is :- ";
            set<T> visited;
            stack<T> topogical_stack;

            topolgical_util(source,visited,topogical_stack);
            for(pair<T,list<T>> currentVertex : graph){
                bool isVisited = visited.find(currentVertex.first) != visited.end();
                if(!isVisited){
                topolgical_util(currentVertex.first,visited,topogical_stack);
                }
            }
            while(!topogical_stack.empty()){
                T curentItem = topogical_stack.top();
                topogical_stack.pop();
                cout<<curentItem<<" ";
            }
            cout<<endl;
        }


};
int main(){

    Graph<string> g;
    g.addEdge("delhi","lucknow");
    g.addEdge("delhi","chandigardh");
    g.addEdge("kolkata","mumbai");
    g.addEdge("delhi","jaipur");
    g.addEdge("lucknow","kolkata");
    g.addEdge("chandigardh","amritsir");
    g.addEdge("jammu","amritsir");
    g.addEdge("jammu","srinagar");
    g.addEdge("jammu","laddak");
    g.addEdge("chandigardh","jammu");
    g.addEdge("laddak","srinagar");
    g.addEdge("kolkata","gowahati");
    g.addEdge("sikkim","gowahati");
    g.addEdge("beguluru","kolkata");
    g.addEdge("beguluru","chennai");
    g.addEdge("beguluru","mumbai");
    g.addEdge("jaipur","mumbai");
    g.addEdge("jaipur","bhopal");
    g.addEdge("delhi","bhopal");
    g.topological_sorting("delhi");

    Graph<char> g1;
    g1.addEdge('a','b');
    g1.addEdge('a','c');
    g1.addEdge('d','a');
    g1.addEdge('d','e');
    g1.addEdge('c','e');
    g1.topological_sorting('a');

    Graph<char>g2;
    g2.addEdge('a','c');
    g2.addEdge('b','c');
    g2.addEdge('b','d');
    g2.addEdge('c','e');
    g2.addEdge('e','f');
    g2.addEdge('f','g');
    g2.addEdge('d','f');
    g2.topological_sorting('c');
    return 0;
}