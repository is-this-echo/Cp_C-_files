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
    


class Node{
public:
    int val;
    Node *left, *right, *next;

    Node(int d){
        val = d;
        left=right=next=NULL;
    }
};


// using BFS, TC=O(n), SC=O(n)

Node* connect(Node* root) {
    queue<Node*>q;
    Node* temp=NULL;
    
    if(root==NULL)
        return root;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        
        if(curr==NULL){
            temp = NULL;
            
            if(!q.empty())
                q.push(NULL);
        }
        
        else{
            if(temp!=NULL)
                temp->next = curr;
            
            temp = curr;
            
            if(curr->left)
                q.push(curr->left);
            
            if(curr->right)
                q.push(curr->right);
        }
    }
    return root;
}


// using dfs; TC=O(n),SC = O(1) 

void solve(Node*root){
    if(root->left==NULL)
        return;
    
    root->left->next = root->right;

    if(root->next){
        root->right->next = root->next->left;
    }

    solve(root->left);
    solve(root->right);
}


Node* connect2(Node *root){
    solve(root);

    return root;
}


int main() {
    fastio();
    
    return 0;
}