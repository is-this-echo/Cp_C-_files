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
    void populateParent(TreeNode* root, TreeNode* parent, unordered_map<int,TreeNode*>& mp)
    {
        if (!root)
            return;

        mp[root->val] = parent;
        populateParent(root->left, root, mp);
        populateParent(root->right, root, mp);
    }

    TreeNode* dfs(TreeNode* root, int start)
    {
        if (!root)
            return nullptr;

        if (root->val == start)
            return root;

        TreeNode* left = dfs(root->left, start);
        if (left)
            return left;

        return dfs(root->right, start);
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, TreeNode*> parentMap; // node-val, parent-node
        populateParent(root, nullptr, parentMap);

        int ans = -1;
        TreeNode* startPtr = dfs(root, start);

        queue<TreeNode*> q;
        unordered_map<int, bool> visited;
 
        q.push(startPtr);
        q.push(NULL);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (curr == NULL)
            {
                ans++;
                if (!q.empty())
                    q.push(NULL);
            }
            else
            {   
                visited[curr->val] = true;

                if (curr->left && !visited.count(curr->left->val))
                    q.push(curr->left);
                
                if (curr->right && !visited.count(curr->right->val))
                    q.push(curr->right);

                if (parentMap[curr->val] &&
                                    !visited.count(parentMap[curr->val]->val))
                    q.push(parentMap[curr->val]);
            }
        }
        return ans;
    }
};
    
int main() {
    fastio();
    
    return 0;
}