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
    Node *left, *right;

    Node(int val){
        this->val = val;
        left=right=nullptr;
    }
};


class HDpair{
public:
    int height, diameter;
};
    

// function to calculate diameter
HDpair DiaOptimized(Node* root){
    HDpair p;

    if(root==NULL){
        p.height=0; p.diameter=0;
        return p;
    }

    HDpair left = DiaOptimized(root->left);
    HDpair right = DiaOptimized(root->right);

    p.height = 1 + max(left.height, right.height);

    int d1 = left.height + right.height;
    int d2 = left.diameter;
    int d3 = right.diameter;

    p.diameter = max(d1,max(d2,d3));
    return p;
}

// pre order tree-build
Node* buildTree() {
	int d;
	cin >> d;

	if (d == -1) {
	    return NULL;
	}
	Node* n = new Node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}


int main() {
    fastio();

    // input : 1 2 4 -1 -1 5 3 -1 6 -1 7 -1 -1
    // then press Enter and type -1 to end

    auto x = buildTree();
    auto pp = DiaOptimized(x);
    
    cout<<pp.diameter;
    
    return 0;
}