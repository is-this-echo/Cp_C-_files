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


/**
 * Definition for a binary tree node. 
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int moves;

    int dfs(TreeNode* root)
    {
        if (!root)
            return 0;  // size of subtree(including itself), coins

        int leftExtraCoins = dfs(root->left);
        int rightExtraCoins = dfs(root->right);

        int currExtraCoins = leftExtraCoins + rightExtraCoins + root->val - 1;
        moves += abs(currExtraCoins);
        return currExtraCoins;     
    }

public:
    int distributeCoins(TreeNode* root)
    {
        dfs(root);
        return moves;
    }
};


int main() {
    fastio();
    
    return 0;
}