// Leet code 743. Network Delay Time

#include<iostream>
#include<list>
#include<vector>
#include<set>
#include<climits>
using namespace std;

// using Dijkstra's algo, as it has directed nodes and weights, also need to find minimum cost
// Dijkstra's algo = BFS + minHeap
int networkDelayTime(vector<vector<int>>& times, int n, int k) { 
    list<pair<int,int>> l[n+1];
    vector<int> dist(n+1,INT_MAX);
    
    for(auto x : times){
        int src = x[0], des = x[1], cost = x[2];
        l[src].push_back({des,cost});
    }
    
    dist[k] = 0;
    set<pair<int,int>> s;
    s.insert({dist[k],k});
    
    // BFS
    while(!s.empty()){
        auto itr = s.begin();
        int curr_dist = itr->first;
        int node = itr->second;
        
        s.erase(itr);
        
        for(auto nbrs : l[node]){
            int distTillNow = curr_dist + nbrs.second;
            int des = nbrs.first;
            
            if(distTillNow<dist[des]){
                auto p = s.find({dist[des],des});
                
                if(p!=s.end())
                    s.erase(p);
                
                dist[des] = distTillNow;
                s.insert({dist[des],des});
            }
        }
    }
    int time_taken=0;
    for(int i=1;i<=n;i++){
        if(dist[i]==INT_MAX)
            return -1;
        time_taken = max(time_taken, dist[i]);
    }
    return time_taken;
}




int main()
{
    vector<vector<int>> ex = {{2,1,1},{2,3,1},{3,4,1}};
    int n=4,k=2;
    // n-> number of nodes vaued from 1 to n
    // k-> source node, ex-> directed edges like {src,dest,cost}
    
    cout<<networkDelayTime(ex,n,k);
    
    return 0;
}