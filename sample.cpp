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
    
    
class Node
{
public:
    int val;
    Node *left, *right;

    Node(int x)
    {
        val = x;
        left = right = nullptr;
    }
};

class Solution { 
public:
    string tree2str(Node* root) {
        string res="";
        tree2str(root, res);
        return res;
    }

    void tree2str(Node* root, string &res){
        if(root==nullptr)
            return;

        res += to_string(root->val);

        if(root->left){
            res += '(';
            tree2str(root->left, res);
            res += ')';
        }

        if(root->right){
            if(!root->left){
                res += "()";
            }
            res += '(';
            tree2str(root->right, res);
            res += ')';
        }
    }
};

int main()
{
    fastio();

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    Solution st;
    cout << st.tree2str(root);

    return 0;
}

