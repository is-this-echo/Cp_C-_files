#include<iostream>
#include<list>
#include<vector>
using namespace std;


class Graph{
    int V;
    list<int> *l;

    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    // undirected graph
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool dfsHelper(int node, vector<bool> &visited, int parent){
        visited[node]=true;
        
        for(auto nbr : l[node]){
            // if nbr is not visited, visit it
            if(!visited[nbr]){
                bool cycleFound = dfsHelper(nbr,visited,node);
                if(cycleFound)
                    return true;
            }
            // if parent is the previous node in dfs path which you just visited, then skip
            else if (nbr!=parent)
                return true;
        }
        return false;
    }
    
    //wrapper function
    bool containsCycle(){
        vector<bool> visited(V,false);
        return dfsHelper(0,visited,-1);
    }
};


int main()
{
    Graph g(3);
    g.addEdge(0,1);
    //g.addEdge(1,2);
    g.addEdge(2,0);

    if(g.containsCycle())
        cout<<"The graph has a cycle";
    else
         cout<<"Graph is not cyclic";

    return 0;
}