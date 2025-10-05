
// 867. Transpose Matrix

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;

 
vector<vector<int>> transpose(vector<vector<int>>& arr) {
    int m = arr.size(), n=arr[0].size();
    vector<vector<int>>ans(n,vector<int>(m));
    //vector<int>temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //temp.push_back(arr[j][i]);
            ans[i][j] = arr[j][i];
        }
        //ans.push_back(temp);
        //temp.clear();
    }
    return ans;
}


void print(vector<vector<int>>&grid){
    for(auto x : grid){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    vector<vector<int>>matrix = {{1,3},{2,8},{7,5}};

    print(matrix);
    auto g = transpose(matrix);
    print(g);

    return 0;
}