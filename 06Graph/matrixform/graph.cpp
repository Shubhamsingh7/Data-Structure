#include<iostream>
#include<queue>
#include "declaration.h"
using namespace std;

static int graph[100][100];
static int n = 4;
bool visited[4];

int main(){

    createGraph();
    addedge(0,1,5);
    addedge(0,2,3);
    addedge(3,0,5);
    addedge(1,3,8);
    addedge(3,4,7);
    addedge(3,3,2);
    addedge(1,2,2);

    displayGraph();
    // cout<<"dfs :- ";
    // dfs(2);
    cout<<"bfs :- ";
    bfs(1);
    // dijkstra({2,3});

}

void createGraph(){
    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
        for(int j = 0 ; j < n ; j++){
            graph[i][j] = 0;
        }
    }
}

void addedge(int source ,int destination,int weight){
    graph[source][destination] = weight;
    // graph[destination][source] = weight;
}

void displayGraph(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

// dfs

void dfs(int source){
    cout<<source<<" ";
    visited[source] = true;
    for(int i = 0 ; i < n ; i++){
        if(graph[source][i] != 0 && !visited[i]){
            dfs(i);
        }
    }

}

void bfsHelper(queue<int> &q){
    while(!q.empty()){
        int currentElement = q.front();
        q.pop();
        cout<<currentElement<<" ";
        // visited[currentElement] = true;
        for(int i = 0 ; i < n ; i++){
            if(graph[currentElement][i] != 0 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void bfs(int source){
    queue<int> q;
    q.push(source);
    visited[source] = true;
    bfsHelper(q);
}



