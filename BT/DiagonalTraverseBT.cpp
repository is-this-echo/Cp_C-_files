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
    

// C++ program to print diagonal view
class Node
{
  public:
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void diagonalRecur(Node *root, int level, unordered_map<int, vector<int>> &levelData)
{
    if (root == nullptr)
        return;

    levelData[level].push_back(root->data);

    diagonalRecur(root->left, level + 1, levelData);
    diagonalRecur(root->right, level, levelData);
}


vector<int> diagonal(Node *root)
{
    vector<int> ans;

    // Create a hash map to store each
    // node at its respective level.
    unordered_map<int, vector<int>> levelData;
    diagonalRecur(root, 0, levelData);

    int level = 0;
    while (levelData.find(level) != levelData.end())
    {
        for (const auto& x : levelData[level])
            ans.emplace_back(x);
        level++;
    }
    return ans;
}


// Iterative function to print diagonal view, without using additional hashmap
vector<int> diagonalOptimized(Node* root)
{
    vector<int> ans;

    if (root == nullptr)
        return ans;

    std::queue<Node*> q;
    q.emplace(root);
    q.emplace(nullptr);

    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        
        if (curr == nullptr)
        {
            if (!q.empty())
                q.emplace(nullptr);
        }
        else
        {
            while (curr)
            {
                ans.push_back(curr->data);

                // if left child is present push into queue to be part of the next diangonal
                if (curr->left)
                    q.emplace(curr->left);

                // current equals to right child, part of the same diagonal
                curr = curr->right;
            }
        }
    }
    return ans;
}


void printList(vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    fastio();

    // Create a hard coded tree
    //         8
    //       /   \
    //     3      10
    //    /      /  \
    //   1      6    14
    //         / \   /
    //        4   7 13
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(7);

    vector<int> ans = diagonal(root);
    printList(ans);
    vector<int> ans2 = diagonalOptimized(root);
    printList(ans2);

    return 0;
}