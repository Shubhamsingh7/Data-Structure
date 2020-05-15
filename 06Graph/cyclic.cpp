#include<iostream>
#include<list>
#include<set>
#include<stack>
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
        }

        bool isCyclic(int source){
            bool visited[V];
            for(int i = 0 ; i < V ; i++){
                visited[i] = false;
            }
            set<int>current_stack;
            stack<int>s;
            bool result  = dfs(source,visited,current_stack,s);
            for(int i = 0 ; i < V ; i++){
                if(visited[i] == false){
                    return dfs(i,visited,current_stack,s);  
                }
            }
            return result;

        }
    private:
    bool dfs(int vertex,bool visited[],set<int> &current_stack,stack<int> &s){
            visited[vertex] = true;
            s.push(vertex);
            current_stack.insert(vertex);
            for(int neighbour : arr[vertex]){
                if(visited[neighbour] == false){
                    return dfs(neighbour,visited,current_stack,s);
                }else{
                    bool inCurentStack = current_stack.find(neighbour) != current_stack.end();
                    if(inCurentStack){
                        while(s.top() != neighbour){
                            cout<<s.top()<<", ";
                            current_stack.erase(s.top());
                            s.pop();
                        }
                        cout<<s.top()<<",  ";
                        cout<<endl;
                        return true;
                    }
                }
            }
            current_stack.erase(vertex);
            s.pop();
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
    g.isCyclic(0)?cout<<"cyclic":cout<<"acyclic";
    return 0;
}