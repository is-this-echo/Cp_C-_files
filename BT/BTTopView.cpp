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


/*
q) Given a pointer to the root of a binary tree, print the top view of the binary tree.
The tree as seen from the top the nodes, is called the top view of the tree.

For example :
   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4
Top View : 
Complete the function and print the resulting values on a single line separated by space.
*/

class Node 
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

/*
In the below tree, a pre-order dfs traversal would provide a wrong answer
as we get 5 before 3 (both with horizontal distance = 1) in the top view although
3 comes before 5. So, a bfs solution with horizontal distance tracking is the way
to go as it guarantees level wise (vertical) traversal.

        1 (0)
       /   \
    2(-1)  3(1)
      \
     4(0)
       \
       5(1)
         \
         6(2)

Correct top view result : 2 1 3 6
*/
void topView(Node* root)
{
    map<int, int> mp;  // horizontal dist, node val
    queue<pair<Node*, int>> q; // nodePtr, horizontal dist

    q.push({root, 0});
    while (!q.empty())
    {
        auto [currNode, hd] = q.front();
        q.pop();

        if (!mp.count(hd))  // only need the first node value from top
            mp[hd] = currNode->data;

        if (currNode->left)
            q.push({currNode->left, hd - 1});

        if (currNode->right)
            q.push({currNode->right, hd + 1});
    }

    for (const auto& [key, top] : mp)
        cout << top << " ";
}


int main() {
    fastio();

    return 0;
}