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

// 501. Find Mode in Binary Search Tree

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
    int prevNode = 1e6;
    int freq = 1, maxFreq = 0;

    void dfs(TreeNode* root, vector<int>& ans)
    {
        if (!root)
            return;

        dfs(root->left, ans);

        if (prevNode == 1e6)
            prevNode = root->val;

        else if (prevNode != root->val)
        {
            if (freq > maxFreq)
            {
                maxFreq = freq;
                ans = {prevNode};
            }
            else if (freq == maxFreq)
                ans.emplace_back(prevNode);
            
            prevNode = root->val;
            freq = 1;
        }
        else
            freq++;

        dfs(root->right, ans);
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);

        if (freq > maxFreq)
            ans = {prevNode};
 
        else if (freq == maxFreq)
            ans.emplace_back(prevNode);

        return ans;
    }
};

int main() {
    fastio();
    
    return 0;
}