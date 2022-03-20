#include<iostream>
#include<list>
#include<vector>
#include<climits>
// #include<utility>
#include<set>
using namespace std;


class Graph{
    int V;
    list<pair<int,int>> *l;

public:
    Graph(int V){
        this->V=V;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int x, int y, int w, bool undir=true){
        l[x].push_back({y,w});

        if(undir)
            l[y].push_back({x,w});
    }

    int dijkstraShortestPath(int src, int dest){
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> s; 

        // initialization
        dist[src] = 0;
        s.insert({dist[src],src});

        while(!s.empty()){
            auto itr = s.begin();
            int distTillNow = itr->first;
            int node = itr->second;

            // pop the element from the set
            s.erase(itr);

            // iterate over all the nbrs of the node
            for( auto nbrPair : l[node]){
                int nbr =nbrPair.first;
                int currentEdge = nbrPair.second;

                // comparison to find min. distance
                if(distTillNow+currentEdge < dist[nbr]){
                    //remove the node if already present in set
                    auto p = s.find({dist[nbr],nbr});
                    if(p!=s.end())
                        s.erase(p);

                    // re-insert the node with updated values
                    dist[nbr] = distTillNow+currentEdge;
                    s.insert({dist[nbr],nbr});
                } 
            }
        }
        return dist[dest];
    }


};


int main()
{
    Graph g(5);
    int src=4,dest=0;
    g.addEdge(0,1,1);
    g.addEdge(0,3,7);
    g.addEdge(0,2,4);
    g.addEdge(1,2,1);
    g.addEdge(2,3,2);
    g.addEdge(3,4,3);
    
    cout<<"Shortest distance from "<<src<<" to "<<dest<<" is :  "<<g.dijkstraShortestPath(src,dest);

    return 0;
}