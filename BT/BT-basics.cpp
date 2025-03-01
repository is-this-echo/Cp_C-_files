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


class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {} 
};

// pre-order
Node* buildTree() {
    int d;
    cin>>d;

    if(d == -1)
        return NULL;

    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void preOrderTraversal(Node* root) {
    if(root == NULL)
        return;

    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


void inOrderTraversal(Node* root) {
    if(root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}


void postOrderTraversal(Node* root) {
    if(root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
}

/*
Height of a node : The number of edges on the longest path from the node to a leaf node.
so, height of tree = height of root node, the number of edges on the longest path from the root node to a leaf node.

Depth of a node: The number of edges from the root node to that node.
so, depth of tree = max height of tree.
*/

int treeHeight(Node *root) {
    if(root == NULL)
        return 0;

    int leftH = treeHeight(root->left);
    int rightH = treeHeight(root->right);

    return 1 + max(leftH, rightH);
}

// unoptimized version
int treeDiameter(Node *root) {
    if(root == NULL)
        return 0;

    int d1 = treeHeight(root->left) + treeHeight(root->right);
    int d2 = treeDiameter(root->left);
    int d3 = treeDiameter(root->right);

    return max(d1, max(d2, d3));
}


void bfsTraversal(Node *root) {
    queue<Node*>q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            cout << endl;

            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout << curr->val << " ";

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }
    }
}


Node* levelOrderBuild() {
    queue<Node*>q;

    int d;
    cin >> d;

    if( d == -1)
        return NULL;

    Node* root = new Node(d);
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        int v1,v2;
        cin>>v1>>v2;

        if(v1 != -1){
            curr->left = new Node(v1);
            q.push(curr->left);
        }

        if(v2 != -1){
            curr->right = new Node(v2);
            q.push(curr->right);
        }
    }
    return root;
}

Node* minHeightBST(int arr2[], int st, int end) {
    if(st>end)
        return NULL;

    int mid = (st+end)>>1;
    Node* root = new Node(arr2[mid]);

    root->left = minHeightBST(arr2, st, mid-1);
    root->right = minHeightBST(arr2, mid+1, end);

    return root;
}


Node* insertBST(Node* root, int key)
{
    if (root == NULL)
        return new Node(key);
    
    if (root->val < key)
        root->right = insertBST(root->right, key);
    
    else
        root->left = insertBST(root->left, key);
    
    return root;
}


int main() {

   // input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
//    Node* root = buildTree();

//    postOrderTraversal(root);
//    preOrderTraversal(root);
//    inOrderTraversal(root);

    // cout << treeDiameter(root);

    // bfs(root);

    // int arr2[] = {1,2,3,4,5,6,7};
    // Node* root2 = minHeightBST(arr2,0,sizeof(arr2)/sizeof(arr2[0]) - 1);
    // inOrderTraversal(root2);

    int arrBST[] = {4, 5, 1, 3, 9, 2, 7, 6};
    Node* ans = NULL;

    for (int x : arrBST)
        ans = insertBST(ans, x);

    inOrderTraversal(ans);

    return 0;
}