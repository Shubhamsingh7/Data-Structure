#include<iostream>
#include "declaration.h"
using namespace std;

static int graph[100][100];
static int n = 4;

int main(){

    createGraph();
    addedge(0,1,5);
    addedge(0,2,3);
    addedge(3,0,5);
    addedge(1,3,8);
    addedge(3,4,7);
    addedge(3,3,2);

    displayGraph();
    // dfs({4,3});
    // bfs({1,2});
    // dijkstra({2,3});

}

void createGraph(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            graph[i][j] = 0;
        }
    }
}

void addedge(int source ,int destination,int weight){
    graph[source][destination] = weight;
    graph[destination][source] = weight;
}

void displayGraph(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}



