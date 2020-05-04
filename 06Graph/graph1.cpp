#include<iostream>
#include<vector>
using namespace std;

class Graph{
    private:
        int V;
        vector<vector<bool>> adjMatrix;
        // bool ** adjMatrix;
    public:
        Graph(int V){
            this->V = V;
            // adjMatrix = new bool*
            for(int i = 0 ; i < V ; i++){
                cout<<"j ";
                // for(int j = 0 ; j < V ; j++){
                //     adjMatrix[i][j] = false;
                // }
            }
        }

        // void addEdge(int u,int v,bool isBidirectional = false){
        //     cout<<"r ";
        //     adjMatrix[u][v] = true;
        //     if(isBidirectional){
        //     adjMatrix[v][u] = true;

        //     }
        // }
        // void display(){
        //     for(int i = 0 ; i < V ; i++){
        //         cout<<i<<" -> ";
        //         for(int j = 0 ; j <V ; j++){
        //             if(adjMatrix[i][j]){
        //                 cout<<j<<", ";
        //             }
        //         }
        //         cout<<endl;
        //     }
        // }

};

int main(){
    Graph *g = new Graph(5);
    // g->addEdge(0,1);
    // g->addEdge(0,4);
    // g->addEdge(1,2);
    // g->addEdge(1,3);
    // g->addEdge(3,0);
    // g->addEdge(2,4,true);
    // g->display();
    return 0;
}