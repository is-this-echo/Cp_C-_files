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

 // DFS solution
class Solution
{
public:
    bool isCousins(TreeNode* root, int x, int y)
    {
		unordered_map<int, pair<int, int>> m;

		helper(root, 0, -1, m);
		return m[x].first == m[y].first && m[x].second != m[y].second;
    }
    
    void helper(TreeNode* node, int depth, int parent, unordered_map<int, pair<int, int>>& m)
    {
    	if (!node) return;

    	m[node->val] = {depth, parent};
    	helper(node->left, depth + 1, node->val, m);
    	helper(node->right, depth + 1, node->val, m);
    }
};

// BFS solution
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
public:
    bool isCousins(TreeNode* root, int x, int y)
    {
        // node val : level, parent
        unordered_map<int, pair<int, int>> mp; 
        queue<TreeNode*> q;

        q.push(root);
        mp[root->val] = {0, -1};

        int level = 1;
        while (!q.empty())
        {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i)
            {
                auto curr = q.front();
                q.pop();
                
                if (curr->left)
                {
                    q.push(curr->left);
                    mp[curr->left->val] = {level, curr->val};
                }

                if (curr->right)
                {
                    q.push(curr->right);
                    mp[curr->right->val] = {level, curr->val};
                }
            }
            level++;
        }

        return mp[x].first == mp[y].first && mp[x].second != mp[y].second;    
    }
};


int main() {
    fastio();
    
    return 0;
}