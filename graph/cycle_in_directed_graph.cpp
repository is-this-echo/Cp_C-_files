#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int> *l;

    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
    }

    bool dfs(int node, vector<bool>&visited, vector<bool> &stack){
        visited[node]=true;
        stack[node]  =true;

        for(auto nbr:l[node]){
            // if nbr node not visited, visit it
            if(!visited[nbr]){
                bool foundCycle = dfs(nbr,visited,stack);
                if(foundCycle)
                    return true;
            }
            // if nbr is present in  call stack of dfs path, then its a cyclic graph
            else if(stack[nbr]==true){
                return true;
            }
        }
        // while going back to original caller, pop it from stack
        stack[node] = false;
        return false;
        
    }

    // wrapper function
    bool detectCycle(){
        vector<bool> visited(V,false);
        vector<bool> stack(V,false);

        for(int i=0;i<V;i++){
            bool ans = dfs(i,visited,stack);
            if(ans==true)
                return true;
        }
        return false;
    }

};


int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.addEdge(4,0);

    if(g.detectCycle())
        cout<<"Cycle is present in the directed graph";
    else 
        cout<<"Directed acyclic graph";
    
    return 0;
}