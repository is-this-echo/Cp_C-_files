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
    int open, close, full;
    // the structure of the node is designed 
    Node(int o=0, int c=0, int f=0){
        open=o;
        close=c;
        full=f;
    }
};


Node merge(Node left, Node right){
    Node n(0,0,0);
    // 'new' keyword is used when we use pointers, for ex- Node *n = new Node();
    // from left node we can take open brackets and close brackets can be taken from the right node

    int k = min(left.open,right.close);
    n.full = left.full + right.full + k;
    n.open = left.open + right.open - k;
    n.close = left.close + right.close - k;
    return n;
}


void build(int idx, int low, int high, string &s, vector<Node>&seg){
    if(low==high){
        seg[idx].open = (s[low]=='(');
        seg[idx].close = (s[low]==')');
        seg[idx].full = 0;
        return;
    }

    int mid = (low+high)>>1;
    build(2*idx+1, low, mid, s, seg);
    build(2*idx+2, mid+1, high, s, seg);
    seg[idx] = merge(seg[2*idx+1],seg[2*idx+2]);
}


Node solve(int idx, int low, int high, int l, int r, vector<Node>&seg){
    if(low>=l && high<=r){
        return seg[idx];
    }

    if(low>r || high<l){
        return Node(0,0,0);
    }

    int mid = (low+high)>>1;
    Node left = solve(2*idx+1, low, mid, l, r, seg);
    Node right = solve(2*idx+2, mid+1, high, l, r, seg);
    return merge(left,right);
}
    

int main() {
    fastio();

    string s;
    cin>>s;

    int n = (int)s.length();
    vector<Node>seg(4*n);

    build(0,0,n-1,s,seg);

    int m;
    cin>>m;

    while(m--){
        int l,r;
        cin>>l>>r;

        // as queries are 1-indexed
        --l,--r;

        Node ans = solve(0,0,n-1,l,r,seg);
        cout<<ans.full*2<<"\n";
        
    }
    
    return 0;
}