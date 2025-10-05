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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // 1,2,3,#,#,4,5,#,#,#,# 
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (!root)
            return "";

        std::queue<TreeNode*> q;
        q.emplace(root);

        std::string code{};
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (curr == nullptr)
            {
                code.append("#,");
            }
            else
            {
                code.append(to_string(curr->val) + ',');
                q.emplace(curr->left);
                q.emplace(curr->right);
            }
        }
        return code;
    }

    // Decodes your encoded data to tree.
    // "1,2,3,#,#,4,5,#,#,#,#"
    TreeNode* deserialize(string data)
    {
        // cout << data << "\n";
 
        if (data.length() == 0)
            return nullptr;

        std::istringstream iss(data);
        std::string token;
        std::getline(iss, token, ',');

        TreeNode* root{nullptr};
        if (token != "#")
            root = new TreeNode(std::stoi(token));
        
        std::queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            std::getline(iss, token, ',');
            if (token != "#")
            {
                auto left = new TreeNode(std::stoi(token));
                curr->left = left;
                q.emplace(left);
            }

            std::getline(iss, token, ',');
            if (token != "#")
            {
                auto right = new TreeNode(std::stoi(token));
                curr->right = right;
                q.emplace(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

    
int main() {
    fastio();
    
    return 0;
}