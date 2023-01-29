/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define PI 3.1415926535897932384626
#define mod 998244353
#define f first
#define s second 

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}


class Node{
public:
    int val;
    vector<Node*>child;

    Node(int d){
        val = d;
    }
};

int dfs(int node, unordered_map<int,Node*>&mp, vector<int>&ans){

    if(mp[node]->child.size()==0){
        return 1;
    }

    for(auto ch : mp[node]->child){
        ans[node] += dfs(ch->val, mp, ans);
    }

    return ans[node] + 1;
}

int main() {
    fastio();

    int n,x;
    cin>>n;

    unordered_map<int,Node*>mp;
    for(int i=1;i<=n;i++){
        mp[i] = new Node(i);
    }

    for(int i=2;i<=n;i++){
        cin>>x;
        mp[x]->child.push_back(mp[i]);
    }

    vector<int>ans(n+1,0);
    dfs(1,mp,ans);

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}