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

    Node(int d){
        val=d;
        left=right=NULL;
    }
 };


void VOrderPrint(Node* root, map<int,vector<int>>&mp,int d){
    if(root==NULL)
        return;

    mp[d].push_back(root->val);
    VOrderPrint(root->left,mp,d-1);
    VOrderPrint(root->right,mp,d+1);
}

    
int main() {
    fastio();

    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    map<int,vector<int>>mp;
    VOrderPrint(root,mp,0);

    for(auto x : mp){
        vector<int> y = x.s; 
        for(int i : y)
            cout<<i<<" ";
        cout<<"\n";
    }
    
    return 0;
}