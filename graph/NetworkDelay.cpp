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


// using some modern C++
/**
 * @brief std::set supports logarithmic erase, so you can efficiently remove the older distance entry. That makes it easier to ensure no outdated values remain.
But this leads to extra cost:
erase is O(log N)
insert is O(log N)
This makes the set-based version slightly slower in practice compared to the heap-based version.
 */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<pair<int, int>>> adjl(n + 1); // node -> (nbr, wt)
        for (const auto& edge : times)
            adjl[edge[0]].emplace_back(edge[1], edge[2]);

        vector<int> dist(n + 1, INT_MAX); // 1-indexed
        set<pair<int, int>> st; // (dist, node)

        dist[k] = 0;
        st.insert({0, k});

        while (!st.empty())
        {
            auto [currDist, node] = *st.begin();
            st.erase(st.begin());

            for (auto [nbr, wt] : adjl[node])
            {
                if (currDist + wt < dist[nbr])
                {
                    if (auto ptr = st.find({dist[nbr], nbr}); ptr != st.end())
                        st.erase(ptr);

                    dist[nbr] = currDist + wt;
                    st.insert({dist[nbr], nbr});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};


// using priority queue
/**
 * @brief 
 * In Dijkstra’s algorithm with a min-heap, we don’t erase old entries — we simply skip processing if the current distance is outdated: This technique is called lazy deletion. It works because:
If a node has already been visited with a shorter path, any longer one will be ignored.
This avoids the cost of removing elements from the middle of a heap (which is expensive and unsupported by std::priority_queue  directly).
 */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<pair<int, int>>> adjl(n + 1); // node -> (nbr, wt)
        for (const auto& edge : times)
            adjl[edge[0]].emplace_back(edge[1], edge[2]);

        vector<int> dist(n + 1, INT_MAX); // 1-indexed
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
                    greater<pair<int,int>>> pq; // min-heap (dist, node)

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty())
        {
            auto [currDist, node] = pq.top();
            pq.pop();

            for (auto [nbr, wt] : adjl[node])
            {
                if (currDist + wt < dist[nbr])
                {
                    dist[nbr] = currDist + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};


int main()
{
    vector<vector<int>> ex = {{2,1,1},{2,3,1},{3,4,1}};
    int n=4,k=2;
    // n-> number of nodes vaued from 1 to n
    // k-> source node, ex-> directed edges like {src,dest,cost}
    
    cout<<networkDelayTime(ex,n,k);
    
    return 0;
}