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

    Node(int val) : val(val), left(NULL), right(NULL) {}
};


class Solution {
    bool dfs(Node* p, Node* q){
        if(p== NULL && q== NULL)
            return true;
        
        if(p== NULL || q== NULL)
            return false;
        
        if(p->val != q->val)
            return false;
        
        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }

public:
    bool isSubtree(Node* root, Node* subRoot) {
        // a null node is present as a subtree for any root node
        if(subRoot == NULL)
            return true;

        // need not check for subroot as it must be not null if control reaches here
        if(root == NULL)
            return false;

        if(dfs(root, subRoot))
            return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
}; 


int main() {
    fastio();
    
    return 0;
}