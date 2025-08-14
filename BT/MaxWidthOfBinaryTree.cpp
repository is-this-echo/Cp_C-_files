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
public:
    int widthOfBinaryTree(TreeNode* root)
    {   
        using ull = unsigned long long;

        if (!root)
            return 0;

        int ans = 1;
        std::queue<pair<TreeNode*, ull>> q; // node ptr, node number
        q.push({root, 0});

        while (!q.empty())
        {
            int levelSize = q.size();

            int firstIdx = q.front().second;
            int lastIdx = q.back().second;
            ans = max(ans, lastIdx - firstIdx + 1);

            for (int i = 0; i < levelSize; ++i)
            {   
                auto norIdx = q.front().second - firstIdx;
                TreeNode* node = q.front().first;
                q.pop();

                if (node->left)
                    q.push({node->left, 2 * norIdx});
                
                if (node->right)
                    q.push({node->right, 2 * norIdx + 1});
            }
        }
        return static_cast<int>(ans);
    }
};

    
int main() {
    fastio();
    
    return 0;
}