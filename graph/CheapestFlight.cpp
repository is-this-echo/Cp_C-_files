#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// can be done using Bellman-Ford algo or Dijkstras algo

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
// Bellman Ford algo, 
// O(k*E) time complexity, E-> # of edges, k as given

    vector<int> prices(n,INT_MAX);
    vector<int> temp;
    prices[src]=0;

    for(int i=0;i<=k;i++){
        temp = prices;
        
        for(auto x : flights){
            int s=x[0], d = x[1], p=x[2];
            
            if(prices[s]==INT_MAX)
                continue;
            // need to check temp array as we want the latest cost
            if(prices[s]+p<temp[d])
                temp[d] = prices[s]+p;
        }
        // copying temp array to prices
        prices = temp;
    }
    
    return prices[dest]==INT_MAX?-1:prices[dest];
}
        


int main()
{
    int n = 3,  src = 0, dest = 2, k = 1;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};

    cout<<findCheapestPrice(n,flights,src,dest,k);

    return 0;
}