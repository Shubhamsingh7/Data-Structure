#include<iostream>
using namespace std;
class Graph{
    private:
        int** matrix;
        int V;
    public:
        Graph(int V){
            this->V = V;
            matrix= new int*[V];
            for(int i = 0 ; i < V ; i++){
                matrix[i] = new int[V];
            }

            // mark all node distance as infinity
            for(int i = 0 ; i < V ; i++){
                for(int j = 0 ; j <V;j++){
                    if(i == j){
                        matrix[i][j] = 0;
                    }else{
                    matrix[i][j] = INT_MAX;
                    }
                }
            }
        
        }

        void add(int source ,int destination,int weight){
            matrix[source][destination] = weight;
        }

        void floydWarshall(){
            for(int k = 0 ; k < V ; k++){
                for(int i = 0 ; i < V ; i++){
                    for(int j = 0 ; j < V ; j++){
                        if(i == k || j == k)
                            continue;
                        else{
                            if(*matrix[i,j] != INT_MAX){
                                int newDistance = *matrix[i,k] + *matrix[k,j];
                                if(newDistance < *matrix[i,j]){
                                    *matrix[i,j] = newDistance;
                                }
                            } 
                        }
                    }
                }
            }
        }

        void display(){
            for(int i = 0 ; i < V ; i++){
                cout<<"distance from "<<i<<" -> ";
                for(int j = 0 ; j <V;j++){
                    cout<<matrix[i][j]<<", ";
                }
                cout<<endl;
            }
        }
};
int main(){

Graph g(4);
g.add(0,1,3);
g.add(0,3,7);
g.add(3,0,2);
g.add(2,3,1);
g.add(2,0,5);
g.add(1,0,8);
g.add(1,2,2);
g.display();
}