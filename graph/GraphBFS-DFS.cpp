#include<iostream>
#include<queue>
#include<list>
using namespace std;


class Graph{
    int V;
    list<int> *l;

public:
    Graph(int v){
        V=v;
        l = new list<int> [V];
    }

    void addEdge(int x, int y, bool undir=true){
        l[x].push_back(y);
        if(undir)
            l[y].push_back(x);
    }
    
    void prindAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<"--> ";
            for(auto j : l[i])
                cout<<j<<", ";
            cout<<endl;
        }
    }

    void bfsTraversal(int source, int dest=-1){
        queue<int> q;
        bool *visited = new bool[V]{0};

        // storing parent node for each node to find the shortest path 
        int *distance = new int[V]{0};
        int *parent = new int[V];
        for(int i=0;i<V;i++)
            parent[i]=-1;
        //
        q.push(source);
        visited[source]= true;

        // setting dist of source node as 0 and its parent as itself
        distance[source]=0;
        parent[source]=source;
        //

        while(!q.empty()){
            int curr = q.front();
            // Print node values for simple bfs traversal
           // cout<<curr<<" ";
            q.pop();

            for(auto j : l[curr]){
                if(!visited[j]){
                    q.push(j);
                    visited[j]=true;
                    // first visit will give us the shortest distance from source
                    distance[j]=distance[curr]+1;
                    parent[j]=curr;
                    //
                }    
            }
        }
        // shortest distance print
        //for(int i=0;i<V;i++)
        //   cout<<"Shortest distance of "<<i<<" is-> "<<dist[i]<<endl;

        //shortest path print
        if(dest!=-1){
            int temp=dest;
            while(temp!=source){
                cout<<temp<<"-->";
                temp=parent[temp];
            }
            cout<<source;
        }
    }

    void dfsHelper(int x, bool *visited){
        visited[x]=true;
        cout<<x<<"-> ";

        for(auto nbr:l[x]){
            if(!visited[nbr])
                dfsHelper(nbr,visited);
        }
        return;
    }

    //wrapper function
    void dfsTraversal(int source){
        bool *visited = new bool[V]{0};
        dfsHelper(source, visited);
    }
};


int main()
{
    Graph g(7);
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(0,4);
    g.addEdge(3,5);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);

    //g.prindAdjList();
    // g.bfsTraversal(1,6);
    g.dfsTraversal(1);
    
    return 0;
}