#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    

 //  Leetcode 658. Find K Closest Elements

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    // using max-heap and pushing elements in a vector after sorting
    // T.C = O(nlogn) + O(nlogk), S.C = O(k)+O(k)
    int n = arr.size();
    vector<int>ans;
    priority_queue<pair<int,int>>pq;
    
    for(int i=0;i<n;i++){
        int dist = abs(arr[i]-x);
        pq.push({dist,arr[i]});
        
        if(pq.size()>k)
            pq.pop();
    }
    
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
} 


    // using binary search approach, T.C = O(klogn)
    // S.C = O(k) 
vector<int> solve(vector<int>& arr, int k, int x){
    vector<int>ans;
    int dist=0, n = arr.size();

    while(k>0){
        int val1 = x-dist, val2 = x+dist;

        int freq1 = upper_bound(arr.begin(),arr.end(),val1)
                    - lower_bound(arr.begin(), arr.end(), val1);
        
        int freq2 = upper_bound(arr.begin(),arr.end(),val2)
                    - lower_bound(arr.begin(), arr.end(), val2);

        while(k>0 && freq1>0){
            ans.push_back(val1);
            k--; freq1--;
        }
    
        if(val1!=val2)
            while(k>0 && freq2>0){
                ans.push_back(val2);
                k--; freq2--;
            }
        dist+=1; 
    }

    sort(ans.begin(), ans.end());
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<int> arr = {0,1,1,1,2,3,6,7,8,9};
    int k=9, x=4;

    auto vec = solve(arr,k,x);

    for(auto elem : vec)
        cout<<elem<<" ";
    
    return 0;
}