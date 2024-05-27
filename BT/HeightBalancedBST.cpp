 #pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 2e18
#define mod 998244353
const double eps = 1e-12;


class Node{
public:
    int val;
    Node *left, *right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};


/*
    Height balanced binary tree -> All the nodes in the tree should have left and right
    subtrees as balanced and the difference in heights between the left and right subtrees
    should be less than or equal to 1.
*/

// O(n) time complexity
pair<int,bool> HeightBalanced(Node* root){
    pair<int,bool> p, leftTree, rightTree;
 
    // base case
    if(root == nullptr){
        p.first = 0;   // height
        p.second = true;   // isBalanced
        return p;
    }

    leftTree = HeightBalanced(root->left);
    rightTree  = HeightBalanced(root->right); 

    int heightDiff = abs(leftTree.first-rightTree.first);
    int currHeight = max(leftTree.first, rightTree.first)+1;

    if(heightDiff<=1 && leftTree.second && rightTree.second)
        return {currHeight,true};
    
    return make_pair(currHeight, false);
}
    

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    return 0;
}