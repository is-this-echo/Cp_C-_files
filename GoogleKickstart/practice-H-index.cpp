#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 
class Compare{
public:
    bool operator()(int a, int b){
        return a>b;
    }
};


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int ts;
    cin>>ts;

    for(int tt=0;tt<ts;tt++){
        int n;
        cin>>n;

        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];

        priority_queue<int, vector<int> ,Compare>pq;
        int ans=0,val=0;

        cout<<"Case #"<<tt+1<<": ";

        for(int i=0;i<n;i++){
            if(arr[i]>ans)
                pq.push(arr[i]);
            
        // remove all elements less than or equal to current h-index as they cant contribute mores
            while(!pq.empty() && pq.top()<=ans)
                pq.pop();

        // now all elements in pq are greater than ans, so if the size>=next h-idx, do ans++
            if(pq.size()>=ans+1){
                ans++;
                //cout<<ans<<" ";
            }
            cout<<ans<<" ";
        }

       cout<<"\n";
    }

    return 0;
}