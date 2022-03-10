#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;
    
 

int largestMountain(vector<int>arr){
    int maxSize = 1, currSize=0;
    int n = arr.size();

    for(int i=1;i<=n-2;){

        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            int j = i;
            currSize=1;
            
            while(j>=1 && arr[j]>arr[j-1]){
                currSize++;
                j--;
            }

            while(i<=n-2 && arr[i]>arr[i+1]){
                currSize++;
                i++;
            }

            maxSize = max(maxSize, currSize);
        }
        else
            i++;
    }   
    return maxSize;
}
    



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<int>arr = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

    int ans = largestMountain(arr);
    cout<<ans;
    
    return 0;
}