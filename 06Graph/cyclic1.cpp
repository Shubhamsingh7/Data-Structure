//cyclic in undirected graph
#include<iostream>
#include<list>
#include<map>
using namespace std;

class Graph{
    private:
        int V;
        list<int> *arr;
    public:
        Graph(int V){
            this->V = V;
            arr = new list<int>[V];
        }
        void addEdge(int source,int destination){
            arr[source].push_back(destination);
            arr[destination].push_back(source);
        }

        bool isCyclic(){

            int parent[V];
            bool visited[V];
            for(int i = 0 ; i < V ; i++){
                parent[i] = -1;
                visited[i] = false;
            }
            for(int i = 0 ; i < V ; i++){
                if(visited[i] == false){
                    return cyclicUtil(i,visited,parent);
                }
            }
            return false;
        }
    private:
        bool cyclicUtil(int vertex,bool visited[],int parent[]){
            visited[vertex ] = true;
            for(int neighbour : arr[vertex]){
                parent[neighbour] = vertex;
                bool isVisited = visited[neighbour];
                if(isVisited){
                    if(parent[vertex] != neighbour){
                        int currentVertex = neighbour;
                        while(currentVertex != -1){
                            cout<<currentVertex<<", ";
                            currentVertex = parent[currentVertex];
                        }
                        return true;
                    } 
                }else{
                    return cyclicUtil(neighbour,visited,parent);
                }
            }
            return false;
        }


};

int main(){

    
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(4,0);
    cout<<endl;
    g.isCyclic()?cout<<"cyclic":cout<<"acyclic";
    return 0;
}